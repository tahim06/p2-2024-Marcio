#include <stdio.h>

int main(){
    
    int size1,size2;
    
    printf("Digite o tamanho do 1º Vetor: ");
    scanf("%d",&size1);
    
    printf("Digite o tamanho do 2º Vetor: ");
    scanf("%d",&size1);

    int vetor1[size1], vetor2[size2];

    for(int i = 0; i < size1; i++){
        printf("Digite o %dº valor do Vetor 1: ", i+1);
        scanf("%d",&vetor1[i]);
        printf("\n");

        if(i != 0){
            for(int j = 0; j < i; j++){
                while(vetor1[j] == vetor1[i]){
                    printf("Este valor já foi digitado, por favor digite outro valor para a %dª posição do Vetor1: ", i+1);
                    scanf("%d",&vetor1[i]);
                    printf("\n");
                }
   
            }

        }
        
    }

    for(int i = 0; i < size2; i++){
        printf("Digite o %dº valor do Vetor 2: ", i+1);
        scanf("%d",&vetor2[i]);
        printf("\n");

        if(i != 0){
            for(int j = 0; j < i; j++){
                while(vetor2[j] == vetor2[i]){
                    printf("Este valor já foi digitado, por favor digite outro valor para a %dª posição do Vetor1: ", i+1);
                    scanf("%d",&vetor2[i]);
                    printf("\n");
                }
   
            }

        }
        
    }
    


    return 0;
}