%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<ctype.h>

    #define YYDEBUG 1
    extern FILE *yyin;

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    typedef struct no{
        char *nome;
        int qtdFilhos; //Tamanho da lista de filhos
        struct no **filhos;
    } no;

    // Funções da arvore
    no* criaNo(char *nome);
    no* addFilhos(no *no_, no **novosFilhos, int qtdFilhos);
    void printArvore(no *arvore);
    no* criaArvoreIfGoto(char *tag, no* expr);

    // Variaveis da árvore
    no *raiz;
    no **filhos;

%}

%union { 
    struct token1{
        //char nome[20];
        struct no *no_;
    } tkn1;
    struct token2{
        char *valor;
        //int tipo;
    }tkn2;
    struct token3{
        float valor;
        //int tipo;
    }tkn3;
}



%token <tkn1> INT FLOAT CHAR FOR WHILE IF ELSE ASSIGN EQ LT GT GTE LTE NEQ PLUS MINUS ASTERISK SLASH SEMICOLON COMMA OPENPARENTHESIS CLOSEPARENTHESIS OPENBRACKETS CLOSEBRACKETS 
%token <tkn2> NUMBER FLOATNUMBER CHARACTER IDENTIFIER
%type  <tkn1> FunctionList Function Type ArgList Arg ArgListLinha Declaration IdentList Stmt ForStmt WhileStmt IfStmt CompoundStmt OptExpr Expr ElsePart StmtList StmtListLinha Rvalue Compare Mag Term Factor

// Precedencia para resolver o conflito de shift/reduce do else
%precedence NOELSE
%precedence ELSE

%%

Program: FunctionList{raiz = criaNo("Program"); 
                      filhos = malloc(sizeof(no *));
                      filhos[0] = $1.no_; 
                      raiz = addFilhos(raiz,filhos, 1);
                      free(filhos);
                    }
; 

FunctionList:  
            Function FunctionList {$$.no_ = criaNo("FunctionList");
                                   filhos = malloc(2 * sizeof(no *));
                                   filhos[0] = $1.no_; 
                                   filhos[1] = $2.no_;
                                   addFilhos($$.no_,filhos,2);
                                   free(filhos);
                                   } 
|           Function {$$.no_ = criaNo("FunctionList");
                                   filhos = malloc(sizeof(no *));
                                   filhos[0] = $1.no_; 
                                   addFilhos($$.no_,filhos,1);
                                   free(filhos);
                                   } 
;

Function: Type IDENTIFIER OPENPARENTHESIS ArgList CLOSEPARENTHESIS CompoundStmt {$$.no_ = criaNo("Function");
                                                                                 filhos = malloc(6 * sizeof(no *));
                                                                                 filhos[0] = $1.no_; 
                                                                                 filhos[1] = criaNo($2.valor);
                                                                                 filhos[2] = criaNo("(");
                                                                                 filhos[3] = $4.no_;
                                                                                 filhos[4] = criaNo(")");
                                                                                 filhos[5] = $6.no_;
                                                                                 addFilhos($$.no_,filhos,6);
                                                                                 free(filhos);                                                                                
                                                                                }
;

ArgList: Arg ArgListLinha{$$.no_ = criaNo("ArgList");
                          filhos = malloc(2 * sizeof(no *));
                          filhos[0] = $1.no_; 
                          filhos[1] = $2.no_;
                          addFilhos($$.no_,filhos,2);
                          free(filhos);    
}                    
;

ArgListLinha: COMMA Arg ArgListLinha {$$.no_ = criaNo("ArgListLinha");
                                      filhos = malloc(3 * sizeof(no *));
                                      filhos[0] = $1.no_; 
                                      filhos[1] = criaNo(",");
                                      filhos[2] = $3.no_;
                                      addFilhos($$.no_,filhos,3);
                                      free(filhos);
                                    }
|  {$$.no_ = criaNo("ArgListLinha");
    filhos = malloc(1 * sizeof(no *));
    filhos[0] = criaNo("ε"); 
    addFilhos($$.no_,filhos,1);
    free(filhos);
    }            
;

