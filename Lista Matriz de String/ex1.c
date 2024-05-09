#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LINHAS 20
#define COLUNAS 80

int main(){
    char nomeAluno[LINHAS][COLUNAS];
    double primNota[LINHAS],segNota[LINHAS],media[LINHAS];

    for(int i = 0 ; i < LINHAS; i++){
        printf("Informe o nome do %d aluno: ", i + 1);
        fgets(nomeAluno[i],COLUNAS,stdin);
        
        printf("Informe a primeira nota do aluno %s: ", nomeAluno[i]);
        scanf("%lf",&primNota[i]);
        
        printf("Informe a segunda nota do aluno %s: ", nomeAluno[i]);
        scanf("%lf",&segNota[i]);
    }

    for(int i = 0; i < LINHAS; i++){
        media[i] = ((primNota[i] * 2) + (segNota[i] * 3)) / 5;
    }

    for(int i = 0; i < LINHAS; i++){
        int passado = 0;
        if(media[i] >= 7){
            
        }
    }


    return 0;
}