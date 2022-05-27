%{
#include <stdio.h>
#include <string.h>
extern int yylex();
int yyerror(char *s);
char* add_expr_tag(char* str);
%}

%union {
  char charVal;
  char *stringVal;
}

%token<stringVal> INT_NUM
%token<stringVal> FLOAT_NUM
%token<stringVal> ID
%token<stringVal> '=' '+' '-' '*' '/' '%'
%token<stringVal> ':' ';' ',' '.' '[' ']' '(' ')' '{' '}'
%token CONST SIGNED UNSIGNED SHORT LONG LONG_LONG INT CHAR DOUBLE VOID FLOAT STRUCT RETURN
%token FOR DO WHILE BREAK CONTINUE
%token IF ELSE SWITCH CASE DEFAULT
%token ESCAPE
%token INC DEC LEQ GEQ EQL NEQ LAND LOR

%type<stringVal> statement expression
%type<stringVal> type int_type char_type other_type
%type<stringVal> idents ident
%type<stringVal> scalar_decl

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%start program
%% 

program
  : statements
;

statements
  : statement {}
  | statement statements {}
;

statement
  : scalar_decl ';' { printf("<scalar_decl>%s;</scalar_decl>", $1); }
;

expression
  : expression '+' INT_NUM { char* str = strdup($1); strcat(str, $2); strcat(str, add_expr_tag($3)); $$ = add_expr_tag(str);}
  | expression '-' INT_NUM {}
  | expression '*' INT_NUM {}
  | expression '/' INT_NUM {}
  | INT_NUM { $$ = add_expr_tag($1);}
;

scalar_decl
  : type idents { char *str = strdup($1); strcat(str, $2); $$ = str; }
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
  : ID { $$ = $1;}
  | '*' ID { char *str = strdup($1);; strcat(str, $2); $$ = str; }
;

idents
  : ident ',' idents { char* str = strdup($1); strcat(str, $2); strcat(str, $3); $$ = str; }
  | ident '=' expression { char* str = strdup($1); strcat(str, $2); strcat(str, $3); $$ = str;}
  | ident { $$ = $1;}
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

char* add_expr_tag(char* str){
  char *tag_str = strdup("<expr>");
  // printf("%s\n", tag_str);
  strcat(tag_str, str);
  // printf("%s\n", tag_str);
  strcat(tag_str, "</expr>");
  // printf("%s\n", tag_str);
  return tag_str;
}