#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 80

int isVogal(char );

int main(){
    char frase[TAM];

    scanf("%[^\n]", frase);
    int tamReal = strlen(frase);

    int cont = 0;
    for(int i = 0; i < tamReal+1; i++){
        if (isVogal(frase[i])){
            cont += 1;
            frase[i] = '*';
        }
    }

    printf("%s\n", frase);
    printf("Possui %d Vogais.\n", cont);
    return 0;
}

int isVogal(char c){
    char minusculo = tolower(c);
    char letras[5] = {'a','e','i','o','u'};

    for (int i = 0; i < 5; i++){
        if (minusculo == letras[i]){
            return 1;
        }
    }

    return 0; 
}