%{
#include <stdio.h>
#include <string.h>
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

%type<int_v> expr term factor

%token<int_v> INT_NUM
%token<float_v> FLOAT_NUM
%token<string_v> ID
%token<string_v> '=' '+' '-' '*' '/' '%' '<' '>' '!' '&' '|' INC DEC LEQ GEQ EQL NEQ LAND LOR
%token<string_v> ':' ';' ',' '.' '[' ']' '(' ')' '{' '}'
%token<string_v> CONST SIGNED UNSIGNED SHORT LONG LONGLONG INT CHAR DOUBLE VOID FLOAT STRUCT RETURN
%token<string_v> FOR DO WHILE BREAK CONTINUE
%token<string_v> IF ELSE SWITCH CASE DEFAULT
%token<string_v> ESCAPE

%left ';'
%left ','
%right '='
%right ':'
%left LOR
%left LAND
%left '|'
%left '^'
%left '&'
%left EQL
%left '>' '<' LEQ GEQ
%left '+' '-'
%left '*' '/' '%'
%right INC DEC
%nonassoc UMINUS


%% 

program
  : statements
;

statements
  : statement {}
  | statement statements {}
;

statement
  : expr {printf("%d", $1);}
;

expr
  : expr '+' term { $$ = $1 + $3; }
  | expr '-' term { $$ = $1 - $3; }
  | term { $$ = $1; }
;
term
  : term '*' factor { $$ = $1 * $3; }
  | term '/' factor { $$ = $1 / $3; }
  | term '%' factor { $$ = $1 % $3; }
  | factor { $$ = $1; }
;
factor
  : '(' expr ')' { $$ = $2; }
  | ID { $$ = 0; }
  | INT_NUM { $$ = $1; }
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