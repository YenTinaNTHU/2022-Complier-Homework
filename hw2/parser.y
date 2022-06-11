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

char* init_str(char*str){
  int n = sizeof(str);
  for(int i=0; i<n; i++) str[i] = '\0';
  return str;
}

char* add_tag(char* tag, char* str){
  size_t n = strlen(tag) * 2 + strlen(str) + 5 + 1; // <> </> & \0
  char *tag_str = (char*) malloc(n*sizeof(char)); tag_str = init_str(tag_str);
  strcat(tag_str, "<"); strcat(tag_str, tag); strcat(tag_str, ">");
  strcat(tag_str, str);
  strcat(tag_str, "</"); strcat(tag_str, tag); strcat(tag_str, ">\0");
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
%type<string_v> scalar_decl type ident idents int_type char_type other_type
%type<string_v> array_decl arrays array arr_dim arr_content
%type<string_v> func_decl parameters func_def func
%type<string_v> expr exprs literal char string variable
%type<string_v> stmt for_stmt variable_decl compound_stmt stmt_or_decl stmt_or_decls switch_clause switch_clauses switch_clause_stmt

%token<int_v> INT_NUM POS_INT_NUM NEG_INT_NUM
%token<float_v> FLOAT_NUM POS_FLOAT_NUM NEG_FLOAT_NUM
%token<string_v> ID
%token<string_v> '=' '+' '-' '*' '/' '%' '<' '>' '!' '~' '&' '|' '^' INC DEC LEQ GEQ EQL NEQ LAND LOR
%token<string_v> ':' ';' ',' '.' '[' ']' '(' ')' '{' '}'
%token<string_v> CONST SIGNED UNSIGNED SHORT LONG LONGLONG INT CHAR CHAR4 CHAR8 DOUBLE VOID FLOAT STRUCT RETURN LSHIFT RSHIFT STR NUL
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
%right '!' '~'
%left INC DEC '(' ')'
%right ESCAPE_START STR
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
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
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
      $$ = strdup($1);
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
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
;

func_def
  :  func compound_stmt
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
;

func
  : type ident '(' parameters ')'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5);
      $$ = str;
    }
  | type '*' ident '(' parameters ')'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6);
      $$ = str;
    }
;

type
  : int_type { $$ = strdup($1); }
  | char_type { $$ = strdup($1); }
  | other_type { $$ = strdup($1); }
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
  | CONST SIGNED CHAR4 { $$ = "constsignedchar4"; }
  | CONST SIGNED CHAR8 { $$ = "constsignedchar8"; }
  | CONST UNSIGNED LONGLONG { $$ = "constunsignedlonglong"; }
  | CONST UNSIGNED LONG { $$ = "constunsignedlong"; }
  | CONST UNSIGNED SHORT { $$ = "constunsignedshort"; }
  | CONST UNSIGNED CHAR { $$ = "constunsignedchar"; }
  | CONST UNSIGNED CHAR4 { $$ = "constunsignedchar4"; }
  | CONST UNSIGNED CHAR8 { $$ = "constunsignedchar8"; }
  | CONST LONGLONG { $$ = "constlonglong"; }
  | CONST LONG { $$ = "constlong"; }
  | CONST SHORT { $$ = "constshort"; }
  | CONST CHAR { $$ = "constchar"; }
  | CONST CHAR4 { $$ = "constchar4"; }
  | CONST CHAR8 { $$ = "constchar8"; }
  | SIGNED LONGLONG { $$ = "signedlonglong"; }
  | SIGNED LONG { $$ = "signedlong"; }
  | SIGNED SHORT { $$ = "signedshort"; }
  | SIGNED CHAR { $$ = "signedchar"; }
  | SIGNED CHAR4 { $$ = "signedchar4"; }
  | SIGNED CHAR8 { $$ = "signedchar8"; }
  | UNSIGNED LONGLONG { $$ = "unsignedlonglong"; }
  | UNSIGNED LONG { $$ = "unsignedlong"; }
  | UNSIGNED SHORT { $$ = "unsignedshort"; }
  | UNSIGNED CHAR { $$ = "unsignedchar"; }
  | UNSIGNED CHAR4 { $$ = "unsignedchar4"; }
  | UNSIGNED CHAR8 { $$ = "unsignedchar8"; }
  | LONGLONG { $$ = "longlong"; }
  | LONG { $$ = "long"; }
  | SHORT { $$ = "short"; }
  | CHAR { $$ = "char"; }
  | CHAR4 { $$ = "char4"; }
  | CHAR8 { $$ = "char8"; }
;

other_type
  : CONST SIGNED { $$ = "constsigned"; }
  | CONST UNSIGNED { $$ = "constunsigned"; }
  | CONST FLOAT { $$ = "constfloat"; }
  | CONST DOUBLE { $$ = "constdouble"; }
  | CONST VOID { $$ = "constvoid"; }
  | SIGNED { $$ = "signed"; }
  | UNSIGNED { $$ = "unsigned"; }
  | FLOAT { $$ = "float"; }
  | DOUBLE { $$ = "double"; }
  | VOID { $$ = "void"; }
;

