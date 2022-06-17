parser:parser.y
	@yacc -d -v parser.y
	@flex scanner.l
	@gcc -o parser lex.yy.c y.tab.c code.c -lfl
	
clean:
	@rm -rf parser lex.yy.c y.tab.c y.tab.h