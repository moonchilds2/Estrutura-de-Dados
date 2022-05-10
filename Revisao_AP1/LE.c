#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char* nome;
    int idade;
    double altura;

    struct pessoa* prox;
}pessoa;

pessoa* inicio = NULL;
pessoa* fim = NULL;
int tamanho = 0;

void add_na_lista(char* nome, int idade, double altura, int posicao){

    if(posicao >= 0 && posicao <= tamanho){
        pessoa* nova = malloc(sizeof(pessoa));
        nova->nome = nome;
        nova->idade = idade;
        nova->altura = altura;
        nova->prox = NULL;

        if(inicio == NULL){
            inicio = nova;
            fim = nova;
        }
        else if(posicao == 0){
            nova->prox = inicio;
            inicio = nova;
        }
        else if(posicao == tamanho){
            fim->prox = nova;
            fim = nova;
        }
        else{
            pessoa* aux = inicio;
            for(int i = 0; i < posicao - 1; i++){
                aux = aux->prox;
            }
            nova->prox = aux->prox;
            aux->prox = nova;
        }
        tamanho++;
    }
}

void remove_na_lista(int posicao){
    
    if(posicao >= 0 && posicao < tamanho){
        pessoa* lixo;

        if(posicao == 0){
            lixo = inicio;
            inicio = inicio->prox;
        }
        else{
            pessoa* aux = inicio;
            for(int i = 0; i < posicao - 1; i++){
                aux = aux->prox;
            }
            lixo = aux->prox;
            aux->prox = aux->prox->prox;
        }
        free(lixo);
        tamanho--;
    }
}

void imprime(){
    pessoa* aux = inicio;

    for(int i = 0; i < tamanho; i++){
        printf("Nome: %s\n", aux->nome);
        aux = aux->prox;
    }
}

int main(){
    add_na_lista("Rennis", 18, 1.84, 0);
    add_na_lista("Rodrigo", 19, 1.90, 1);
    add_na_lista("Vitoria", 19, 1.66, 2);
    add_na_lista("Julia", 18, 1.62, 3);
    imprime();
    printf("------------------\n");
    remove_na_lista(2);
    remove_na_lista(1);
    imprime();
}