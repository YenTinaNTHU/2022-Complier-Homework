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
%}

%union {
  int int_v;
  float float_v;
  char char_v;
  char* string_v;  
}

%start program

%type<string_v> program
%type<string_v> expr statement factor char string escape

%token<int_v> INT_NUM
%token<float_v> FLOAT_NUM
%token<string_v> ID
%token<string_v> '=' '+' '-' '*' '/' '%' '<' '>' '!' '&' '|' INC DEC LEQ GEQ EQL NEQ LAND LOR
%token<string_v> ':' ';' ',' '.' '[' ']' '(' ')' '{' '}'
%token<string_v> CONST SIGNED UNSIGNED SHORT LONG LONGLONG INT CHAR DOUBLE VOID FLOAT STRUCT RETURN LSHIFT RSHIFT STR
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
%left EQL
%left '>' '<' LEQ GEQ
%left LSHIFT RSHIFT
%left '+' '-'
%left '*' '/' '%'
%right INC DEC '!' '~'
%nonassoc UMINUS UPLUS

%% 


program
	: statement {printf("%s", $1);}
;

statement
	: expr ';'
	| statement expr ';'
;

expr
	: expr '+' expr
	| expr '-' expr
	| expr '*' expr
	| expr '/' expr
	| expr '%' expr
	| factor
;

factor
  : INT_NUM { $$ = itoa($1); }
  | FLOAT_NUM { $$ = ftoa($1); }
  | CHAR_START char CHAR_END
    {
      size_t n = strlen($1) + 2;
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, "\'"); strcat(str, $1); strcat(str, $3);
      $$ = str;
    }
  | STRING_START string STRING_END
;

char
  : CHAR { $$ = $1; }
  | ESCAPE_START escape
    {
      size_t n = strlen($1) + strlen($2);
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
  | { $$ = ""; }
;

string
  : STR { $$ = $1; }
  | string escape string
    {
      size_t n = strlen($1) + strlen($2);
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
      $$ = str;
    }
  | { $$ = ""; }
;

escape
  : ESCAPE_START ESCAPE_CHAR
    {
      size_t n = strlen($1) + strlen($2);
      char *str = (char*) malloc(n*sizeof(char));
      strcat(str, $1); strcat(str, $2);
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
//  + - * / % ++ -- < <= > >= == != = && || ! ~ ^ & | >> << [ ] ( )