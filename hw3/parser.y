%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "code.h"
    extern int yylex();
    int yyerror(char *s);

    void fcomment(char *s){
      char *str1 = "//";
      fprintf(codegen, "%s %s\n", str1, s);
    }

%}

%start program

%union {
  int int_v;
  float float_v;
  char char_v;
  char* string_v;  
}

%type<string_v> program program_ingredients program_ingredient
%type<string_v> codegen_decl codegen_def codegen_stmts codegen_stmt
%type<string_v> digital_write_func delay_func
%type<string_v> scalar_decl type ident variable
%type<int_v> expr int_num
%type<string_v> stmt
%type<string_v> array_decl
%type<string_v> compound_stmt if_stmt if_else_stmt while_stmt do_while_stmt for_stmt


%token<int_v> INT_NUM POS_INT_NUM NEG_INT_NUM
%token<float_v> FLOAT_NUM POS_FLOAT_NUM NEG_FLOAT_NUM
%token<string_v> ID
%token<string_v> '=' '+' '-' '*' '/' '%' '<' '>' '!' '~' '&' '|' '^' INC DEC LEQ GEQ EQL NEQ LAND LOR
%token<string_v> ':' ';' ',' '.' '[' ']' '(' ')' '{' '}'
%token<string_v> CONST SIGNED UNSIGNED SHORT LONG LONGLONG INT CHAR CHAR4 CHAR8 DOUBLE VOID FLOAT STRUCT RETURN LSHIFT RSHIFT STR NUL
%token<string_v> FOR DO WHILE BREAK CONTINUE
%token<string_v> IF ELSE SWITCH CASE DEFAULT
%token<string_v> CHAR_START CHAR_END ESCAPE_START ESCAPE_CHAR STRING_START STRING_END
%token<string_v> CODEGEN DIGITALWRITE DELAY HIGH LOW

%left ';'
%left ','
%right '='
%left EQL NEQ
%left '>' '<'
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%nonassoc UMINUS UPLUS DEREF ADDR

%%

program
  : program_ingredients
;

program_ingredients
  : program_ingredients program_ingredient
  | program_ingredient
;

program_ingredient
  : codegen_decl
  | codegen_def
;

codegen_decl
  : VOID CODEGEN '(' ')' ';'
    {
      //printf("codegen_decl\n");
      // Put codegen() into symbol table
      install_symbol("codegen");
      set_global_vars("codegen");
    }
;

codegen_def:
  VOID CODEGEN '(' ')' '{'
    {
      cur_scope++;
      push_execute_func("codegen");
      set_scope_and_offset_of_param("codegen");
      /* Section A */
      /* 0 argument,  only 2 double words for ra and old fp */
      printf("enter funciton body:\n");
      fcomment("enter funciton body");
      fprintf(codegen, ".global codegen\n");
      fprintf(codegen, "codegen:\n");
      fprintf(codegen, "addi sp, sp, %d\n", -1*FRAME_SIZE);
      fprintf(codegen, "sd ra, %d(sp)\n", FRAME_SIZE-8);
      fprintf(codegen, "sd fp, %d(sp)\n", FRAME_SIZE-16);
      fprintf(codegen, "addi fp, sp, %d\n", FRAME_SIZE);
      fprintf(codegen, "\n");
    }
  codegen_stmts
    {
      /* Section B */
      printf("exit function body\n");
      fcomment("exit function body");
      fprintf(codegen, "ld ra, %d(sp)\n", FRAME_SIZE-8);
      fprintf(codegen, "ld fp, %d(sp)\n", FRAME_SIZE-16);
      fprintf(codegen, "addi sp, sp, %d\n", FRAME_SIZE);
      fprintf(codegen, "jr ra");
      fprintf(codegen, "\n");
      pop_up_symbol(cur_scope);
      cur_scope--;
      pop_execute_func();
    }
  '}'
;

codegen_stmts
  : codegen_stmts codegen_stmt
  | codegen_stmt
;

codegen_stmt
  : digital_write_func
  | delay_func
  | scalar_decl
  | array_decl
  | stmt
;

stmt
  : expr ';' {$$ = "expr";}
  | if_stmt
    {
      fprintf(codegen, ".IF%d0: \n", if_else_stack[if_else_pointer-1]);
      pop_if_else_stack();
    }
  | if_else_stmt
  | while_stmt
  | do_while_stmt
  | for_stmt
;

if_stmt
  : IF '(' expr
    {
      if_else_counter++;
      push_if_else_stack(if_else_counter);
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "beq zero, t0, .IF%d0\n", if_else_stack[if_else_pointer-1]);
    }
    ')' compound_stmt
;

