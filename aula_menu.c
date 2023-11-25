#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "prova1.h"
#define MENU "digite a opcao:\n\
1- Media Fatec(if).\n\
2- Ajuste de preco(if)\n\
3- Ajuste de preco(switch)\n\
4- Fatorial(do-while) \n\
5- Fibonacci(do-while)\n\
6- P.a(do-while) \n\
7- fatorial(while)\n\
8- Fibonacci(while) \n\
9- P.A (while) \n\
10- fatorial(for)\n\
11- Fibonacci(for)\n\
12- P.A(for) \n\
13- Achar menor e maior\n\
14- Manipulacao de valores\n\
15- strlen\n\
16- contador de frequencia\n\
17- verificar se é um palindrono\n\
18- mudar a string para maíuscula\n\
19- copiar string\n\
20- concatenar string\n\
21-operacoes com matriz\n\
22-prova1\n\
23- fatorial recursivo\n\
24- fibonacci recursivo\n"

#define MENU2 "1-Encontrar Maior e Menor \n\
2-Ordem inversa dos valores \n\
3-Valores com o expoente \n\
4-sair \n\
Escolha uma opcao: "

#define MENU3 "1-inserir matrizes\n\
2-somar matrizes\n\
3-subtrair matrizes\n\
4-multiplicar matrizes\n\
5-sair\n\
escolha: "

#define EXIT 25
int medFatec(int, int, int, int);
int ajustarPreco();
int strLen(char string[]);
int createMatriz(int (*matriz)[10], int,int,int);
void printMatriz(int (*matriz)[10], int lenI, int lenJ);
int fatorialRecursivo(int);
int fibonacciRecursivo(int, int, int);

struct ALUNO
	{
		int ra;
		char nome[30];
		char curso[20];
	};
typedef struct ALUNO aluno;

