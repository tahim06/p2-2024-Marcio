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
#define TAM_MAX_USUARIOS 300 

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
void loginAdministrador();
void loginUsuario(struct Usuario usuario[], int *contUsuarios);
void cadastro(struct Usuario usuario[], int *contUsuarios);

int main() {
    int tipoUsuario, contUsuarios = 0;
    struct Usuario usuario[TAM_MAX_USUARIOS];
    
    do {
        printf("Como Deseja Logar?\n 1- Administrador\n 2- Usuário\n");
        scanf("%d", &tipoUsuario);
        while (getchar() != '\n'); 
    } while(tipoUsuario < 1 || tipoUsuario > 2);
    
    if(tipoUsuario == 1) {
        loginAdministrador();
    } else if(tipoUsuario == 2) {
        loginUsuario(usuario, &contUsuarios);
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

void loginAdministrador() {
    char senha[TAM_SENHA];
    char senhaAdm[TAM_SENHA] = "m@st3r2024";
    
    do {
        printf("Informe a senha para acessar como Administrador:\n");
        lerString(senha, TAM_SENHA);
    } while(strcmp(senha, senhaAdm) != 0);
    
    printf("Login como Administrador bem-sucedido!\n");
    printf("\n");
}

void loginUsuario(struct Usuario usuario[], int *contUsuarios) {
    int tipoLogin;
    
    do {
        printf("Já possui um cadastro ou deseja cadastrar?\n 1- Logar\n 2- Cadastrar\n");
        scanf("%d", &tipoLogin);
        while (getchar() != '\n'); 
    } while(tipoLogin < 1 || tipoLogin > 2);

    if(tipoLogin == 1) {
        // Implementar funcionalidade de login aqui
        printf("Função de login ainda não implementada.\n");
    } else {
        cadastro(usuario, contUsuarios);
    }
}

void cadastro(struct Usuario usuario[], int *contUsuarios) {
    char confirmarSenha[TAM_SENHA];
    struct Usuario novoUsuario;
    
    printf("Informe seu Nome Completo: \n");
    lerString(novoUsuario.nome, TAM_NOME);
       
    printf("Informe o Login:\n");
    lerString(novoUsuario.login, TAM_LOGIN);

    printf("Informe a Senha:\n");
    lerString(novoUsuario.senha, TAM_SENHA);

    do {  
        printf("Confirme sua senha:\n");
        lerString(confirmarSenha, TAM_SENHA);
    } while(strcmp(novoUsuario.senha, confirmarSenha) != 0);

    novoUsuario.codigo = *contUsuarios + 1;
    novoUsuario.qtdPlaylists = 0;
    novoUsuario.qtdPlaylistsFav = 0;

    usuario[*contUsuarios] = novoUsuario;
    (*contUsuarios)++;

    printf("Cadastro Bem Sucedido!!\n");
}