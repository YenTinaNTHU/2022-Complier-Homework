%{

#include <stdio.h>
int num_lines = 0;
int src = 1, tok = 1;
int flag1 = 0;
char* input_line;
#include "y.tab.h"

%}
macros NULL|__COUNTER__|__LINE__|INT_MAX|INT_MIN|CHAR_MAX|CHAR_MIN|MAX|MIN
punc_chars ":"|";"|","|"."|"["|"]"|"("|")"|"{"|"}"
identifiers [a-zA-Z_][a-zA-Z0-9_]*
integers [+-]?[0-9]+
floats [+-]?[0-9]*\.[0-9]+|[+-]?[0-9]+\.[0-9]*

%x COMMENTS
%x COMMENT
%x STRING
%x STRING_ESCAPE
%x CHARACTOR
%x CHARACTOR_ESCAPE

%%

"/*" { BEGIN COMMENTS;}
<COMMENTS>"*/" { BEGIN 0;}
<COMMENTS>\n ;
<COMMENTS>. ;

"//" { BEGIN COMMENT; }
<COMMENT>\n {BEGIN 0;}
<COMMENT>. ;

\" { BEGIN STRING; }
<STRING>\" {BEGIN 0;}
<STRING>\\ { BEGIN STRING_ESCAPE;}
<STRING>\n ;
<STRING>.* {
    yylval.string_v = strdup(yytext);
    return STRING;
}
<STRING_ESCAPE>. {
    yylval.string_v = strdup(yytext);
    return ESCAPE;
    BEGIN STRING;
}

\' { BEGIN CHARACTOR;}
<CHARACTOR>\' { BEGIN 0;}
<CHARACTOR>\\ { BEGIN CHARACTOR_ESCAPE;}
<CHARACTOR>\n ;
<CHARACTOR>. {
    yylval.char_v = strdup(yytext)[0];
    return CHAR;
}
<CHARACTOR_ESCAPE>. {
    yylval.char_v = strdup(yytext)[0];
    return ESCAPE;
    BEGIN CHARACTOR;
}

"+"|"-"|"*"|"/"|"%"|"<"|">"|"="|"!"|"&"|"|" {
    yylval.string_v = strdup(yytext);
    char x = strdup(yytext)[0];
    return x;
}
"++" {yylval.string_v = strdup(yytext); return INC;}
"--" {yylval.string_v = strdup(yytext); return DEC;}
"<=" {yylval.string_v = strdup(yytext); return LEQ;}
">=" {yylval.string_v = strdup(yytext); return GEQ;}
"==" {yylval.string_v = strdup(yytext); return EQL;}
"!=" {yylval.string_v = strdup(yytext); return NEQ;}
"&&" {yylval.string_v = strdup(yytext); return LAND;}
"||" {yylval.string_v = strdup(yytext); return LOR;}


{floats} { yylval.float_v = atof(yytext); return FLOAT_NUM; }

{integers} { yylval.int_v = atoi(yytext); return INT_NUM; }

"for" { yylval.string_v = strdup(yytext); return FOR;}
"do" { yylval.string_v = strdup(yytext); return DO;}
"while" { yylval.string_v = strdup(yytext); return WHILE;}
"break" { yylval.string_v = strdup(yytext); return BREAK;}
"continue" { yylval.string_v = strdup(yytext); return CONTINUE;}
"if" { yylval.string_v = strdup(yytext); return IF;}
"else" { yylval.string_v = strdup(yytext); return ELSE;}
"return" { yylval.string_v = strdup(yytext); return RETURN;}
"struct" { yylval.string_v = strdup(yytext); return STRUCT;}
"switch" { yylval.string_v = strdup(yytext); return SWITCH;}
"case" { yylval.string_v = strdup(yytext); return CASE;}
"default" { yylval.string_v = strdup(yytext); return DEFAULT;}
"void" { yylval.string_v = strdup(yytext); return VOID;}
"int" { yylval.string_v = strdup(yytext); return INT;}
"double" { yylval.string_v = strdup(yytext); return DOUBLE;}
"float" { yylval.string_v = strdup(yytext); return FLOAT;}
"char" { yylval.string_v = strdup(yytext); return CHAR;}
"const" { yylval.string_v = strdup(yytext); return CONST;}
"signed" { yylval.string_v = strdup(yytext); return SIGNED;}
"unsigned" { yylval.string_v = strdup(yytext); return UNSIGNED;}
"short" { yylval.string_v = strdup(yytext); return SHORT;}
"long" { yylval.string_v = strdup(yytext); return LONG;}
"long long" { yylval.string_v = strdup(yytext); return LONGLONG;}

{macros} ;

{identifiers} { yylval.string_v = strdup(yytext); return ID; }

{punc_chars} {
    yylval.string_v = strdup(yytext); 
    char x = strdup(yytext)[0];
    return x;
}

[ ] ;

[ \t] ;

\n ;

%%
// keywords for|do|while|break|continue|if|else|return|struct|switch|case|default|void|int|double|float|char|const|signed|unsigned|short|long
// macros NULL|__COUNTER__|__LINE__|INT_MAX|INT_MIN|CHAR_MAX|CHAR_MIN|MAX|MIN
// operators "+"|"-"|"*"|"/"|"%"|"++"|"--"|"<"|"<="|">"|">="|"=="|"!="|"="|"&&"|"||"|"!"|"&"|"|"