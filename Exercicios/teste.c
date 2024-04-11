#include <stdio.h>
#define TAM 5

void preencherVetor(int v[],int tam);
void quantidade(int v[],int tam);

int main(){
    int v[TAM];
    
    preencherVetor(v,TAM);
    quantidade(v,TAM);

    return 0;
}

void preencherVetor(int v[],int tam){
    for(int i = 0; i < tam; i++){
        printf("Informe o valor da Posição %d do Vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void quantidade(int v[],int tam){
    for(int i = 0; i < 10; i++){
        int qtd = 0;
        for(int j = 0; j < tam; j++){
            if(v[j] % i == 0){
                qtd += 1;
            }
            printf("Quantidade de números que terminam em %d = %d\n",i,qtd);
        }
    }
}