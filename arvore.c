#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *direita, *esquerda;
} NoArv;

/*NoArv* inserir_v1 (NoArv *raiz, int num) { //versão mais custosa, pois tem o retorno de um nó toda vez que utilizada
    if(raiz == NULL) {//verifica se o conteudo é nulo
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->direita = NULL;
        aux->esquerda = NULL;
        return aux;

    } else {
        if (num < raiz->valor) {
            raiz->esquerda = inserir_v1(raiz->esquerda, num);
            
        } else {
            raiz->direita = inserir_v1(raiz->direita, num);
        } 
        return raiz;
    }
}*/

void inserir(NoArv **raiz, int num) {
    if(*raiz == NULL) {//verificando se o conteudo do ponteiro é nulo
        *raiz = malloc(sizeof(NoArv));//altera o conteúdo da raiz direto da main
        (*raiz)->valor = num;
        (*raiz)->direita = NULL;
        (*raiz)->esquerda = NULL;

    } else {
        if(num < (*raiz)->valor) {
            inserir_v2(&((*raiz)->esquerda), num);
        } else {
            inserir_v2(&((*raiz)->direita), num);
        }
    }
}

/*void inserir_v3 (NoArv **raiz, int num) {
    NoArv *aux = *raiz;

    while(aux) {
        if(num < aux->valor) {
            raiz = &aux->esquerda;
        } else {
            raiz = &aux->direita;
        }
        aux = *raiz;
    }

    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->direita = NULL;
    aux->esquerda = NULL;
    *raiz = aux;
}*/

void mostrar_v1 (NoArv *raiz) { // Mostra a arvore em ordem de insercao
    if(raiz) {
        printf("\t%d ", raiz->valor);
        mostrar_v1(raiz->esquerda);
        mostrar_v1(raiz->direita);
    }
}

void mostrar_v2 (NoArv *raiz) { //mostra arvore ordenada
    if(raiz) {
        mostrar_v2(raiz->esquerda);
        printf("\t%d ", raiz->valor);
        mostrar_v2(raiz->direita);
    }
}

int main () {

    NoArv *raiz = NULL;
    int opcao,valor;

    do {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\n\tDigite um valor:");
                scanf("%d",&valor);
                //raiz = inserir_v1(raiz,valor);
                inserir(&raiz, valor);//o & pega o endereço da variavel raiz, como a variavel raiz é um ponteiro, da certinho com o parametro **raiz
                //inserir_v3(&raiz, valor);
                break;
            case 2:
                printf("\n\tPrimeira impressao:\n");
                mostrar_v1(raiz);
                printf("\n");

                printf("\n\tSegunda impressao:\n");
                mostrar_v2(raiz);
                break;
            default:
                if (opcao != 0) {
                    printf("Digite uma opcao valida");
                }
        }
    } while (opcao != 0);

    raiz = inserir_v1(raiz, 50);

    return 0;
}