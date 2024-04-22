#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 80

int isVogal(char );

int main(){
    char frase[TAM];

    scanf("%[^\n]", frase);
    int tamReal = strlen(frase);


    for(int i = 0; i < tamReal+1; i++){
        if (isVogal(frase[i])){
            frase[i] = '*';
        }
    }

    printf("%s\n", frase);
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
