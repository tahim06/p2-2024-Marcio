#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtd = 5;
    int v[qtd],atual;
    for(int i = 0; i < qtd; i++){
        scanf("%d",&v[i]);
    }
    
    for(int i = 1; i < qtd; i++){
        atual = v[i];
        int j = i-1;
        while(j >= 0 && atual < v[j]){
            v[j+1] = v[j];
            j = j-1;
        } 
        v[j+1] = atual;
    }
    
    for(int i = 0; i < qtd; i++){
        printf("%d\n",v[i]);
    }
    
    return 0;
}