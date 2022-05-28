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

char* ftoa(double x) {
    char* s = malloc(sizeof(char) * 30);
    sprintf(s, "%f", x);
    return s;
}

char* add_tag(char* tag, char* str){
  size_t n = strlen(tag) * 2 + strlen(str) + 5 + 1;
  char *tag_str = (char*) malloc(n*sizeof(char));
  strcat(tag_str, "<"); strcat(tag_str, tag); strcat(tag_str, ">");
  strcat(tag_str, str);
  strcat(tag_str, "</"); strcat(tag_str, tag); strcat(tag_str, ">");
  return tag_str;
}
%}

%start program

%union {
  int int_v;
  float float_v;
  char char_v;
  char* string_v;  
}

%type<string_v> program program_ingredient program_ingredients
%type<string_v> global_variable_decl
%type<string_v> scalar_decl type ident idents init_ident int_type char_type other_type
%type<string_v> array_decl arrays array arr_dim arr_content exprs
%type<string_v> func_decl parameters func_def func
%type<string_v> expr literal char string variable
%type<string_v> stmt for_stmt variable_decl compound_stmt stmt_or_decl stmt_or_decls switch_clause switch_clauses

%token<int_v> INT_NUM POS_INT_NUM NEG_INT_NUM
%token<float_v> FLOAT_NUM POS_FLOAT_NUM NEG_FLOAT_NUM
%token<string_v> ID
%token<string_v> '=' '+' '-' '*' '/' '%' '<' '>' '!' '~' '&' '|' '^' INC DEC LEQ GEQ EQL NEQ LAND LOR
%token<string_v> ':' ';' ',' '.' '[' ']' '(' ')' '{' '}'
%token<string_v> CONST SIGNED UNSIGNED SHORT LONG LONGLONG INT CHAR DOUBLE VOID FLOAT STRUCT RETURN LSHIFT RSHIFT STR NUL
%token<string_v> FOR DO WHILE BREAK CONTINUE
%token<string_v> IF ELSE SWITCH CASE DEFAULT
%token<string_v> CHAR_START CHAR_END ESCAPE_START ESCAPE_CHAR STRING_START STRING_END

%left ';'
%left ','
%right '='
%right ':'
%left LOR
%left LAND
%left '|'
%left '^'
%left '&'
%left EQL NEQ
%left '>' '<' LEQ GEQ
%left LSHIFT RSHIFT
%left '+' '-'
%left '*' '/' '%'
%right INC DEC '!' '~'
%right ESCAPE_START
%nonassoc UMINUS UPLUS DEREF ADDR


%% 
program
  : program_ingredients
    {
      printf("%s", $1);
    }
;

program_ingredients
  : program_ingredients program_ingredient
    {
      size_t n = strlen($1) + strlen($2);
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
  | program_ingredient
    {
      $$ = $1;
    }
;

program_ingredient
  : global_variable_decl
    {
      $$ = $1;
    }
  | func_decl
    {
      char* tag_str = add_tag("func_decl", $1);
      $$ = tag_str;
    }
  | func_def
    {
      char* tag_str = add_tag("func_def", $1);
      $$ = tag_str;
    }
;

global_variable_decl
  : scalar_decl
    {
      char* tag_str = add_tag("scalar_decl", $1);
      $$ = tag_str;
      // printf("\n\n%s\n\n", $$);
    }
  | array_decl
    {
      char* tag_str = add_tag("array_decl", $1);
      $$ = tag_str;
    }
;

func_decl
  : func ';'
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
;

func_def
  :  func '{' stmt '}'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
;

func
  : type ident '(' parameters ')'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4)  + strlen($5) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5);
      $$ = str;
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
;

init_ident
  : ID '=' exprs {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;
expr
	: expr '+' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
	| expr '-' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
	| expr '*' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
	| expr '/' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
	| expr '%' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr INC
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | expr DEC
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | INC expr
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | DEC expr
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | expr '<' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr LEQ expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr '>' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr GEQ expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr EQL expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr NEQ expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr '=' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr LAND expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr LOR expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | '!' expr
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | '~' expr
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | expr '^' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr '&' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr '|' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr LSHIFT expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr RSHIFT expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | '[' expr ']'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | '(' expr ')'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | '-' expr %prec UMINUS
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | '+' expr %prec UPLUS
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | '*' expr %prec DEREF
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | '&' expr %prec ADDR
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
	| literal { $$ = add_tag("expr", $1); }
  | variable { $$ = add_tag("expr", $1); }
  | NUL {$$ = add_tag("expr", "0");}
;

literal
  : INT_NUM { $$ = itoa($1); }
  | POS_INT_NUM
    {
      char* s1 = itoa($1);
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "+"); strcat(str, add_tag("expr", s1));
      $$ = str;
    }
  | NEG_INT_NUM
    {
      char* s1 = itoa(-$1);
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "-"); strcat(str, add_tag("expr", s1));
      $$ = str;
    }
  | FLOAT_NUM { $$ = ftoa($1); }
  | POS_FLOAT_NUM
    {
      char* s1 = ftoa($1);
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "+"); strcat(str, add_tag("expr", s1));
      $$ = str;
    }
  | NEG_FLOAT_NUM
    {
      char* s1 = ftoa(-$1);
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "-"); strcat(str, add_tag("expr", s1));
      $$ = str;
    }
  | CHAR_START char CHAR_END
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | STRING_START string STRING_END
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

