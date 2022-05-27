%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
int yyerror(char *s);


char* itoa(int x) {
    int y = x;
    int l = 1;
    while (y > 9) {
        y /= 10;
        l += 1;
    }
    char* t = malloc(sizeof(char) * l);
    sprintf(t, "%d", x);
    return t;
}

char* double2string(double x) {
    char* s = malloc(sizeof(char) * 30);
    sprintf(s, "%f", x);
    return s;
}
%}

%union {
  int int_v;
  float float_v;
  char char_v;
  char* string_v;  
}

%type<string_v> program
%type<string_v> global_variable_decls
%type<string_v> scalar_decl type ident idents int_type char_type other_type
%type<string_v> array_decl arrays array arr_dim arr_content exprs
%type<string_v> statement statements
%type<int_v> expr

%token<int_v> INT_NUM
%token<float_v> FLOAT_NUM
%token<string_v> ID
%token<string_v> '=' '+' '-' '*' '/' '%' '<' '>' '!' '&' '|' INC DEC LEQ GEQ EQL NEQ LAND LOR
%token<string_v> ':' ';' ',' '.' '[' ']' '(' ')' '{' '}'
%token<string_v> CONST SIGNED UNSIGNED SHORT LONG LONGLONG INT CHAR DOUBLE VOID FLOAT STRUCT RETURN LSHIFT RSHIFT
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
program: statements

statements
  : statement statements
  | statement
;

statement: global_variable_decls ;

global_variable_decls
  : scalar_decl ';'
    {
      printf("<scalar_decl>");
      printf("%s;",$1);
      printf("</scalar_decl>");
    }
  | array_decl ';'
    {
      printf("<array_decl>");
      printf("%s", $1);
      printf("</array_decl>");
    }
;

type
  : int_type { $$ = $1; }
  | char_type { $$ = $1; }
  | other_type { $$ = $1; }
  | CONST { $$ = "const"; }
;

int_type
  : CONST SIGNED LONGLONG INT { $$ = "constsignedlonglongint"; }
  | CONST SIGNED LONG INT { $$ = "constsignedlongint"; }
  | CONST SIGNED SHORT INT { $$ = "constsignedshortint"; }
  | CONST SIGNED INT { $$ = "constsignedint"; }
  | CONST UNSIGNED LONGLONG INT { $$ = "constunsignedlonglongint"; }
  | CONST UNSIGNED LONG INT { $$ = "constunsignedlongint"; }
  | CONST UNSIGNED SHORT INT { $$ = "constunsignedshortint"; }
  | CONST UNSIGNED INT { $$ = "constunsignedint"; }
  | CONST LONGLONG INT { $$ = "constlonglongint"; }
  | CONST LONG INT { $$ = "constlongint"; }
  | CONST SHORT INT { $$ = "constshortint"; }
  | CONST INT { $$ = "constint"; }
  | SIGNED LONGLONG INT { $$ = "signedlonglongint"; }
  | SIGNED LONG INT { $$ = "signedlongint"; }
  | SIGNED SHORT INT { $$ = "signedshortint"; }
  | SIGNED INT { $$ = "signedint"; }
  | UNSIGNED LONGLONG INT { $$ = "unsignedlonglongint"; }
  | UNSIGNED LONG INT { $$ = "unsignedlongint"; }
  | UNSIGNED SHORT INT { $$ = "unsignedshortint"; }
  | UNSIGNED INT { $$ = "unsignedint"; }
  | LONGLONG INT { $$ = "longlongint"; }
  | LONG INT { $$ = "longint"; }
  | SHORT INT { $$ = "shortint"; }
  | INT { $$ = "int"; }
;

char_type
  : CONST SIGNED LONGLONG { $$ = "constsignedlonglong"; }
  | CONST SIGNED LONG { $$ = "constsignedlong"; }
  | CONST SIGNED SHORT { $$ = "constsignedshort"; }
  | CONST SIGNED CHAR { $$ = "constsignedchar"; }
  | CONST UNSIGNED LONGLONG { $$ = "constunsignedlonglong"; }
  | CONST UNSIGNED LONG { $$ = "constunsignedlong"; }
  | CONST UNSIGNED SHORT { $$ = "constunsignedshort"; }
  | CONST UNSIGNED CHAR { $$ = "constunsignedchar"; }
  | CONST LONGLONG { $$ = "constlonglong"; }
  | CONST LONG { $$ = "constlong"; }
  | CONST SHORT { $$ = "constshort"; }
  | CONST CHAR { $$ = "constchar"; }
  | SIGNED LONGLONG { $$ = "signedlonglong"; }
  | SIGNED LONG { $$ = "signedlong"; }
  | SIGNED SHORT { $$ = "signedshort"; }
  | SIGNED CHAR { $$ = "signedchar"; }
  | UNSIGNED LONGLONG { $$ = "unsignedlonglong"; }
  | UNSIGNED LONG { $$ = "unsignedlong"; }
  | UNSIGNED SHORT { $$ = "unsignedshort"; }
  | UNSIGNED CHAR { $$ = "unsignedshar"; }
  | LONGLONG { $$ = "longlong"; }
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
  | '*' ID { char *str = strdup($1); strcat(str, $2); $$ = str; }
;

expr
  : expr '+' INT_NUM { $$ = $1 + $3; }
  | expr '-' INT_NUM { $$ = $1 - $3; }
  | INT_NUM { $$ = $1; }
;

exprs
  : expr
    {
      $$ = itoa($1);
    }
  | expr ',' exprs
    {
      char *str = strdup(itoa($1));
      strcat(str, $2);
      strcat(str, $3);
      $$ = str;
    }
;

scalar_decl
  : type idents
    {
      char *str = strdup($1);
      strcat(str, $2);
      $$ = str;
    }
;

idents
  : ident ',' idents {
      char* str = strdup($1);
      strcat(str, $2);
      strcat(str, $3);
      $$ = str; 
    }
  | ident '=' expr {
      char* str = strdup($1);
      strcat(str, $2);
      strcat(str, itoa($3));
      $$ = str;
    }
  | ident { $$ = $1;}
;

array_decl
  : type arrays
    {
      size_t n = strlen($1) + strlen($2);
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }  
;

arrays
  : array ',' arrays
    {
      size_t n = strlen($1) + strlen($2) + strlen($3);
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
      printf("\n\n%s\n\n", str);
    }
  | array
    {
      $$ = strdup($1);
    }
;

array
  : ident arr_dim
    {
      char *str = strdup($1);
      strcat(str, $2);
      $$ = str;
    }
  | ident arr_dim '=' arr_content
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4);
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
;

arr_dim
  : '[' expr ']'
    {
      char *str = strdup($1);
      strcat(str, itoa($2));
      strcat(str, $3);
      $$ = str;
    }
  | '[' expr ']' arr_dim
    {
      char *str = strdup($1);
      strcat(str, itoa($2)); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
;

arr_content
  : '{' exprs '}'
    {
      char *str = strdup($1);
      strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | '{' arr_content '}'
    {
      char *str = strdup($1);
      strcat(str, $2); strcat(str, $3); 
      $$ = str;
    }
  | arr_content ',' arr_content
    {
      size_t n = strlen($1) + strlen($2) + strlen($3);
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
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