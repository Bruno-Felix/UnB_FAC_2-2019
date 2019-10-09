#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verificacao(int n1, int n2, int n3){
  int contador=0;
  if(n1>0 && n2>0 && n3>0){
    for(int i=2;i<n3;i++){
      if(n3%i==0){
        contador++;
      }
    }
    if(contador!=0){
      printf("O modulo nao eh primo.\n");
      return 0;
    }
    else{
      return 1;
    }
  }
  else{
    printf("Entradas invalidas\n");
    return 0;
  }
}

int exponencial(int n1, int n2, int n3){
  int calculo = pow(n1,n2);
  int resultado = calculo%13;
  return resultado;
}
int main() {
  int n1,n2,n3,valor=0;

  scanf("%d%d%d",&n1,&n2,&n3);

  valor = verificacao(n1,n2,n3);

  if(valor != 0){
    printf("A exponencial modular %d elevado a %d (mod %d) eh %d.\n",n1,n2,n3,exponencial(n1,n2,n3));
  }

  return 0;
}
