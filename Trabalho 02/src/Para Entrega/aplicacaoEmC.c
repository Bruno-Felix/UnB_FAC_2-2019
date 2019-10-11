#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numeroBits = 16;

void verificacaoEntradasValidas(int numA, int numB, int numC);
void verificacaoModuloPrimo(int numC);
void transformacaoNumBBinario(int *vetBinarioNumB, int numB);
void exponenciacao(int numA, int numB, int numC);


int main(){

    int numA, numB, numC;

    scanf("%d %d %d", &numA, &numB, &numC);

    verificacaoEntradasValidas(numA, numB, numC);
    verificacaoModuloPrimo(numC);

    exponenciacao(numA, numB, numC);
    
    return 0;
}


void verificacaoEntradasValidas(int numA, int numB, int numC){

    if(numA > 0 && numB > 0 && numC > 0){
        
    }
    else{
        printf("Entradas invalidas.\n");
        exit(1);
    }

    if(numA < 65536 && numB < 65536 && numC < 65536){
    }
    else{
        printf("Entradas invalidas.\n");
        exit(2);
    }
    
}

void verificacaoModuloPrimo(int numC){

    int aux = 0;

    if(numC <= 256){

        for(int i = 1; i <= numC; i++){
            
            if(numC%i == 0){
                aux++;
            }
        }
        if(aux == 2){
            aux = 0;
        }
    }
    else{
        
        for(int i = 1; i < 256; i++){
            
            if(numC%i == 0){
                aux++;
            }
        }

        if(aux == 1){
            aux = 0;
        }
    }
    
    if(numC == 1){
        aux++;
    }
    else if(numC == 2){
        aux = 0;
    }

    if(aux != 0){
        printf("O modulo nao eh primo.\n");
        exit(3);
    }
}

void transformacaoNumBBinario(int *vetBinarioNumB, int numB){

    int auxNumB = numB;
    int descolamento;

    for(int i = 15; i >= 0; i--) {

        descolamento = auxNumB >> i;
            
        if(descolamento & 1) {
            printf("1");
            vetBinarioNumB[i] = 1;
        }
        else {
            printf("0");
            vetBinarioNumB[i] = 0;
        }
    }
    printf("\n");
}

void exponenciacao(int numA, int numB, int numC){
    
    int *vetBinarioNumB = (int *) calloc(numeroBits, sizeof(int));

    transformacaoNumBBinario(vetBinarioNumB, numB);

    int FAT = numA;
    int auxFAT = numA;

    for(int j = 0; j <= 15; j++){

        if(j == 0 && vetBinarioNumB[j] == 1){

            auxFAT = (vetBinarioNumB[j]*FAT)%numC;
            FAT = auxFAT;
        }

        if(vetBinarioNumB[j] == 1 && j != 0){

            FAT = (auxFAT*FAT*vetBinarioNumB[j])%numC;
        }

        FAT *= FAT;
    }

    printf("A exponencial modular %d elevado a %d (mod %d) eh %d.\n", numA, numB, numC, auxFAT);
}