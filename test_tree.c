#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct no{
    char *nome;
    int qtdFilhos; //Tamanho da lista de filhos
    struct no   **filhos;

} no;

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

int main(){
    no *arvore, *filho, **filhos;


    arvore = criaNo("Teste");
    filho = criaNo("Filho");
    filhos = malloc(sizeof(no *));
    filhos[0] = filho;


    arvore = addFilhos(arvore, filhos, 1);

    printf("Hello Word!\n");

    printf("Pai: %s\n", arvore->nome);
    printf("Filho: %s\n", arvore->filhos[0]->nome);

    return 0;
}