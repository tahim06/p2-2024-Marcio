#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtd = 15;
    int v[qtd],atual;
    
    for(int i = 1; i < qtd; i++){
        atual = v[i];
        int j = i-1;
        while(j>=0 && atual < v[j]){
            v[j+1] = v[j];
            j = j-1;
        } 
        v[j+1] = atual;
    }


    return 0;
}