int main()
{
	aluno aluno1;
	aluno1.ra = 123456;
	int opcao = 0;
	int exitOption = 22;
	int numFatorial = 0;
	int num2Fatorial = 0;
	int numFibonacci = 1;
	int num2Fibonacci = 1;
	int temp = 0;
	int termo = 0;
	int termo2 = 0;
	int numPa = 0;
	int razao = 0;
    int p1 = 0;
    int t1 = 0;
    int p2 = 0;
    int t2 = 0;
	
	float price = 0;
	float desconto = 0;
	float valorDesconto = 0;
	float valorFinal = 0;
	
	int valores[100];
	int controle = 0;
	
	int* indice = valores;
	
    int _maiorNum = 0;
    int _menorNum = 0;
    int numero = 0;
    char resposta[1];
    int* ponteiro = valores;

    int maiorNum = valores[0];
	int menorNum = valores [0];

    char palavra2[10];
    int isPalindrono = 1;
    int k = strlen(palavra2);

	
	
    int opcaoMatriz = 0;
    int matriz[10][10];
    int matriz2[10][10];
    int lenI = 10;
    int lenJ = 10;
    int lenI_2 = 10;
    int lenJ_2 = 10;
    int MlenI = 0;
    int MlenJ = 0;
    int MlenI_2 = 0;
    int MlenJ_2 = 0;
    int produtoMatriz = 0;
    char palavra6[10];
    char palavra7[10];
    char palavra4[10];
    char palavra5[10];
    char palavra3[10];
    int palavraNum = 0;
    char palavra[10];
    char character;
    int count = 0;
    char string[10];
    int expoente = 0;

    for(int i = 0; i<100;i++){
        valores[i] = 0;
    }
    printf("%i", *indice);
	do{
		printf("%s%i- sair\nEscolha uma opção: ",MENU,EXIT);
		scanf("%i", &opcao);
        system("clear");

		switch (opcao)
		{
			case 1:
                system("clear");
				printf("Qual a nota da p1: ");
				scanf("%i", &p1);
				printf("\nQual a nota do t1: ");
				scanf("%i", &t1);
				printf("\nQual a nota do p2: ");
				scanf("%i", &p2);
				printf("\nQual a nota do t2: ");
				scanf("%i", &t2);
                medFatec(p1, t1, p2, t2);
				break;
			case 2:
                ajustarPreco();
				break;
			case 3:
                
				printf("Digite o preco do produto\n");
				scanf("%f", &price);
				printf("Selecione o desconto:\n");
				printf("1- 5%% \n");
				printf("2- 8%% \n");
				printf("3- 20%% \n");
				printf("4- 35%% \n");
				scanf("%i", &opcao);

				switch (opcao)
				{
					case 1:
						desconto = 5;
						break;

					case 2:
						desconto = 8;
						break;

					case 3:
						desconto = 20;
						break;

					case 4:
						desconto = 35;
						break;

					default:
						printf("Valor incorreto");
				}

				valorDesconto = price *(desconto / 100.0);
				valorFinal = price - valorDesconto;
				printf("o preco final eh:  %f", valorFinal);
				break;

			case 4:
		
				printf("Digite um valor para o calculo do fatorial\n");
				scanf("%i", &numFatorial);
				num2Fatorial = numFatorial;
				numFatorial--;
				do { 	num2Fatorial *= numFatorial;
					numFatorial--;
				}

				while (numFatorial > 1);
				printf("O fatorial eh : %i \n", num2Fatorial);
				break;
			case 5:
			   
				printf("Digite um valor para o calculo do termo de Fibonacci\n");
				scanf("%i", &termo);

				if (termo >= 2)
				{
					termo -= 2;	
					do { 	temp = num2Fibonacci;
						num2Fibonacci += numFibonacci;
						numFibonacci = temp;
						termo--;
					}

					while (termo >= 0);
				}

				printf("O termo eh: %i \n", num2Fibonacci);
				break;
			case 6:
			    
				printf("Digite o razao: ");
				scanf("%i", &razao);
				printf("Digite o numero de termos: ");
				scanf("%i", &termo2);
				do { 	printf("%i ", numPa);
					numPa += razao;
					termo2--;
				}

				while (termo2 > 0);
				printf("\n");
				break;
			case 7:
			    
				printf("Digite um valor para o calculo do fatorial\n");
				scanf("%i", &numFatorial);
				num2Fatorial = numFatorial;
				numFatorial--;

				while (numFatorial > 1)
				{
					num2Fatorial *= numFatorial;
					numFatorial--;
				}

				printf("O fatorial eh : %i \n", num2Fatorial);
				break;
			case 8:
			    
				printf("Digite um valor para o calculo do termo de Fibonacci\n");
				scanf("%i", &termo);

				if (termo >= 2)
				{
					termo -= 2;
					while (termo >= 0)
					{
						temp = num2Fibonacci;
						num2Fibonacci += numFibonacci;
						numFibonacci = temp;
						termo--;
					}
				}

				printf("O termo eh: %i \n", num2Fibonacci);
				break;
			case 9:
			   
				printf("Digite a razao: ");
				scanf("%i", &razao);
				printf("Digite o numero de termos: ");
				scanf("%i", &termo2);

				while (termo2 > 0)
				{
					printf("%i ", numPa);
					numPa += razao;
					termo2--;
				}

				printf("\n");
				break;

			case 10:
			    
				printf("Digite um valor para o calculo do fatorial\n");
				scanf("%i", &numFatorial);
				num2Fatorial = numFatorial;
				numFatorial--;

				for (; numFatorial > 1; numFatorial--)
				{
					num2Fatorial *= numFatorial;
				}

				printf("O fatorial eh : %i \n", num2Fatorial);
				break;
			case 11:
			    
				printf("Digite um valor para o calculo do termo de Fibonacci\n");
				scanf("%i", &termo);

				if (termo >= 2)
				{
					termo -= 2;
					for (; termo >= 0; termo--)
					{
						temp = num2Fibonacci;
						num2Fibonacci += numFibonacci;
						numFibonacci = temp;
					}

					printf("O termo eh: %i \n", num2Fibonacci);
				}

				break;
			case 12:
			    
				printf("Digite o razao: ");
				scanf("%i", &razao);
				printf("Digite o numero de termos: ");
				scanf("%i", &termo2);
				for (; termo2 > 0; termo2--)
				{
					printf("%i ", numPa);
					numPa += razao;
				}

				printf("\n");
				break;
			case 13:
				
				system("clear");
                

				do { 	
				    printf("Digite um numero: (max: %i)", 100 - controle);
					scanf("%i", &numero);
					valores[controle] = numero;
                    controle++;
					getchar();
					printf("Deseja finalizar o programa? s/n: ");
					scanf("%c", &resposta[0]);
				} while (resposta[0] != 's');
				
				printf("O resultado do maior numero eh %i e do menor numero eh %i ", _maiorNum, _menorNum);

				break;
				
			case 14 : 
			    
			    do{
			        printf("%s", MENU2);
			        scanf("%i",&opcao);
			        
			        switch (opcao){
			             case 1 :  
			             
			             printf("lista de valores: ");
		                        for (int i=0;i < controle; i++){
		                            if(valores[i] > _maiorNum){
		                                _maiorNum = ponteiro[i];
		                            }
		                            if(valores[i] < _menorNum){
		                                _menorNum = ponteiro[i];
		                            }
		                 printf("%i ", valores[i]);
		                        }	             
			             printf("\nO maior numero eh %i e o menor numero eh %i", maiorNum,_menorNum);
			             break;
			             case 2 : 
			               
			                for(int i = controle - 1;i >= 0;i--){
			                    printf("%i ",ponteiro[i]);
			                }
			             break;
			             case 3 : 
                         
			              
			              
			              
			                    printf("Digite um expoente: ");
			                    scanf("%i", &expoente);
			                    for(int i = 0; i < controle;i++){
			                        
			                 
			                     //printf("%.2f ", pow(*(ponteiro + i), expoente));   
			                    }
			                   printf("\n");
			             break;
			             case 4 : 
			             break;
			        }
			      getchar();
			     getchar();   
			     system("clear");
			    }while(opcao != 4);
			    
			break;
			case 15:
			    fflush(stdin);
			    getchar();
                
				printf("digite uma palavra menor que 10 letras: ");
				
				scanf("%[^\n]",string);
				//printf("essa string (%s) tem %i characters", string, strLen(string));
			    break;
			  
			case 16:
			    getchar();
			    printf("digite uma palavra com menos de 10 letras\n");
			    scanf("%[^\n]",palavra);
			    getchar();
			    printf("digite o character no qual deseja saber a frequencia na string: ");
			    scanf("%c",&character);
			    for(int i = 0; i < 10; i++){
			        
			        if(palavra[i] == character){
			            count++;
			        }
			      
			    }
			    printf("\nA frequencia de %c na palavra %s é %i",character,palavra,count);
			    break;
			case 17:
			    
			    getchar();
				printf("digite uma palavra de menor que 10 letras: ");
				scanf("%[^\n]",palavra2);
				
			    for(int j =0; j < k/2; j++){
			        if(palavra2[j] != palavra2[k - (j + 1)]){
			            isPalindrono = 0;
			            break;
			        }
			    }
			    if(isPalindrono){
			        printf("é um Palindrono");
			    }
			    else{
			        printf("não é um Palindrono");
			    }
			    break;
			
			case 18:
            
		    printf("digite uma palavra com menos de 10 letras: ");
			scanf("%s",palavra3);
			
			//printf("palavra em maiusculo %s",strupr(palavra3));
			break;
			case 19:
                
			    printf("escreva uma palavra: ");
			    scanf("%s", palavra4);
			    strcpy(palavra5, palavra4);
			    printf("palavra digitada %s\n",palavra4);
			    printf("palavra copiada %s",palavra5);
			    break;
			case 20:
                
			    printf("escreva uma palavra: ");
			    scanf("%s", palavra6);
			    printf("escreva uma palavra: ");
			    scanf("%s", palavra7);
			    strcat(palavra6, palavra7);
			    printf("resultado: %s", palavra6);
			    break;
			case 21:
    			
    			do{
    			    printf("%s",MENU3);
    			    scanf("%i",&opcaoMatriz);
    			    switch (opcaoMatriz){
    			        case 1:
    			            MlenI, MlenJ = createMatriz(matriz, 1, lenI, lenJ);
    			            MlenI_2, MlenJ_2 = createMatriz(matriz2, 2, lenI, lenJ);
            			    
            			        printf("matriz 1: \n");  
                			    printMatriz(matriz, MlenI, MlenJ);
                			    
                			    printf("matriz 2: \n");
                			    printMatriz(matriz2, MlenI_2, MlenJ_2);
            			    
    			            break;
    			        case 2:
    			            for(int i = 0; i < 3; i++){
    			                for(int j = 0; j < 3; j++){
    			                    printf("%i", matriz[i][j] + matriz2[i][j]);
    			                }
    			                printf("\n");
    			            }
    			            break;
    			        case 3:
    			            for(int i = 0; i < 3; i++){
    			                for(int j = 0; j < 3; j++){
    			                    printf("%i", matriz[i][j] - matriz2[i][j]);
    			                }
    			                printf("\n");
    			            }
    			            break;
    			        case 4:
    			            
    			            for(int i = 0; i<MlenI; i++){
        			            for(int j = 0; j < 3; j++){
        			                for(int k =0; k < 3;k++){
        			                    produtoMatriz += matriz[i][k] * matriz2[k][j];
        			                }
        			                printf("%i ",produtoMatriz);
        			                produtoMatriz = 0;
        			            }
        			            printf("\n");
        			             
        			            
    			            }
    			        
    			    }
    			    getchar();
    			    getchar();
    			    system("clear");
    			}while(opcaoMatriz != 5);
            case 22:
                exer1();
			case 23:
			scanf("%i", &numFatorial);
				fatorialRecursivo(numFatorial);
			case 24:
				scanf("%i", &termo);
				fibonacciRecursivo(termo, 1, 1);
			case EXIT:
                break;
			default:
				printf("Opcao invalida\n");
		}
		
		if (opcao != EXIT){
		    getchar();
		    getchar();
		    system("clear");
		}
		
	} while (opcao != EXIT);

	return 0;
}

