%{

#include <stdio.h>
int num_lines = 0;
int src = 1, tok = 1;
int flag1 = 0;
char* input_line;
#include "y.tab.h"

%}

keywords for|do|while|break|continue|if|else|return|struct|switch|case|default|void|int|double|float|char|const|signed|unsigned|short|long
macros NULL|__COUNTER__|__LINE__|INT_MAX|INT_MIN|CHAR_MAX|CHAR_MIN|MAX|MIN
identifiers [a-zA-Z_][a-zA-Z0-9_]*
operators "+"|"-"|"*"|"/"|"%"|"++"|"--"|"<"|"<="|">"|">="|"=="|"!="|"="|"&&"|"||"|"!"|"&"|"|"
integers [+-]?[0-9]+
floats [+-]?[0-9]*\.[0-9]+|[+-]?[0-9]+\.[0-9]*

%x COMMENTS
%x COMMENT
%x STRING
%x STRING_ESCAPE
%x CHAR
%x CHAR_ESCAPE

%%

"/*" {
    BEGIN COMMENTS;
}

<COMMENTS>"*/" {
    BEGIN 0;
}
<COMMENTS>. ;
<COMMENTS>.*\n {
    if(!flag1){
        flag1 = 1;
        input_line = yytext;
    }
    REJECT;
}
<COMMENTS>\n {
    num_lines++;
    if(src) printf("%d:%s", num_lines, input_line);
    flag1 = 0;
}

"//" {
    BEGIN COMMENT;
}
<COMMENT>. ;
<COMMENT>\n {
    num_lines++;
    if(src) printf("%d:%s", num_lines, input_line);
    flag1 = 0;
    BEGIN 0;
}

\" {
    if(tok) printf("#string:\"");
    BEGIN STRING;
}
<STRING>\" {
    if(tok) printf("\"\n");
    BEGIN 0;
}
<STRING>\\ {
    if(tok) ECHO;
    BEGIN STRING_ESCAPE;
}
<STRING>. if(tok) ECHO;
<STRING>\n if(tok) ECHO;
<STRING_ESCAPE>. {
    if(tok) ECHO;
    BEGIN STRING;
}

\' {
    if(tok) printf("#char:\'");
    BEGIN CHAR;
}
<CHAR>\' {
    if(tok) printf("\'\n");
    BEGIN 0;
}
<CHAR>\\ {
    if(tok) ECHO;
    BEGIN CHAR_ESCAPE;
}
<CHAR>. if(tok) ECHO;
<CHAR>\n if(tok) ECHO;
<CHAR_ESCAPE>. {
    if(tok) ECHO;
    BEGIN CHAR;
}

{operators} {
    if(tok){
        printf("#op:"); ECHO;
        printf("\n");
    } 
}

{floats} {
    yylval.floatVal = atof(yytext);
    return FLOAT_NUM;
}

{integers} {
    yylval.intVal = atoi(yytext);
    return INT_NUM;
}

{keywords} {
    if(tok){
        printf("#key:");
        ECHO;
        printf("\n");
    }
}
"for" {return ;}
"do" {return ;}
"while" {return ;}
"break" {return ;}
"continue" {return ;}
"if" {return ;}
"else" {return ;}
"return" {return ;}
"struct" {return ;}
"switch" {return ;}
"case" {return ;}
"default" {return ;}
"void" {return VOID;}
"int" {return INT;}
"double" {return DOUBLE;}
"float" {return ;}
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

":" {return ':';}
";" {return ':';}
"," {return ':';}
"." {return ':';}
"[" {return ':';}
"]" {return ':';}
"(" {return ':';}
")" {return ':';}
"{" {return ':';}
"}" {return ':';}

[ ] ;

[ \t] ;

\n ;

%%