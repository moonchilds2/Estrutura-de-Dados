#include <stdio.h>
#include <stdlib.h>

typedef struct produto {

    int cod;

    //ponteiros necessarios para percorrer a lista.
    struct produto* prox;
    struct produto* ant;

}produto;

//ponteiros de partida e fim da lista.
produto* Inicio = NULL;
produto* Fim = NULL;

int tamanho = 0;

//funcao para adicionar valores ao novo elemento da lista

void add(int cod, int posicao) {

    //validacao para o acontecimento da funcao.
    if(posicao >= 0 && posicao <= tamanho) {

        //criacao do novo produto atraves de um ponteiro que aloca espaco na memoria.
        produto* novo = malloc(sizeof(produto));
        novo->cod = cod;
        novo->ant = NULL;
        novo->prox = NULL;
        
        //caso nao tenha nenhum elemento na lista, os ponteiros "Inicio" e "Fim" irao apontar...
        //para o mesmo elemento.
        if(Inicio == NULL) {
            Inicio = novo;
            Fim = novo;
        }
        
        //caso a posicao passada para adicionar o novo elemento seja 0, ela tomara o 1 lugar da lista...
        //ent o antigo Inicio tera o ponteiro ant apontando para o novo inicio, ja que ele eh o anterior...
        //o elemento frente ao novo elemente sera o proprio inicio, e depois de atualizar os ponteiros...
        //o Inicio eh atualizado recebendo o endereco do novo elemento.
        else if(posicao == 0) {
            Inicio->ant = novo;
            novo->prox = Inicio;
            Inicio = novo;
        }

        //No caso do elemento ser adicionado no final da lista, primeiro iremos atualizar os ponteiros...
        //como o novo elemento esta a frente do q antes era o Fim, o elemento anterior a ele eh o proprio...
        //Fim, ent novo->ant = Fim, da mesma forma o elemento frente ao Fim eh o novo elemento, logo, ...
        //Fim->prox = novo, e depois de ponteiros atualizados, o Fim apontará para o novo elemento.
        else if(posicao == tamanho) {
            novo->ant = Fim;
            Fim->prox = novo;
            Fim = novo;
        }


        //Caso o elemento seja adicionado no meio da lista, primeiro temos que criar um ponteiro...
        //para percorrer toda a lista, ent para (for) cada item da lista ate a posicao desejada...
        //o ponteiro auxiliar vai sendo atualizado ate chegar na posicao desejada.
        
        //Agora atualizaremos os ponteiros, pensando que o ponteiro aux esta no elemento frente...
        //ao novo elemento, entao novo->prox = aux. 
        
        //Agora iremos atualizar a posicao do ponteiro novo...
        //Como queremos adicionar ele entre o elemento que o ponteiro aux esta apontando e o ponteiro...
        //anterior ao ponteiro aux, usaremos aux->ant para referir ao anterior ao aux e depois...
        //usaremos o ->prox pois eh onde ficara o novo, logo, aux->ant->prox = novo.

        //Agora so resta o ponteiro ant do novo elemento, o elemento anterior sera o mesmo elemento que...
        //antes era anterior ao aux, ja que o novo sera adicionado entre o aux e o aux->ant, logo, ...
        //novo->ant = aux->ant.

        // Agora que ja temos o novo elemento encaixado na lista, so precisamos atualizar o...
        //ponteiro ant do aux que apos as atualizacoes, se tornou o novo elemento, logo, aux->ant = novo.


        else{
            produto* aux = Inicio;

            for(int i = 0; i < posicao; i++) {
                aux = aux->prox;
            }
            novo->prox = aux;
            aux->ant->prox = novo;
            novo->ant = aux->ant;
            aux->ant = novo;
        }

        tamanho++;
    }

}

void imprime() {
    produto* aux = Inicio;

            for(int i = 1; i < tamanho + 1; i++) {
                printf("Produto %d\nCodigo: %d\n\n", i, aux->cod);
                aux = aux->prox;
            }
}

int main() {
    add(2, 0);
    add(3, 1);
    add(4, 2);
    imprime();
}