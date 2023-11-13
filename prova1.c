#include <stdio.h>
#include "prova1.h"
void exer1(){
    int esq, dir, soma, num;
    printf("digite um algarismo de 4 digitos: ");
    scanf("%d", &num);
    esq = num / 100;
    dir = num % 100;
    soma = esq + dir;
    soma *= soma;
    if (soma == num){
        printf("o numero %d é um quadrado perfeito\n", num);
    }else{
        printf("o numero %d não é um quadrado perfeito\n", num);
    }
}
void exer2(int matriz1[10][10], int matriz2[10][10]){
    int matrizRes[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                matrizRes[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}