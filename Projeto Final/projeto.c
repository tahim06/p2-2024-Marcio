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
int loginAdministrador();
int loginUsuario(struct Usuario usuario[], int *contUsuarios, int *posicao);
void cadastro(struct Usuario usuario[], int *contUsuarios, int *posicao);
void listarUsuarios(struct Usuario usuario[], int qtdUsuarios);
void listarMusicas(struct Musica musicas[], int qtdMusicas);
void listarPlaylists(struct Usuario usuario[], int qtdUsuarios, struct Musica musicas[], int qtdMusicas);
char *buscarTituloMusica(struct Musica musicas[], int qtdMusicas, int codigo);
void cadastrarMusicas(struct Musica musicas[], int *qtdMusicas);
void consultarUsuario(struct Usuario usuario[], int qtdUsuarios);
void ADM_alterarSenhaUsuario(struct Usuario usuario[],int qtdUsuarios);
void consultarMusica(struct Musica musicas[], int qtdMusicas);
void alterarDadosMusica(struct Musica musicas[], int qtdMusicas);
void consultarPlaylist(struct Usuario usuario[], int qtdUsuarios, struct Musica musicas[], int qtdMusicas);
void excluirMusica(struct Musica musicas[], int *qtdMusicas, struct Usuario usuarios[], int qtdUsuarios);
void dados_do_usuario_atual(struct Usuario usuario[], int posicao);
void alterarSenha_Usuario(struct Usuario usuario[], int posicao);
void alterarNome_Usuario(struct Usuario usuario[], int posicao);
void alterarLogin_Usuario(struct Usuario usuario[], int posicao);
void listarUsuarios_usuario(struct Usuario usuario[], int qtdUsuarios, int posicao);

