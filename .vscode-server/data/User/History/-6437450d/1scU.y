%{
    /* C declaration */
    #include <stdio.h> // header files.
    // Other variables you want to define.

    /* Yacc declaration */
    %token<intVal> ID NUM
%}

%%

expression:
    expression '+' NUM {
        $$ = $1 + $3;
    }
    | expression '-' NUM {
        $$ = $1 - $3;
    }
    | NUM {
        $$ = $1;
    };

%%

int main(void) {
    yyparse(); return 0;
}
int yyerror(char *s) {
    fprintf(stderr, "%s\n", s); return 0;
}