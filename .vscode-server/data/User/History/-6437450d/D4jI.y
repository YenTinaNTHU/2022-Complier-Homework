%{
#include <stdio.h>
%}

%union {
  int intVal;
  float floatVal;
  char *stringVal;
}

%token <intVal>INT_NUM <floatVal>FLOAT_NUM
%token '=' '+' '-'

%type<intVal> statement expression

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
  fprintf(stderr, "%s\n", s); return 0;
}