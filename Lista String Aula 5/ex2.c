#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 80

int isVogal(char );

int main(){
    char frase[TAM];

    scanf("%[^\n]", frase);
    int tamReal = strlen(frase);
    char aux;

    for(int i = 0; i < (tamReal+1)/2; i++){
        aux = frase[i];
        frase[i] = frase[tamReal-1-i];
        frase[tamReal-1-i] = aux;
    }

    printf("%s\n", frase);
    return 0;
}

