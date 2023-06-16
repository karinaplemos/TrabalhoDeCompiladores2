%{
    #include "stdio.h"
    #include "parser.tab.h"
    int count=1;
%}

letra[a-zA-Z]
digito[0-9]

%%

"int"                           {printf("int, %s, %d\n", yytext, count); }
"float"                         {printf("float, %s, %d\n", yytext, count); }
"char"                          {printf("char, %s, %d\n", yytext, count); }
"for"                           {printf("for, %s, %d\n", yytext, count); }
"while"                         {printf("while, %s, %d\n", yytext, count); }
"if"                            {printf("if, %s, %d\n", yytext, count); }
"else"                          {printf("else, %s, %d\n", yytext, count); }
['].[']                         {printf("character, %s, %d\n", yytext, count); }
{letra}({letra}|{digito})*      {printf("identifier, %s, %d\n", yytext, count); }
[-]?{digito}+                   {printf("number, %s, %d\n", yytext, count); }  
[-]?{digito}*\.{digito}+        {printf("floatNumber, %s, %d\n", yytext, count); }  
"+"                             {printf("plus, %s, %d\n", yytext, count); }
"-"                             {printf("minus, %s, %d\n", yytext, count); }
"*"                             {printf("asterisk, %s, %d\n", yytext, count); }
"/"                             {printf("slash, %s, %d\n", yytext, count); }
"<"                             {printf("lt, %s, %d\n", yytext, count); }
"<="                            {printf("lte, %s, %d\n", yytext, count); }
">"                             {printf("gt, %s, %d\n", yytext, count); }
">="                            {printf("gte, %s, %d\n", yytext, count); }
"=="                            {printf("eq, %s, %d\n", yytext, count); }
"!="                            {printf("neq, %s, %d\n", yytext, count); }
"="                             {printf("assign, %s, %d\n", yytext, count); }
";"                             {printf("semicolon, %s, %d\n", yytext, count); }
","                             {printf("comma, %s, %d\n", yytext, count); }
"("                             {printf("openparenthesis, %s, %d\n", yytext, count); }
")"                             {printf("closeparenthesis, %s, %d\n", yytext, count); }
"{"                             {printf("openbrackets, %s, %d\n", yytext, count); }
"}"                             {printf("closebrackets, %s, %d\n", yytext, count); }
\n                              {count++;}

%%


int yywrap()
{
}

int main(){
    yyin=fopen("entrada.txt", "r");
    yylex();
    return 0;
}