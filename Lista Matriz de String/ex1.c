#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALUNOS 2
#define COLUNAS 80

int passou(double media);

int main(){
    char nomeAluno[ALUNOS][COLUNAS];
    double primNota[ALUNOS],segNota[ALUNOS],media[ALUNOS];

    for(int i = 0 ; i < ALUNOS; i++){
        printf("Informe o nome do %d aluno:\n", i + 1);
        fgets(nomeAluno[i], COLUNAS, stdin);
        int tam = strlen(nomeAluno[i]);
        if (nomeAluno[i][tam - 1] == '\n') 
            nomeAluno[i][tam - 1] = '\0';  

        printf("Informe a primeira nota do aluno %s: ", nomeAluno[i]);
        scanf("%lf", &primNota[i]);
        
        printf("Informe a segunda nota do aluno %s: ", nomeAluno[i]);
        scanf("%lf", &segNota[i]);
        getchar(); 
    }

    for(int i = 0; i < ALUNOS; i++){
        media[i] = ((primNota[i] * 2) + (segNota[i] * 3)) / 5;
        if(passou(media[i])){
            printf("O aluno %s obteve média %lf e foi Aprovado.\n", nomeAluno[i], media[i]);
        }else{
            printf("O aluno %s obteve média %lf e foi Reprovado.\n", nomeAluno[i], media[i]);
        }
    }

    return 0;
}

int passou(double media){
    int aprovado = 0;
    if(media >= 7){
        aprovado = 1;
    }
    return aprovado;       
}
