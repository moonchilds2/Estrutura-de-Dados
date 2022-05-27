#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int cod_prod;

    struct no* prox;
}no;


//Para o imprimir passar a ser recursivo, eh preciso retirar atribuicao de variaveis e os lacos de repeticao
//para isso o ponteiro auxiliar sera passado como parametro, pois dita de onde iniciara a funcao
//depois eh preciso criar uma condicao de parada de execucao da pilha de chamadas de funcao
//e queremos que pare de imprimir quando o aux apontar para NULL, pois indica que o aux ja percorreu toda a TAD
//e enquanto o aux nao apontar para NULL, ela printara o cod_prod do aux atual e chamara novamente a mesma funcao
//que agora recebera como parametro aux->prox, e assim sera percorrido e printado toda a TAD.

//Caso o imprimir viesse antes do print, seria empilhado as chamadas de funcoes antes dos prints e depois comecaria
//a ser imprimido a partir da ultima chamada de funcao, ou seja, seria a impressao do inverso da TAD.

//Desenhar mentalmente o empilhamento das chamadas ajuda na resolucao do raciocinio, lembrando sempre de priorizar 
//as chamadas da funcoes, e tudo so sera executado quando nao houver novas chamadas.

void imprimir(no* aux){
    if(aux != NULL){
        printf("Codigo do produto: %d\n", aux->cod_prod);
        imprimir(aux->prox);
    }
}