#include <stdio.h>
#include <string.h>

#define TAM 50

int main(){
    char s1[TAM],s2[TAM];
    printf("Digite a primeira palavra: ");
    fgets(s1,TAM,stdin);

    printf("Digite a segunda palavra: ");
    fgets(s2,TAM,stdin);

    if(strcmp(s1,s2) < 0){
        printf("%s vem antes de %s",s1,s2);
    }
    if(strcmp(s1,s2)> 0){
        printf("%s vem antes de %s",s2,s1);
    }else{
        printf("%s e %s posuem mesma ordem alfabética",s1,s2);
    }
    
    return 0;

}