Arg: Type IDENTIFIER {$$.no_ = criaNo("Arg");
                      filhos = malloc(2 * sizeof(no *));
                      filhos[0] = $1.no_;
                      filhos[1] = criaNo($2.valor); 
                      addFilhos($$.no_,filhos,2);
                      free(filhos);
                    }
;   

Declaration: Type IdentList SEMICOLON{$$.no_ = criaNo("Declaration");
                                      filhos = malloc(3 * sizeof(no *));
                                      filhos[0] = $1.no_; 
                                      filhos[1] = $2.no_;
                                      filhos[2] = criaNo(";"); 
                                      addFilhos($$.no_,filhos,3);
                                      free(filhos);
                                    }
;

Type:   INT {$$.no_ = criaNo("Type");
               filhos = malloc(1 * sizeof(no *));
               filhos[0] = criaNo("int"); 
               addFilhos($$.no_,filhos,1);
               free(filhos);
            }          
|       
    FLOAT {$$.no_ = criaNo("Type");
               filhos = malloc(1 * sizeof(no *));
               filhos[0] = criaNo("float"); 
               addFilhos($$.no_,filhos,1);
               free(filhos);
          }                                     
|                   
    CHAR  {$$.no_ = criaNo("Type");
               filhos = malloc(1 * sizeof(no *));
               filhos[0] =  criaNo("char"); 
               addFilhos($$.no_,filhos,1);
               free(filhos);
          } 
;

IdentList: IDENTIFIER COMMA IdentList {$$.no_ = criaNo("IdentList");
                                       filhos = malloc(3 * sizeof(no *));
                                       filhos[0] = criaNo($1.valor); 
                                       filhos[1] = criaNo(","); 
                                       filhos[2] = $3.no_; 
                                       addFilhos($$.no_,filhos,3);
                                       free(filhos);
                                    }
|         
    IDENTIFIER {$$.no_ = criaNo("IdentList");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = criaNo($1.valor); 
                addFilhos($$.no_,filhos,1);
                free(filhos);
            }
;

Stmt:   ForStmt {$$.no_ = criaNo("Stmt");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = $1.no_; 
                 addFilhos($$.no_,filhos,1);
                 free(filhos);   
            }                                   
|      
        WhileStmt {$$.no_ = criaNo("Stmt");
                  filhos = malloc(1 * sizeof(no *));
                  filhos[0] = $1.no_; 
                  addFilhos($$.no_,filhos,1);
                  free(filhos);
            }                                    
|       
        Expr SEMICOLON {$$.no_ = criaNo("Stmt");
                  filhos = malloc(2 * sizeof(no *));
                  filhos[0] = $1.no_; 
                  filhos[1] = criaNo(";"); 
                  addFilhos($$.no_,filhos,2);
                  free(filhos);    
            }                                   
|       
        IfStmt {$$.no_ = criaNo("Stmt");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = $1.no_; 
                addFilhos($$.no_,filhos,1);
                free(filhos);
            }                                        
|       
        CompoundStmt {$$.no_ = criaNo("Stmt");
                     filhos = malloc(1 * sizeof(no *));
                     filhos[0] = $1.no_; 
                     addFilhos($$.no_,filhos,1);
                     free(filhos);
                }                                 
|       
        Declaration {$$.no_ = criaNo("Stmt");
                     filhos = malloc(1 * sizeof(no *));
                     filhos[0] = $1.no_; 
                     addFilhos($$.no_,filhos,1);
                     free(filhos);
                }                                   
|       
        SEMICOLON {$$.no_ = criaNo("Stmt");
                   filhos = malloc(1 * sizeof(no *));
                   filhos[0] = criaNo(";"); 
                   addFilhos($$.no_,filhos,1);
                   free(filhos);
                }
;        

