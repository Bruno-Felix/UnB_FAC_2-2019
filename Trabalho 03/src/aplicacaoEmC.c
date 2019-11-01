#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void encontra_inteiros(int numero, int *a0, int *b0);
void validacao_entradas(int numero, int erro);
void calc_raiz(int numero, int erro, int *a0, int *b0, float *raiz, int *interacoes);
void imprime_saida(int numero, int raiz);
void validacao_interacoes(int numero, int **interacoes);


int main(){

    unsigned int numero, erro;
    float raiz;
    int interacoes = 1;

    scanf("%d", &numero); //numero a ser calculado a raiz
    scanf("%d", &erro); //erro de aproximação

    validacao_entradas(numero, erro);

    int a0 = 0;
    int b0 = 0;
    
    encontra_inteiros(numero, &a0, &b0);

    printf("a0: %d\n", a0);
    printf("b0: %d\n", b0);
    
    calc_raiz(numero, erro, &a0, &b0, &raiz, &interacoes);

    
    //printf("interacoes: %d\n", interacoes);

    return 0;
}


void validacao_entradas(int numero, int erro){
    
    if(numero <= 1){

        printf("Entradas invalidas.\n");
        exit(1);
    }
    if(erro < 1 || erro > 16){

        printf("Entradas invalidas.\n");
        exit(2);
    }
}

void encontra_inteiros(int numero, int *a0, int *b0){

    if(numero <= 100){

        for(int i = 0; i <= 10; i++){
            if( ((i+1)*(i+1)) > numero){
                
                *b0 = i+1;

                if(i*i == numero){
                    *a0 = i-1;
                }
                else{
                    *a0 = i;
                }
                
                break;
            }
        }
    }

    if(numero > 100 && numero <= 400){
        
        for(int i = 10; i <= 20; i++){
            if( ((i+1)*(i+1)) > numero){
                
                *b0 = i+1;

                if(i*i == numero){
                    *a0 = i-1;
                }
                else{
                    *a0 = i;
                }
                
                break;
            }
        }
    }
    if(numero > 400 && numero <= 900){

        for(int i = 20; i <= 30; i++){
            if( ((i+1)*(i+1)) > numero){
                
                *b0 = i+1;

                if(i*i == numero){
                    *a0 = i-1;
                }
                else{
                    *a0 = i;
                }
                
                break;
            }
        }
    }
}

void calc_raiz(int numero, int erro, int *a0, int *b0, float *raiz, int *interacoes){

    float aInt;
    float bInt;

    float aux = 1;
    float aux1 = pow(10, erro+1);
    float aux2 = aux/aux1;
    //printf("%f\n", aux2);

    int auxInteracoes = 1;
    while(auxInteracoes != 6){
        
        if(auxInteracoes == 1){

            aInt = *a0;

            bInt = numero/ aInt;

            printf("aInt %d: %f\n", auxInteracoes, aInt);
            printf("bInt %d: %f\n", auxInteracoes, bInt);
        }
        else{

            aInt = (aInt + bInt)/2;

            bInt = (numero/ aInt);
            printf("aInt %d: %f\n", auxInteracoes, aInt);
            printf("bInt %d: %f\n", auxInteracoes, bInt);
        }

        *interacoes = auxInteracoes;
        validacao_interacoes(numero, &interacoes);
        auxInteracoes++;
    }


}

void imprime_saida(int numero, int raiz){

}

void validacao_interacoes(int numero, int **interacoes){
    
    //printf("interacoes: %d\n", **interacoes);
    if(**interacoes == 100){

        printf("Nao foi possivel calcular sqrt(%d).\n", numero);
        exit(3);
    }
}