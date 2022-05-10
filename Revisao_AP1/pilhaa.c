// Na pilha temos o modelo FILO (firs in, last out);

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char* nome;
    int idade;
    double altura;

    struct pessoa* prox;
}pessoa;    

pessoa* topo = NULL;;
int tamanho = 0;

void add_na_pilha(char* nome, int idade, double altura){

    pessoa* nova = malloc(sizeof(pessoa));
    nova->nome = nome;
    nova->idade = idade;
    nova->altura = altura;
    nova->prox = NULL;

    if(topo == NULL){
        topo = nova;
    }
    else{
        nova->prox = topo;
        topo = nova;
    }

    tamanho++;
}

void remove_na_pilha(){
    pessoa* lixo;

    lixo = topo;
    topo = topo->prox;
    free(lixo);
    tamanho--;
}

void imprime(){
    pessoa* aux = topo;

    for(int i = 0; i < tamanho; i++){
        printf("Nome: %s\n", aux->nome);
        aux = aux->prox;
    }
}

int main(){
    add_na_pilha("Rennis", 18, 1.84);
    add_na_pilha("Rodrigo", 19, 1.90);
    add_na_pilha("Vitoria", 19, 1.66);
    add_na_pilha("Julia", 18, 1.62);
    imprime();
    printf("------------------\n");
    remove_na_pilha();
    remove_na_pilha();
    imprime();
}