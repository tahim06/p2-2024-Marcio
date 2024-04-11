#include <stdio.h>
#include <string.h>
#define TAM 50


int main(){
    char s1[TAM];
    printf("Digite uma string: ");
    fgets(s1,TAM,stdin);

    int tamReal = strlen(s1);
    int j = 0;
    char reverso[tamReal];

    for(int i = tamReal ; i >= 0 ; i--){
        reverso[j] = s1[i];
        j++;
    }
    puts(reverso);
    
    
    return 0;
}