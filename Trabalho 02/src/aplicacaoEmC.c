#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numeroBits = 16;

void verificacaoEntradasValidas(int numA, int numB, int numC);
void verificacaoModuloPrimo(int numC);
void verificacaoModuloPrimoImpar(int numC);
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

    int contador = 0;

    if(numC%2 == 0){
        if(numC > 2){
            printf("O modulo nao eh primo.\n");
            exit(1);
        }
    }
    else{
        verificacaoModuloPrimoImpar(numC);
    }
}

void verificacaoModuloPrimoImpar(int numC){
    
    int contador = 0;

    if(numC < 256){
        for(int i = 3; i < numC; i += 2){
        
            int aux = numC%i;

            if(aux == 0){

                contador++;
            }
        }
    }
    else{
        for(int i = 3; i < 256; i += 2){
        
            int aux = numC%i;

            if(aux == 0){

                contador++;
            }
        }
    }

    if(numC == 1){
        contador++;
    }

    if(contador != 0){
        printf("O modulo nao eh primo.\n");
        exit(1);
    }
}

void transformacaoNumBBinario(int *vetBinarioNumB, int numB){

    int auxNumB = numB;
    int descolamento;

    for(int i = 15; i >= 0; i--) {

        descolamento = auxNumB >> i;
            
        if(descolamento & 1) {
            //printf("1");
            vetBinarioNumB[i] = 1;
        }
        else {
            //printf("0");
            vetBinarioNumB[i] = 0;
        }
    }
    printf("\n");
}

void exponenciacao(int numA, int numB, int numC){
    
    int *vetBinarioNumB = (int *) calloc(numeroBits, sizeof(int));

    transformacaoNumBBinario(vetBinarioNumB, numB);


    unsigned int FAT = numA;
    int ACC = 1;
    unsigned int FatFinal = 1;

    int modFatFinal;

    for(int i = 0; i <= 15; i++){

        if(i == 0){
            
            FAT = ACC*FAT;
            //printf("fat[%d]: %d\n", i, FAT);
        }
        else{

            FAT = (ACC*FAT*FAT)%numC;
            //printf("fat[%d]: %d\n", i, FAT);
        }

        if(vetBinarioNumB[i] == 1){

            /* printf("FatFinal %d: %d\n", i, FAT); */
            FatFinal *= FAT;
            FatFinal = FatFinal%numC;
            //printf("        FatFinal: %d\n", FatFinal);
        }
    }

    /* modFatFinal = FatFinal%numC; */

    printf("A exponencial modular %d elevado a %d (mod %d) eh %d.\n", numA, numB, numC, FatFinal);
}