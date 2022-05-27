clear
yacc -d expr.y
flex scanner.l
gcc -o parser lex.yy.c y.tab.c -lfl
yacc -v expr.y
./parser < ./basic_testcase/expr_input.txt > ans.txt