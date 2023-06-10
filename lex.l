%{
    #include "stdio.h"
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
"+"                             {printf("+, %s, %d\n", yytext, count); }
"-"                             {printf("-, %s, %d\n", yytext, count); }
"*"                             {printf("*, %s, %d\n", yytext, count); }
"/"                             {printf("/, %s, %d\n", yytext, count); }
"<"                             {printf("<, %s, %d\n", yytext, count); }
"<="                            {printf("<=, %s, %d\n", yytext, count); }
">"                             {printf(">, %s, %d\n", yytext, count); }
">="                            {printf(">=, %s, %d\n", yytext, count); }
"=="                            {printf("==, %s, %d\n", yytext, count); }
"!="                            {printf("!=, %s, %d\n", yytext, count); }
"="                             {printf("=, %s, %d\n", yytext, count); }
";"                             {printf(";, %s, %d\n", yytext, count); }
","                             {printf(",, %s, %d\n", yytext, count); }
"("                             {printf("(, %s, %d\n", yytext, count); }
")"                             {printf("), %s, %d\n", yytext, count); }
"{"                             {printf("{, %s, %d\n", yytext, count); }
"}"                             {printf("}, %s, %d\n", yytext, count); }
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