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

//Começaremos criando uma função auxiliar para buscar determinado vértice a partir de um id passado por parâmetro
//A função terá como parâmetro a raiz, pois esta função sempre começará a partir dela.
//Inicialmente temos que verificar se realmente existe uma raiz, e a função só ocorrerá se existir tal, ou seja,
//if(aux!=NULL) acontecerá a função, caso contrário será retornado NULL, e vale ressaltar a importância de algo
//sempre ser retornado, dando sinal para o fim da função.



vertice* busca(int id, vertice* aux){

    if(aux != NULL){
        
        //Agora precisamos começar verificando se o id buscado é o id do ponteiro que o aux está apontando.
        //e se for, como não pode ser adicionado vértice já existente, ele retornará um print de erro.
        if(id == aux->id){
            return printf("VERTICE %d JA EXISTE", aux->id);
        }
        
        //Caso ele náo esteja no atual aux, precisamos fazer com que ele percorra a árvore.
        //Iniciaremos este processo pela esquerda, como estamos trabalhando com uma Árvore de Busca, sabemos que
        //o vértice-filho à esquerda é sempre é menor do que o vértice-pai, então usaremos isso.

        else if(id < aux->id){
            //Agora precisamos verificar se este vértice à esquerda realmente existe, ou seja, if(aux->esq != NULL)
            //Se existir, temos que retornar a chamada da própria função busca, passando agora como parâmetro o aux->esq
            //assim fará a verificação deste vértice. Agora se o id for menor que o aux->id e não existir nenhum elemento à
            //esquerda, sabemos que o novo vértice deverá ser um filho do aux, e na função add verificaremos se este filho ficará
            //à esquerda ou à direita deste aux.
            if(aux->esq != NULL){

                return busca(id, aux->esq);

            }else{
                return aux;
            }
        }


        //Agora precisamos verificar para caso o id seja maior do que o vértice atual, e se for, faremos o mesmo processo usado
        //usado para quando o id era menor, mudando que a chamada recursiva receberá como parâmetro o aux->dir.
        

        else if(id > aux->id){
            
            if(aux->dir != NULL){

                return busca(id, aux->dir);
                
            }
            else{
                return aux;
            }
        }

    }else{
        return NULL;
    }

}


//Agora que temos uma òtima função auxiliar, podemos desenvolver nossa função que realmente vai adicionar um novo vértice.

void add(int id){

    //Primeiro alocaremos espaço na memória para este novo vértice e atribuiremos valores às suas variáveis.

    vertice* novo = malloc(sizeof(vertice));
    novo->id = id;
    novo->esq = NULL;
    novo->dir = NULL;

    //Agora agora com o auxilio de uma variável de ponteiro, descobriremos a partir de qual vértice devemos adicionar o novo
    //usando da função que retorna NULL, caso não tenha vértice na raiz e retorna o ponteiro de um vértice sem filho do qual
    //poderemos adicionar um novo.

    vertice* aux = busca(id, raiz);


    //Se o aux retornar NULL, quer dizer que não existe vértice na raiz, logo, a raiz receberá este novo vértice que criamos.
    //Caso não retorne NULL, teremos o aux apontando para um vértice que pode receber o filho que estamos criando, apenas teremos
    //que descobrir se este vértice será adicionado à esquerda ou à direita do vértice-pai.
    if(aux == NULL){
        raiz = novo;
    }else{

        //Se o id do novo vertice for menor do que o id do aux, o novo deverá ser adicionado à esquerda do aux:
        if(id < aux->id){
            aux->esq = novo;
        }

        //Agora, caso o id seja maior, ele deverá ser adicionado à direita:

        else if(id > aux->id){
            aux->dir = novo;
        }

    }

}

// E assim está finalizada a função de adicionar vértices em uma Árvore Binária de Busca.