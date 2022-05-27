%{

#include <stdio.h>
int num_lines = 0;
int src = 1, tok = 1;
int flag1 = 0;
char* input_line;

%}

keywords for|do|while|break|continue|if|else|return|struct|switch|case|default|void|int|double|float|char|const|signed|unsigned|short|long
macros NULL|__COUNTER__|__LINE__|INT_MAX|INT_MIN|CHAR_MAX|CHAR_MIN|MAX|MIN
identifiers [a-zA-Z_][a-zA-Z0-9_]*
operators "+"|"-"|"*"|"/"|"%"|"++"|"--"|"<"|"<="|">"|">="|"=="|"!="|"="|"&&"|"||"|"!"|"&"|"|"
punc_chars ":"|";"|","|"."|"["|"]"|"("|")"|"{"|"}"
integers [+-]?[0-9]*
floats [+-]?[0-9]*\.[0-9]*

pragma_src_on (#pragma)[ \t]*(source)[ \t]*(on)
pragma_src_off (#pragma)[ \t]*(source)[ \t]*(off)
pragma_tok_on (#pragma)[ \t]*(token)[ \t]*(on)
pragma_tok_off (#pragma)[ \t]*(token)[ \t]*(off)

%x COMMENTS
%x COMMENT
%x STRING
%x CHAR

%%

.*\n {
    if(!flag1){
        flag1 = 1;
        input_line = yytext;
    }
    REJECT;
}

{pragma_src_on} {
    src = 1;
}
{pragma_src_off} {
    src = 0;
}
{pragma_tok_on} {
    tok = 1;
}
{pragma_tok_off} {
    tok = 0;
}

"/*" {
    BEGIN COMMENTS;
}

<COMMENTS>"*/" {
    BEGIN 0;
}

<COMMENTS>. ;
<COMMENTS>\n {
    num_lines++;
    if(src) printf("%d", num_lines);
    ECHO;
    flag1 = 0;
};

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

<STRING>. {
    if(tok) ECHO;
}
<STRING>\n {
    if(tok) ECHO;
}

\' {
    if(tok) printf("#char:\'");
    BEGIN CHAR;
}

<CHAR>.\' {
    if(tok) {
        ECHO;
        printf("\n");
    }
    BEGIN 0;
}

{operators} {
    if(tok){
        printf("#op:"); ECHO;
        printf("\n");
    } 
}

{floats} {
    if(tok){
        printf("#float:"); ECHO;
        printf("\n");
    } 
}

{integers} {
    if(tok){
        printf("#integer:"); ECHO;
        printf("\n");
    }   
}

{keywords} {
    if(tok){
        printf("#key:");
        ECHO;
        printf("\n");
    }
}

{macros} {
    if(tok){
        printf("#macro:");ECHO;
        printf("\n");
    }
}

{identifiers} {
    if(tok){
        printf("#id:"); ECHO;
        printf("\n");
    }

}

{punc_chars} {
    if(tok){
        printf("#punc:"); ECHO;
        printf("\n");
    }
}

[ ] ;

\n {
    num_lines++;

    if(src) printf("%d:%s", num_lines, input_line);
    flag1 = 0;
}



%%

int main(int argc, char* argv[])
{
    yylex();
    // printf("num of line = %d\n", num_lines);
    return 0;
}