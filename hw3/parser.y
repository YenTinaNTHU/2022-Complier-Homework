%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "code.h"
    extern int yylex();
    int yyerror(char *s);


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
%type<int_v> expr

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
  | scalar_decl
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
      fprintf(codegen, ".global codegen\n");
      fprintf(codegen, "codegen:\n");
      fprintf(codegen, "addi sp, sp, %d\n", -1*FRAME_SIZE);
      fprintf(codegen, "sd ra, %d(sp)\n", FRAME_SIZE-8);
      fprintf(codegen, "sd fp, %d(sp)\n", FRAME_SIZE-16);
      fprintf(codegen, "addi fp, sp, %d\n", FRAME_SIZE);
    }
  codegen_stmts
    {
      /* Section B */
      printf("exit function body\n");
      fprintf(codegen, "ld ra, %d(sp)\n", FRAME_SIZE-8);
      fprintf(codegen, "ld fp, %d(sp)\n", FRAME_SIZE-16);
      fprintf(codegen, "addi sp, sp, %d\n", FRAME_SIZE);
      fprintf(codegen, "jr ra");
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
    }
  | DIGITALWRITE '(' INT_NUM ',' LOW ')' ';'
    {
      // printf("digital_write_func, %d, LOW\n", $3);
      /* put the argument in to a0, a1 and call digitalWrite() */
      printf("call digitalWrite()\n");
      fprintf(codegen, "li a0, %d\n", $3);
      fprintf(codegen, "li a1, 0\n");
      fprintf(codegen, "jal ra, digitalWrite\n");
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
    }
;

scalar_decl
  : type ident '=' expr ';'
    {
      printf("scalar declaraition\n");
      /* set local variable */
      install_symbol($2);
      set_local_vars($2);
      /* store value to the stack */
      int idx = look_up_symbol($2);
      int byte_offset = -1 * (2 + MAX_ARGUMENT_NUM + table[idx].offset) * 8;
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 16\n");
      fprintf(codegen, "sd t0, %d(fp)\n", byte_offset);
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
    }
;

type: INT;

ident: ID;

expr
	: expr '+' expr
    {
      /* Assume the operants are already in stack */
      fprintf(codegen, "ld t0, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "ld t1, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 8\n");
      fprintf(codegen, "add t0, t1, t0\n");
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");

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
      printf("mod %d %d\n", $1, $3);
      $$ = $1 % $3;
    }
  | '(' expr ')' {$$ = $2;}
  | INT_NUM {
      fprintf(codegen, "li t0, %d\n", $1);
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      $$ = $1;
    }
  | variable 
    {
      // Find the variable in symbol table
      int idx = look_up_symbol($1);
      // Get the offset
      int byte_offset = -1 * (2 + MAX_ARGUMENT_NUM + table[idx].offset) * 8;
      fprintf(codegen, "ld t0, %d(fp)\n", byte_offset);
      fprintf(codegen, "addi sp, sp, -8\n");
      fprintf(codegen, "sd t0, 0(sp)\n");
      $$ = 1;
    }
;

variable: ident {$$ = $1;};

%%

int main(void)
{
  init_symbol_table();
  init_execute_func();
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