int main()
{
    int tipoUsuario, contUsuarios = 0;
    int posicao_usuario = -1;
    struct Usuario usuario[TAM_MAX_USUARIOS];
    struct Musica musicas[TAM_MUSICAS];
    int qtdMusicas = 0;
    int logadoAdm = 0, logadoUsuario = 0;
    int sair = 0;

    while (!sair)
    {
        do
        {
            printf("Como Deseja Logar?\n 1- Administrador\n 2- Usuário\n 3- Encerrar Programa\n");
            scanf("%d", &tipoUsuario);
            while (getchar() != '\n');
             
        } while (tipoUsuario < 1 || tipoUsuario > 3);

        if (tipoUsuario == 3)
        {
            sair = 1;
            continue;
        }

        if (tipoUsuario == 1)
        {
            int tentarNovamenteADM = 1;
            while (tentarNovamenteADM)
            {
                if (loginAdministrador())
                {
                    logadoAdm = 1;
                    tentarNovamenteADM = 0;
                }
                else
                {
                    do
                    {
                        printf("O que Deseja?\n 1- Tentar Novamente\n 2- Mudar opção de Login\n");
                        scanf("%d", &tentarNovamenteADM);
                        while (getchar() != '\n')
                            ;
                    } while (tentarNovamenteADM < 1 || tentarNovamenteADM > 2);

                    if (tentarNovamenteADM == 2)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            int opcao;
            int tentarNovamente;

            do
            {
                
                printf("Já possui um cadastro ou deseja cadastrar?\n 1- Logar\n 2- Cadastrar\n");
                scanf("%d", &opcao);
                while (getchar() != '\n');

            } while (opcao < 1 || opcao > 2);

            if (opcao == 1)
            {
                while (1)
                {
                    if (loginUsuario(usuario, &contUsuarios, &posicao_usuario))
                    {
                        printf("Login Bem Sucedido !!\n");
                        logadoUsuario = 1;
                        break;
                    }
                    else
                    {
                        printf("Login ou Senha inválida!!\n\n");
                        do
                        {
                            printf("O que Deseja?\n 1- Tentar Novamente\n 2- Cadastrar Novo Usuário\n");
                            scanf("%d", &tentarNovamente);
                            while (getchar() != '\n')
                                ;
                        } while (tentarNovamente < 1 || tentarNovamente > 2);

                        if (tentarNovamente == 1)
                        {
                            continue;
                        }
                        else
                        {
                            cadastro(usuario, &contUsuarios, &posicao_usuario);
                            logadoUsuario = 1;
                            break;
                        }
                    }
                }
            }
            else
            {
                cadastro(usuario, &contUsuarios, &posicao_usuario);
                logadoUsuario = 1;
            }
        }

        int escolha;
        while (logadoAdm)
        {
            do
            {
                printf("Escolha uma ação:\n");
                printf("1- Listar Usuários\n");
                printf("2- Listar Músicas\n");
                printf("3- Listar Playlists\n");
                printf("4- Cadastrar Música\n");
                printf("5- Consultar um Usuário\n");
                printf("6- Alterar Senha de um Usuário\n");
                printf("7- Consultar uma Música\n");
                printf("8- Alterar Dados de Músicas Cadastradas\n");
                printf("9- Consultar Playlist\n");
                printf("10- Excluir Música Cadastrada\n");
                printf("11- Deslogar\n");

                scanf("%d", &escolha);
                while (getchar() != '\n')
                    ;
            } while (escolha < 1 || escolha > 11);

            if (escolha == 1)
            {
                listarUsuarios(usuario, contUsuarios);
            }
            else if (escolha == 2)
            {
                listarMusicas(musicas, qtdMusicas);
            }
            else if (escolha == 3)
            {
                listarPlaylists(usuario, contUsuarios, musicas, qtdMusicas);
            }
            else if (escolha == 4)
            {
                cadastrarMusicas(musicas, &qtdMusicas);
            }
            else if (escolha == 5){
                consultarUsuario(usuario,contUsuarios);
            }
            else if (escolha == 6)
            {
                ADM_alterarSenhaUsuario(usuario,contUsuarios);
            } 
            else if (escolha == 7)
            {
                consultarMusica(musicas,qtdMusicas);
            }
            else if (escolha == 8)
            {
                alterarDadosMusica(musicas,qtdMusicas);
            }
            else if (escolha == 9)
            {
                consultarPlaylist(usuario,contUsuarios,musicas,qtdMusicas);
            }
            else if(escolha == 10)
            {
                excluirMusica(musicas,&qtdMusicas,usuario,contUsuarios);
            }
            else
            {
                logadoAdm = 0;
                break;
            }
        }

        while (logadoUsuario)
        {
            do{
                printf("Escolha uma ação:\n");
                printf("1- Ver meus Dados \n");
                printf("2- Alterar Senha \n");
                printf("3- Alterar Nome de Usuário \n");
                printf("4- Alterar Login \n");
                printf("5- Listar Tods os Usuários \n");
                printf("6- \n");
                printf("7- \n");
                printf("8- \n");
                printf("9- \n");
                printf("10- \n");
                printf("11- Deslogar\n");
                scanf("%d", &escolha);
                while (getchar() != '\n');
            }while (escolha < 1 || escolha > 11);

            if(escolha == 11){
                logadoUsuario = 0;
                break;
            }
            else if(escolha == 1){
                dados_do_usuario_atual(usuario,posicao_usuario);
            }
            else if(escolha == 2){
                alterarSenha_Usuario(usuario,posicao_usuario);
            }
            else if(escolha == 3){
                alterarNome_Usuario(usuario,posicao_usuario);
            }
            else if(escolha == 4){
                alterarLogin_Usuario(usuario,posicao_usuario);
            }
            else if(escolha == 5){
                listarUsuarios_usuario(usuario,contUsuarios,posicao_usuario);
            }
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

int loginAdministrador()
{
    char senha[TAM_SENHA];
    char senhaAdm[TAM_SENHA] = "m@st3r2024";
    printf("-----------LOGIN ADM-----------\n \n");

    printf("Informe a senha para acessar como Administrador:\n");
    lerString(senha, TAM_SENHA);

    if (strcmp(senha, senhaAdm) == 0)
    {
        printf("Login como Administrador bem-sucedido!\n\n");
        return 1;
    }
    else
    {
        printf("Senha incorreta!\n\n");
        return 0;
    }
}

int loginUsuario(struct Usuario usuario[], int *contUsuarios, int *posicao)
{
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int encontrado = 0;
    printf("-----------LOGIN-----------\n \n");
    printf("Digite seu Login:\n ");
    lerString(login, TAM_LOGIN);

    printf("Digite sua senha:\n ");
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
    char confirmarSenha[TAM_SENHA];

    printf("-----------CADASTRO-----------\n");

    printf("Informe seu Nome Completo: \n");
    lerString(novoUsuario.nome, TAM_NOME);

    printf("Informe o Login:\n");
    lerString(novoUsuario.login, TAM_LOGIN);

    printf("\n");
    do
    {
        printf("Informe a Senha:\n");
        lerString(novoUsuario.senha, TAM_SENHA);
        printf("Informe novamente a mesma senha:\n");
        lerString(confirmarSenha, TAM_SENHA);
        
    } while (strcmp(novoUsuario.senha, confirmarSenha) != 0);

    novoUsuario.codigo = *contUsuarios + 1;
    novoUsuario.qtdPlaylists = 0;
    novoUsuario.qtdPlaylistsFav = 0;

    usuario[*contUsuarios] = novoUsuario;

    (*contUsuarios)++;
    *posicao = *contUsuarios - 1;

    printf("Cadastro realizado com sucesso!\n Conta Cadastrada foi Logada automaticamente.\n \n");
}

void listarUsuarios(struct Usuario usuario[], int qtdUsuarios)
{
    printf("-----------LISTA DE USUÁRIOS-----------\n");
    for (int i = 0; i < qtdUsuarios; i++)
    {
        printf("Usuário %d:\n", i + 1);
        printf("Nome: %s\n", usuario[i].nome);
        printf("Login: %s\n", usuario[i].login);
        printf("Código: %d\n", usuario[i].codigo);
    }
}

void listarPlaylists(struct Usuario usuario[], int qtdUsuarios, struct Musica musicas[], int qtdMusicas)
{
    printf("-----------LISTA DE PLAYLISTS-----------\n");
    for (int i = 0; i < qtdUsuarios; i++)
    {
        for (int j = 0; j < usuario[i].qtdPlaylists; j++)
        {
            printf("Usuário %d:\n", i + 1);
            printf("Código: %d\n", usuario[i].playlists[j].codigo);
            printf("Título: %s\n", usuario[i].playlists[j].titulo);
            printf("Nome do Criador: %s\n", usuario[i].nome);
            printf("Músicas:\n");
            for (int k = 0; k < usuario[i].playlists[j].qtdMusicas; k++)
            {
                char *titulo = buscarTituloMusica(musicas, qtdMusicas, usuario[i].playlists[j].musicas[k]);
                printf("%dª- %s\n", k + 1, titulo);
            }
            printf("\n");
        }
    }
}

char *buscarTituloMusica(struct Musica musicas[], int qtdMusicas, int codigo)
{
    for (int i = 0; i < qtdMusicas; i++)
    {
        if (musicas[i].codigo == codigo)
        {
            return musicas[i].titulo;
        }
    }
    return "Música não encontrada\n";
}

void listarMusicas(struct Musica musicas[], int qtdMusicas)
{
    printf("-----------LISTA DE MÚSICAS-----------\n");
    for (int i = 0; i < qtdMusicas; i++)
    {
        printf("----------Música %d----------\n", i + 1);
        printf("Código: %d\n", musicas[i].codigo);
        printf("Título: %s\n", musicas[i].titulo);
        printf("Artista: %s\n", musicas[i].artista);
    }
    printf("\n");
}

void cadastrarMusicas(struct Musica musicas[], int *qtdMusicas)
{
    int qtds = TAM_MAX_PLYLST;
    if (*qtdMusicas < qtds)
    {
        printf("Informe o Titulo da Música:\n");
        lerString(musicas[*qtdMusicas].titulo, TAM_NOME);
        printf("Informe o Nome do Artista:\n ");
        lerString(musicas[*qtdMusicas].artista, TAM_NOME);
        musicas[*qtdMusicas].codigo = *qtdMusicas + 1;
        *qtdMusicas += 1;
        printf("Música Cadastrada!!\n Código da Música: %d\n \n", *qtdMusicas);
    }
    else
    {
        printf("Não é possível adicionar mais músicas, lista de Músicas Cheia.\n Exclua alguma Música para cadastrar outra Música!!\n \n");
    }
}

void consultarUsuario(struct Usuario usuario[], int qtdUsuarios)
{
    int opcao;
    do
    {
        printf("Como deseja buscar o usuário?\n 1- Por código\n 2- Por login\n 3- Por parte do nome\n");
        scanf("%d", &opcao);
        while (getchar() != '\n')
            ;
    } while (opcao < 1 || opcao > 3);

    int encontrado = 0;

    if (opcao == 1)
    {
        int codigo;
        printf("Informe o código do usuário:\n ");
        scanf("%d", &codigo);
        while (getchar() != '\n')
            ;

        for (int i = 0; i < qtdUsuarios; i++)
        {
            if (usuario[i].codigo == codigo)
            {
                printf("-----------USUÁRIO ENCONTRADO-----------\n");
                printf("Nome: %s\n", usuario[i].nome);
                printf("Login: %s\n", usuario[i].login);
                printf("Código: %d\n", usuario[i].codigo);
                printf("Quantidade de Playlists: %d\n", usuario[i].qtdPlaylists);
                printf("Quantidade de Playlists Favoritadas: %d\n", usuario[i].qtdPlaylistsFav);
                printf("Código das Playlists Favoritadas: ");
                for (int j = 0; j < usuario[i].qtdPlaylistsFav; j++)
                {
                    printf("%d ", usuario[i].playlistsFav[j]);
                }
                printf("\n");
                encontrado = 1;
                
            }
        }
    }
    else if (opcao == 2)
    {
        char login[TAM_LOGIN];
        printf("Informe o login do usuário:\n ");
        lerString(login, TAM_LOGIN);

        for (int i = 0; i < qtdUsuarios; i++)
        {
            if (strcmp(usuario[i].login, login) == 0)
            {
                printf("-----------USUÁRIO ENCONTRADO-----------\n");
                printf("Nome: %s\n", usuario[i].nome);
                printf("Login: %s\n", usuario[i].login);
                printf("Código: %d\n", usuario[i].codigo);
                printf("Quantidade de Playlists: %d\n", usuario[i].qtdPlaylists);
                printf("Quantidade de Playlists Favoritadas: %d\n", usuario[i].qtdPlaylistsFav);
                printf("Código das Playlists Favoritadas: ");
                for (int j = 0; j < usuario[i].qtdPlaylistsFav; j++)
                {
                    printf("%d\n ", usuario[i].playlistsFav[j]);
                }
                printf("\n \n");
                encontrado = 1;
                
            }
        }
    }
    else if (opcao == 3)
    {
        char parteNome[TAM_NOME];
        printf("Informe parte do nome do usuário:\n ");
        lerString(parteNome, TAM_NOME);

        for (int i = 0; i < qtdUsuarios; i++)
        {
            if (strstr(usuario[i].nome, parteNome) != NULL)
            {
                printf("-----------USUÁRIO ENCONTRADO-----------\n");
                printf("Nome: %s\n", usuario[i].nome);
                printf("Login: %s\n", usuario[i].login);
                printf("Código: %d\n", usuario[i].codigo);
                printf("Quantidade de Playlists: %d\n", usuario[i].qtdPlaylists);
                printf("Quantidade de Playlists Favoritadas: %d\n", usuario[i].qtdPlaylistsFav);
                printf("Código das Playlists Favoritadas: ");
                for (int j = 0; j < usuario[i].qtdPlaylistsFav; j++)
                {
                    printf("%d\n ", usuario[i].playlistsFav[j]);
                }
                printf("\n");
                encontrado = 1;

            }
        }
    }

    if (!encontrado)
    {
        printf("Usuário não encontrado.\n \n");
    }
}

void ADM_alterarSenhaUsuario(struct Usuario usuario[],int qtdUsuarios){
    int codigo;
    int encontrado = 0, tentarNovamente = 1;
    int opcao, opcao2;
    char senha1[TAM_SENHA];
    char confirmarSenha[TAM_SENHA];

    while(tentarNovamente){
        printf("-----------ALTERANDO SENHA DE USUÁRIO-----------\n");
        printf("Informe o código do usuário:\n");
        scanf("%d", &codigo);
        while (getchar() != '\n');

        for (int i = 0; i < qtdUsuarios; i++){
            if (usuario[i].codigo == codigo){
                printf("-----------USUÁRIO ENCONTRADO!!-----------\n");
                printf("Nome: %s\n", usuario[i].nome);
                do{ 
                    printf("Deseja alterar a senha desse Usuário?\n 1- Sim\n 2- Não\n");
                    scanf("%d",&opcao);
                }while(opcao < 1 || opcao > 2);
            
                printf("\n");
                encontrado = 1;
                
                if(opcao == 1){
                    do{
                        printf("Informe a nova senha:\n");
                        lerString(senha1,TAM_SENHA);
                        printf("Informe novamente a nova senha:\n");
                        lerString(confirmarSenha,TAM_SENHA);
                        if(strcmp(senha1,confirmarSenha) != 0){
                            printf("Senhas diferentes, digite novamente!\n");
                        }
                    }while(strcmp(senha1,confirmarSenha) != 0);

                    strcpy(usuario[i].senha,senha1);
                    printf("Senha Atualizada com Sucesso!!\n \n");
                    tentarNovamente = 0;
                    break;
                }else{
                    printf("Senha não atualizada e operação finalizada!!\n \n");
                    printf("Deseja buscar outro Usuario?\n 1- Sim\n 2- Não\n");
                    scanf("%d", &opcao2);
                    if(opcao2 == 1){
                        tentarNovamente = 1;
                        break;
                    }
                    else{
                        tentarNovamente = 0;
                        break;
                    }
                }
                
            }
        }
        if (!encontrado)
        {
        printf("Usuário não encontrado.\n");
        }
    	
    }
}

void consultarMusica(struct Musica musicas[], int qtdMusicas) {
    int opcao;
    do {
        printf("Como deseja buscar a música?\n 1- Por código\n 2- Por parte do título\n 3- Por parte do nome do artista\n");
        scanf("%d", &opcao);
        while (getchar() != '\n');
    } while (opcao < 1 || opcao > 3);

    int encontrado = 0;

    if (opcao == 1) {
        int codigo;
        printf("Informe o código da música:\n ");
        scanf("%d", &codigo);
        while (getchar() != '\n');

        for (int i = 0; i < qtdMusicas; i++) {
            if (musicas[i].codigo == codigo) {
                printf("-----------MÚSICA ENCONTRADA-----------\n");
                printf("Título: %s\n", musicas[i].titulo);
                printf("Artista: %s\n", musicas[i].artista);
                printf("Código: %d\n", musicas[i].codigo);
                encontrado = 1;
            }
        }
        printf("\n");
    } else if (opcao == 2) {
        char parteTitulo[TAM_TITULO];
        printf("Informe parte do título da música:\n ");
        lerString(parteTitulo, TAM_TITULO);

        for (int i = 0; i < qtdMusicas; i++) {
            if (strstr(musicas[i].titulo, parteTitulo) != NULL) {
                printf("-----------MÚSICA ENCONTRADA-----------\n");
                printf("Título: %s\n", musicas[i].titulo);
                printf("Artista: %s\n", musicas[i].artista);
                printf("Código: %d\n", musicas[i].codigo);
                encontrado = 1;
            }
        }
        printf("\n");
    } else if (opcao == 3) {
        char parteArtista[TAM_NOME];
        printf("Informe parte do nome do artista:\n ");
        lerString(parteArtista, TAM_NOME);

        for (int i = 0; i < qtdMusicas; i++) {
            if (strstr(musicas[i].artista, parteArtista) != NULL) {
                printf("-----------MÚSICA ENCONTRADA-----------\n");
                printf("Título: %s\n", musicas[i].titulo);
                printf("Artista: %s\n", musicas[i].artista);
                printf("Código: %d\n", musicas[i].codigo);
                encontrado = 1;
            }
        }
        printf("\n");
    }

    if (!encontrado) {
        printf("Música não encontrada.\n \n");
    }
}

void alterarDadosMusica(struct Musica musicas[], int qtdMusicas)
{
    int codigo;
    int encontrado = 0, tentarNovamente = 1;
    int opcao;
    char novoTitulo[TAM_TITULO];
    char novoArtista[TAM_NOME];

    while (tentarNovamente)
    {
        printf("-----------ALTERANDO DADOS DE MÚSICA-----------\n");
        printf("Informe o código da música:\n");
        scanf("%d", &codigo);
        while (getchar() != '\n');

        for (int i = 0; i < qtdMusicas; i++)
        {
            if (musicas[i].codigo == codigo)
            {
                printf("-----------MÚSICA ENCONTRADA!!-----------\n");
                printf("Título atual: %s\n", musicas[i].titulo);
                printf("Artista atual: %s\n", musicas[i].artista);
                
                do
                {
                    printf("Deseja alterar o título da música?\n 1- Sim\n 2- Não\n");
                    scanf("%d", &opcao);
                } while (opcao < 1 || opcao > 2);

                if (opcao == 1)
                {
                    printf("Informe o novo título da música:\n");
                    lerString(novoTitulo, TAM_TITULO);
                    strcpy(musicas[i].titulo, novoTitulo);
                    printf("Título da música atualizado com sucesso!!\n \n");
                }

                do
                {
                    printf("Deseja alterar o artista da música?\n 1- Sim\n 2- Não\n");
                    scanf("%d", &opcao);
                } while (opcao < 1 || opcao > 2);

                if (opcao == 1)
                {
                    printf("Informe o novo nome do artista:\n");
                    lerString(novoArtista, TAM_NOME);
                    strcpy(musicas[i].artista, novoArtista);
                    printf("Artista da música atualizado com sucesso!!\n");
                }

                encontrado = 1;
                tentarNovamente = 0;
                break;
            }
        }

        if (!encontrado)
        {
            printf("Música não encontrada.\n");
            printf("Deseja buscar outra música?\n 1- Sim\n 2- Não\n");
            scanf("%d", &opcao);
            if (opcao != 1)
            {
                tentarNovamente = 0;
            }
        }
    }
}

void consultarPlaylist(struct Usuario usuario[], int qtdUsuarios, struct Musica musicas[], int qtdMusicas) {
    int opcao;
    do {
        printf("Como deseja buscar a playlist?\n 1- Por código da playlist\n 2- Por parte do título da playlist\n 3- Por código de música\n");
        scanf("%d", &opcao);
        while (getchar() != '\n');
    } while (opcao < 1 || opcao > 3);

    int encontrado = 0;

    if (opcao == 1) {
        int codigo;
        printf("Informe o código da playlist:\n ");
        scanf("%d", &codigo);
        while (getchar() != '\n');

        for (int i = 0; i < qtdUsuarios; i++) {
            for (int j = 0; j < usuario[i].qtdPlaylists; j++) {
                if (usuario[i].playlists[j].codigo == codigo) {
                    printf("-----------PLAYLIST ENCONTRADA-----------\n");
                    printf("Título: %s\n", usuario[i].playlists[j].titulo);
                    printf("Criador: %s\n", usuario[i].nome);
                    printf("Código: %d\n", usuario[i].playlists[j].codigo);
                    printf("Músicas:\n");
                    for (int k = 0; k < usuario[i].playlists[j].qtdMusicas; k++) {
                        char *titulo = buscarTituloMusica(musicas, qtdMusicas, usuario[i].playlists[j].musicas[k]);
                        if (titulo != NULL) {
                            printf("- %s\n", titulo);
                        }
                    }
                    encontrado = 1;
                }
            }
        }
        printf("\n");
    } else if (opcao == 2) {
        char parteTitulo[TAM_TITULO];
        printf("Informe parte do título da playlist: ");
        lerString(parteTitulo, TAM_TITULO);

        for (int i = 0; i < qtdUsuarios; i++) {
            for (int j = 0; j < usuario[i].qtdPlaylists; j++) {
                if (strstr(usuario[i].playlists[j].titulo, parteTitulo) != NULL) {
                    printf("-----------PLAYLIST ENCONTRADA-----------\n");
                    printf("Título: %s\n", usuario[i].playlists[j].titulo);
                    printf("Criador: %s\n", usuario[i].nome);
                    printf("Código: %d\n", usuario[i].playlists[j].codigo);
                    printf("Músicas:\n");
                    for (int k = 0; k < usuario[i].playlists[j].qtdMusicas; k++) {
                        char *titulo = buscarTituloMusica(musicas, qtdMusicas, usuario[i].playlists[j].musicas[k]);
                        if (titulo != NULL) {
                            printf("- %s\n", titulo);
                        }
                    }
                    encontrado = 1;
                }
            }
        }
        printf("\n");
    } else if (opcao == 3) {
        int codigoMusica;
        printf("Informe o código da música: ");
        scanf("%d", &codigoMusica);
        while (getchar() != '\n');

        for (int i = 0; i < qtdUsuarios; i++) {
            for (int j = 0; j < usuario[i].qtdPlaylists; j++) {
                for (int k = 0; k < usuario[i].playlists[j].qtdMusicas; k++) {
                    if (usuario[i].playlists[j].musicas[k] == codigoMusica) {
                        printf("-----------PLAYLIST ENCONTRADA-----------\n");
                        printf("Título: %s\n", usuario[i].playlists[j].titulo);
                        printf("Criador: %s\n", usuario[i].nome);
                        printf("Código: %d\n", usuario[i].playlists[j].codigo);
                        printf("Músicas:\n");
                        for (int l = 0; l < usuario[i].playlists[j].qtdMusicas; l++) {
                            char *titulo = buscarTituloMusica(musicas, qtdMusicas, usuario[i].playlists[j].musicas[l]);
                            if (titulo != NULL) {
                                printf("- %s\n", titulo);
                            }
                        }
                        encontrado = 1;
                    }
                }
            }
        }
        printf("\n");
    }

    if (!encontrado) {
        printf("Playlist não encontrada.\n \n");
    }
}

void excluirMusica(struct Musica musicas[], int *qtdMusicas, struct Usuario usuarios[], int qtdUsuarios) {
    int codigoMusica;
    int encontrado = 0;

    printf("Digite o código da música que deseja remover:\n ");
    scanf("%d", &codigoMusica);
    while (getchar() != '\n');

    for (int i = 0; i < *qtdMusicas; i++) {
        if (musicas[i].codigo == codigoMusica) {
            for (int j = i; j < *qtdMusicas - 1; j++) {
                musicas[j] = musicas[j + 1];
            }
            (*qtdMusicas)--;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Música com código %d não encontrada.\n", codigoMusica);
        return;
    }

    for (int i = 0; i < qtdUsuarios; i++) {
        for (int j = 0; j < usuarios[i].qtdPlaylists; j++) {
            int novaQtdMusicas = usuarios[i].playlists[j].qtdMusicas;

            for (int k = 0; k < usuarios[i].playlists[j].qtdMusicas; k++) {
                if (usuarios[i].playlists[j].musicas[k] == codigoMusica) {
                    for (int l = k; l < novaQtdMusicas - 1; l++) {
                        usuarios[i].playlists[j].musicas[l] = usuarios[i].playlists[j].musicas[l + 1];
                    }
                    usuarios[i].playlists[j].qtdMusicas--;
                    break;
                }
            }
        }
    }

    printf("Música removida com sucesso.\n \n");
}

void dados_do_usuario_atual(struct Usuario usuario[], int posicao)
{
    {
        printf("Nome: %s\n", usuario[posicao].nome);
        printf("Login: %s\n", usuario[posicao].login);
        printf("Código: %d\n", usuario[posicao].codigo);
    }
}

void alterarSenha_Usuario(struct Usuario usuario[], int posicao) {
    int tentarNovamente = 1;
    int opcao, opcao2;
    char senha[TAM_SENHA];
    char senha1[TAM_SENHA];
    char confirmarSenha[TAM_SENHA];

    while (tentarNovamente) {
        printf("-----------ALTERANDO SENHA DE USUÁRIO-----------\n");

        do {
            printf("Deseja alterar a senha desse Usuário?\n 1- Sim\n 2- Não\n");
            scanf("%d", &opcao);
            while (getchar() != '\n');
        } while (opcao < 1 || opcao > 2);

        printf("\n");

        if (opcao == 1) {
            printf("Digite sua senha atual:\n");
            lerString(senha, TAM_SENHA);
            if (strcmp(senha, usuario[posicao].senha) == 0) {
                do {
                    printf("Informe a nova senha:\n");
                    lerString(senha1, TAM_SENHA);
                    printf("Informe novamente a nova senha:\n");
                    lerString(confirmarSenha, TAM_SENHA);
                } while (strcmp(senha1, confirmarSenha) != 0);

                strcpy(usuario[posicao].senha, senha1);
                printf("Senha Atualizada com Sucesso!!\n \n");
                tentarNovamente = 0;
            } else {
                do {
                    printf("Senha Incorreta!!\n Deseja Tentar Novamente?\n 1- Sim\n 2- Não\n");
                    scanf("%d", &opcao2);
                    while (getchar() != '\n');
                } while (opcao2 < 1 || opcao2 > 2);
                if (opcao2 == 2) {
                    printf("Senha não atualizada e operação finalizada!!\n \n");
                    tentarNovamente = 0;
                }else{
                    tentarNovamente = 1;
                }
            }
        } else {
            printf("Senha não atualizada e operação finalizada!!\n \n");
            tentarNovamente = 0;
        }
    }
}

void alterarNome_Usuario(struct Usuario usuario[], int posicao) {
    int tentarNovamente = 1;
    int opcao, opcao2;
    char senha[TAM_SENHA];
    char novoNome[TAM_NOME];

    while (tentarNovamente) {
        printf("-----------ALTERANDO NOME DE USUÁRIO-----------\n");

        do {
            printf("Deseja alterar o nome desse Usuário?\n 1- Sim\n 2- Não\n");
            scanf("%d", &opcao);
            while (getchar() != '\n'); 
        } while (opcao < 1 || opcao > 2);

        printf("\n");

        if (opcao == 1) {
            printf("Digite sua senha atual:\n");
            lerString(senha, TAM_SENHA);
            if (strcmp(senha, usuario[posicao].senha) == 0) {
                printf("Informe o novo nome:\n");
                lerString(novoNome, TAM_NOME);

                strcpy(usuario[posicao].nome, novoNome);
                printf("Nome Atualizado com Sucesso!!\n \n");
                tentarNovamente = 0;
            } else {
                do {
                    printf("Senha Incorreta!!\n Deseja Tentar Novamente?\n 1- Sim\n 2- Não\n");
                    scanf("%d", &opcao2);
                    while (getchar() != '\n'); 
                } while (opcao2 < 1 || opcao2 > 2);
                if (opcao2 == 2) {
                    printf("Nome não atualizado e operação finalizada!!\n \n");
                    tentarNovamente = 0;
                }else{
                    tentarNovamente = 1;
                }
            }
        } else {
            printf("Nome não atualizado e operação finalizada!!\n \n");
            tentarNovamente = 0;
        }
    }
}

void alterarLogin_Usuario(struct Usuario usuario[], int posicao) {
    int tentarNovamente = 1;
    int opcao, opcao2;
    char senha[TAM_SENHA];
    char novoLogin[TAM_LOGIN];

    while (tentarNovamente) {
        printf("-----------ALTERANDO LOGIN DE USUÁRIO-----------\n");

        do {
            printf("Deseja alterar o login desse Usuário?\n 1- Sim\n 2- Não\n");
            scanf("%d", &opcao);
            while (getchar() != '\n'); 
        } while (opcao < 1 || opcao > 2);

        printf("\n");

        if (opcao == 1) {
            printf("Digite sua senha atual:\n");
            lerString(senha, TAM_SENHA);
            if (strcmp(senha, usuario[posicao].senha) == 0) {
                printf("Informe o novo login:\n");
                lerString(novoLogin, TAM_LOGIN);

                strcpy(usuario[posicao].login, novoLogin);
                printf("Login Atualizado com Sucesso!!\n \n");
                tentarNovamente = 0;
            } else {
                do {
                    printf("Senha Incorreta!!\n Deseja Tentar Novamente?\n 1- Sim\n 2- Não\n");
                    scanf("%d", &opcao2);
                    while (getchar() != '\n'); 
                } while (opcao2 < 1 || opcao2 > 2);
                if (opcao2 == 2) {
                    printf("Login não atualizado e operação finalizada!!\n \n");
                    tentarNovamente = 0;
                }else{
                    tentarNovamente = 1;
                }
            }
        } else {
            printf("Login não atualizado e operação finalizada!!\n \n");
            tentarNovamente = 0;
        }
    }
}
        
void listarUsuarios_usuario(struct Usuario usuario[], int qtdUsuarios, int posicao)
{
    printf("-----------LISTA DE USUÁRIOS-----------\n");
    for (int i = 0; i < qtdUsuarios; i++)
    {
        if(i == posicao){
            i++;
        }
        printf("Usuário %d:\n", i + 1);
        printf("Nome: %s\n \n", usuario[i].nome);
    }
}