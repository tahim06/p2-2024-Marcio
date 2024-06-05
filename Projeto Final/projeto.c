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

struct Musica {
    int codigo;              // autoincremento
    char titulo[TAM_TITULO]; // título da música
    char artista[TAM_NOME];  // nome do artista que canta esta música
};

struct Playlist {
    int codigo;               // autoincremento
    int codUsuario;           // o código do usuário que criou a playlist
    char titulo[TAM_TITULO];  // título desta playlist
    int qtdMusicas;           // qtd atual de músicas incluídas nesta playlist
    int musicas[TAM_MUSICAS]; // vetor contendo os códigos das músicas
};

struct Usuario {
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
int loginAdministrador();
int loginUsuario(struct Usuario usuario[], int *contUsuarios, int *posicao);
void cadastro(struct Usuario usuario[], int *contUsuarios, int *posicao);
void listarUsuarios(struct Usuario usuario[], int qtdUsuarios);
void listarMusicas(struct Musica musicas[], int qtdMusicas);
void listarPlaylists(struct Usuario usuario[], int qtdUsuarios, struct Musica musicas[], int qtdMusicas);
char* buscarTituloMusica(struct Musica musicas[], int qtdMusicas, int codigo);

int main() {
    int tipoUsuario, contUsuarios = 0;
    int posicao_usuario = -1;
    struct Usuario usuario[TAM_MAX_USUARIOS];
    struct Musica musicas[TAM_MUSICAS];
    int qtdMusicas = 0;
    int logadoAdm = 0, logadoUsuario = 0;
    int sair = 0;  

    while (!sair) {
        do {
            printf("Como Deseja Logar?\n 1- Administrador\n 2- Usuário\n 3- Encerrar Programa\n");
            scanf("%d", &tipoUsuario);
            while (getchar() != '\n');
        } while (tipoUsuario < 1 || tipoUsuario > 3);

        if (tipoUsuario == 3) {
            sair = 1;
            continue;
        }

        if (tipoUsuario == 1) {
            int tentarNovamenteADM = 1;
            while (tentarNovamenteADM) {
                if (loginAdministrador()) {
                    logadoAdm = 1;
                    tentarNovamenteADM = 0; // Login bem-sucedido, sair do loop
                } else {
                    printf("O que Deseja?\n 1- Tentar Novamente\n 2- Mudar opção de Login\n");
                    scanf("%d", &tentarNovamenteADM);
                    while (getchar() != '\n');
                    if (tentarNovamenteADM == 2) {
                        break;
                    }
                }
            }
        } else {
            int opcao;
            int tentarNovamente;

            do {
                printf("Já possui um cadastro ou deseja cadastrar?\n 1- Logar\n 2- Cadastrar\n");
                scanf("%d", &opcao);
                while (getchar() != '\n');
            } while (opcao < 1 || opcao > 2);

            if (opcao == 1) {
                while (1) {
                    if (loginUsuario(usuario, &contUsuarios, &posicao_usuario)) {
                        printf("Login Bem Sucedido !!\n");
                        logadoUsuario = 1;
                        break;
                    } else {
                        printf("Login ou Senha inválida!!\n\n");
                        do {
                            printf("O que Deseja?\n 1- Tentar Novamente\n 2- Cadastrar Novo Usuário\n");
                            scanf("%d", &tentarNovamente);
                            while (getchar() != '\n');
                        } while (tentarNovamente < 1 || tentarNovamente > 2);

                        if (tentarNovamente == 1) {
                            continue;
                        } else {
                            cadastro(usuario, &contUsuarios, &posicao_usuario);
                            logadoUsuario = 1;
                            break;
                        }
                    }
                }
            } else {
                cadastro(usuario, &contUsuarios, &posicao_usuario);
                logadoUsuario = 1;
            }
        }
        
        while (logadoAdm) {
            int escolha;
            printf("Escolha uma ação:\n 1- Listar Usuários\n 2- Listar Músicas\n 3- Listar Playlists\n 4- Deslogar\n");
            scanf("%d", &escolha);
            while (getchar() != '\n');

            if (escolha == 1) {
                listarUsuarios(usuario, contUsuarios);
            } else if (escolha == 2) {
                listarMusicas(musicas, qtdMusicas);
            } else if (escolha == 3) {
                listarPlaylists(usuario, contUsuarios, musicas, qtdMusicas);
            } else if (escolha == 4) {
                logadoAdm = 0;
                break;
            } else {
                printf("Escolha inválida, tente novamente.\n");
            }
        }

        while (logadoUsuario) {
            // Placeholder para funcionalidades do usuário
            // Por agora, apenas desloga o usuário imediatamente
            logadoUsuario = 0;
        }
    }

    return 0;
}

void lerString(char *str, int maxTam) {
    fgets(str, maxTam, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

int loginAdministrador() {
    char senha[TAM_SENHA];
    char senhaAdm[TAM_SENHA] = "m@st3r2024";
    printf("-----------LOGIN ADM-----------\n \n");
    
    printf("Informe a senha para acessar como Administrador:\n");
    lerString(senha, TAM_SENHA);

    if (strcmp(senha, senhaAdm) == 0) {
        printf("Login como Administrador bem-sucedido!\n\n");
        return 1;
    } else {
        printf("Senha incorreta!\n\n");
        return 0;
    }
}

int loginUsuario(struct Usuario usuario[], int *contUsuarios, int *posicao) {
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int encontrado = 0;
    printf("-----------LOGIN-----------\n \n");
    printf("Digite seu Login: ");
    lerString(login, TAM_LOGIN);

    printf("Digite sua senha: ");
    lerString(senha, TAM_SENHA);

    for (int i = 0; i < *contUsuarios; i++) {
        if (strcmp(login, usuario[i].login) == 0 && strcmp(senha, usuario[i].senha) == 0) {
            encontrado = 1;
            *posicao = i;
            break;
        }
    }

    return encontrado;
}

void cadastro(struct Usuario usuario[], int *contUsuarios, int *posicao) {
    struct Usuario novoUsuario;
    char confirmarSenha[TAM_SENHA];

    printf("-----------CADASTRO-----------\n");

    printf("Informe seu Nome Completo: \n");
    lerString(novoUsuario.nome, TAM_NOME);

    printf("Informe o Login:\n");
    lerString(novoUsuario.login, TAM_LOGIN);

    do {
        printf("Informe a Senha:\n");
        lerString(novoUsuario.senha, TAM_SENHA);
        printf("Informe novamente a mesma senha:\n");
        lerString(confirmarSenha, TAM_SENHA);
        if (strcmp(novoUsuario.senha, confirmarSenha) != 0) {
            printf("Senhas diferentes!!\n");
        }
    } while (strcmp(novoUsuario.senha, confirmarSenha) != 0);

    novoUsuario.codigo = *contUsuarios + 1;
    novoUsuario.qtdPlaylists = 0;
    novoUsuario.qtdPlaylistsFav = 0;

    usuario[*contUsuarios] = novoUsuario;

    (*contUsuarios)++;
    *posicao = *contUsuarios - 1;

    printf("Cadastro realizado com sucesso!\n Conta Cadastrada foi Logada automaticamente.\n");
}

void listarUsuarios(struct Usuario usuario[], int qtdUsuarios) {
    printf("-----------LISTA DE USUÁRIOS-----------\n");
    for (int i = 0; i < qtdUsuarios; i++) {
        printf("Usuário %d:\n", i + 1);
        printf("Nome: %s\n", usuario[i].nome);
        printf("Login: %s\n", usuario[i].login);
        printf("Código: %d\n", usuario[i].codigo);
    }
}

void listarPlaylists(struct Usuario usuario[], int qtdUsuarios, struct Musica musicas[], int qtdMusicas) {
    printf("-----------LISTA DE PLAYLISTS-----------\n");
    for (int i = 0; i < qtdUsuarios; i++) {
        for (int j = 0; j < usuario[i].qtdPlaylists; j++) {
            printf("Usuário %d:\n", i + 1);
            printf("Código: %d\n", usuario[i].playlists[j].codigo);
            printf("Título: %s\n", usuario[i].playlists[j].titulo);
            printf("Nome do Criador: %s\n", usuario[i].nome);
            printf("Músicas:\n");
            for (int k = 0; k < usuario[i].playlists[j].qtdMusicas; k++) {
                char* titulo = buscarTituloMusica(musicas, qtdMusicas, usuario[i].playlists[j].musicas[k]);
                printf("%dª- %s\n", k + 1, titulo);
            }
            printf("\n");
        }
    }
}

char* buscarTituloMusica(struct Musica musicas[], int qtdMusicas, int codigo) {
    for (int i = 0; i < qtdMusicas; i++) {
        if (musicas[i].codigo == codigo) {
            return musicas[i].titulo;
        }
    }
    return "Música não encontrada";
}

void listarMusicas(struct Musica musicas[], int qtdMusicas) {
    printf("-----------LISTA DE MÚSICAS-----------\n");
    for (int i = 0; i < qtdMusicas; i++) {
        printf("----------Música %d----------\n", i + 1);
        printf("Código: %d\n", musicas[i].codigo);
        printf("Título: %s\n", musicas[i].titulo);
        printf("Artista: %s\n", musicas[i].artista);
    }
}
