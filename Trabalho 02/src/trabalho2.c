#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void validacaoEntradaInvalida(int numA, int numB, int numC);
void validacaoPrimo(int numC);
void exponenciacao(int numA, int numB, int numC);


int main(){

    int numA, numB, numC;

    scanf("%d %d %d", &numA, &numB, &numC);

    validacaoEntradaInvalida(numA, numB, numC);
    validacaoPrimo(numC);

    exponenciacao(numA, numB, numC);
    
    return 0;
}

void validacaoEntradaInvalida(int numA, int numB, int numC){

    if(numA > 0 || numB > 0 || numC > 0){
    }
    else{
        exit(1);
    }

    if(numA < 65536 || numB < 65536 || numC < 65536){
    }
    else{
        exit(1);
    }
    
}

void validacaoPrimo(int numC){

    int aux = 0;

    for(int i = 2; i <= 256; i+=2){

        if(numC%i == 0){
            aux++;
        }
    }
    if(numC%2 == 0){
        aux++;
    }

    if(aux != 0){
        exit(1);
    }
}

void exponenciacao(int numA, int numB, int numC){
    
    int auxNum = numA;
    int bin[16]; // <---------------
    int aux;

   for (aux = 15; aux >= 0; aux--)
   {
      if (auxNum % 2 == 0)
         bin[aux] = 0;
      else
         bin[aux] = 1;
         auxNum = auxNum / 2;
   }

   for (aux = 0; aux < 16; aux++){
       printf("%d", bin[aux]);
   }
   printf("\n");

    int FAT = numA;
    int ACC = 1;
    int auxACC;
    
    for(int i = 15; i >= 0; i--){

        if(i==15){
            auxACC = ACC*bin[15]*FAT;
            printf("auxACC = %d\n", auxACC);

            ACC = (auxACC)%numC;
            int x = 5/13; printf("x = %d\n", x);
            printf("ACC = %d\n", ACC);
        }

        if(bin[i] == 1 && i !=15){
            FAT *= FAT;
            auxACC = ACC*bin[i]*FAT;
            printf("auxACC = %d\n", auxACC);

            ACC = ACC%numC;
            printf("ACC = %d\n", ACC);
        }
    }

    printf("A exponencial modular %d elevado a %d (mod %d) eh %d.\n", numA, numB, numC, ACC);
}