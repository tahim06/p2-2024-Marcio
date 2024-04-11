#include <stdio.h>
#define TAM 30

int main(){
    char nome[TAM];
    printf("Digite seu Nome: ");
    printf("\n");

    fgets(nome,TAM,stdin);
    printf("\n");

    int count = 0,i = 0;
    while(1){
        if(nome[i] != "\0"){
            count++;
        }else{
            break;
        }
    }

    printf("%s",nome);
    printf("%d caracteres",count);
    return 0;
}