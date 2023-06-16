# TrabalhoDeCompiladores2

##Como rodar o lex:
#flex lex.l
#bison -d parser.y
#gcc lex.yy.c parser.tab.c -o scanner
#.\scanner > saida.txt
