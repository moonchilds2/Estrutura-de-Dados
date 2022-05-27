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
//será iniciada a percursão de toda a árvore e a busca caso necessária, dele que serão adicionados "filhos"
//à esquerda ou direita.

vertice* raiz = NULL;
int tamanho = 0;

//Começaremos criando uma função para buscar determinado vértice a partir de um id passado por parâmetro
//A função terá como parâmetro a raiz, pois esta função sempre começará a partir dela.
//Inicialmente temos que verificar se realmente existe uma raiz, e a função só ocorrerá se existir tal, ou seja,
//if(aux!=NULL) acontecerá a função, caso contrário será retornado NULL, e vale ressaltar a importância de algo
//sempre ser retornado, dando sinal para o fim da função.



vertice* busca(int id, vertice* aux){

    if(aux != NULL){
        
        //Agora precisamos começar verificando se o id buscado é o id do ponteiro que o aux está apontando.
        //e se for, ele retornará o próprio aux e a função será finalizada.
        if(id == aux->id){
            return aux;
        }
        
        //Caso ele náo esteja no atual aux, precisamos fazer com que ele percorra a árvore.
        //Iniciaremos este processo pela esquerda, como estamos trabalhando com uma Árvore de Busca, sabemos que
        //o vértice-filho à esquerda é sempre é menor do que o vértice-pai, então usaremos isso.

        else if(id < aux->id){
            //Agora precisamos verificar se este vértice à esquerda realmente existe, ou seja, if(aux->esq != NULL)
            //Se existir, temos que retornar a chamada da própria função busca, passando agora como parâmetro o aux->esq
            //assim será verificado se o aux->esq é o vértice procurado, se for, já será retornado ele, e se não for, será
            //retornado NULL. Mas se nem existir vértice à esquerda, precisamos garantir que seja retornado NULL, fazendo com
            //que a função prossiga com sua execução.
            if(aux->esq != NULL){

                return busca(id, aux->esq);

            }else{
                return NULL;
            }
        }


        //Caso o vértice desejado não esteja à esquerda do aux, precisamos fazer com que olhe à direita, e usaremos a mesma
        //lógica da ABB, if(id > aux->id) ele verificará se existe um aux->dir, se sim, ele fará a busca do vértice que está
        //à sua direita (aux->dir), se não existir, retornará NULL.
        

        else if(id > aux->id){
            
            if(aux->dir != NULL){

                return busca(id, aux->dir);
                
            }
            else{
                return NULL;
            }
        }

    }else{
        return NULL;
    }

}