%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<ctype.h>
    #include "tabela_simbolos.h"

    #define YYDEBUG 1
    extern FILE *yyin;
    extern int LINHA;

    int qtdFuncoes = 0;

    int valInt = 1;
    int valFloat = 2;
    int valChar = 3;


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
    no* criaArvoreIfGotoWhile(char *tag, no* expr);
    no* criaArvoreIfGotoFor(char *tag, no* expr, no* optExpr);

    void geraLabel();

    //Funções de erro semântico
    void identificador_ja_declarado(char *identificador, int linha);
    void identificador_nao_declarado(char *identificador, int linha);

    // Variaveis da árvore
    no *raiz;
    no **filhos;

    int checa_declaracao_id(char *identificador){
        simbolo_na_tabela *simb;
        simb = get_simbolo_da_tabela(identificador);
        if(simb == 0)
            simb = put_simbolo_na_tabela(identificador);
        else{
            identificador_ja_declarado(identificador, LINHA);
        }
        return 0;
    }   

    int adiciona_tipo_para_declaracao_id(char *identificador, int tipo){
        simbolo_na_tabela *simb;
        simb = get_simbolo_da_tabela(identificador);
        if(simb == 0){
            simb = put_simbolo_na_tabela(identificador);
        }
        simb->tipo = tipo;  

        return 0;
    }

    int adiciona_tipo_identilist(no *no_, int tipo ){
        // Adiciona o tipo no primeiro elemento
        adiciona_tipo_para_declaracao_id(no_->filhos[0]->nome, tipo);

        // Se não for raiz, entra em recursão
        if(no_->qtdFilhos == 3){
            adiciona_tipo_identilist(no_->filhos[2], tipo );
        }

        return 0;
    }

    int checa_contexto_id(char *identificador){
        simbolo_na_tabela *simb;
        simb = get_simbolo_da_tabela(identificador);
        if(simb == 0){
            identificador_nao_declarado(identificador, LINHA);
        }
        return 0;
    }

    char* val_para_tipo(int tipo){
        if(tipo == valInt){
            return "int";
        }else if(tipo == valFloat){
            return "float";
        }else if(tipo == valChar){
            return "char";
        }

        return "erro";
    }

    int checa_tipos(int tipo1, int tipo2){

        if(tipo1 == 0 || tipo2 == 0 ){
            //Algum erro já teria sido notificado anteriormente
            return 0;
        }
        if((tipo1 == valChar && tipo2 != valChar) || (tipo1 != valChar && tipo2 == valChar)){
            // foi encontrado o erro
            char *msg_erro = malloc(50);
            sprintf(msg_erro, "Linha %d: operacao invalida entre os tipos \"%s\" e \"%s\"\n",LINHA, val_para_tipo(tipo1),val_para_tipo(tipo2));
            yyerror(msg_erro);
            free(msg_erro);
            return 0;
            
        }else{
            // não possui erro e um dos tipos é retornado
            return tipo1;
        }

        return 0;
    }

    void identificador_ja_declarado(char *identificador, int linha){    
        char *msg_erro = malloc(50);
        sprintf(msg_erro, "Linha %d: Identificador %s ja declarado anteriormente\n", linha, identificador);
        yyerror(msg_erro);
        free(msg_erro);
    }

    void identificador_nao_declarado(char *identificador, int linha){    
        char *msg_erro = malloc(50);
        sprintf(msg_erro, "Linha %d: Identicador %s nao declarado anteriormente\n", linha, identificador);
        yyerror(msg_erro);
        free(msg_erro);
    }

    //Variavel GOTO
    int labelCont = 0;
    char *label;

%}

%union { 
    struct token1{
        struct no *no_;
    } tkn1;
    struct token2{
        char *valor;
    }tkn2;
    struct token3{
        struct no *no_;
        int tipo;
    }tkn3;
}



%token <tkn1> INT FLOAT CHAR FOR WHILE IF ELSE ASSIGN EQ LT GT GTE LTE NEQ PLUS MINUS ASTERISK SLASH SEMICOLON COMMA OPENPARENTHESIS CLOSEPARENTHESIS OPENBRACKETS CLOSEBRACKETS 
%token <tkn2> NUMBER FLOATNUMBER CHARACTER IDENTIFIER
%type  <tkn1> FunctionList Function ArgList Arg ArgListLinha Declaration IdentList IdentListLinha Stmt ForStmt WhileStmt IfStmt CompoundStmt OptExpr ElsePart StmtList StmtListLinha Rvalue Compare 
%type  <tkn3> Type Mag Term Factor Expr

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

                                                                                checa_declaracao_id($2.valor);
                                                                                adiciona_tipo_para_declaracao_id($2.valor, $1.tipo);    

                                                                                qtdFuncoes++;
                                                                                reseta_tabela(qtdFuncoes);                   
                                                                                }