int medFatec(int p1, int p2, int t1, int t2){
    int b1 = 0;
	int b2 = 0;
	int pr = 0;
	int mf = 0;
	b1 = p1 * 0.7 + t1 * 0.3;
	b2 = p2 * 0.6 + t2 * 0.4;

	mf = (b1 + b2) / 2;
	if (mf >= 6)
	{
		printf("\nAprovado");
	}
	else
	{
		if (mf >= 2 && mf < 6)
		{
			printf("\nQual a nota da pr: ");
			scanf("%i", &pr);

			if ((mf + pr) / 2 >= 6)
			{
				printf("\nAprovado");
			}
			else
			{
				printf("\nReprovado\n");
			}
		}
		else
		{
			printf("\nReprovado\n");
		}
	}
}
int ajustarPreco(){
    float price = 0;
	float desconto = 0;
	float valorDesconto = 0;
	float valorFinal = 0;
	int opcao = 0;
	printf("Digite o preco do produto\n");
    scanf("%f", &price);
    printf("Selecione o desconto: \n 1- 5%% \n 2- 8%% \n 3- 20%% \n 4- 35%% \n");
    scanf("%i", &opcao);
    				if (opcao == 1)
    				{
    					desconto = 0.05;
    				}
    				else if (opcao == 2)
    				{
    					desconto = 0.08;
    				}
    				else if (opcao == 3)
    				{
    					desconto = 0.2;
    				}
    				else if (opcao == 4)
    				{
    					desconto = 0.35;
    				}
    
    				valorDesconto = price * desconto;
    				valorFinal = price - valorDesconto;
    				printf("o preco final e %f", valorFinal);
    				
}
int strLen(char string[]){
    int count = 0;
    for(int i = 0; i < 10;i++){
        
        if(string[i] == '\0'){
            return count;
        }
         if((int) string[i] !=32){
            printf("%i ",string[i]);
            count++;
        }
    }
}
int createMatriz(int (*matriz)[10], int pos, int lenI, int lenJ){
    int isFine = 0;
    int iMatriz = 0;
    int jMatriz = 0;
    do{
        printf("digite o numero de linhas da matriz %i (max:%i): ",pos,lenI);
        scanf("%i",&iMatriz);
        if(iMatriz > lenI){
            printf("o numero digitado ultrapasou o limite de 10 linhas :/\n");
            continue;
        }
        printf("digite o numero de colunas da matriz %i (max:%i): ",pos,lenJ);
        scanf("%i",&jMatriz);
        
        if(jMatriz > lenJ){
            printf("o numero digitado ultrapasou o limite de 10 colunas :/\n");
            continue;
        }
        isFine = 1;
    }while(!isFine);
    for(int i = 0; i < iMatriz; i++){
        for(int j = 0; j < jMatriz; j++){
            printf("matriz[%i][%i]: ",i,j);
            scanf("%i",&matriz[i][j]);
            
        }
    }
    return iMatriz, jMatriz;
}
void printMatriz(int (*matriz)[10], int lenI, int lenJ){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%i ",matriz[i][j]);
            
        }
        printf("\n");
            
    }
}
int fatorialRecursivo(int num){
	if(num == 1){
		return 1;
	}
	return num * fatorialRecursivo(num - 1);
}
int fibonacciRecursivo(int termo, int num, int num2){
	if (termo == 2){
		printf("%i", num2);
		return 1;
	}
	num2 == 1 ? printf("%i ", num) : printf(" ");
	printf("%i ", num2);
	fibonacciRecursivo(termo - 1, num2, num + num2);

}












