#include <stdio.h>
#include <stdlib.h>

// Na pilha o primeiro elemento adicionado será o último a ser removido (FILO)
// Já a sua estrutura é bem parecida com a lista encadeada, no entanto não precisamos
// nos preocupar tanto com adicionar e remover em todos os lugares, somente nos necessários.

typedef struct produto {

    int codigo;

    struct produto* prox;

}produto;


// Da mesma forma que foi criado o ponteiro "Inicio" na fila encadeada, aqui será criadoa 
// um ponteiro que servirá para identificar qual elemento está no topo da lista.

produto* topo = NULL;
int tamanho = 0;

void add(int codigo) {

    produto* novo = malloc(sizeof(produto));
    novo->codigo = codigo;
    novo->prox = NULL;

    // Se a lista estiver vazia quando o produto for criado, o topo será o novo produto.

    if(topo == NULL) {
        topo = novo;
    }

    // Caso já tenha elementos na lista, queremos que o elemento a ser adicionado
    // fique no topo da lista, então:

    else{
        // Vamos começar atualizando o ponteiro prox do novo elemento, e como
        // a pilha é sequenciada de cima pra baixo, o próximo elemento será o que antes era o topo.
        novo->prox = topo;

        // Agora só preciamos atualizar quem é o novo elemento no topo:
        topo = novo;
    }  

    tamanho++;

}

//Já na remoção precisamos também remover sempre pelo topo e atualizar o topo para o próximo produto.

void remova() {
    produto* lixo;

    if(topo != NULL){
        lixo = topo;

        topo = topo->prox;

        free(lixo);

        tamanho--;
    }
}

void imprima() {
    produto* aux = topo;

    for(int i = 0; i < tamanho; i++) {
        printf("Codigo: %d\n", aux->codigo);
        aux = aux->prox;
    }
}

//Assim temos uma pilha em que sempre é adicionada ou removida pelo topo e que usa apenas operações Lineares.

int main() {
    add(1111);
    add(2222);
    add(3333);
    add(4444);
    imprima();
    remova();
    remova();
    printf("---------------------\n");
    imprima();
}