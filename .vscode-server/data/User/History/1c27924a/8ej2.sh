clear
yacc -d expr.y
flex scanner.l
gcc -o parser lex.yy.c y.tab.c -lfl
yacc -v parser.y
./parser < ./basic_testcase/input.txt > ans.txt