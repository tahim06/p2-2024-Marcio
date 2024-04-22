#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 80

int main(){
    char frase[TAM-1];
    int tamReal = strlen(frase);

    fgets(frase,TAM,stdin);
    frase[tamReal -1] = '\0';

    isVogal(frase);


    return 0;
}

int isVogal(char c){
    char minusculo = tolower(c);
    char letras[5] = {'a','e','i','o','u'};

    for(int i = 0; i < 5; i++){
        if(strcmp(c,letras[i]) == 1){
            return 1;
            break;
        }
        else if(strcmp(c,letras[i]) != 1 && i < 5){
            continue;
        }else{
            break;
        }

    }

}