char
  : CHAR
    {
      $$ = strdup($1);
    }
  | ESCAPE_START ESCAPE_CHAR
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
  | { $$ = ""; }
;

string
  : STR
    {
      $$ = strdup($1);
    }
  | STR ESCAPE_START ESCAPE_CHAR STR
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
  | { $$ = ""; }
;

variable
  : ident
    {
      $$ = strdup($1);
    }
  | ident arr_dim
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
;

exprs
  : expr
    {
      $$ = strdup($1);
    }
  | exprs ',' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

scalar_decl
  : type idents ';'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | type '*' idents ';'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

idents
  : idents ',' ident {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
  }
  | idents ',' init_ident {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
  }
  | ident { $$ = strdup($1);}
  | init_ident { $$ = strdup($1);}
;

array_decl
  : type arrays ';'
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }  
;

arrays
  : array ',' arrays
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | array
    {
      $$ = strdup($1);
    }
;

array
  : ident arr_dim
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
  | ident arr_dim '=' arr_content
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
;

arr_dim
  : '[' expr ']'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | arr_dim '[' expr ']'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
;

arr_content
  : '{' exprs '}'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | '{' arr_content '}'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | arr_content ',' arr_content
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

parameters
  : type ident
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);;
      $$ = str;
    }
  | type '*' ident
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | parameters ',' parameters
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | {$$ = "";}
;


stmt
  : expr ';'
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("stmt", str);
    }
  | IF '(' expr ')' compound_stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5);
      $$ = add_tag("stmt", str);
    }
  | IF '(' expr ')' compound_stmt ELSE compound_stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = add_tag("stmt", str);
    }
  | SWITCH '(' expr ')' '{' switch_clauses '}'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = add_tag("stmt", str);
    }
  | WHILE '(' expr ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5);
      $$ = add_tag("stmt", str);
    }
  | DO stmt WHILE '(' expr ')' ';'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = add_tag("stmt", str);
    }
  | for_stmt
    {
      $$ = add_tag("stmt", $1);
    }
  | RETURN expr ';'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("stmt", str);
    }
  | RETURN ';'
    {
      $$ = add_tag("stmt", "return;");
    }
  | BREAK ';'
    {
      $$ = add_tag("stmt", "break;");
    }
  | CONTINUE ';'
    {
      $$ = add_tag("stmt", "continue;");
    }
  | compound_stmt
    {
      $$ = $1;
    }
;

switch_clauses
  : switch_clause switch_clauses
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
  | { $$ = ""; }
;

switch_clause
  : CASE expr ':' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
  | DEFAULT ':' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

for_stmt
  : FOR '(' exprs ';' exprs ';' exprs ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + strlen($8) + strlen($9) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7); strcat(str, $8); strcat(str, $9);
      $$ = str;
    }
  | FOR '(' exprs ';' exprs ';' ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + strlen($8) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7); strcat(str, $8);
      $$ = str;
    }
  | FOR '(' exprs ';'  ';' exprs ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + strlen($8) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7); strcat(str, $8);
      $$ = str;
    }
  | FOR '(' ';' exprs ';' exprs ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + strlen($8) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7); strcat(str, $8);
      $$ = str;
    }
  | FOR '(' ';'  ';' exprs ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = str;
    }
  | FOR '(' ';' exprs ';' ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = str;
    }
  | FOR '(' exprs ';' ';' ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = str;
    }
  | FOR '(' ';' ';' ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6);
      $$ = str;
    }
;

compound_stmt
  : '{' '}' { $$ = "{}"; }
  | '{' stmt_or_decls '}'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

stmt_or_decls
  : stmt_or_decl stmt_or_decls
    {
      {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
    }
  | stmt_or_decl { $$ = $1; }
;

stmt_or_decl
  : stmt { $$ = $1; }
  | variable_decl { $$ = $1; }
;

variable_decl
  : scalar_decl
    {
      char* tag_str = add_tag("scalar_decl", $1);
      $$ = tag_str;
    }
  | array_decl
    {
      char* tag_str = add_tag("array_decl", $1);
      $$ = tag_str;
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