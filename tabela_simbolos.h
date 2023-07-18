#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct simbolo_na_tabela{
    char *valor;
    int tipo;
    struct simbolo_na_tabela *proximo;
};
typedef struct simbolo_na_tabela simbolo_na_tabela;

//Cadeia de simbolos
simbolo_na_tabela *tabela_simbolos = (simbolo_na_tabela *)0;

//posição com as funções
simbolo_na_tabela *posicao_func  = (simbolo_na_tabela *)0; //Armazana a posição da tabela em que os identificadores de função estarão armazenados.

//Operações existentes na tabela
simbolo_na_tabela * put_simbolo_na_tabela(char *simbolo)
{
    simbolo_na_tabela *ptr;
    ptr = (simbolo_na_tabela *) malloc (sizeof(simbolo_na_tabela));
    ptr->valor = (char *) malloc (strlen(simbolo)+1);
    strcpy (ptr->valor,simbolo);
    ptr->proximo = (struct simbolo_na_tabela *)tabela_simbolos;
    tabela_simbolos = ptr;
    return ptr;
}

simbolo_na_tabela * get_simbolo_da_tabela(char *simbolo)
{
    simbolo_na_tabela *ptr;
    for (ptr = tabela_simbolos; ptr != (simbolo_na_tabela *) 0; ptr = (simbolo_na_tabela *) ptr->proximo)
        if (strcmp (ptr->valor,simbolo) == 0)
            return ptr;
    return 0;
}

void print_tabela()
{
    simbolo_na_tabela *ptr;
    for (ptr = tabela_simbolos; ptr != (simbolo_na_tabela *) 0; ptr = (simbolo_na_tabela *) ptr->proximo)
        printf("simbolo: %s, tipo: %d \n", ptr->valor, ptr->tipo);
}

// Apaga a tabela até chegar na posição em que as funções estão armazenadas
void limpa_tabela(simbolo_na_tabela * ptr){
    if(ptr->proximo != posicao_func){
        limpa_tabela(ptr->proximo);
    }

    free(ptr->valor);
    free(ptr);
}

// Reseta a tabela para um novo contexto 
simbolo_na_tabela * reseta_tabela(int index){
    //print_tabela();
    simbolo_na_tabela *ptr;
    ptr = tabela_simbolos;

    //Todos os elementos referentes ao contexto atual serão removidos, só permanecendo os identificadores de funções
    if(ptr->proximo != posicao_func){
        limpa_tabela(ptr->proximo);
    }
    
    ptr->proximo = posicao_func;
    posicao_func = ptr;
    printf("\n");
    //print_tabela();
}

