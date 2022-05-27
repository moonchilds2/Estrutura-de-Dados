#include <stdio.h>
#include <stdlib.h>

typedef struct conta{

    char* nome;
    int numero;
    int senha;
    double saldo;

    struct conta* prox;

}conta;

conta* inicio = NULL;
conta* fim = NULL;
int tamanho = 0;

void cadastrarConta(char* nome, int numero, int senha, double saldo){

    conta* nova = malloc(sizeof(conta));
    nova->nome = nome;
    nova->numero = numero;
    nova->senha = senha;
    nova->saldo = saldo;

    if(inicio == NULL){
        inicio = nova;
        fim = nova;
    }
    else if(nova->saldo <= inicio->saldo){
        nova->prox = inicio;
        inicio = nova;
    }
    else if(nova->saldo >= fim->saldo){
        fim->prox = nova;
        fim = nova;
    }
    else{
        conta* aux = inicio;

        while(nova->saldo >= aux->prox->saldo){
            aux = aux->prox;
        }
        nova->prox = aux->prox;
        aux->prox = nova;
    }
    tamanho++;
}



void visualizar(){
    conta* aux = inicio;

    for(int i = 0; i < tamanho; i++){
        printf("Titular: %s, Saldo: %.1f\n", aux->nome, aux->saldo);
        aux = aux->prox;
    }
}

void removerConta(int numero){
    conta* lixo;

    if(numero == inicio->numero){
        lixo = inicio;
        inicio = inicio->prox;
    }
    else{
        conta* aux = inicio;

        while(aux->prox->numero != numero){
            aux = aux->prox;
        }
        lixo = aux->prox;
        aux->prox = aux->prox->prox;

    }
    free(lixo);
    tamanho--;
}

void depositar(int numero, int senha, int valor){

    if(inicio->numero == numero && inicio->senha == senha){

        inicio->saldo += valor;

        char* inicio_nome = inicio->nome;
        double saldo = inicio->saldo;
        
        removerConta(inicio->numero);
        cadastrarConta(inicio_nome, numero, senha, saldo);
    }

    else if(numero == fim->numero && senha == fim->senha){
        fim->saldo += valor;
    }

    else{
        conta* aux = inicio;

        while(aux->prox->numero != numero){
            aux = aux->prox;
        }
        if(senha == aux->prox->senha){
            aux->prox->saldo += valor;

            char* aux_nome = aux->prox->nome;
            double aux_saldo = aux->prox->saldo;

            removerConta(numero);
            cadastrarConta(aux_nome, numero, senha, aux_saldo);

        }else{
            printf("SENHA INVALIDA, TENTE NOVAMENTE.");
        }
    }
}

void sacar(int numero, int senha, int valor){
    if(numero == inicio->numero && senha == inicio->senha){
        inicio->saldo -= valor;
    }
    else if(numero == fim->numero && senha == fim->senha){
        fim->saldo -= valor;
        char* nome_fim = fim->nome;
        double saldo_fim = fim->saldo;
        removerConta(fim->numero);
        cadastrarConta(nome_fim, numero, senha, saldo_fim);

    }
    else{
        conta* aux = inicio;

        while(aux->prox->numero != numero){
            aux = aux->prox;
        }
        if(senha == aux->prox->senha){
            aux->prox->saldo -= valor;

            char* aux_nome = aux->prox->nome;
            double aux_saldo = aux->prox->saldo;

            removerConta(numero);
            cadastrarConta(aux_nome, numero, senha, aux_saldo);

        }
    }
}


int main(){
    cadastrarConta("Rennis", 1, 123, 10.0);
    cadastrarConta("Julia", 2, 123, 20.0);
    cadastrarConta("Roberta", 3, 123, 30.0);
    visualizar();
    depositar(3, 123, 5);
    printf("-----------------\n");
    visualizar();
    
    
}