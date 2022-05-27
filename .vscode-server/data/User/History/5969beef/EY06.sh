clear
yacc -d parser.y
flex scanner.l
gcc y.tab.c lex.yy.c -lfl -o parser