if_else_stmt
  : if_stmt ELSE
    {
      fprintf(codegen, "j .IF%d1\n", if_else_stack[if_else_pointer-1]);
      fprintf(codegen, "\n");
      fprintf(codegen, ".IF%d0:\n", if_else_stack[if_else_pointer-1]);
    }
    compound_stmt
    {
      fprintf(codegen, ".IF%d1:\n", if_else_stack[if_else_pointer-1]);
      pop_if_else_stack();
    }
;

while_stmt
  : WHILE '('
    {
      fprintf(codegen, "WHILE:\n");
    }
    expr
    {
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "beq zero, t0, END_WHILE\n");
    }
    ')' compound_stmt
    {
      fprintf(codegen, "j WHILE\n");
      fprintf(codegen, "\n");
      fprintf(codegen, "END_WHILE:\n");
    }
;

do_while_stmt
  : DO
    {
      fprintf(codegen, "DOWHILE:\n");
    }
    compound_stmt WHILE '(' expr
    {
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "beq zero, t0, END_DOWHILE\n");
      fprintf(codegen, "j DOWHILE\n");
      fprintf(codegen, "\n");
      fprintf(codegen, "END_DOWHILE:\n");
    }
    ')' ';'
;

for_stmt
  : FOR '(' expr
    {
      // init
      for_counter++;
      fprintf(codegen, ".FOR%d:\n", for_counter);
    }
    ';' expr 
    {
      // test
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "beq zero, t0, .END_FOR%d\n", for_counter);
    }
    ';'
    {
      fprintf(codegen, "j .FOR_STMT%d\n", for_counter);
      fprintf(codegen, ".FOR_UPDATE%d:\n", for_counter);
    }
    expr 
    {
      fprintf(codegen, "j .FOR%d\n", for_counter);
    }
    ')'
    {
      fprintf(codegen, ".FOR_STMT%d:\n", for_counter);
    }
    compound_stmt
    {
      fprintf(codegen, "j .FOR_UPDATE%d\n", for_counter);
      fprintf(codegen, "\n");
      fprintf(codegen, ".END_FOR%d:\n", for_counter);
    }
;

digital_write_func
  : DIGITALWRITE '(' INT_NUM ',' HIGH ')' ';'
    {
      // printf("digital_write_func, %d, HIGH\n", $3);
      /* put the argument in to a0, a1 and call digitalWrite() */
      printf("call digitalWrite()\n");
      fprintf(codegen, "li a0, %d\n", $3);
      fprintf(codegen, "li a1, 1\n");
      fprintf(codegen, "jal ra, digitalWrite\n");
      fprintf(codegen, "\n");
    }
  | DIGITALWRITE '(' INT_NUM ',' LOW ')' ';'
    {
      // printf("digital_write_func, %d, LOW\n", $3);
      /* put the argument in to a0, a1 and call digitalWrite() */
      printf("call digitalWrite()\n");
      fprintf(codegen, "li a0, %d\n", $3);
      fprintf(codegen, "li a1, 0\n");
      fprintf(codegen, "jal ra, digitalWrite\n");
      fprintf(codegen, "\n");
    }
;

