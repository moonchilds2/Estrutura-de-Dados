#include <stdio.h>
#include <stdlib.h>

// A fila tem como modelo FIFO (First in, first out)

typedef struct pessoa{
    char* nome;
    int idade;
    double altura;

    struct pessoa* prox;
}pessoa;    

pessoa* inicio = NULL;
pessoa* fim = NULL;
int tamanho = 0;

void add_na_fila(char* nome, int idade, double altura){

    pessoa* nova = malloc(sizeof(pessoa));
    nova->nome = nome;
    nova->idade = idade;
    nova->altura = altura;
    nova->prox = NULL;

    if(inicio == NULL){
        inicio = nova;
        fim = nova;
    }
    else{
        fim->prox = nova;
        fim = nova;
    }
    tamanho++;

}

void remove_na_fila(){
    pessoa* lixo;

    lixo = inicio;
    inicio = inicio->prox;
    free(lixo);
    tamanho--;
}

void imprime(){
    pessoa* aux = inicio;

    for(int i = 0; i < tamanho; i++){
        printf("Nome: %s\n", aux->nome);
        aux = aux->prox;
    }
}

int main(){
    add_na_fila("Rennis", 18, 1.84);
    add_na_fila("Rodrigo", 19, 1.90);
    add_na_fila("Vitoria", 19, 1.66);
    add_na_fila("Julia", 18, 1.62);
    imprime();
    printf("------------------\n");
    remove_na_fila();
    remove_na_fila();
    imprime();
}