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
    //caso o numero lido seja menor ou igual a 1, retorna entrada invalida
    if(numero <= 1){
        printf("Entradas invalidas.\n");
        exit(1);
    }
    //caso a precisao lida seja menor que 1 ou maior que 16, retorna entrada invalida
    if(precisao < 1 || precisao > 16){
        printf("Entradas invalidas.\n");
        exit(2);
    }
}

void encontrarInteirosA0eB0(int numero, int *inteiroA0, int *inteiroB0){
    //caso o numero lido seja menor ou igual a 100, ele entra nesse for para encontrar os inteiros A0 e B0
    if(numero <= 100){
        for(int i = 0; i <= 10; i++){

            if(((i+1)*(i+1)) > numero){
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
    //caso o numero lido seja maior que 100 e menor ou igual a 400, ele entra nesse for para encontrar os inteiros A0 e B0
    if(numero > 100 && numero <= 400){
        for(int i = 10; i <= 20; i++){
            if(((i+1)*(i+1)) > numero){
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
    //caso o numero lido seja maior que 400 e menor ou igual a 900, ele entra nesse for para encontrar os inteiros A0 e B0
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
    //caso o numero lido seja maior que 900 e menor ou igual a 1600, ele entra nesse for para encontrar os inteiros A0 e B0
    if(numero > 900 && numero <= 1600){
        for(int i = 30; i <= 40; i++){
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
    //caso o numero lido seja maior que 1600 e menor ou igual a 2500, ele entra nesse for para encontrar os inteiros A0 e B0
     if(numero > 1600 && numero <= 2500){
        for(int i = 40; i <= 50; i++){
            if(((i+1)*(i+1)) > numero){

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

    double auxPrecisao = pow(10, -(precisao)); // 1,0x10^(-precisao) = erro de aproximacao

    while(*interacoes != 0){
        if(*interacoes == 1){
            inteiroA = *inteiroA0;        //A2 = inteiro A (vindo da funcao encontrar inteiro A0 e B0
            inteiroB = numero / inteiroA; //B2 = numero/A2
        }
        else{
            inteiroA = (inteiroA + inteiroB) / 2; //A2 = (A1+B1)/2
            inteiroB = (numero / inteiroA);       //B2 = numero/A2
        }

        double diferencaEntreAeB = inteiroB - inteiroA; //medida do erro de aproximacao = Bn - An
        if(diferencaEntreAeB < 0){
            diferencaEntreAeB *= -1; //Tornar positivo
        }
        if(diferencaEntreAeB <= auxPrecisao){         // Bn - An <= erro de aproximacao (1,0x10^(-precisao))
            raiz = inteiroB;
            imprimirSaida(numero, raiz, &interacoes); //impressao da raiz na tela e da quantidade de iteracoes necessarias
        }
        else{
            *interacoes += 1;                          //incremento a quantidade de iteracoes ate atingir o erro de aproximacao
            validacaoInteracoes(numero, &interacoes);  //verifico se as iteracoes passaram de 100
        }
    }
}

void validacaoInteracoes(int numero, int **interacoes){
    if(**interacoes > 100){
        //Caso passe de 100 iteracoes e o criterio de parada nao seja atendido, printo que nao foi possivel calcular a raiz
        printf("Nao foi possivel calcular sqrt(%d).\n", numero);
        exit(3);
    }
}

void imprimirSaida(int numero, double raiz, int **interacoes){
    //Impressao depois de calcular a raiz do numero
    printf("A raiz quadrada de %d eh %.15lf, calculada em %d iteracoes.\n", numero, raiz, **interacoes);
    exit(4);
}