ForStmt: FOR OPENPARENTHESIS Expr SEMICOLON OptExpr SEMICOLON OptExpr CLOSEPARENTHESIS Stmt {$$.no_ = criaNo("ForStmt");
                                                                                            filhos = malloc(9 * sizeof(no *));
                                                                                            filhos[0] = criaNo("for"); 
                                                                                            filhos[1] = criaNo("(");
                                                                                            filhos[2] = $3.no_; 
                                                                                            filhos[3] = criaNo(";");
                                                                                            filhos[4] = $5.no_; 
                                                                                            filhos[5] = criaNo(";");
                                                                                            filhos[6] = $7.no_; 
                                                                                            filhos[7] = criaNo(")");
                                                                                            filhos[8] = $9.no_; 
                                                                                            addFilhos($$.no_,filhos,9);
                                                                                            free(filhos);
                                                                                        }
; 

OptExpr:    Expr {$$.no_ = criaNo("OptExpr");
                   filhos = malloc(1 * sizeof(no *));
                   filhos[0] = $1.no_; 
                   addFilhos($$.no_,filhos,1);
                   free(filhos);
            }                                     
|   {$$.no_ = criaNo("OptExpr");
     filhos = malloc(1 * sizeof(no *));
     filhos[0] = criaNo("ε"); 
     addFilhos($$.no_,filhos,1);
     free(filhos);
     }               
;

WhileStmt: WHILE OPENPARENTHESIS Expr CLOSEPARENTHESIS Stmt {$$.no_ = criaNo("WhileStmt");
                                                             filhos = malloc(3 * sizeof(no *));
                                                             filhos[0] = criaNo("GotoTagX"); //Precisa generalizar a Tag
                                                             filhos[1] = $5.no_; 
                                                             filhos[2] = criaArvoreIfGoto("GotoTagX", $3.no_);
                                                             addFilhos($$.no_,filhos,3);
                                                             free(filhos);
                                                            }

;

IfStmt: IF OPENPARENTHESIS Expr CLOSEPARENTHESIS Stmt ElsePart {$$.no_ = criaNo("IfStmt");
                                                             filhos = malloc(6 * sizeof(no *));
                                                             filhos[0] = criaNo("if");
                                                             filhos[1] = criaNo("(");
                                                             filhos[2] = $3.no_; 
                                                             filhos[3] = criaNo(")");
                                                             filhos[4] = $5.no_; 
                                                             filhos[5] = $6.no_; 
                                                             addFilhos($$.no_,filhos,6);
                                                             free(filhos);
                                                        }
;


ElsePart:    ELSE Stmt {$$.no_ = criaNo("ElsePart");
                        filhos = malloc(2 * sizeof(no *));
                        filhos[0] = criaNo("else");
                        filhos[1] = $2.no_; 
                        addFilhos($$.no_,filhos,2);
                        free(filhos);
                    }                                
|            %prec NOELSE {$$.no_ = criaNo("ElsePart");
                           filhos = malloc(1 * sizeof(no *));
                           filhos[0] = criaNo("ε"); 
                           addFilhos($$.no_,filhos,1);
                           free(filhos);
                           }    
;

CompoundStmt: OPENBRACKETS StmtList CLOSEBRACKETS { $$.no_ = criaNo("CompoundStmt");
                                                    filhos = malloc(3 * sizeof(no *));
                                                    filhos[0] = criaNo("{");
                                                    filhos[1] = $2.no_;
                                                    filhos[2] = criaNo("}");
                                                    addFilhos($$.no_,filhos,3);
                                                    free(filhos);
}

;  

StmtList:   Stmt StmtListLinha {$$.no_ = criaNo("StmtList");
                                filhos = malloc(2 * sizeof(no *));
                                filhos[0] = $1.no_; 
                                filhos[1] = $2.no_;
                                addFilhos($$.no_,filhos,2);
                                free(filhos);
                            }                       
|  {$$.no_ = criaNo("StmtList");
    filhos = malloc(1 * sizeof(no *));
    filhos[0] = criaNo("ε"); 
    addFilhos($$.no_,filhos,1);
    free(filhos);
    }                
;

StmtListLinha:  Stmt StmtListLinha {$$.no_ = criaNo("StmtListLinha");
                                    filhos = malloc(2 * sizeof(no *));
                                    filhos[0] = $1.no_; 
                                    filhos[1] = $2.no_;
                                    addFilhos($$.no_,filhos,2);
                                    free(filhos);
                                }                    
