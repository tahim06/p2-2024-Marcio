#include <stdio.h>
#include <math.h>

int main(){
    
    int size1,size2;
    
    //pega o tam dos vetores 
    printf("Digite o tamanho do 1º Vetor: ");
    scanf("%d",&size1);
    
    printf("Digite o tamanho do 2º Vetor: ");
    scanf("%d",&size2);

    int vetor1[size1], vetor2[size2];

   //Preenche e garante que não tenha números repetidos no vetor1
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
    
    //Preenche e garante que não tenha números repetidos no vetor2
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

    int sizeUniao = size1 + size2;
    
    //Cria a União dos dois Vetores anteriores
    int vetorUniao[sizeUniao];
    int tamRealUniao = 0;

    for(int i = 0; i < size1; i++){
        vetorUniao[i] = vetor1[i];  
        tamRealUniao += 1;
    }
    
    for(int i = 0; i < size2; i++){
        int repetido = 0;
        for(int j = 0; j < size1; j++){
            if(vetor2[i] == vetor1[j]){
                repetido = 1;
                break;
            }
        }
        if(repetido == 0){
            vetorUniao[tamRealUniao++] = vetor2[i];
        }
    }
   
    //interseção dos dois conjuntos
    int vetorIntersecao[sizeUniao];
    int tamRealIntersecao = 0;

   
    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            if(vetor1[i] == vetor2[j]) {
                vetorIntersecao[tamRealIntersecao++] = vetor1[i];
                break;  
            }
        }
    }
       
   
   //print do vetorUniao
    for(int i = 0; i < tamRealUniao; i++){
       if(i == 0){
            printf("[");
            printf("%d",vetorUniao[i]);
       }else{
            printf(", %d",vetorUniao[i]);
       }
    }printf("]\n");

    //Print do vetorIntersecao
    for(int i = 0; i < tamRealIntersecao; i++){
       if(i == 0){
            printf("[");
            printf("%d",vetorIntersecao[i]);
       }else{
            printf(", %d",vetorIntersecao[i]);
       }
    }printf("]");
    
    printf("\n");

    return 0;
}


