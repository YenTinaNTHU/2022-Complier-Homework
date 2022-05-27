%{
#include <stdio.h>
#include <string.h>
extern int yylex();
int yyerror(char *s);
%}

%union {
  int intVal;
  float floatVal;
  char charVal;
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
%token INC DEC LEQ GEQ EQL NEQ LAND LOR

%type<intVal> statement expression
%type<stringVal> type int_type char_type other_type
%type<stringVal> idents ident
%type<stringVal> scalar_decl

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%start statement
%% 

statement
  : ID '=' expression ';' {printf("%s = %d\n", $1, $3);}
  | expression ';' { printf("%d\n", $1); }
  | scalar_decl ';' { printf("") }
;

expression
  : expression '+' INT_NUM { $$ = $1 + $3; }
  | expression '-' INT_NUM { $$ = $1 - $3; }
  | expression '*' INT_NUM { $$ = $1 * $3; }
  | expression '/' INT_NUM { $$ = $1 / $3; }
  | INT_NUM { $$ = $1; }
;

scalar_decl
  : type idents ';' { printf("%s%s\n", $1, $2); }
;

type
  : int_type { $$ = $1; }
  | char_type { $$ = $1; }
  | other_type { $$ = $1; }
  | CONST { $$ = "const"; }
;

int_type
  : CONST SIGNED LONG_LONG INT { $$ = "constsignedlonglongint"; }
  | CONST SIGNED LONG INT { $$ = "constsignedlongint"; }
  | CONST SIGNED SHORT INT { $$ = "constsignedshortint"; }
  | CONST SIGNED INT { $$ = "constsignedint"; }
  | CONST UNSIGNED LONG_LONG INT { $$ = "constunsignedlonglongint"; }
  | CONST UNSIGNED LONG INT { $$ = "constunsignedlongint"; }
  | CONST UNSIGNED SHORT INT { $$ = "constunsignedshortint"; }
  | CONST UNSIGNED INT { $$ = "constunsignedint"; }
  | CONST LONG_LONG INT { $$ = "constlonglongint"; }
  | CONST LONG INT { $$ = "constlongint"; }
  | CONST SHORT INT { $$ = "constshortint"; }
  | CONST INT { $$ = "constint"; }
  | SIGNED LONG_LONG INT { $$ = "signedlonglongint"; }
  | SIGNED LONG INT { $$ = "signedlongint"; }
  | SIGNED SHORT INT { $$ = "signedshortint"; }
  | SIGNED INT { $$ = "signedint"; }
  | UNSIGNED LONG_LONG INT { $$ = "unsignedlonglongint"; }
  | UNSIGNED LONG INT { $$ = "unsignedlongint"; }
  | UNSIGNED SHORT INT { $$ = "unsignedshortint"; }
  | UNSIGNED INT { $$ = "unsignedint"; }
  | LONG_LONG INT { $$ = "longlongint"; }
  | LONG INT { $$ = "longint"; }
  | SHORT INT { $$ = "shortint"; }
  | INT { $$ = "int"; }
;

char_type
  : CONST SIGNED LONG_LONG { $$ = "constsignedlonglong"; }
  | CONST SIGNED LONG { $$ = "constsignedlong"; }
  | CONST SIGNED SHORT { $$ = "constsignedshort"; }
  | CONST SIGNED CHAR { $$ = "constsignedchar"; }
  | CONST UNSIGNED LONG_LONG { $$ = "constunsignedlonglong"; }
  | CONST UNSIGNED LONG { $$ = "constunsignedlong"; }
  | CONST UNSIGNED SHORT { $$ = "constunsignedshort"; }
  | CONST UNSIGNED CHAR { $$ = "constunsignedchar"; }
  | CONST LONG_LONG { $$ = "constlonglong"; }
  | CONST LONG { $$ = "constlong"; }
  | CONST SHORT { $$ = "constshort"; }
  | CONST CHAR { $$ = "constchar"; }
  | SIGNED LONG_LONG { $$ = "signedlonglong"; }
  | SIGNED LONG { $$ = "signedlong"; }
  | SIGNED SHORT { $$ = "signedshort"; }
  | SIGNED CHAR { $$ = "signedchar"; }
  | UNSIGNED LONG_LONG { $$ = "unsignedlonglong"; }
  | UNSIGNED LONG { $$ = "unsignedlong"; }
  | UNSIGNED SHORT { $$ = "unsignedshort"; }
  | UNSIGNED CHAR { $$ = "unsignedshar"; }
  | LONG_LONG { $$ = "longlong"; }
  | LONG { $$ = "long"; }
  | SHORT { $$ = "short"; }
  | CHAR { $$ = "char"; }
;

other_type
  : CONST SIGNED { $$ = "constsigned"; }
  | CONST UNSIGNED { $$ = "ocnstunsigned"; }
  | CONST FLOAT { $$ = "constfloat"; }
  | CONST DOUBLE { $$ = "constdouble"; }
  | CONST VOID { $$ = "constvoid"; }
  | SIGNED { $$ = "signed"; }
  | UNSIGNED { $$ = "unsigned"; }
  | FLOAT { $$ = "float"; }
  | DOUBLE { $$ = "double"; }
  | VOID { $$ = "void"; }
;

ident
  : ID {}
  | '*' ID {}
;

idents
  : ident ',' idents {}
  | ident '=' expression {}
  | ident
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