delay_func
  : DELAY '(' expr ')' ';'
    {
      // printf("delay_func, %d\n", $3);
      /* put the argument in to a0 and call delay() */
      printf("call delay()\n");
      fprintf(codegen, "ld a0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "jal ra, delay\n");
      fprintf(codegen, "\n");
    }
;

scalar_decl
  : type ident '=' expr ';'
    {
      printf("declare and assign variable %s\n", $2);
      /* set local variable */
      install_symbol($2);
      set_local_vars($2);
      set_int_type($2);
      print_symbol_table(10);
      /* store value to the stack */
      int idx = look_up_symbol($2);
      int byte_offset = -1 * (2 + MAX_ARGUMENT_NUM + table[idx].offset) * 8;
      // pop value from stack
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      // write the value to the variable
      fprintf(codegen, "sd t0, %d(fp)\n", byte_offset);
      fprintf(codegen, "\n");
      // print_symbol_table(5);
    }
  | type '*' ident '=' expr ';'
    {
      printf("declare and assign pointer %s\n", $3);
      /* set local variable */
      install_symbol($3);
      set_local_vars($3);
      set_ptr_type($3);
      print_symbol_table(10);
      /* Write the offset of variable to the ident address on stack. */
      // get offset from symbol table and count byte offset
      int idx = look_up_symbol($3);
      int byte_offset = -1 * (2 + MAX_ARGUMENT_NUM + table[idx].offset) * 8;
      // pop the address store on stack and put to t0
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      // write the variable's byte offset to the address of ident
      fprintf(codegen, "sd t0, %d(fp)\n", byte_offset);
      fprintf(codegen, "\n");
    }
  | type ident ';'
    {
      printf("declare variable %s\n", $2);
      /* set local variable */
      install_symbol($2);
      set_local_vars($2);
      set_int_type($2);
      print_symbol_table(20);
    }
;

array_decl
  : type ident '[' INT_NUM ']' ';'
    {
      /* set local variable */
      fcomment("array declaration");
      /* store the INT_NUM(elements) + 1(pointer) symbol to the symbol table */
      install_symbol($2);
      set_local_vars($2);
      set_ptr_type($2);
      char* arr_ele_name = strdup($2);
      for(int i=0; i<$4; i++){
        install_symbol("");
        set_local_vars("");
        set_int_type($2);
      }
      print_symbol_table(10);
      /* since we fix the size of frame, no need to move the stack pointer */
      // let ident point to ident[0]
      int idx = look_up_symbol($2);
      int byte_offset = (2 + MAX_ARGUMENT_NUM + table[idx].offset) * 8;
      // load ident[0] to ident address
      fprintf(codegen, "li t0, %d\n", byte_offset + 8);
      fprintf(codegen, "sd t0, %d(fp)\n", -1 * byte_offset);
    }
;

type: INT | CONST INT;

ident: ID;

expr
	: expr '+' expr
    {
      /* Assume the operants are already in stack */
      fprintf(codegen, "\n");
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "add t0, t1, t0\n");
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      fprintf(codegen, "\n");
      printf("add %d %d\n", $1, $3);
      $$ = $1 + $3;
    }
	| expr '-' expr
    {
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "sub t0, t1, t0\n");
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      fprintf(codegen, "\n");
      printf("sub %d %d\n", $1, $3);
      $$ = $1 - $3;
    }
	| expr '*' expr
    {
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "mul t0, t1, t0\n");
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      fprintf(codegen, "\n");
      printf("mul %d %d\n", $1, $3);
      $$ = $1 * $3;
    }
	| expr '/' expr
    {
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "div t0, t1, t0\n");
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      fprintf(codegen, "\n");
      printf("div %d %d\n", $1, $3);
      $$ = $1 / $3;
    }
	| expr '%' expr
    {
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "mod t0, t1, t0\n");
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      fprintf(codegen, "\n");
      printf("mod %d %d\n", $1, $3);
      $$ = $1 % $3;
    }
  | expr '>' expr
    {
      /* e1: 8(sp)->t1, e2:0(sp)->t0 */
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      // t2 = t0 - t1
      fprintf(codegen, "sub t2, t0, t1\n");
      // if t2 < 0, t1 > t0, -> t3 = 1
      fprintf(codegen, "slt t3, t2, zero\n");
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t3, 0(sp)\n");

    }
  | expr '<' expr
    {
      /* e1: 8(sp)->t1, e2:0(sp)->t0 */
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      // t2 = t1 - t0
      fprintf(codegen, "sub t2, t1, t0\n");
      // if t2 < 0, t1 < t0, -> t3 = 1
      fprintf(codegen, "slt t3, t2, zero\n");
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t3, 0(sp)\n");
    }
  | expr EQL expr
    {
      /* e1: 8(sp)->t1, e2:0(sp)->t0 */
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");

      fprintf(codegen, "xor t2, t0, t1\n");
      fprintf(codegen, "sltu t3, zero, t2\n");
      fprintf(codegen, "xori t4, t3, 1\n");

      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t4, 0(sp)\n");
    }
  | expr NEQ expr
    {
      /* e1: 8(sp)->t1, e2:0(sp)->t0 */
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");

      fprintf(codegen, "xor t2, t0, t1\n");
      fprintf(codegen, "sltu t3, zero, t2\n");

      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t2, 0(sp)\n");
    }
  | '(' expr ')' {$$ = $2;}
  | int_num {
      fcomment("push num to stack");
      fprintf(codegen, "li t0, %d\n", $1);
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      printf("Put integer:%d onto stack.\n", $1);
      fprintf(codegen, "\n");
      $$ = $1;
    }
  | variable 
    {
      printf("push variable:%s value to stack.\n", $1);
      /* push the variable's value to the stack */
      // 1. pop and load the address to t0
      fcomment("get variable's value");
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "sub t0, fp, t0\n");
      // 2. store the value to t1
      fprintf(codegen, "ld t1, 0(t0)\n");
      // 3. push t1 to stack
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t1, 0(sp)\n");
      fprintf(codegen, "\n");
      
      $$ = 1;
    }
  | variable '=' expr
    {;
      printf("assign variable %s\n", $1);
      fcomment("assign variable");
      /* init -- variable's byte offset: 8(sp), expr: 0(sp) */
      /* t0: variable's byte offset */
      /* t1: expr's value */
      // 1. pop and load value of expr to t1
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      // 2. pop and load the address to t0
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "sub t0, fp, t0\n");
      // 3. stored the value of expr to *variable (address stored in t1)
      fprintf(codegen, "sd t1, 0(t0)\n");
      fprintf(codegen, "\n");
      $$ = $3;
    }
  | '&' variable %prec ADDR
    {
      /* push the variable's address to the stack */
      /* since variable's address is put at sp(0), there is noting to do. */
      printf("%s address\n", $2);
      fcomment("address");
      $$ = 1;
    }
  | '-' expr %prec UMINUS
    {
      printf("minus\n");
      fcomment("minus");
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "sub t0, zero, t0\n");
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      fprintf(codegen, "\n");
      $$ = 1;
    }
