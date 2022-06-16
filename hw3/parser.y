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

%%

program
  : program_ingredients
    {

    }
;

program_ingredients
  : program_ingredients program_ingredient
    {

    }
  | program_ingredient
    {

    }
;

program_ingredient
  : codegen_decl
    {

    }
  | codegen_def
    {

    }
;

codegen_decl
  : VOID CODEGEN '(' ')' ';'
    {
      //printf("codegen_decl\n");
      // put codegen() into symbol table?
    }
;

codegen_def:
  VOID CODEGEN '(' ')' '{'
    {
      /* Section A */
      /* 0 argument,  only 2 double words for ra and old fp */
      printf("enter funciton body:\n");
      fprintf(codegen, ".global codegen\n");
      fprintf(codegen, "codegen:\n");
      fprintf(codegen, "addi sp, sp, -16\n");
      fprintf(codegen, "sd ra, 8(sp)\n");
      fprintf(codegen, "sd fp, 0(sp)\n");
      fprintf(codegen, "addi fp, sp, 16\n");
    }
  codegen_stmts
    {
      /* Section B */
      printf("exit function body\n");
      fprintf(codegen, "ld ra, 8(sp)\n");
      fprintf(codegen, "ld fp, 0(sp)\n");
      fprintf(codegen, "addi sp, sp, 16\n");
      fprintf(codegen, "jr ra");
    }
  '}'
;

codegen_stmts
  : codegen_stmts codegen_stmt
  | {$$ = "";}
;

codegen_stmt
  : digital_write_func
  | delay_func
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
  : DELAY '(' INT_NUM ')' ';'
    {
      // printf("delay_func, %d\n", $3);
      /* put the argument in to a0 and call delay() */
      printf("call delay()\n");
      fprintf(codegen, "li a0, %d\n", $3);
      fprintf(codegen, "jal ra, delay\n");
    }
;


%%

int main(void)
{
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