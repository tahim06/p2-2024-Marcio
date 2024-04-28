#include <stdio.h>
#include <string.h>
#define TAM 51

void removerEspaco(char frase[]);

int main() {
    char frase[TAM];
    do {
        printf("Digite uma Frase com até %d caracteres: ", TAM - 1);
        scanf(" %[^\n]", frase);
    } while (strlen(frase) < 1 || strlen(frase) >= TAM);

    removerEspaco(frase);

    puts(frase);

    return 0;
}

void removerEspaco(char frase[]) {
    int count = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ') {
            frase[count++] = frase[i];
        }
    }
    frase[count] = '\0';
}

