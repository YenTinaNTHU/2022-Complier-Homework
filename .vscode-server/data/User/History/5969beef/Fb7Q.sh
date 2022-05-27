clear
yacc -d parser.y
flex scanner.l
gcc lex.yy.c y.tab.c -lfl