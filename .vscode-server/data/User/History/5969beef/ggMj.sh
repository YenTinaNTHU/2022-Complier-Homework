clear
yacc -d parser.y
flex scanner.l
gcc -o parser lex.yy.c y.tab.c -lfl

yacc -v parser.y