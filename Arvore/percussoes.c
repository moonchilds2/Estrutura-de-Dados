#include <stdio.h>
#include <stdlib.h>

//Primeiramente na árvore é preciso criar um struct e como é binária, cada vértice terá 2 ponteiros
//sendo eles o vértice que ficará à esquerda e outro para a direita.

typedef struct vertice{

    int id;

    struct vertice* esq;
    struct vertice* dir;

}vertice;


//Primeiramente criaremos um ponteiro de vértice que apontará para a raiz de toda a árvore, é de lá que
//será iniciada a percusão de toda a árvore e a busca caso necessária, dele que serão adicionados "filhos"
//à esquerda ou direita.

vertice* raiz = NULL;
int tamanho = 0;


//Existem 3 formas de percorrer uma árvore binária, começaremos pela in_ordem:

//In Ordem: 

//Nesse forma de percorrer a árvore, precisamos de uma função com parâmetro de um ponteiro de vértice
//Faremos uma verificação: Se houver vértice à esquerda do vértice atual, será feita a chamada da função passando
//como parâmetro esse vértice à esquerda (aux->esq), quando isso acontecer, a função será chamada novamente mas dessa
//vez para este novo vértice, e isso acontecerá enquanto houverem vértices à esquerda do vértice atual. 
//Quando finalmente não houver vértice nenhum à esquerda, printaremos o vértice em questão, e agora que verificaremos se
//existe vértice à direita, se houver, será feita a chamada da função para este vértice (aux->dir), e aí acontecerá toda
//a verificação passada (se tem vértice na esquerda ou não, até que não haja vértice nem à esquerda e nem à direita
//quando isso finalmente acontecer, a função será desempilhada, voltando à função que chamou ela e assim por diante
//até todas as funções empilhadas serem finalizadas.

void in_ordem(vertice* aux){

    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }

    printf("Vertice: %d", aux->id);

    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }

}


//Pre Ordem: 

//A mesma lógica de empilhar funções feita no pre_ordem será aplicada aqui, mas agora funcionará diferente
//assim que a chamada da função for feita, já será feita a impressão do vértice, e após isso, verificará
//se tem vértice à esquerda ou não, se tiver a função é chamada para aquele vértice (aux->esq) e já feita
//a impressão, e acontece até não ter vértices à esquerda, quando não houver, será verificado se tem à direita
//e acontecerá da mesma forma, sempre priorizando os da esquerda.


void pre_ordem(vertice* aux){

    printf("Vertice: %d", aux->id);
    if(aux->esq != NULL){
        pre_ordem(aux->esq);
    }
    if(aux->dir != NULL){
        pre_ordem(aux->dir);
    }

}


//Pos Ordem: 

//Aqui tamém será usada a mesma lógica das outras duas formas, mas agora será impresso apenas depois de percorrer tanto
//toda a esquerda quanto toda a direita de tal vértice, ou seja, enquanto houver vértice à esquerda, percorre, se não houver
//verifica se tem à direita, se tiver, é feita a chamada da função, se não houver, acontece a impressão.

void pos_ordem(vertice* aux){

    if(aux->esq != NULL){
        pos_ordem(aux->esq);
    }
    if(aux->dir != NULL){
        pos_ordem(aux->dir);
    }
    printf("Vertice: %d", aux->id);
}