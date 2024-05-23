#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALUNOS 2
#define COLUNAS 80

struct notasAlunos{
    char nomeAluno[COLUNAS];
    double primNota;
    double segNota;
    double media;
};

int passou(double media);
void lerString(char *str, int maxTam);

int main(){
    struct notasAlunos alunos[ALUNOS]; 

    for(int i = 0 ; i < ALUNOS; i++){
        printf("Informe o nome do %d aluno:\n", i + 1);
        lerString(alunos[i].nomeAluno,COLUNAS);

        printf("Informe a primeira nota do aluno %s:\n", alunos[i].nomeAluno);
        scanf("%lf", &alunos[i].primNota);
        
        printf("Informe a segunda nota do aluno %s:\n", alunos[i].nomeAluno);
        scanf("%lf", &alunos[i].segNota);
        getchar(); 
    }
    
    double somaMedia = 0;
    for(int i = 0; i < ALUNOS; i++){
        alunos[i].media = ((alunos[i].primNota * 2) + (alunos[i].segNota * 3)) / 5;
        if(passou(alunos[i].media)){
            printf("O aluno %s obteve média %lf e foi Aprovado.\n", alunos[i].nomeAluno, alunos[i].media);
        }else{
            printf("O aluno %s obteve média %lf e foi Reprovado.\n", alunos[i].nomeAluno, alunos[i].media);
        }
        somaMedia += alunos[i].media;
    }
    double mediaTurma = somaMedia/ALUNOS;
    
    int abaixoMediaTurma = 0;
    char abaixoTurma[ALUNOS][COLUNAS];

    for(int i = 0;  i < ALUNOS; i++){
        if (alunos[i].media < mediaTurma){
            abaixoMediaTurma+=1;
        }  
    }
    printf("%d Aluno(s) ficaram abaixo da média, Nomes:\n ",abaixoMediaTurma);
    for(int i = 0;  i < ALUNOS; i++){
        if (alunos[i].media < mediaTurma){
                printf("%s\n", alunos[i].nomeAluno);
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

void lerString(char *str, int maxTam) {
    fgets(str, maxTam, stdin);
    int tam = strlen(str);
    if (str[tam - 1] == '\n') {
      str[tam - 1] = '\0';
    }
}