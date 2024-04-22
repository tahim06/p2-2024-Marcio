#include <stdio.h>
#include <stdlib.h>

int main(){
    float M[12][12];
    int L;
    char T;
        
    scanf("%d",&L);
    while(L < 0 || L > 11){
        scanf("%d",&L);
    }

    scanf(" %c",&T);
    while(T != 'S' && T!= 's' && T!= 'M' && T!= 'm'){
        scanf(" %c",&T);
    }

    for(int j = 0; j < 12; j++){
        scanf("%f",&M[L][j]);
    }
    

    if(T == 'S' || T == 's'){
        float soma = 0;
        for(int j = 0; j < 12; j++){
            soma += M[L][j];
        }
        printf("%f",soma);
    }else{
        int cont = 12;
        float soma = 0;
        for(int j = 0; j < 12; j++){
            soma += M[L][j];
        }
        float media = soma/cont;
        printf("%f",media);
    }

    return 0;
}
