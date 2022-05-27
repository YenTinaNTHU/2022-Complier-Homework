%{

#include <stdio.h>
int num_lines = 0;
int src = 1, tok = 1;
int flag1 = 0;
char* input_line;
#include "y.tab.h"

%}
punc_chars ":"|";"|","|"."|"["|"]"|"("|")"|"{"|"}"
identifiers [a-zA-Z_][a-zA-Z0-9_]*
integers [+-]?[0-9]+
floats [+-]?[0-9]*\.[0-9]+|[+-]?[0-9]+\.[0-9]*

%x COMMENTS
%x COMMENT
%x STRING
%x STRING_ESCAPE
%x CHAR
%x CHAR_ESCAPE

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
    yylval.charVal = strdup(yytext);
    return ESCAPE;
    BEGIN STRING;
}

\' { BEGIN CHAR;}
<CHAR>\' { BEGIN 0;}
<CHAR>\\ { BEGIN CHAR_ESCAPE;}
<CHAR>\n ;
<CHAR>. {
    yylval.charVal = strdup(yytext);
    return CHAR;
}
<CHAR_ESCAPE>. {
    yylval.charVal = strdup(yytext);
    return ESCAPE;
    BEGIN CHAR;
}

"+"|"-"|"*"|"/"|"%"|"<"|">"|"="|"!"|"&"|"|" {
    char x = strdup(yytext);
    return x;
}
"++" {return INC;}
"--" {return DEC;}
"<=" {return LEQ;}
">=" {return GEQ;}
"==" {return EQL;}
"!=" {return NEQ;}
"&&" {return LAND;}
"||" {return LOR;}


{floats} {
    yylval.floatVal = atof(yytext);
    return FLOAT_NUM;
}

{integers} {
    yylval.intVal = atoi(yytext);
    return INT_NUM;
}

"for" {return FOR;}
"do" {return DO;}
"while" {return WHILE;}
"break" {return BREAK;}
"continue" {return CONTINUE;}
"if" {return IF;}
"else" {return ELSE;}
"return" {return RETURN;}
"struct" {return STRUCT;}
"switch" {return SWITCH;}
"case" {return CASE;}
"default" {return DEFAULT;}
"void" {return VOID;}
"int" {return INT;}
"double" {return DOUBLE;}
"float" {return FLOAT;}
"char" {return CHAR;}
"const" {return CONST;}
"signed" {return SIGNED;}
"unsigned" {return UNSIGNED;}
"short" {return SHORT;}
"long" {return LONG;}
"long long" {return LONG_LONG;}

{macros} ;

{identifiers} {
    yylval.stringVal = strdup(yytext);
    return ID;
}

{punc_chars} {
    char x = strdup(yytext);
    return x;
}

[ ] ;

[ \t] ;

\n ;

%%
// keywords for|do|while|break|continue|if|else|return|struct|switch|case|default|void|int|double|float|char|const|signed|unsigned|short|long
// macros NULL|__COUNTER__|__LINE__|INT_MAX|INT_MIN|CHAR_MAX|CHAR_MIN|MAX|MIN
// operators "+"|"-"|"*"|"/"|"%"|"++"|"--"|"<"|"<="|">"|">="|"=="|"!="|"="|"&&"|"||"|"!"|"&"|"|"