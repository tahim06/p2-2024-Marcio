#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ESTADOS 26
#define TAM_TEXTO 61

struct infoEstados{
    char nome[TAM_TEXTO];
    int qtdVeiculos;
    int qtdAcidentes;
};
void solicitarDados(struct infoEstados *estado[], int qtdEstados,int tamTexto);

void maior_menor_qtdAcidentes(struct infoEstados *estado[], int qtdEstados,int *maior, int *menor);

double  percentual(struct infoEstados estado);

int main(){
    struct infoEstados estados[ESTADOS];
    solicitarDados(estados,ESTADOS,TAM_TEXTO);

    int indice_maior, indice_menor;
    maior_menor_qtdAcidentes(estados,ESTADOS, &indice_maior, &indice_menor);
    prinf("O estado com mais acidentes é %s e o com menos é %s.\n",estados[indice_maior].nome, 
    estados[indice_menor].nome);

    for(int i = 0; i < ESTADOS; i++){
       double per = percentual(estados[i]);
        printf("O Percentual de Veículos envolvidos em acidente em %s é : %lf% ", estados[i].nome, per);
    }
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

double  percentual(struct infoEstados estado){
    if(estado.qtdVeiculos == 0){
        return 0.0;
    }
    
    return((double)estado.qtdAcidentes/estado.qtdVeiculos * 100);

    
}
