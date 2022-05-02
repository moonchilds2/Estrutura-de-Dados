#include <stdio.h>
#include <stdlib.h>

// Na fila o primeiro elemento adicionado será o primeiro a sair (FIFO)

typedef struct produto {

    int codigo;

    struct produto* prox;

}produto;

// Serão criados 2 ponteiros que ajudarão na compreensão do primeiro e último elemento.

produto* primeiro = NULL;
produto* ultimo = NULL;
int tamanho = 0;


void add(int codigo) {

    produto* novo = malloc(sizeof(produto));
    novo->codigo = codigo;
    novo->prox = NULL;

    if(primeiro == NULL) {
        primeiro = novo;
        ultimo = novo;
    }

    // Assim como em uma fila comum, na estrutura sempre adicionaremos um novo elemento
    // no final dela, ou seja, na ultima posição.

    else {
        // Assim que o novo elemento for adicionada, ele ficará atrás de quem antes era o último.
        ultimo->prox = novo;

        // Depois atualizamos quem agora será a último elemento.
        ultimo = novo;

    }
    tamanho++;
}

void remova() {

    // Na remoção iremos tirar sempre quem foi adicionado primeiro (FIFO), assim, atribuímos o
    // o ponteiro lixo ao elemento que está em primeiro na lista, depois atualizamos quem será o novo
    // primeiro, e desalocamos o espaço do lixo.

    if(primeiro != NULL) {

        produto* lixo;

        lixo = primeiro;

        primeiro = primeiro->prox;

        free(lixo);

        tamanho--;
    }
    
}

void imprima() {
    produto* aux = primeiro;

    for(int i = 0; i < tamanho; i++) {
        printf("Codigo: %d\n", aux->codigo);
        aux = aux->prox;
    }
}

int main() {
    add(1111);
    add(2222);
    add(3333);
    add(4444);
    imprima();
    remova();
    remova();
    printf("--------------------\n");
    imprima();
}