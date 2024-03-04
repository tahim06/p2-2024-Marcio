#include <stdio.h>

int main(){
    int n;
    printf("Informe a quantidade de valores para os conjunto de valores: ");
    scanf("%d",&n);
    printf("\n");

    int vetor1[n],vetor2[n];
    
    for(int i = 0; i < n; i++){
        printf("Informe o %dº número do primeiro conjunto de valores:\n ", i + 1);
        scanf("%d",&vetor1[i]);
    } printf("\n");
    
    for(int i = 0; i < n; i++){
        printf("Informe o %dº número do segundo conjunto de valores: ", i + 1);
        scanf("%d",&vetor2[i]);
    } printf("\n");
    int vetorSoma[n];
    
    for(int i = 0; i < n; i++){
        vetorSoma[i] = vetor1[i] + vetor2[i];
        printf("A soma da %d posição dos Vetores é: %d\n", i + 1, vetorSoma[i]);
    } printf("\n");

    return 0;
}