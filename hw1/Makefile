scanner:scanner.l
	@flex scanner.l
	@gcc lex.yy.c -lfl -o scanner
	
clean:
	@rm -rf scanner lex.yy.c