expr
	: expr '+' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
	| expr '-' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
	| expr '*' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
	| expr '/' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
	| expr '%' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr INC
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | expr DEC
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | INC expr
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | DEC expr
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | expr '<' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr LEQ expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr '>' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr GEQ expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr EQL expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr NEQ expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr '=' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr LAND expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr LOR expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | '!' expr
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | '~' expr
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | expr '^' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr '&' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr '|' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr LSHIFT expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | expr RSHIFT expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | '[' expr ']'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | '(' expr ')'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
  | '(' type ')' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = add_tag("expr", str);
    }
  | '(' type '*' ')' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5);
      $$ = add_tag("expr", str);
    }
  | '-' expr %prec UMINUS
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | '+' expr %prec UPLUS
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | '*' expr %prec DEREF
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
  | '&' expr %prec ADDR
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("expr", str);
    }
	| literal { $$ = add_tag("expr", $1); }
  | variable { $$ = add_tag("expr", $1); }
  | NUL {$$ = add_tag("expr", "0");}
  | expr '(' exprs ')'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = add_tag("expr", str);
    }
  | expr '(' ')'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = add_tag("expr", str);
    }
;

literal
  : INT_NUM { $$ = itoa($1); }
  | POS_INT_NUM
    {
      char* s1 = itoa($1);
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, "+"); strcat(str, add_tag("expr", s1));
      $$ = str;
    }
  | NEG_INT_NUM
    {
      char* s1 = itoa(-$1);
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, "-"); strcat(str, add_tag("expr", s1));
      $$ = str;
    }
  | FLOAT_NUM { $$ = ftoa($1); }
  | POS_FLOAT_NUM
    {
      char* s1 = ftoa($1);
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, "+"); strcat(str, add_tag("expr", s1));
      $$ = str;
    }
  | NEG_FLOAT_NUM
    {
      char* s1 = ftoa(-$1);
      size_t n = strlen(s1) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, "-"); strcat(str, add_tag("expr", s1));
      $$ = str;
    }
  | CHAR_START char CHAR_END
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | STRING_START string STRING_END
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

char
  : CHAR { $$ = strdup($1); }
  | CHAR4 { $$ = strdup($1); }
  | CHAR8 { $$ = strdup($1); }
  | ESCAPE_START ESCAPE_CHAR
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
  | { $$ = ""; }
;

string
  : STR string
    {
      $$ = strdup($1);
    }
  | string ESCAPE_START ESCAPE_CHAR STR
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
  | string ESCAPE_START ESCAPE_CHAR
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
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
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
;

exprs
  : expr
    {
      $$ = strdup($1);
    }
  | expr ',' exprs
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

scalar_decl
  : type idents ';'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

idents
  : idents ',' idents
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | ident { $$ = strdup($1);}
  | ident '=' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | '*' ident
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
  | '*' ident '=' expr
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
;

ident
  : ID { $$ = strdup($1);}
;


array_decl
  : type arrays ';'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);  strcat(str, $3);
      $$ = str;
    }  
;

arrays
  : array ',' arrays
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
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
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
  | ident arr_dim '=' '{' arr_content '}'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);  strcat(str, $5); strcat(str, $6);
      $$ = str;
    }
;

arr_dim
  : '[' expr ']'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | arr_dim '[' expr ']'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
;

arr_content
  : expr
    {
      size_t n = strlen($1) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1);
      $$ = str;
    }
  | '{' arr_content '}'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | arr_content ',' arr_content
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

parameters
  : type ident
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);;
      $$ = str;
    }
  | type '*' ident
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | parameters ',' parameters
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
  | {$$ = "";}
;


stmt
  : expr ';'
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = add_tag("stmt", str);
    }
  | IF '(' expr ')' compound_stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5);
      $$ = add_tag("stmt", str);
    }
  | IF '(' expr ')' compound_stmt ELSE compound_stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = add_tag("stmt", str);
    }
  | SWITCH '(' expr ')' '{' switch_clauses '}'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = add_tag("stmt", str);
    }
  | WHILE '(' expr ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5);
      $$ = add_tag("stmt", str);
    }
  | DO stmt WHILE '(' expr ')' ';'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
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
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
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
      $$ = add_tag("stmt", $1);
    }
;

switch_clauses
  : switch_clause switch_clauses
    {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
  | { $$ = ""; }
;

switch_clause
  : CASE expr ':' switch_clause_stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4);
      $$ = str;
    }
  | DEFAULT ':' switch_clause_stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

switch_clause_stmt
  : stmt {$$ = strdup($1);}
  | {$$ = "";}
;

for_stmt
  : FOR '(' exprs ';' exprs ';' exprs ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + strlen($8) + strlen($9) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7); strcat(str, $8); strcat(str, $9);
      $$ = str;
    }
  | FOR '(' exprs ';' exprs ';' ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + strlen($8) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7); strcat(str, $8);
      $$ = str;
    }
  | FOR '(' exprs ';'  ';' exprs ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + strlen($8) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7); strcat(str, $8);
      $$ = str;
    }
  | FOR '(' ';' exprs ';' exprs ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + strlen($8) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7); strcat(str, $8);
      $$ = str;
    }
  | FOR '(' ';'  ';' exprs ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = str;
    }
  | FOR '(' ';' exprs ';' ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = str;
    }
  | FOR '(' exprs ';' ';' ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + strlen($7) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6); strcat(str, $7);
      $$ = str;
    }
  | FOR '(' ';' ';' ')' stmt
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + strlen($4) + strlen($5) + strlen($6) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3); strcat(str, $4); strcat(str, $5); strcat(str, $6);
      $$ = str;
    }
;

compound_stmt
  : '{' '}' { $$ = "{}"; }
  | '{' stmt_or_decls '}'
    {
      size_t n = strlen($1) + strlen($2) + strlen($3) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
      strcat(str, $1); strcat(str, $2); strcat(str, $3);
      $$ = str;
    }
;

stmt_or_decls
  : stmt_or_decl stmt_or_decls
    {
      {
      size_t n = strlen($1) + strlen($2) + 1;
      char *str = (char*) malloc(n*sizeof(char)); str = init_str(str);
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