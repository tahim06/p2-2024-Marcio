#include <stdio.h>
#include <math.h>

int main(){
  int qtd, numeros[10];
  double media;

  printf("Você quer tirar a média de quantos números?");
  scanf("%d", &qtd);
  
  while(qtd < 1 || qtd > 10) {
    printf("Você quer tirar a média de quantos números?");
    scanf("%d", &qtd);
  }

  printf("Você está tirando a média de %d números\n",qtd);

  for(int i = 0; i < qtd; i++){
        
  }

  return 0;
}