#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void encontrarInteirosA0eB0(int numero, int *inteiroA0, int *inteiroB0);
void validacaoEntradas(int numero, int precisao);
void calcularRaiz(int numero, int precisao, int *inteiroA0, int *inteiroB0, int *interacoes);
void validacaoInteracoes(int numero, int **interacoes);
void imprimirSaida(int numero, double raiz, int **interacoes);


int main(){

    int numero, precisao;
    int interacoes = 1;

    scanf("%d", &numero); //numero a ser calculado a raiz
    scanf("%d", &precisao); //precisao de aproximação

    validacaoEntradas(numero, precisao);

    int inteiroA0;
    int inteiroB0;
    
    encontrarInteirosA0eB0(numero, &inteiroA0, &inteiroB0);
    
    calcularRaiz(numero, precisao, &inteiroA0, &inteiroB0, &interacoes);

    return 0;
}


void validacaoEntradas(int numero, int precisao){
    
    if(numero <= 1){

        printf("Entradas invalidas.\n");
        exit(1);
    }
    if(precisao < 1 || precisao > 16){

        printf("Entradas invalidas.\n");
        exit(2);
    }
}

void encontrarInteirosA0eB0(int numero, int *inteiroA0, int *inteiroB0){

    if(numero <= 100){

        for(int i = 0; i <= 10; i++){
            if( ((i+1)*(i+1)) > numero){
                
                *inteiroB0 = i+1;

                if(i*i == numero){
                    *inteiroA0 = i-1;
                }
                else{
                    *inteiroA0 = i;
                }
                
                break;
            }
        }
    }

    if(numero > 100 && numero <= 400){
        
        for(int i = 10; i <= 20; i++){
            if( ((i+1)*(i+1)) > numero){
                
                *inteiroB0 = i+1;

                if(i*i == numero){
                    *inteiroA0 = i-1;
                }
                else{
                    *inteiroA0 = i;
                }
                
                break;
            }
        }
    }
    if(numero > 400 && numero <= 900){

        for(int i = 20; i <= 30; i++){
            if( ((i+1)*(i+1)) > numero){
                
                *inteiroB0 = i+1;

                if(i*i == numero){
                    *inteiroA0 = i-1;
                }
                else{
                    *inteiroA0 = i;
                }
                
                break;
            }
        }
    }
}

void calcularRaiz(int numero, int precisao, int *inteiroA0, int *inteiroB0, int *interacoes){

    double inteiroA;
    double inteiroB;
    double raiz;

    double auxPrecisao = pow(10, -(precisao));

    while(*interacoes != 0){

        if(*interacoes == 1){

            inteiroA = *inteiroA0;

            inteiroB = numero / inteiroA;
        }
        else{

            inteiroA = (inteiroA + inteiroB) / 2;

            inteiroB = (numero / inteiroA);
        }


        double diferencaEntreAeB = inteiroB - inteiroA;
        if(diferencaEntreAeB < 0){
            diferencaEntreAeB *= -1;
        }

        if(diferencaEntreAeB <= auxPrecisao){

            raiz = inteiroB;

            imprimirSaida(numero, raiz, &interacoes);
        }
        else{

            *interacoes += 1;

            validacaoInteracoes(numero, &interacoes);
        }
    }
}

void validacaoInteracoes(int numero, int **interacoes){
    
    if(**interacoes > 100){

        printf("Nao foi possivel calcular sqrt(%d).\n", numero);
        exit(3);
    }
}

void imprimirSaida(int numero, double raiz, int **interacoes){

    printf("A raiz quadrada de %d eh %.15lf, calculada em %d iteracoes.\n", numero, raiz, **interacoes);
    exit(4);
}