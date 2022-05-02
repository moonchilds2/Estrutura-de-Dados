#include <stdio.h>
#include <stdlib.h>

typedef struct musica {
    char* nome_musica;
    char* cantor_ou_banda;
    int tempo;

    struct musica* ant;
    struct musica* prox;
}musica;

musica* inicio = NULL;
musica* fim = NULL;
int tamanho = 0;

void add_na_playlist(char* nome_musica, char* cantor_ou_banda, int tempo) {

    musica* nova = malloc(sizeof(musica));
    nova->nome_musica = nome_musica;
    nova->cantor_ou_banda = cantor_ou_banda;
    nova->tempo = tempo;
    nova->ant = NULL;
    nova->prox = NULL;

    if(inicio == NULL) {      
        inicio = nova;
        fim = nova;

    }else{
        nova->ant = fim;
        fim->prox = nova;
        fim = nova;
        fim->prox = inicio;     
    }
}


void play_ordem(int num_vezes) {

    musica* aux = inicio;

    int i = 0;
    while(i < num_vezes) {

        if(aux->prox == inicio) {
            i++;
        }
        
        printf("\nMusica: %s, Cantor/Banda: %s, tempo: %d segundos\n\n", aux->nome_musica, aux->cantor_ou_banda, aux->tempo);
        aux = aux->prox;       
    }

}

char* remove_na_playlist(char* nome_musica) {
    musica* lixo;
    
    if(nome_musica == inicio->nome_musica) {
        lixo = inicio;
        inicio = inicio->prox;
    }
    else if(nome_musica == fim->nome_musica) {
        lixo = fim;
        fim = fim->ant;
        fim->prox = NULL;
    }else{
        musica* aux = inicio;

        while(aux->nome_musica != nome_musica) {
            aux = aux->prox;
        }
        lixo = aux;
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
    }
    char* ret_nome_musica = lixo->nome_musica;
    free(nome_musica);
    tamanho--;

    return ret_nome_musica;

}
int main() {
    add_na_playlist("Sozinho", "Caetano Veloso", 120);
    add_na_playlist("Unstoppable", "Sia", 100);
    add_na_playlist("Carrinho De Madeira", "Kamaitachi", 80);
    play_ordem(2);
    remove_na_playlist("Unstoppable");
    printf("---------------------------------------------------------------\n\n");
    play_ordem(2);
}