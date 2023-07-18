run:
	flex lex.l
	bison -d parser.y
	gcc lex.yy.c parser.tab.c -o scanner
	.\scanner > saida.txt


win: 
	win_flex lex.l
	win_bison -d parser.y
	gcc lex.yy.c parser.tab.c -o scanner
	.\scanner > saida.txt

scan:
	.\scanner > saida.txt

scan_terminal:
	.\scanner