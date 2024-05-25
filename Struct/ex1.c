#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ESTADOS 2
#define TAM_TEXTO 61

struct infoEstados{
    char nome[TAM_TEXTO];
    int qtdVeiculos;
    int qtdAcidentes;
};

void solicitarDados(struct infoEstados *estado[], int qtdEstados,int tamTexto);
void maior_menor_qtdAcidentes(struct infoEstados *estado[], int qtdEstados,int *maior, int *menor);


int main(){
    struct infoEstados estados[ESTADOS];
    solicitarDados(estados,ESTADOS,TAM_TEXTO);

    int indice_maior, indice_menor;

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
        
        while(getchar() != '\n');
    }
} 

void maior_menor_qtdAcidentes(struct infoEstados *estado[], int qtdEstados,int *maior, int *menor){
    *maior = 0;
    *menor = 0;
    
    for(int i = 0; i < qtdEstados;i++){
        if(estado[i]->qtdAcidentes > estado[*maior]->qtdAcidentes){
            *maior = i;
        }
        else if(estado[i]->qtdAcidentes < estado[*menor]->qtdAcidentes){
            *menor = i;
        }
    }
}

