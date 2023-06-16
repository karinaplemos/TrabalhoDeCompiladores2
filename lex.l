%{
    #include "stdio.h"
    #include "parser.tab.h"
    int count=1;
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
['].[']                         {return CHARACTER;}
{letra}({letra}|{digito})*      {return IDENTIFIER;}
[-]?{digito}+                   {return NUMBER;} // usar função atoi para retornar o valor em formato de número
[-]?{digito}*\.{digito}+        {return FLOATNUMBER;}  
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
\n                              {count++;}

%%

int yywrap(){
    
}

int main(){
    yyin=fopen("entrada.txt", "r");
    yylex();
    return 0;
}