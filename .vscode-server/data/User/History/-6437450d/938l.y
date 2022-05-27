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
%type <stringVal> type int_type char_type other_type

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
  | other_type { $$ = $1; }
  | CONST { $$ = $1; }
;

int_type
  : CONST SIGNED LONG_LONG INT { $$ = strdup("constsignedlonglongint"); }
  | CONST SIGNED LONG INT { $$ = strdup("constsignedlongint"); }
  | CONST SIGNED SHORT INT { $$ = strdup("constsignedshortint"); }
  | CONST SIGNED INT { $$ = strdup("constsignedint"); }
  | CONST UNSIGNED LONG_LONG INT { $$ = strdup("constunsignedlonglongint"); }
  | CONST UNSIGNED LONG INT { $$ = strdup(""); }
  | CONST UNSIGNED SHORT INT { $$ = strdup(""); }
  | CONST UNSIGNED INT { $$ = strdup(""); }
  | CONST LONG_LONG INT { $$ = strdup(""); }
  | CONST LONG INT { $$ = strdup(""); }
  | CONST SHORT INT { $$ = strdup(""); }
  | CONST INT { $$ = strdup(""); }
  | SIGNED LONG_LONG INT { $$ = strdup(""); }
  | SIGNED LONG INT { $$ = strdup(""); }
  | SIGNED SHORT INT { $$ = strdup(""); }
  | SIGNED INT { $$ = strdup(""); }
  | UNSIGNED LONG_LONG INT { $$ = strdup(""); }
  | UNSIGNED LONG INT { $$ = strdup(""); }
  | UNSIGNED SHORT INT { $$ = strdup(""); }
  | UNSIGNED INT { $$ = strdup(""); }
  | LONG_LONG INT { $$ = strdup(""); }
  | LONG INT { $$ = strdup(""); }
  | SHORT INT { $$ = strdup(""); }
  | INT { $$ = strdup(""); }
;

char_type
  : CONST SIGNED LONG_LONG { $$ = strdup("constsignedlonglong"); }
  | CONST SIGNED LONG { $$ = strdup("constsignedlong"); }
  | CONST SIGNED SHORT { $$ = strdup("constsignedshort"); }
  | CONST SIGNED CHAR { $$ = strdup("constsignedchar"); }
  | CONST UNSIGNED LONG_LONG { $$ = strdup("constunsignedlonglong"); }
  | CONST UNSIGNED LONG { $$ = strdup("constunsignedlong"); }
  | CONST UNSIGNED SHORT { $$ = strdup("constunsignedshort"); }
  | CONST UNSIGNED CHAR { $$ = strdup("constunsignedchar"); }
  | CONST LONG_LONG { $$ = strdup("constlonglong"); }
  | CONST LONG { $$ = strdup("constlong"); }
  | CONST SHORT { $$ = strdup("constshort"); }
  | CONST CHAR { $$ = strdup("constchar"); }
  | SIGNED LONG_LONG { $$ = strdup("signedlonglong"); }
  | SIGNED LONG { $$ = strdup("signedlong"); }
  | SIGNED SHORT { $$ = strdup("signedshort"); }
  | SIGNED CHAR { $$ = strdup("signedchar"); }
  | UNSIGNED LONG_LONG { $$ = strdup("unsignedlonglong"); }
  | UNSIGNED LONG { $$ = strdup("unsignedlong"); }
  | UNSIGNED SHORT { $$ = strdup("unsignedshort"); }
  | UNSIGNED CHAR { $$ = strdup("unsignedshar"); }
  | LONG_LONG { $$ = strdup("longlong"); }
  | LONG { $$ = strdup("long"); }
  | SHORT { $$ = strdup("short"); }
  | CHAR { $$ = strdup("char"); }
;

other_type
  : CONST SIGNED { $$ = strdup("constsigned"); }
  | CONST UNSIGNED { $$ = strdup("ocnstunsigned"); }
  | CONST FLOAT { $$ = strdup("constfloat"); }
  | CONST DOUBLE { $$ = strdup("constdouble"); }
  | CONST VOID { $$ = strdup("constvoid"); }
  | SIGNED { $$ = strdup("signed"); }
  | UNSIGNED { $$ = strdup("unsigned"); }
  | FLOAT { $$ = strdup("float"); }
  | DOUBLE { $$ = strdup("double"); }
  | VOID { $$ = strdup("void"); }
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