;

ArgList: Arg ArgListLinha{$$.no_ = criaNo("ArgList");
                          filhos = malloc(2 * sizeof(no *));
                          filhos[0] = $1.no_; 
                          filhos[1] = $2.no_;
                          addFilhos($$.no_,filhos,2);
                          free(filhos);    
                        }             
| {$$.no_ = criaNo("ArgList");
    filhos = malloc(1 * sizeof(no *));
    filhos[0] = criaNo("ε"); 
    addFilhos($$.no_,filhos,1);
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

                      checa_declaracao_id($2.valor);
                      adiciona_tipo_para_declaracao_id($2.valor, $1.tipo);
                      
                    }
;   

Declaration: Type IdentList SEMICOLON{$$.no_ = criaNo("Declaration");
                                      filhos = malloc(3 * sizeof(no *));
                                      filhos[0] = $1.no_; 
                                      filhos[1] = $2.no_;
                                      filhos[2] = criaNo(";"); 
                                      addFilhos($$.no_,filhos,3);
                                      free(filhos);

                                      adiciona_tipo_identilist($2.no_, $1.tipo);

                                    }
;

Type:   INT {$$.no_ = criaNo("Type");
               filhos = malloc(1 * sizeof(no *));
               filhos[0] = criaNo("int"); 
               addFilhos($$.no_,filhos,1);
               free(filhos);

               // Tipo int possui valor 1
               $$.tipo = valInt;
            }          
|       
    FLOAT {$$.no_ = criaNo("Type");
               filhos = malloc(1 * sizeof(no *));
               filhos[0] = criaNo("float"); 
               addFilhos($$.no_,filhos,1);
               free(filhos);

               // Tipo float possui valor 2
               $$.tipo = valFloat;
          }                                     
|                   
    CHAR  {$$.no_ = criaNo("Type");
               filhos = malloc(1 * sizeof(no *));
               filhos[0] =  criaNo("char"); 
               addFilhos($$.no_,filhos,1);
               free(filhos);

               // Tipo char possui valor 3
               $$.tipo = valChar;
          } 
;

IdentList: IDENTIFIER COMMA IdentList {$$.no_ = criaNo("IdentList");
                                       filhos = malloc(3 * sizeof(no *));
                                       filhos[0] = criaNo($1.valor); 
                                       filhos[1] = criaNo(","); 
                                       filhos[2] = $3.no_; 
                                       addFilhos($$.no_,filhos,3);
                                       free(filhos);

                                       checa_declaracao_id($1.valor);
                                    }
|         
    IDENTIFIER {$$.no_ = criaNo("IdentList");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = criaNo($1.valor); 
                addFilhos($$.no_,filhos,1);
                free(filhos);

                checa_declaracao_id($1.valor);
            }
;

IdentListLinha: IDENTIFIER COMMA IdentListLinha {$$.no_ = criaNo("IdentListLinha");
                                       filhos = malloc(3 * sizeof(no *));
                                       filhos[0] = criaNo($1.valor); 
                                       filhos[1] = criaNo(","); 
                                       filhos[2] = $3.no_; 
                                       addFilhos($$.no_,filhos,3);
                                       free(filhos);

                                       checa_contexto_id($1.valor);
                                       //checa_declaracao_id($1.valor);
                                    }
|         
    IDENTIFIER {$$.no_ = criaNo("IdentListLinha");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = criaNo($1.valor); 
                addFilhos($$.no_,filhos,1);
                free(filhos);

                checa_contexto_id($1.valor);
            }
|   {$$.no_ = criaNo("IdentListLinha");
    filhos = malloc(1 * sizeof(no *));
    filhos[0] = criaNo("ε"); 
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
                                                                                            geraLabel();
                                                                                            filhos = malloc(4 * sizeof(no *));
                                                                                            filhos[0] = $3.no_; 
                                                                                            filhos[1] = criaNo(label);
                                                                                            filhos[2] = $9.no_; 
                                                                                            filhos[3] = criaArvoreIfGotoFor(label, $5.no_, $7.no_);
                                                                                            addFilhos($$.no_,filhos, 4);
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
                                                             geraLabel();
                                                             filhos = malloc(3 * sizeof(no *));
                                                             filhos[0] = criaNo(label); //Precisa generalizar a Tag
                                                             filhos[1] = $5.no_; 
                                                             filhos[2] = criaArvoreIfGotoWhile(label, $3.no_);
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

                                    checa_contexto_id($1.valor);

                                    simbolo_na_tabela *identificador;
                                    identificador = get_simbolo_da_tabela($1.valor);
                                    if(identificador == 0){
                                        $$.tipo = 0;
                                    }else{
                                        $$.tipo = identificador->tipo;
                                    }
                            }                     
