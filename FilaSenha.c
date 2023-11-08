#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct No {
    char *senha;
    struct No *prox;
} No;


No *push(No *atual, int *t);
No *pop(No *atual);
void print(No *atual);


int main() {

    setlocale(LC_ALL,"");

    No *fila = NULL;
    int op, tam = 0;


    printf("Seja bem vindo ao sistema do Mec-Dunud\n");

    do {
        printf("\n\nGostaria de fazer um pedido? \n1 - Gerar senha\n2 - Atender usuario\n3 - Imprimir \n0 - Sair do sistema\n\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                fila = push(fila, &tam);
                break;
            case 2:
                if(fila==NULL){
                    printf("Lista vazia");
                }else{
                    fila = pop(fila);
                }
                break;
            case 3:
                print(fila);
                break;
            case 0:
                break;
            default:
                printf("Valor inválido, escolha um de 0 - 3\n");
                break;
        }
    } while (op != 0);


    while (fila != NULL) {
        No *temp = fila;
        fila = fila->prox;
        free(temp->senha);
        free(temp);
    }

    return 0;
}

No *push(No *atual, int *t) {
    No *novo = (No *)malloc(sizeof(No));
    novo->senha = (char *)malloc(50);
    sprintf(novo->senha, "IFET %d", (*t) + 1);
    novo->prox = atual;
    atual = novo;
    (*t)++;

    return atual;
}

No *pop(No *atual) {

    No *inicio=(No*)malloc(sizeof(No));
    inicio=atual;
    No *temp = NULL;

    if(atual==NULL){
        return atual;
    }else{
        while(atual->prox!=NULL){
            temp=atual;
            atual=atual->prox;
        }
        if(atual->prox==NULL&&temp==NULL){
            atual=atual->prox;
            return atual;
        }else{
            temp->prox=atual->prox;
            free(atual);
            return inicio;
        }
    }
}

void print(No *atual) {
    if (atual == NULL) {
        printf("Lista vazia\n");
    } else {
        while (atual != NULL) {
            printf("Senha: %s\n", atual->senha);
            atual = atual->prox;
        }
    }
}
