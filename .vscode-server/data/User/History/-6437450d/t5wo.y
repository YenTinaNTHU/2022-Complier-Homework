%{
#include <stdio.h>
%}

%union {
  int intVal;
  float floatVal;
  char *stringVal;
}

%token<intVal> INT_NUM
%token<floatVal> FLOAT_NUM
%token<stringVal> ID
%token '=' '+' '-'
%token ':' ';' ',' '.' '[' ']' '(' ')' '{' '}'
%token CONST SIGNED UNSIGNED SHORT LONG LONG_LONG INT CHAR DOUBLE VOID FLOAT STRUCT RETURN
%token FOR DO WHILE BREAK CONTINUE
%token IF ELSE SWITCH CASE DEFAULT

%type<intVal> statement expression

%left '+' '-'
%left '*' '/'
%nonssoc UMINUS
%% 

statement
  : ID '=' expression
  | expression { printf("= %d\n", $1); }
;

expression
  : expression '+' NUM { $$ = $1 + $3; }
  | expression '-' NUM { $$ = $1 - $3; }
  | NUM { $$ = $1; }
;

%%
int main(void)
{
  yyparse();
  return 0;
}

int yyerror(char *s)
{ 
  fprintf(stderr, "%s\n", s);
  return 0;
}