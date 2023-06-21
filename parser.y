%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<ctype.h>
    extern FILE *yyin;

    void yyerror(const char *s);
    int yylex();
    int yywrap();
%}

%token INT FLOAT CHAR NUMBER FLOATNUMBER CHARACTER IDENTIFIER FOR WHILE IF ELSE ASSIGN EQ LT GT GTE LTE NEQ PLUS MINUS ASTERISK SLASH SEMICOLON COMMA OPENPARENTHESIS CLOSEPARENTHESIS OPENBRACKETS CLOSEBRACKETS 

// Precedencia para resolver o conflito de shift/reduce do else
%precedence NOELSE
%precedence ELSE

%%

Program: FunctionList; 

FunctionList:  
            Function FunctionList 
|           Function 
;

Function: Type IDENTIFIER OPENPARENTHESIS ArgList CLOSEPARENTHESIS CompoundStmt;

ArgList: Arg ArgListLinha;

ArgListLinha: COMMA Arg ArgListLinha
|             
;

Arg: Type IDENTIFIER;   

Declaration: Type IdentList SEMICOLON;

Type:   INT             
|       FLOAT                                         
|       CHAR
;

IdentList: IDENTIFIER COMMA IdentList 
|          IDENTIFIER 
;

Stmt:   ForStmt                                        
|       WhileStmt                                      
|       Expr SEMICOLON                                        
|       IfStmt                                         
|       CompoundStmt                                   
|       Declaration                                    
|       SEMICOLON
;        

ForStmt: FOR OPENPARENTHESIS Expr SEMICOLON OptExpr SEMICOLON OptExpr CLOSEPARENTHESIS Stmt ; 

OptExpr:    Expr                                       
|              
;

WhileStmt: WHILE OPENPARENTHESIS Expr CLOSEPARENTHESIS Stmt;

IfStmt: IF OPENPARENTHESIS Expr CLOSEPARENTHESIS Stmt ElsePart


ElsePart:    ELSE Stmt                                 
|            %prec NOELSE
;

CompoundStmt: OPENBRACKETS StmtList CLOSEBRACKETS ;  

StmtList:   Stmt StmtListLinha                         
|               
;

StmtListLinha:  Stmt StmtListLinha                    
|                 
;

Expr: IDENTIFIER ASSIGN Expr                             
| Rvalue
;

Rvalue: Rvalue Compare Mag
| Mag ;  


Compare:    EQ                                         
|           LT                                           
|           GT                                           
|           LTE                                          
|           GTE                                          
|           NEQ 
;  

Mag:    Mag PLUS Term
|       Mag MINUS Term
|       Term
;

Term:   Term ASTERISK Factor 
|       Term SLASH Factor
|       Factor
; 

Factor: OPENPARENTHESIS Expr CLOSEPARENTHESIS                                    
|       MINUS Factor                                     
|       PLUS Factor                                     
|       IDENTIFIER                                   
|       NUMBER
|       FLOATNUMBER
|       CHARACTER       
;

%%

int main(){ 
    yyin=fopen("entrada.txt", "r");
    yyparse();
    return 0;
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}