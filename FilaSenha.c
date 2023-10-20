#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct No {
    char *senha;
    struct No *prox;
} No;

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

    No *temp,*inicio =(No*)malloc(sizeof(No));
    if (atual == NULL) {
        printf("Lista vazia\n");
    } else {
        inicio = atual;
        temp = atual;
        while(atual->prox!=NULL){
            atual=atual->prox;
        }
        while(temp->prox!=atual){
            temp=temp->prox;
        }
        temp->prox=NULL;
        atual=inicio;
    }
    return atual;
}

void print(No *atual) {
    int c = 0;
    if (atual == NULL) {
        printf("Lista vazia\n");
    } else {
        while (atual != NULL) {
            printf("Senha %d: %s\n", c + 1, atual->senha);
            atual = atual->prox;
            c++;
        }
    }
}
int main() {
    No *fila = NULL;
    int op, tam = 0;

    printf("Seja bem vindo ao sistema do Mec-Dunud\n");

    do {
        printf("Gostaria de fazer um pedido? \n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                fila = push(fila, &tam);
                break;
            case 2:
                fila = pop(fila);
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
