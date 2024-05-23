#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ESTADOS 2
#define TAM_TEXTO 61

void lerString(char *str);
void solicitarDados(struct infoEstados *estado[], int qtdEstados,int tamTexto);

struct infoEstados{
    char nome[TAM_TEXTO];
    int qtdVeiculos;
    int qtdAcidentes;
};


int main(){
    struct infoEstados estados[ESTADOS];
    solicitarDados(&estados,ESTADOS,TAM_TEXTO);

    return 0;
}

void solicitarDados(struct infoEstados *estado[], int qtdEstados,int tamTexto){
    for(int i = 0; i < qtdEstados;i++){
        printf("Informe o nome do %d estado:\n ", i+1);
        fgets(estado[i]->nome,tamTexto,stdin);

        printf("Informe quantos veículos circulam em %s:\n ", estado[i]->nome);
        scanf("%d",&estado[i]->qtdVeiculos);

        printf("Informe quantos acidentes de trânsito tiveram em %s: ", estado[i]->nome);
        scanf("%d",&estado[i]->qtdAcidentes);
        
        lerString(&estado[i]->nome);
    }
}

void lerString(char *str){
    int tam = strlen(str);
    if(str[tam - 1] == '\n'){
        str[tam - 1] = '\0';
    }
}