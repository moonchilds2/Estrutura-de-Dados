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

void cadastrarConta(char* nome, int numero, int senha, double saldo) {
    
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
        nova->ant = fim;
        fim->prox = nova;
        fim = nova;
    }

    else{
        conta* aux = inicio;

        while(aux->prox->saldo < nova->saldo) {
            aux = aux->prox;
        }
        nova->ant = aux;
        nova->prox = aux->prox;
        nova->ant->prox = nova;
        nova->prox->ant = nova;

    }

    tamanho++;  
}

char* removerConta(int numero) {
    conta* lixo;

    if(numero == inicio->numero) {
        lixo = inicio;
        inicio = inicio->prox;
    }
    else if(numero == fim->numero){
        lixo = fim;
        fim = fim->ant;
        fim->prox = NULL;
    }
    else {
        conta* aux = inicio;

        while(aux->numero != numero) {
            aux = aux->prox;
        }
        lixo = aux;
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
    }
    char* titular_removido = lixo->nome;
    free(lixo);
    tamanho--;
    
    return titular_removido;
}

void depositar(int numero, int senha, int valor) {

    if(numero == inicio->numero) {
        if(senha == inicio->senha) {
            inicio->saldo += valor;
        }else{
            printf("Senha incorreta.\n");
        }
    }

    else if(numero == fim->numero) {
        if(senha == fim->senha) {
            fim->saldo += valor;
        }else{
            printf("Senha incorreta.\n");
        }
    }

    else {
        conta* aux = inicio;

        while(numero != aux->numero) {
            aux = aux->prox;
        }

        if(senha == aux->senha) {
            aux->saldo += valor;
        }else {
            printf("Senha incorreta.\n");
        }
    }

}

void sacar(int numero, int senha, int valor) {
    if(numero == inicio->numero) {
        if(senha == inicio->senha) {
            inicio->saldo -= valor;
        }else{
            printf("Senha incorreta.\n");
        }
    }

    else if(numero == fim->numero) {
        if(senha == fim->senha) {
            fim->saldo -= valor;
        }else{
            printf("Senha incorreta.\n");
        }
    }

    else {
        conta* aux = inicio;

        while(numero != aux->numero) {
            aux = aux->prox;
        }

        if(senha == aux->senha) {
            aux->saldo -= valor;
        }else {
            printf("Senha incorreta.\n");
        }
    }
}

void visualizar() {
    conta* aux = inicio;

    for(int i = 0; i < tamanho; i++) {
        printf("\nTitular: %s, Saldo: %.2f\n\n", aux->nome, aux->saldo);
        aux = aux->prox;
    }
}

int main() {
    cadastrarConta("Rodrigo", 1, 123, 20.00);
    cadastrarConta("Fernando", 2, 123, 30.00);
    cadastrarConta("Julia", 3, 123, 40.00);
    cadastrarConta("Rennis", 4, 123, 50.00);
    visualizar();

    printf("Removendo uma conta");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".\n\n");
    printf("Titular da conta removida: %s\n", removerConta(2));

    printf("----------------------------\n\n");
    depositar(4, 123, 50.00);
    visualizar();
    printf("----------------------------\n\n");
    sacar(4, 123, 20.00);
    visualizar();

}