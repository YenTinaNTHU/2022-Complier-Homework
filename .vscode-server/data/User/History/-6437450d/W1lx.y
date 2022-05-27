%{
#include <stdio.h>
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
%token CONST SIGNED UNSIGNED SHORT LONG LONG_LONG INT CHARACTOR DOUBLE VOID FLOAT STRUCT RETURN
%token FOR DO WHILE BREAK CONTINUE
%token IF ELSE SWITCH CASE DEFAULT
%token ESCAPE

%type<intVal> statement expression
%type<stringVal> type int_type char_type other_type
%type<stringVal> idents ident

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%start statement
%% 

statement
  : ID '=' expression {}
  | expression { printf("= %d\n", $1); }
  | type idents {}
;

expression
  : expression '+' INT_NUM { $$ = $1 + $3; }
  | expression '-' INT_NUM { $$ = $1 - $3; }
  | expression '*' INT_NUM { $$ = $1 * $3; }
  | expression '/' INT_NUM { $$ = $1 / $3; }
  | INT_NUM { $$ = $1; }
;

type
  : int_type { $$ = $1; }
  | char_type { $$ = $1; }
  | other_type { $$ = $1; }
  | CONST { $$ = "const"; }
;

int_type
  : CONST SIGNED LONG_LONG INT { $$ = strdup("constsignedlonglongint"); }
  | CONST SIGNED LONG INT { $$ = strdup("constsignedlongint"); }
  | CONST SIGNED SHORT INT { $$ = strdup("constsignedshortint"); }
  | CONST SIGNED INT { $$ = strdup("constsignedint"); }
  | CONST UNSIGNED LONG_LONG INT { $$ = strdup("constunsignedlonglongint"); }
  | CONST UNSIGNED LONG INT { $$ = strdup("constunsignedlongint"); }
  | CONST UNSIGNED SHORT INT { $$ = strdup("constunsignedshortint"); }
  | CONST UNSIGNED INT { $$ = strdup("constunsignedint"); }
  | CONST LONG_LONG INT { $$ = strdup("constlonglongint"); }
  | CONST LONG INT { $$ = strdup("constlongint"); }
  | CONST SHORT INT { $$ = strdup("constshortint"); }
  | CONST INT { $$ = strdup("constint"); }
  | SIGNED LONG_LONG INT { $$ = strdup("signedlonglongint"); }
  | SIGNED LONG INT { $$ = strdup("signedlongint"); }
  | SIGNED SHORT INT { $$ = strdup("signedshortint"); }
  | SIGNED INT { $$ = strdup("signedint"); }
  | UNSIGNED LONG_LONG INT { $$ = strdup("unsignedlonglongint"); }
  | UNSIGNED LONG INT { $$ = strdup("unsignedlongint"); }
  | UNSIGNED SHORT INT { $$ = strdup("unsignedshortint"); }
  | UNSIGNED INT { $$ = strdup("unsignedint"); }
  | LONG_LONG INT { $$ = strdup("longlongint"); }
  | LONG INT { $$ = strdup("longint"); }
  | SHORT INT { $$ = strdup("shortint"); }
  | INT { $$ = strdup("int"); }
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