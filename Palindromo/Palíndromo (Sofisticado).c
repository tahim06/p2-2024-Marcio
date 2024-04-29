#include <stdio.h>
#include <string.h>
#define TAM 51

int isPalindromo(char frase[]);

int main() {
    char frase[TAM];
    do {
        printf("Digite uma Frase com até %d caracteres: ", TAM - 1);
        scanf(" %[^\n]", frase);
    } while (strlen(frase) < 1 || strlen(frase) >= TAM);
    
    if (isPalindromo(frase)) {
        printf("A palavra %s é palíndromo.\n", frase);
    } else {
        printf("A palavra %s não é palíndromo.\n", frase);
    }

    return 0;
}

int isPalindromo(char frase[]) {
    int tamReal = strlen(frase);
    char frase2[tamReal + 1];

    int j = 0, k = 0;
    for (int i = tamReal - 1; i >= 0; i--) {
        if (frase[i] != ' ') {
            frase2[j++] = frase[i];
        }
        if (frase[k] != ' ') {
            frase[k++] = frase[k];
        }
    }
    frase[j+1] = '\0';
    frase2[j+1] = '\0';

    return strcmp(frase2, frase) == 0;
}


