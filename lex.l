%{
    #include "stdio.h"
    #include "stdlib.h"
    #include "parser.tab.h"
    int LINHA=1;
%}

letra[a-zA-Z]
digito[0-9]

%%

"int"                           {return INT;}
"float"                         {return FLOAT;}
"char"                          {return CHAR;}
"for"                           {return FOR;}
"while"                         {return WHILE;}
"if"                            {return IF;}
"else"                          {return ELSE;}
['].[']                         {yylval.tkn2.valor = (char *) strdup(yytext); return CHARACTER;}
{letra}({letra}|{digito})*      {yylval.tkn2.valor = (char *) strdup(yytext); return IDENTIFIER;}
[-]?{digito}+                   {yylval.tkn2.valor = (char *) strdup(yytext); return NUMBER;}
[-]?{digito}*\.{digito}+        {yylval.tkn2.valor = (char *) strdup(yytext); return FLOATNUMBER;}  
"+"                             {return PLUS;}
"-"                             {return MINUS;}
"*"                             {return ASTERISK;}
"/"                             {return SLASH;}
"<"                             {return LT;}
"<="                            {return LTE;}
">"                             {return GT;}
">="                            {return GTE;}
"=="                            {return EQ;}
"!="                            {return NEQ;}
"="                             {return ASSIGN;}
";"                             {return SEMICOLON;}
","                             {return COMMA;}
"("                             {return OPENPARENTHESIS;}
")"                             {return CLOSEPARENTHESIS;}
"{"                             {return OPENBRACKETS;}
"}"                             {return CLOSEBRACKETS;}
\n                              {LINHA++;}

%%

int yywrap(){
    
}

// int main(){
//     yyin=fopen("entrada.txt", "r");
//     yylex();
//     return 0;
// }