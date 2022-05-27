clear
yacc -d expr.y
flex scanner.l
gcc -o expr_parser lex.yy.c y.tab.c -lfl
yacc -v expr.y
./expr_parser < ./basic_testcase/expr_input.txt > ans.txt