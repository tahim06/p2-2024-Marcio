#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10

void preencherMatriz(int matriz[][COLUNAS], int linhas, int colunas);
void zerarDiagonalPrincipal(int matriz[][COLUNAS],int ordem);
void zerarDiagonalSecundaria(int matriz[][COLUNAS],int ordem);
void printMatriz(int matriz[][COLUNAS], int linhas, int colunas);

int main(){
    int linhas,colunas;
    int matriz[LINHAS][COLUNAS];

    printf("Informe a quantidade de Linhas da Matriz : ");
    scanf("%d",&linhas);
    printf("\n");

    printf("Informe a quantidade de colunas da Matriz : ");
    scanf("%d",&colunas);
    printf("\n");

    preencherMatriz(matriz,linhas,colunas);
    zerarDiagonalPrincipal(matriz,linhas);
    //zerarDiagonalSecundaria(matriz, linhas);
    printMatriz(matriz,linhas,colunas);

    printf("\n");

    return 0;
}

void preencherMatriz(int matriz[][COLUNAS], int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("Informe o valor da posição Matriz[%d][%d]: ",i+1, j+1);
            scanf("%d",&matriz[i][j]);
        }        
    }

}

void zerarDiagonalSecundaria(int matriz[][COLUNAS],int ordem){
    for(int i = 1; i < ordem; i++){
        for(int j = ordem - i; j < ordem; j++){
            matriz[i][j] = 0;
        }

    }
}

void zerarDiagonalPrincipal(int matriz[][COLUNAS],int ordem){
    for(int i = 1; i < ordem; i++){
        for(int j = 0; j < i; j++){
            matriz[i][j] = 0;
        }

    }
}

void printMatriz(int matriz[][COLUNAS], int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(j == 0){
                printf("%d", matriz[i][j]);
            }
            else if(j == colunas - 1){
                printf(" %d\n", matriz[i][j]);
            }else{
                printf(" %d", matriz[i][j]);
            }
        }
    }

}