|  {$$.no_ = criaNo("StmtListLinha");
    filhos = malloc(1 * sizeof(no *));
    filhos[0] = criaNo("ε"); 
    addFilhos($$.no_,filhos,1);
    free(filhos);
    }                   
;

Expr: IDENTIFIER ASSIGN Expr {$$.no_ = criaNo("Expr");
                                    filhos = malloc(3 * sizeof(no *));
                                    filhos[0] = criaNo($1.valor);
                                    filhos[1] = criaNo("=");
                                    filhos[2] = $3.no_;
                                    addFilhos($$.no_,filhos,3);
                                    free(filhos);
                            }                     
| 
    Rvalue {$$.no_ = criaNo("Expr");
          filhos = malloc(1 * sizeof(no *));
          filhos[0] = $1.no_;
          addFilhos($$.no_,filhos,1);
          free(filhos);
        }
;

Rvalue: Rvalue Compare Mag {$$.no_ = criaNo("Rvalue");
                            filhos = malloc(3 * sizeof(no *));
                            filhos[0] = $1.no_;
                            filhos[1] = $2.no_;
                            filhos[2] = $3.no_;
                            addFilhos($$.no_,filhos,3);
                            free(filhos);
                        }
| 
        Mag {$$.no_ = criaNo("Rvalue");
            filhos = malloc(1 * sizeof(no *));
            filhos[0] = $1.no_;
            addFilhos($$.no_,filhos,1);
            free(filhos);
        }
;  


Compare:    EQ {$$.no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo("==");
                 addFilhos($$.no_,filhos,1);
                 free(filhos);
            }                                        
|           
            LT {$$.no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo("<");
                 addFilhos($$.no_,filhos,1);
                 free(filhos);
            }                                        
|           
            GT {$$.no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo(">");
                 addFilhos($$.no_,filhos,1);
                 free(filhos);
            }                                          
|           
            LTE {$$.no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo("<=");
                 addFilhos($$.no_,filhos,1);
                 free(filhos);
            }                                         
|           
            GTE {$$.no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo(">=");
                 addFilhos($$.no_,filhos,1);
                 free(filhos);
            }                                          
|           
            NEQ {$$.no_ = criaNo("Compare");
                 filhos = malloc(1 * sizeof(no *));
                 filhos[0] = criaNo("!=");
                 addFilhos($$.no_,filhos,1);
                 free(filhos);
            }
;  

Mag:    Mag PLUS Term {$$.no_ = criaNo("Mag");
                       filhos = malloc(3 * sizeof(no *));
                       filhos[0] = $1.no_;
                       filhos[1] = criaNo("+");
                       filhos[2] = $3.no_;
                       addFilhos($$.no_,filhos,3);
                       free(filhos);
                    }
|       
        Mag MINUS Term {$$.no_ = criaNo("Mag");
                        filhos = malloc(3 * sizeof(no *));
                        filhos[0] = $1.no_;
                        filhos[1] = criaNo("-");
                        filhos[2] = $3.no_;
                        addFilhos($$.no_,filhos,3);
                        free(filhos);
                    }
|       
        Term {$$.no_ = criaNo("Mag");
              filhos = malloc(1 * sizeof(no *));
              filhos[0] = $1.no_;
              addFilhos($$.no_,filhos,1);
              free(filhos);
            }
;

Term:   Term ASTERISK Factor {$$.no_ = criaNo("Term");
                              filhos = malloc(3 * sizeof(no *));
                              filhos[0] = $1.no_;
                              filhos[1] = criaNo("*");
                              filhos[2] = $3.no_;
                              addFilhos($$.no_,filhos,3);
                              free(filhos);
                            }
|       
        Term SLASH Factor {$$.no_ = criaNo("Term");
                           filhos = malloc(3 * sizeof(no *));
                           filhos[0] = $1.no_;
                           filhos[1] = criaNo("/");
                           filhos[2] = $3.no_;
                           addFilhos($$.no_,filhos,3);
                           free(filhos);
                        }
|       
        Factor {$$.no_ = criaNo("Term");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = $1.no_;
                addFilhos($$.no_,filhos,1);
                free(filhos);
            } 
; 