| 
    Rvalue {$$.no_ = criaNo("Expr");
          filhos = malloc(1 * sizeof(no *));
          filhos[0] = $1.no_;
          addFilhos($$.no_,filhos,1);
          free(filhos);

          // boleanos serao tratados como inteiros, como em C
          $$.tipo = valInt;
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

                       $$.tipo = checa_tipos($1.tipo, $3.tipo);
                    }
|       
        Mag MINUS Term {$$.no_ = criaNo("Mag");
                        filhos = malloc(3 * sizeof(no *));
                        filhos[0] = $1.no_;
                        filhos[1] = criaNo("-");
                        filhos[2] = $3.no_;
                        addFilhos($$.no_,filhos,3);
                        free(filhos);

                        $$.tipo = checa_tipos($1.tipo, $3.tipo);
                    }
|       
        Term {$$.no_ = criaNo("Mag");
              filhos = malloc(1 * sizeof(no *));
              filhos[0] = $1.no_;
              addFilhos($$.no_,filhos,1);
              free(filhos);

              $$.tipo = $1.tipo;
            }
;

Term:   Term ASTERISK Factor {$$.no_ = criaNo("Term");
                              filhos = malloc(3 * sizeof(no *));
                              filhos[0] = $1.no_;
                              filhos[1] = criaNo("*");
                              filhos[2] = $3.no_;
                              addFilhos($$.no_,filhos,3);
                              free(filhos);

                              $$.tipo = checa_tipos($1.tipo, $3.tipo);
                            }
|       
        Term SLASH Factor {$$.no_ = criaNo("Term");
                           filhos = malloc(3 * sizeof(no *));
                           filhos[0] = $1.no_;
                           filhos[1] = criaNo("/");
                           filhos[2] = $3.no_;
                           addFilhos($$.no_,filhos,3);
                           free(filhos);

                           $$.tipo = checa_tipos($1.tipo, $3.tipo);
                        }
|       
        Factor {$$.no_ = criaNo("Term");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = $1.no_;
                addFilhos($$.no_,filhos,1);
                free(filhos);

                $$.tipo = $1.tipo;
            } 
; 

Factor: OPENPARENTHESIS Expr CLOSEPARENTHESIS  {$$.no_ = criaNo("Factor");
                                                filhos = malloc(3 * sizeof(no *));
                                                filhos[0] = criaNo("(");
                                                filhos[1] = $2.no_;
                                                filhos[2] = criaNo(")");
                                                addFilhos($$.no_,filhos,3);
                                                free(filhos);

                                                $$.tipo = $2.tipo;
                                            }                                  
|       
        MINUS Factor {$$.no_ = criaNo("Factor");
                      filhos = malloc(2 * sizeof(no *));
                      filhos[0] = criaNo("-");
                      filhos[1] = $2.no_;
                      addFilhos($$.no_,filhos,2);
                      free(filhos);

                      $$.tipo = $2.tipo;
                }                                     
|       
        PLUS Factor {$$.no_ = criaNo("Factor");
                     filhos = malloc(2 * sizeof(no *));
                     filhos[0] = criaNo("+");
                     filhos[1] = $2.no_;
                     addFilhos($$.no_,filhos,2);
                     free(filhos);

                     $$.tipo = $2.tipo;
                }                                     
|       
        IDENTIFIER {$$.no_ = criaNo("Factor");
                    filhos = malloc(1 * sizeof(no *));
                    filhos[0] = criaNo($1.valor);
                    addFilhos($$.no_,filhos,1);
                    free(filhos);

                    simbolo_na_tabela *identificador;
                    identificador = get_simbolo_da_tabela($1.valor);
                    if(identificador == 0){
                        $$.tipo = 0;
                    }else{
                        $$.tipo = identificador->tipo;
                    }

                    checa_contexto_id($1.valor);
                    
                }                                   
|       
        NUMBER {$$.no_ = criaNo("Factor");
                filhos = malloc(1 * sizeof(no *));
                filhos[0] = criaNo($1.valor);
                addFilhos($$.no_,filhos,1);
                free(filhos);
                
                $$.tipo = valInt;
                }

                
|       
        FLOATNUMBER {$$.no_ = criaNo("Factor");
                     filhos = malloc(1 * sizeof(no *));
                     filhos[0] = criaNo($1.valor);
                     addFilhos($$.no_,filhos,1);
                     free(filhos);

                     $$.tipo = valInt;
                }
|       
        CHARACTER  {$$.no_ = criaNo("Factor");
                    filhos = malloc(1 * sizeof(no *));
                    filhos[0] = criaNo($1.valor);
                    addFilhos($$.no_,filhos,1);
                    free(filhos);

                    $$.tipo = valChar;
                } 
