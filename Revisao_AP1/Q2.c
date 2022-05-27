#include <stdio.h>
#include <stdlib.h>

typedef struct musica{
    char* nome;
    char* cantor;
    int tempo;

    struct musica* prox;
}musica;

musica* primeira_musica = NULL;
musica* ultima_musica = NULL;
int tamanho = 0;

void add_na_playlist(char* nome, char* cantor, int tempo){
    musica* nova = malloc(sizeof(musica));
    nova->nome = nome;
    nova->cantor = cantor;
    nova->tempo = tempo;
    nova->prox = NULL;

    if(primeira_musica == NULL){
        primeira_musica = nova;
        ultima_musica = nova;
    }else{

        ultima_musica->prox = nova;
        ultima_musica = nova;
        ultima_musica->prox = primeira_musica;
        
    }
    tamanho++;
}

void play_ordem(int num_vezes){
    musica* aux = primeira_musica;

    int i = 0;
    while(i < num_vezes){
        if(aux->prox == primeira_musica){
            i++;
        }
        printf("Musica: %s\n", aux->nome);
        aux = aux->prox;
    }
}

void remove_da_playlist(char* nome){
    musica* lixo;

    if(nome == primeira_musica->nome){
        lixo = primeira_musica;
        primeira_musica = primeira_musica->prox;
    }
    else{
        musica* aux = primeira_musica;

        while(aux->prox->nome != nome){
            aux = aux->prox;
        }
        lixo = aux->prox;
        aux->prox = aux->prox->prox;
    }
}

int main(){
    add_na_playlist("Chandelier", "Sia", 19);
    add_na_playlist("Chuva de Sexta", "Kamai", 20);
    add_na_playlist("miau", "gato", 25);
    play_ordem(2);
    printf("------------\n");
    remove_da_playlist("miau");
    play_ordem(2);
}