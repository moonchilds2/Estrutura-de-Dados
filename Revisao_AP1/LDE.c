#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{

    char* nome;
    int idade;
    double altura;

    struct pessoa* ant;
    struct pessoa* prox;

}pessoa;

pessoa* inicio = NULL;
pessoa* fim = NULL;
int tamanho = 0;

void add_na_LDE(char* nome, int idade, double altura, int posicao){

    if(posicao >= 0 && posicao <= tamanho){

        pessoa* nova = malloc(sizeof(pessoa));
        nova->idade = idade;
        nova->nome = nome;
        nova->altura = altura;
        nova->ant = NULL;
        nova->prox = NULL;

        if(inicio == NULL){
            inicio = nova;
            fim = nova;
        }
        else if(posicao == 0){
            nova->prox = inicio;
            inicio->ant = nova;
            inicio = nova;
        }
        else if(posicao == tamanho){
            nova->ant = fim;
            fim->prox = nova;
            fim = nova;
        }
        else{
            pessoa* aux = inicio;
            for(int i = 0; i < posicao; i++){
                aux = aux->prox;
            }
            nova->prox = aux;
            nova->ant = aux->ant;
            nova->ant->prox = nova;
            nova->prox->ant = nova;
            
        }


        tamanho++;
    }

}

void remove_na_LDE(int posicao){
    
    if(posicao >= 0 && posicao < tamanho){
        pessoa* lixo;

        if(posicao == 0){
            lixo = inicio;
            inicio = inicio->prox;
            inicio->ant = NULL;
        }
        else if(posicao == tamanho - 1){
            lixo = fim;
            fim = fim->ant;
            fim->prox = NULL;
        }
        else{
            pessoa* aux = inicio;

            for(int i = 0; i < posicao; i++){
                aux = aux->prox;
            }
            lixo = aux;
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
        }

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
    add_na_LDE("Rennis", 18, 1.84, 0);
    add_na_LDE("Rodrigo", 19, 1.90, 1);
    add_na_LDE("Vitoria", 19, 1.66, 2);
    add_na_LDE("Julia", 18, 1.62, 3);
    imprime();
    printf("------------------\n");
    remove_na_LDE(1);
    remove_na_LDE(1);
    imprime();
}