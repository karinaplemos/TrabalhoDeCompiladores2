#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*-------------------------------------------------------------------------
                               Tabela de símbolos
-------------------------------------------------------------------------*/
struct simbolo_na_tabela{
    char *valor; 
    struct simbolo_na_tabela *proximo;
};
typedef struct simbolo_na_tabela simbolo_na_tabela;

//Cadeia de simbolos
simbolo_na_tabela *tabela_simbolos = (simbolo_na_tabela *)0;

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