;

int_num
  : INT_NUM {$$ = $1;}
  | POS_INT_NUM {$$ = $1;}
  | NEG_INT_NUM {$$ = $1;}
;

variable
  : ident 
    {
      /* push the variable's byte offset to the stack */
      printf("push %s's byte offset to the stack\n", $1);
      int idx = look_up_symbol($1);
      int byte_offset = (2 + MAX_ARGUMENT_NUM + table[idx].offset) * 8;
      fcomment("push ident offset to stack");
      fprintf(codegen, "li t0, %d\n", byte_offset);
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      fprintf(codegen, "\n");
      $$ = $1;
    }
  | ident '[' expr ']'
    {
      /* push the byte offset of array's element to the stack */
      /* t0: byte offset of ident */
      /* t1: value of expr */
      printf("push the byte offset of array's element to the stack\n");
      int idx = look_up_symbol($1);
      int byte_offset = (2 + MAX_ARGUMENT_NUM + table[idx].offset) * 8; // +1 for the first element of array
      fcomment("push array's ident byte offset to stack");
      // write the offset of the first element into t0
      fprintf(codegen, "li t1, %d\n", byte_offset);
      fprintf(codegen, "sub t1, fp, t1\n");
      fprintf(codegen, "ld t0, 0(t1)\n");
      // pop the value of expr to t1 and count the byte offset
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "li t3, 8\n");
      fprintf(codegen, "mul t1, t1, t3\n");
      // target byte offset = t0 + t1
      fprintf(codegen, "add t0, t0, t1\n");
      // push the target byte offset to the stack
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      fprintf(codegen, "\n");
      $$ = $1;
    }
  | '*' ident %prec DEREF
    {
      /* push the value of ident to the stack (the offset of *ident) */
      printf("push the value of ident to the stack\n");
      int idx = look_up_symbol($2);
      int byte_offset =  (2 + MAX_ARGUMENT_NUM + table[idx].offset) * 8;
      fcomment("push value of pointer to stack");
      // read the value of ident and put to t0
      fprintf(codegen, "li t1, %d\n", byte_offset);
      fprintf(codegen, "sub t1, fp, t1\n");
      fprintf(codegen, "ld t0, 0(t1)\n");
      // push the target byte offset to the stack
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      fprintf(codegen, "\n");
      $$ = $2;
    }
  | '*' '(' ident '+' expr ')' %prec DEREF
    {
       /* push the address of array's element to the stack */
      /* t0: byte offset of ident */
      /* t1: value of expr */
      printf("push the address of array's element to the stack\n");
      int idx = look_up_symbol($3);
      int byte_offset = (2 + MAX_ARGUMENT_NUM + table[idx].offset) * 8; // +1 for the first element of array
      fcomment("push the address of array's element to the stack");
      // write the offset of the first element into t0
      fprintf(codegen, "li t1, %d\n", byte_offset);
      fprintf(codegen, "sub t1, fp, t1\n");
      fprintf(codegen, "ld t0, 0(t1)\n");
      // pop the value of expr to t1 and count the byte address
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "li t3, 8\n");
      fprintf(codegen, "mul t1, t1, t3\n");
      // target byte offset = t0 + t1
      fprintf(codegen, "add t0, t0, t1\n");
      // push the target byte offset to the stack
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      fprintf(codegen, "\n");
      $$ = $3;
    }
;

compound_stmt
  : '{' '}' { $$ = "{}"; }
  | '{' codegen_stmts '}'
;

%%

int main(void)
{
  init_symbol_table();
  init_execute_func();
  init_if_else_stack();
  for_counter = 0;
  codegen = fopen("codegen.S","w");
  yyparse();
  fclose(codegen);
  return 0;
}

int yyerror(char *s)
{ 
  fprintf(stderr, "%s\n", s);
  return 0;
}