|   
        IDENTIFIER OPENPARENTHESIS IdentListLinha CLOSEPARENTHESIS  {$$.no_ = criaNo("Factor");
                                                                filhos = malloc(4 * sizeof(no *));
                                                                filhos[0] = criaNo($1.valor);
                                                                filhos[0] = criaNo("(");
                                                                filhos[1] = $3.no_;
                                                                filhos[2] = criaNo(")");
                                                                addFilhos($$.no_,filhos,4);
                                                                free(filhos);

                                                                checa_contexto_id($1.valor); 

                                                                simbolo_na_tabela *identificador;
                                                                identificador = get_simbolo_da_tabela($1.valor);
                                                                if(identificador == 0){
                                                                    $$.tipo = 0;
                                                                }else{
                                                                    $$.tipo = identificador->tipo;
                                                                }

                                                                
                                                            }  
;

%%

int main(){ 
    //yydebug = 1;
    yyin = fopen("Exemplos/entrada_sem_erros.txt", "r");
    //yyin = fopen("Exemplos/entrada_com_erro_lexico.txt", "r");
    //yyin = fopen("Exemplos/entrada_com_erro_sintatico.txt", "r");
    //yyin = fopen("Exemplos/entrada_com_erro_semantico.txt", "r");

    do
    {
        yyparse();
    }while (!feof(yyin)); 

    /*printf("\nTabela de símbolos:\n");
    print_tabela();*/

    printf("Arvore: \n");
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

no* criaArvoreIfGotoWhile(char *tag, no* expr){
    no* arvore = criaNo("IfStmt");
    no **tempFilhos = malloc(5 * sizeof(no *));
    no *tempNo;

    char *gotoStr = malloc(50);
    strcpy(gotoStr, "Goto ");
    strcat(gotoStr, tag);
    tempFilhos[0] = criaNo(gotoStr);

    tempNo = criaNo("Stmt");
    tempFilhos[4] = addFilhos(tempNo,tempFilhos, 1);// Stmt vai para a última posição da lista

    tempFilhos[0] = criaNo("if");
    tempFilhos[1] = criaNo("(");
    tempFilhos[2] = expr;
    tempFilhos[3] = criaNo(")");
    // Eu removi direto a parte do else, verificar se da algum problema

    addFilhos(arvore,tempFilhos,5);
    free(tempFilhos);

    return arvore;
}

no* criaArvoreIfGotoFor(char *tag, no* expr, no* optExpr){
    no* arvore = criaNo("IfStmt");
    no* tempNo;
    no **tempFilhos = malloc(5 * sizeof(no *));


    // As árvores são criadas de baixo para cima para usar a mesma lista
    char *gotoStr = malloc(50);
    strcpy(gotoStr, "Goto ");
    strcat(gotoStr, tag);
    tempFilhos[0] = criaNo(gotoStr);

    tempNo = criaNo("Stmt");
    tempFilhos[0] = addFilhos(tempNo,tempFilhos, 1); //Nó Stmt vai para o início da lista

    tempNo = criaNo("StmtListLinha");
    tempFilhos[1] = addFilhos(tempNo,tempFilhos, 1); // StmtListLinha vai para a segunda posicao para liberar a primeira para outro nó Stmt

    tempNo = criaNo("Stmt");
    tempFilhos[0] = optExpr;
    tempFilhos[0] = addFilhos(tempNo,tempFilhos, 1);

    tempNo = criaNo("StmtList");
    tempFilhos[1] = addFilhos(tempNo,tempFilhos, 2); // StmtList vai para a segunda posicao para liberar a primeira para outro nó {
    tempFilhos[0] = criaNo("{");    
    tempFilhos[2] = criaNo("}"); 

    tempNo = criaNo("CompoundStmt");
    tempFilhos[0] = addFilhos(tempNo,tempFilhos, 3);

    tempNo = criaNo("Stmt");
    tempFilhos[4] = addFilhos(tempNo,tempFilhos, 1);// Stmt vai para a última posição da lista


    tempFilhos[0] = criaNo("if");
    tempFilhos[1] = criaNo("(");
    tempFilhos[2] = expr;
    tempFilhos[3] = criaNo(")");
    // Eu removi direto a parte do else, verificar se da algum problema

    addFilhos(arvore,tempFilhos,5);
    free(tempFilhos);

    return arvore;
}

void geraLabel(){
    labelCont++;
    char *numStr = malloc(50);

    label = malloc(50);
    strcpy(label, "GotoLabel");

    sprintf(numStr,"%d", labelCont);
    strcat(label, numStr);

    free(numStr);
}