Factor: OPENPARENTHESIS Expr CLOSEPARENTHESIS  {$$.no_ = criaNo("Factor");
                                                filhos = malloc(3 * sizeof(no *));
                                                filhos[0] = criaNo("(");
                                                filhos[1] = $2.no_;
                                                filhos[2] = criaNo(")");
                                                addFilhos($$.no_,filhos,3);
                                                free(filhos);
                                            }                                  
|       
        MINUS Factor {$$.no_ = criaNo("Factor");
                      filhos = malloc(2 * sizeof(no *));
                      filhos[0] = criaNo("-");
                      filhos[1] = $2.no_;
                      addFilhos($$.no_,filhos,2);
                      free(filhos);
                }                                     
|       
        PLUS Factor {$$.no_ = criaNo("Factor");
                     filhos = malloc(2 * sizeof(no *));
                     filhos[0] = criaNo("+");
                     filhos[1] = $2.no_;
                     addFilhos($$.no_,filhos,2);
                     free(filhos);
                }                                     
|       
        IDENTIFIER {$$.no_ = criaNo("Factor");
                    filhos = malloc(1 * sizeof(no *));
                    filhos[0] = criaNo($1.valor);
                    addFilhos($$.no_,filhos,1);
                    free(filhos);
                }                                   
|       
        NUMBER {$$.no_ = criaNo("Factor");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = criaNo($1.valor);
                addFilhos($$.no_,filhos,1);
                free(filhos);}
|       
        FLOATNUMBER {$$.no_ = criaNo("Factor");
                     filhos = malloc(1 * sizeof(no *));
                     filhos[0] = criaNo($1.valor);
                     addFilhos($$.no_,filhos,1);
                     free(filhos);
                }
|       
        CHARACTER  {$$.no_ = criaNo("Factor");
                    filhos = malloc(1 * sizeof(no *));
                    filhos[0] = criaNo($1.valor);
                    addFilhos($$.no_,filhos,1);
                    free(filhos);
                }     
;

%%

int main(){ 
    //yydebug = 1;

    yyin = fopen("entrada.txt", "r");

    do
    {
        yyparse();
    }while (!feof(yyin)); 

    printf("\nÁrvore: \n");
    printArvore(raiz);
    return 0;
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

no* criaNo(char *nome){
    no *novoNo;
    novoNo = malloc(sizeof(no));
    novoNo->nome = nome; 
    novoNo->filhos = malloc(sizeof(no)); //Adiciona uma lista vazia
    novoNo->qtdFilhos = 0;

    return novoNo;
} 

no* addFilhos(no *no_, no **novosFilhos, int qtdFilhos){
    int j = no_->qtdFilhos; //Variável para salvar a quantidade original de filhos 
    no_->qtdFilhos += qtdFilhos;
    no_->filhos = realloc(no_->filhos, (no_->qtdFilhos ) * sizeof(no));

    for(int i=0; i<qtdFilhos; i++, j++ ){
        no_->filhos[j] = novosFilhos[i];
    }

    return no_;
}

void printArvore_(no *arvore, int cont){
    char *nivel=malloc((cont)*sizeof(char));
    memset(nivel,'|',cont);
    printf("%.*s %s \n",cont,nivel,arvore->nome);
    free(nivel);

    for(int i=0; i < arvore->qtdFilhos; i++){
        printArvore_(arvore->filhos[i], cont+1);
    }
}

void printArvore(no *arvore){
    printArvore_(arvore, 1);
}

no* criaArvoreIfGoto(char *tag, no* expr){
    no* arvore = criaNo("IfStmt");
    no **tempFilhos = malloc(5 * sizeof(no *));

    tempFilhos[0] = criaNo("if");
    tempFilhos[1] = criaNo("(");
    tempFilhos[2] = expr;
    tempFilhos[3] = criaNo(")");

    char *gotoStr = malloc(50);
    strcpy(gotoStr, "Goto ");
    strcat(gotoStr, tag);
    tempFilhos[4] = criaNo(gotoStr);
    // Eu removi direto a parte do else, verificar se da algum problema

    addFilhos(arvore,tempFilhos,5);
    free(tempFilhos);

    return arvore;
}