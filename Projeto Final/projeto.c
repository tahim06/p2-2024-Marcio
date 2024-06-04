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
#define TAM_MAX_USUARIOS 100

struct Musica
{
    int codigo;              // autoincremento
    char titulo[TAM_TITULO]; // título da música
    char artista[TAM_NOME];  // nome do artista que canta esta música
};

struct Playlist
{
    int codigo;               // autoincremento
    int codUsuario;           // o código do usuário que criou a playlist
    char titulo[TAM_TITULO];  // título desta playlist
    int qtdMusicas;           // qtd atual de músicas incluídas nesta playlist
    int musicas[TAM_MUSICAS]; // vetor contendo os códigos das músicas
};

struct Usuario
{
    int codigo; // autoincremento
    char nome[TAM_NOME];
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int qtdPlaylists;                        // quantidade de playlists criadas pelo usuário
    struct Playlist playlists[TAM_PLAYLIST]; // todas as playlists criadas
    int qtdPlaylistsFav;                     // quantidade de playlists favoritadas pelo usuário
    int playlistsFav[TAM_PLAYLIST];          // códigos das playlists favoritadas pelo usuário
};

void lerString(char *str, int maxTam);
void loginAdministrador();
int loginUsuario(struct Usuario usuario[], int *contUsuarios, int *posicao);
void cadastro(struct Usuario usuario[], int *contUsuarios, int *posicao);

int main()
{
    int tipoUsuario, contUsuarios = 0;
    int posicao_usuario = -1;
    struct Usuario usuario[TAM_MAX_USUARIOS];

    do
    {
        printf("Como Deseja Logar?\n 1- Administrador\n 2- Usuário\n");
        scanf("%d", &tipoUsuario);
        while (getchar() != '\n'); // Limpar buffer
    } while (tipoUsuario < 1 || tipoUsuario > 2);

    if (tipoUsuario == 1)
    {
        loginAdministrador();
    }
    else
    {
        int opcao;
        int tentarNovamente;

        do
        {
            printf("Já possui um cadastro ou deseja cadastrar?\n 1- Logar\n 2- Cadastrar\n");
            scanf("%d", &opcao);
            while (getchar() != '\n'); // Limpar buffer
        } while (opcao < 1 || opcao > 2);

        if (opcao == 1)
        {
            while (1)
            {
                if (loginUsuario(usuario, &contUsuarios, &posicao_usuario))
                {
                    printf("Login Bem Sucedido !!\n");
                    break; // Sair do loop de login
                }
                else
                {
                    printf("Login ou Senha inválida!!\n\n");
                    do
                    {
                        printf("O que Deseja?\n 1- Tentar Novamente\n 2- Cadastrar Novo Usuário\n");
                        scanf("%d", &tentarNovamente);
                        while (getchar() != '\n'); // Limpar buffer
                    } while (tentarNovamente < 1 || tentarNovamente > 2);

                    if (tentarNovamente == 1)
                    {
                        continue; // Tentar login novamente
                    }
                    else
                    {
                        cadastro(usuario, &contUsuarios, &posicao_usuario);
                        break; // Sair do loop de login após cadastro
                    }
                }
            }
        }
        else
        {
            cadastro(usuario, &contUsuarios, &posicao_usuario);
        }
    }

    return 0;
}

void lerString(char *str, int maxTam)
{
    fgets(str, maxTam, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n')
    {
        str[tam - 1] = '\0';
    }
}

void loginAdministrador()
{
    char senha[TAM_SENHA];
    char senhaAdm[TAM_SENHA] = "m@st3r2024";
    printf("-----------LOGIN ADM-----------\n");
    do
    {
        printf("Informe a senha para acessar como Administrador:\n");
        lerString(senha, TAM_SENHA);
    } while (strcmp(senha, senhaAdm) != 0);

    printf("Login como Administrador bem-sucedido!\n");
    printf("\n");
}

int loginUsuario(struct Usuario usuario[], int *contUsuarios, int *posicao)
{
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int encontrado = 0;
    printf("-----------LOGIN-----------\n");
    printf("Digite seu Login: ");
    lerString(login, TAM_LOGIN);

    printf("Digite sua senha: ");
    lerString(senha, TAM_SENHA);

    for (int i = 0; i < *contUsuarios; i++)
    {
        if (strcmp(login, usuario[i].login) == 0 && strcmp(senha, usuario[i].senha) == 0)
        {
            encontrado = 1;
            *posicao = i;
            break;
        }
    }

    return encontrado;
}

void cadastro(struct Usuario usuario[], int *contUsuarios, int *posicao)
{
    struct Usuario novoUsuario;

    printf("-----------CADASTRO-----------\n");

    printf("Informe seu Nome Completo: \n");
    lerString(novoUsuario.nome, TAM_NOME);

    printf("Informe o Login:\n");
    lerString(novoUsuario.login, TAM_LOGIN);

    printf("Informe a Senha:\n");
    lerString(novoUsuario.senha, TAM_SENHA);

    novoUsuario.codigo = *contUsuarios + 1;
    novoUsuario.qtdPlaylists = 0;
    novoUsuario.qtdPlaylistsFav = 0;

    usuario[*contUsuarios] = novoUsuario;

    (*contUsuarios)++;
    *posicao = *contUsuarios - 1;

    printf("Cadastro realizado com sucesso!\n Conta Cadastrada foi Logada automaticamente.\n");
}