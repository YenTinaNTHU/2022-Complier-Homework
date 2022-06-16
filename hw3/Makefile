parser:parser.y
	@yacc -d parser.y
	@flex scanner.l
	@gcc -o parser lex.yy.c y.tab.c -lfl
	
clean:
	@rm -rf parser lex.yy.c