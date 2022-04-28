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
        else{
            produto* aux = Inicio;

            for(int i = 0; i < posicao; i++) {
                aux = aux->prox;
            }
        //Agora atualizaremos os ponteiros, comecando com os ponteiros do novo elemento temos que:
        //lembrando que o aux esta no elemento que vai ficar a frente do novo elemento, entao...
        //novo->prox = aux; 
        //Agora falta o ponteiro ant do novo elemento, basta lembrar que como o novo ainda nao foi...
        //"encaixado", o elemento que sera o ant dele, sera o ant do proprio aux, logo, novo->ant = aux->ant.
            novo->prox = aux;
            novo->ant = aux->ant;
        //Agora iremos atualizar os ponteiros dos elementos que estao na frente e atras do novo elemento, assim...
        //começando pelo elemento anterior ao novo (novo->ant) como queremos atualizar o próximo elemento dele, ...
        //usaremos novo->ant->prox que receberá o próprio novo elemento, então novo->ant->prox = novo;
        //Agora só resta atualizar o ponteiro ant do elemento frente ao novo, sendo (novo->prox) este elemento...
        //como queremos atualizar o ponteiro ant deste elemento, teremos: novo->prox->ant = novo;
            novo->ant->prox = novo;
            novo->prox->ant = novo;
        }

        tamanho++;
    }

}

//função para remover elementos da lista.
int remova(int posicao) {

    //condição para o elemento ser removido:
    if(posicao >= 0 && posicao < tamanho) {

        //cria-se um ponteiro que recebera o endereco do elemento a ser removido:
        produto* lixo;

        
        //Caso o elemento a ser removido esteja na primeira posição, primeiro temos que atualizar o...
        //ponteiro inicio para o elemento frente à ele, pois este passará a ser o novo inicio.
        if(posicao == 0) {
            lixo = Inicio;
            Inicio = Inicio->prox;
        }

        
        //Agora para caso o elemento a ser removido seja o último elemento, temos o mesmo processo...
        //mas dessa vez atualizando o ponteiro fim para o elemento anterior a ele, logo:
        else if(posicao == tamanho - 1) {
            lixo = Fim;
            Fim = Fim->ant;
            Fim->prox = NULL;
        }

        
        //Agora se o elemento a ser removido for um que está no meio da lista, temos que criar um ponteiro...
        //para percorrer a lista e chegar até o elemento a ser removido, de forma que ele comece do inicio...
        else{
            produto* aux = Inicio;
            for(int i = 0; i < posicao; i++) {
                aux = aux->prox;
            }
            //Agora o aux está apontando para o elemento a ser removido, aí basta fazer o lixo apontar para ele...
            //depois temos que religar os elementos da lista depois da remoção, exemplo: tendo 3 elementos 1, 2 e 3...
            //se removermos o elemento 2, temos que ligar o 1 ao 3.
            lixo = aux;

            //O aux representa o 2 nesse exemplo, o 1 é o aux->ant e como queremos atualizar o ponteiro prox dele,... 
            //usamos aux->ant->prox recebendo o 3, que é aux->prox, assim teremos: aux->ant->prox = aux->prox.            
            aux->ant->prox = aux->prox;

            //Agora o 3 é o aux->prox que terá o ponteiro ant atualizado para o aux->ant, logo: aux->prox->ant = aux->ant
            aux->prox->ant = aux->ant;
        }

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
    add(5, 3);
    imprime();
    printf("----------------\n");
    remova(1);
    printf("Produtos apos a remocao: \n\n");
    imprime();
}