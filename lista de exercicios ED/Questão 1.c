#include <stdio.h>
#include <stdlib.h>

typedef struct conta {

    char* nome;
    int numero;
    int senha;
    double saldo;

    struct conta* ant;
    struct conta* prox;
}conta;

conta* inicio = NULL;
conta* fim = NULL;
int tamanho = 0;

void add(char* nome, int numero, int senha, double saldo) {
    
    conta* nova = malloc(sizeof(conta));
    nova->nome = nome;
    nova->numero = numero;
    nova->senha = senha;
    nova->saldo = saldo;
    nova->ant = NULL;
    nova->prox = NULL;

    if(inicio == NULL) {
        inicio = nova;
        fim = nova;
    }

    //Adicionando no inicio:
    else if(nova->saldo <= inicio->saldo) {
        inicio->ant = nova;
        nova->prox = inicio;
        inicio = nova;
    }

    else if(nova->saldo >= fim->saldo) {
        
    }

    tamanho++;  
}