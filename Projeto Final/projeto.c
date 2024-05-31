#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_MAX_PLYLST 200 
#define TAM_NOME 50 
#define TAM_LOGIN 15 
#define TAM_SENHA 15 
#define TAM_PLAYLIST 100 
#define TAM_TITULO 50 
#define TAM_MUSICAS 100
#define TAM_MAX_USUARIOS 200 

struct Musica { 
int codigo; // autoincremento 
char titulo[TAM_TITULO]; // título da música 
char artista[TAM_NOME]; // nome do artista que canta esta música 
}; 

struct Playlist { 
int codigo; // autoincremento 
int codUsuario; // o código do usuário que criou a playlist 
char titulo[TAM_TITULO]; // título desta playlist 
int qtdMusicas; // qtd atual de músicas incluídas nesta playlist 
int musicas[TAM_MUSICAS]; // vetor contendo os códigos das músicas 
}; 

struct Usuario {  
int codigo; // autoincremento 
char nome[TAM_NOME]; 
char login[TAM_LOGIN]; 
char senha[TAM_SENHA]; 
int qtdPlaylists; // quantid. de playlists criadas pelo usuário 
struct Playlist playlists[TAM_PLAYLIST]; // todas playlists criadas 
int qtdPlaylistsFav; // quantid. de playlists favoritadas pelo usuário 
int playlistsFav[TAM_PLAYLIST]; // códigos das playlists favoritadas pelo usuário 
};

void lerString(char *str, int maxTam);

int main(){
    struct Usuario usuario[TAM_MAX_USUARIOS];
    int tipoUsuario;
    char senha[TAM_SENHA];
    char senhaAdm[TAM_SENHA] = "m@st3r2024\0";

    do{
    printf("Como Deseja Logar?\n 1- Administrador\n 2- Usuário");
    scanf("%d", &tipoUsuario);
    while (getchar() != '\n');
    } while(tipoUsuario < 1 || tipoUsuario > 2);
    
    
    if(tipoUsuario == 1){
        do{
        printf("Informe a senha para acessar como Administrador :\n");
        lerString(senha,TAM_SENHA);
        }while(strcmp(senha,senhaAdm) != 0);



    }





    return 0;
}

void lerString(char *str, int maxTam) {
    fgets(str, maxTam, stdin);
    int tam = strlen(str);
    if (str[tam - 1] == '\n') {
      str[tam - 1] = '\0';
    }
}