#include <stdio.h>
#include <string.h>
#define TAM 51

void removerEspaco(char frase[]);
int isPalindromo(char frase[]);

int main() {
    char frase[TAM];
    do {
        printf("Digite uma Frase com até %d caracteres: ", TAM - 1);
        scanf(" %[^\n]", frase);
    } while (strlen(frase) < 1 || strlen(frase) >= TAM);
    
    removerEspaco(frase);

    if (isPalindromo(frase)) {
        printf("É palíndromo.\n", frase);
    } else {
        printf("Não é palíndromo.\n", frase);
    }

    return 0;
}

void removerEspaco(char frase[]) {
    int count = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ') {
            frase[count] = frase[i];
            count++;
        }
    }
    frase[count] = '\0';
}

int isPalindromo(char frase[]) {
    int tamReal = strlen(frase),j = 0;
    char frase2[tamReal + 1];

    for (int i = tamReal - 1; i >= 0; i--) {
        frase2[j] = frase[i];
        j++;
    }
    frase2[tamReal] = '\0';  

    return strcmp(frase2, frase) == 0;
}
