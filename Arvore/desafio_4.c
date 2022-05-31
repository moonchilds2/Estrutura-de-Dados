#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{

    int id;

    struct vertice* esq;
    struct vertice* dir;

}vertice;

vertice* raiz = NULL;
int tamanho = 0;

vertice* buscar(int id, vertice* aux){

    if(aux != NULL){

        if(id == aux->id){
            return printf("VERTICE %d JA EXISTENTE!\n", aux->id);
        }

        else if(id < aux->id){
            
            if(aux->esq != NULL){
                return buscar(id, aux->esq);
            }else{
                return aux;
            }

        }

        else if(id > aux->id){
            
            if(aux->dir  != NULL){
                return buscar(id, aux->dir);
            }else{
                return aux;
            }
        }
        
    }else{
        return NULL;
    }

}


void add(int id){
    vertice* aux = buscar(id, raiz);

    vertice* novo = malloc(sizeof(vertice));
    novo->id = id;
    novo->esq = NULL;
    novo->dir = NULL;
    

    if(aux == NULL){

        raiz = novo;

    }else{

        if(id > aux->id){
            aux->dir = novo;
        }

        else if(id < aux->id){
            aux->esq = novo;
        }
    }


}


void imprime_in_ordem(vertice* aux){

    if(aux->esq != NULL){
        imprime_in_ordem(aux->esq);
    }
    printf("Vertice: %d\n", aux->id);
    if(aux->dir != NULL){
        imprime_in_ordem(aux->dir);
    }

}

int main(){

    add(10);
    add(3);
    add(15);
    add(12);
    add(8);
    imprime_in_ordem(raiz);

}