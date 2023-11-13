#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20
#define EXIT 5
#define IN 1
#define OUT 0
#define MAX_ARRAY 10
#define MENU "Menu options:\n\
1 - F -> C table pag(26-33)\n\
2 - input reader pag(37)\n\
3 - word counter pag(41)\n\
4 - exit\n"

void tabela_fahrenheit();
void shellSort(int[], int);
void printArray(int[], int);
int main (){
    int option = 0;
    int c, nl, nw, nc, state, isContinue;
    int celsius = 0;
    int size = 0;
    int arr[MAX_ARRAY];
    char answer;
    do{
        printf("%s\n", MENU);
        scanf("%d", &option);
        switch (option){
        case 1:
            
            printf("digite a temperatura em Celsius: \n");
            scanf("%d", &celsius);
            printf("resultado %d\n", celsius * 9/5 + 32);
            printf("escala:\n");
            tabela_fahrenheit();
            break;
        case 2:
            printf("EOF: %d\n", EOF);
            printf("getchar != EOF: %d\n", getchar() != EOF);
            while ((c = getchar())!= EOF){
                putchar(c);
                c = getchar();
            }
        case 3:
            state = OUT;
            c = nl = nw = nc = 0;
            while((c = getchar()) != EOF){
                ++nc;
                if(c == '\n'){
                    ++nl;
                }
                if(c == ' ' || c == '\n' || c == '\t'){
                    state = OUT;
                }else if(state == OUT){
                    state = IN;
                    ++nw;
                }
            }
            case 4:
                do{
                    printf("Array[%i]: ",size);
                    scanf("%i",&arr[size++]);
                    getchar();
                    printf("continue [y/n]: ");
                    answer = getchar();
                    isContinue = (answer == 'n') ? 0 : 1;
                }while(size < MAX_ARRAY && isContinue);
                shellSort(arr, MAX_ARRAY);
        case EXIT:
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }while(option != EXIT);
}

void tabela_fahrenheit(){
    printf("Tabela de conversão de Fahreheit para Celsius\n");
    printf("Fahrenheit\tCelcius\n");
    for (int upper = UPPER; upper > LOWER; upper -= STEP) {
            printf("%3d\t%6.2f\n", upper, (upper- 32) * 5/9.0);
        }
    }
void shellSort(int num [], int n){
    int temp;
    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n;i++){
            for(int j = i - gap; j >= 0 && num[j] > num[j+gap];j -= gap){
                temp = num[j];
                printArray(num, n);
                printf(" %i --> %i\n", j, j+gap);
                num[j] = num[j+gap];
                num[j+gap] = temp;
                
            }
        }
    }
    printArray(num, n);

}
void printArray(int arr [], int n){
    for(int i = 0; i < n; i++){
        printf("%i -- ",arr[i]);
    }
}