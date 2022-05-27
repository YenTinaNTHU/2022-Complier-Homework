%{
#include <stdio.h>
%}

%union {
  int intVal;
  float floatVal;
  char charVal
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
%token ESCAPE

%type<intVal> statement expression
%type <stringVal> type int_type char_type float_type

%left '+' '-'
%left '*' '/'
%nonasoc UMINUS
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

type
  : int_type { $$ = $1; }
  | char_type { $$ = $1; }
  | float_type { $$ = $1; }
  | CONST { $$ = $1; }
;

int_type
  : CONST SIGNED LONG_LONG INT { $$ = strdup("const signed long long int"); }
  | CONST SIGNED LONG INT { $$ = strdup("const signed long int"); }
  | CONST SIGNED SHORT INT { $$ = strdup("const signed short int"); }
  | CONST SIGNED INT {}
  | CONST UNSIGNED LONG_LONG INT {}
  | CONST UNSIGNED LONG INT {}
  | CONST UNSIGNED SHORT INT {}
  | CONST UNSIGNED INT {}
  | CONST LONG_LONG INT {}
  | CONST LONG INT {}
  | CONST SHORT INT {}
  | CONST INT {}
  | SIGNED LONG_LONG INT {}
  | SIGNED LONG INT {}
  | SIGNED SHORT INT {}
  | SIGNED INT {}
  | UNSIGNED LONG_LONG INT {}
  | UNSIGNED LONG INT {}
  | UNSIGNED SHORT INT {}
  | UNSIGNED INT {}
  | LONG_LONG INT {}
  | LONG INT {}
  | SHORT INT {}
  | INT {}
;

char_type
  : CONST SIGNED LONG_LONG {}
  | CONST SIGNED LONG {}
  | CONST SIGNED SHORT {}
  | CONST SIGNED CHAR {}
  | CONST UNSIGNED LONG_LONG {}
  | CONST UNSIGNED LONG {}
  | CONST UNSIGNED SHORT {}
  | CONST UNSIGNED CHAR {}
  | CONST LONG_LONG {}
  | CONST LONG {}
  | CONST SHORT {}
  | CONST CHAR {}
  | SIGNED LONG_LONG {}
  | SIGNED LONG {}
  | SIGNED SHORT {}
  | SIGNED CHAR {}
  | UNSIGNED LONG_LONG {}
  | UNSIGNED LONG {}
  | UNSIGNED SHORT {}
  | UNSIGNED CHAR {}
  | LONG_LONG {}
  | LONG {}
  | SHORT {}
  | CHAR {}
;

float_type
  : CONST SIGNED {}
  | CONST UNSIGNED {}
  | CONST FLOAT {}
  | CONST DOUBLE {}
  | CONST VOID {}
  | SIGNED {}
  | UNSIGNED {}
  | FLOAT {}
  | DOUBLE {}
  | VOID {}
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