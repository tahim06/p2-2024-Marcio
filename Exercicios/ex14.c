#include <stdio.h>
#include <stdlib.h>
#define COLUNAS 21 


void calcularMedia(double notas[][COLUNAS],double pesos[COLUNAS],int qtdAlunos,int qtdNotas);

int main(){
    int linhas,colunas;

    printf("Digite a quantidade de alunos: ");
    scanf("%d",&linhas);

    printf("Digite a quantidade de notas a serem lançadas: ");
    scanf("%d",&colunas);

    double notas[linhas][colunas+1];
    int pesos[colunas];

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("Digite a nota do %dº aluno na %dª prova: da ", i+1,j+1);
            scanf("%lf", &notas[i][j]);
        }

    }

    for(int i = 0; i < colunas; i++){
        printf("Digite o peso da %dª Prova: ");
        scanf("%d",&pesos[i]);
    }


    return 0;
}

void calcularMedia(double notas[][COLUNAS],double pesos[COLUNAS],int qtdAlunos,int qtdNotas){
    double somaPesos, somaNotas;
    
    for(int i = 0;i < qtdNotas; i++){
        somaPesos += pesos[qtdNotas];
    }

    for(int i = 0; i < qtdAlunos;i++){
       double media = 0;
       double somaNotas = 0;
        for(int j = 0; j < qtdNotas;i++){
            somaNotas += notas[qtdAlunos][qtdNotas];     
            if(j = qtdAlunos - 1){
                
            }
        }
    }

}