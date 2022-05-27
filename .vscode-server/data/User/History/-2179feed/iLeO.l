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
    yylval.stringVal = strdup(yytext);
    return STRING;
}
<STRING_ESCAPE>. {
    yylval.stringVal = strdup(yytext);
    return ESCAPE;
    BEGIN STRING;
}

\' { BEGIN CHARACTOR;}
<CHARACTOR>\' { BEGIN 0;}
<CHARACTOR>\\ { BEGIN CHARACTOR_ESCAPE;}
<CHARACTOR>\n ;
<CHARACTOR>. {
    yylval.charVal = strdup(yytext)[0];
    return CHAR;
}
<CHARACTOR_ESCAPE>. {
    yylval.charVal = strdup(yytext)[0];
    return ESCAPE;
    BEGIN CHARACTOR;
}

"+"|"-"|"*"|"/"|"%"|"<"|">"|"="|"!"|"&"|"|" {
    yylval.stringVal = strdup(yytext);
    char x = strdup(yytext)[0];
    return x;
}
"++" {yylval.stringVal = strdup(yytext); return INC;}
"--" {yylval.stringVal = strdup(yytext); return DEC;}
"<=" {yylval.stringVal = strdup(yytext); return LEQ;}
">=" {yylval.stringVal = strdup(yytext); return GEQ;}
"==" {yylval.stringVal = strdup(yytext); return EQL;}
"!=" {yylval.stringVal = strdup(yytext); return NEQ;}
"&&" {yylval.stringVal = strdup(yytext); return LAND;}
"||" {yylval.stringVal = strdup(yytext); return LOR;}


{floats} { yylval.floatVal = strdup(yytext); return FLOAT_NUM; }

{integers} { yylval.intVal = strdup(yytext); return INT_NUM; }

"for" { yylval.stringVal = strdup(yytext); return FOR;}
"do" { yylval.stringVal = strdup(yytext); return DO;}
"while" { yylval.stringVal = strdup(yytext); return WHILE;}
"break" { yylval.stringVal = strdup(yytext); return BREAK;}
"continue" { yylval.stringVal = strdup(yytext); return CONTINUE;}
"if" { yylval.stringVal = strdup(yytext); return IF;}
"else" { yylval.stringVal = strdup(yytext); return ELSE;}
"return" { yylval.stringVal = strdup(yytext); return RETURN;}
"struct" { yylval.stringVal = strdup(yytext); return STRUCT;}
"switch" { yylval.stringVal = strdup(yytext); return SWITCH;}
"case" { yylval.stringVal = strdup(yytext); return CASE;}
"default" { yylval.stringVal = strdup(yytext); return DEFAULT;}
"void" { yylval.stringVal = strdup(yytext); return VOID;}
"int" { yylval.stringVal = strdup(yytext); return INT;}
"double" { yylval.stringVal = strdup(yytext); return DOUBLE;}
"float" { yylval.stringVal = strdup(yytext); return FLOAT;}
"char" { yylval.stringVal = strdup(yytext); return CHAR;}
"const" { yylval.stringVal = strdup(yytext); return CONST;}
"signed" { yylval.stringVal = strdup(yytext); return SIGNED;}
"unsigned" { yylval.stringVal = strdup(yytext); return UNSIGNED;}
"short" { yylval.stringVal = strdup(yytext); return SHORT;}
"long" { yylval.stringVal = strdup(yytext); return LONG;}
"long long" { yylval.stringVal = strdup(yytext); return LONG_LONG;}

{macros} ;

{identifiers} { yylval.stringVal = strdup(yytext); return ID; }

{punc_chars} {
    yylval.stringVal = strdup(yytext); 
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