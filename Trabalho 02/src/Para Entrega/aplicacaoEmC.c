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
        exit(1);
    }
    
}

void validacaoPrimo(int numC){

    int aux = 0;

    if(numC <= 256){

        for(int i = 1; i <=numC; i++){
            
            if(numC%i == 0){
                aux++;
            }
        }
        if(aux == 2){
            aux = 0;
        }
    }
    else{
        
        for(int i = 1; i <256; i++){
            
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
        exit(1);
    }
}

void exponenciacao(int numA, int numB, int numC){
    
    int n = numB;
    int r; // Resultado do deslocamento

    int vetBinarioNumB[16] = {0};
    
    // Utiliza um número de 16 bits como base para a conversão.
    for(int i = 15; i >= 0; i--) {
        // Executa a operação shift right até a 
        // última posição da direita para cada bit.
        r = n >> i;
            
        // Por meio do "e" lógico ele compara se o valor 
        // na posição mais à direita é 1 ou 0 
        // e imprime na tela até reproduzir o número binário.
        if(r & 1) {
            printf("1");
            vetBinarioNumB[i] = 1;
        } else {
            printf("0");
            vetBinarioNumB[i] = 0;
        }
    }
    printf("\n");

    int FAT = numA;
    int auxFAT = numA;

    for(int j = 0; j <= 15; j++){

        /* printf("FATinit %d = %d\n", j, FAT); */

        if(j == 0 && vetBinarioNumB[j] == 1){
            auxFAT = (vetBinarioNumB[j]*FAT)%numC;
            FAT = auxFAT;
            printf("            auxFAT %d = %d\n", j, auxFAT);
        }

        if(vetBinarioNumB[j] == 1 && j != 0){
            printf("    auxfadqwd = %d  ", auxFAT);
            printf("    fatddqqw = %d\n", FAT);
            FAT = (auxFAT*FAT*vetBinarioNumB[j])%numC;
            //FAT = auxFAT;
            printf("            auxFAT %d = %d\n", j, auxFAT);
        }

        FAT *= FAT;
    }

    printf("A exponencial modular %d elevado a %d (mod %d) eh %d.\n", numA, numB, numC, auxFAT);
}