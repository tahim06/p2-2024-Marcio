#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10

void preencherMatriz(int matriz[][COLUNAS],int linhas, int colunas);
int matrizEscada(int matriz[][COLUNAS],int linhas,int colunas);

int main(){
    int linha,coluna;
    int matriz[LINHAS][COLUNAS];

    printf("Informe a quantidade de linhas da matriz: ");
    scanf("%d",&linha);

    printf("Informe a quantidade de colunas da matriz: ");
    scanf("%d",&coluna);

    preencherMatriz(matriz,linha,coluna);

    if(matrizEscada(matriz,linha,coluna)){
        printf("É Escada\n");
    }else{
        printf("Não é Escada\n");
    }

}

void preencherMatriz(int matriz[][COLUNAS],int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%d",&matriz[i][j]);
        }
    }
}

int matrizEscada(int matriz[][COLUNAS],int linhas,int colunas){
    int i, j, ehEscada = 1, primeiroNaoNulo = -1;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(matriz[i][j] != 0){
                if(j <= primeiroNaoNulo){  
                    ehEscada = 0;

                }else{
                    primeiroNaoNulo = j;
                }
                break;
            }
        }
        if(!ehEscada){
            break;
        }
        if(j == colunas){
            primeiroNaoNulo = j;
        }
        
    }
    return ehEscada;
}

