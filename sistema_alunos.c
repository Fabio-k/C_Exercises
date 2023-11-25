#include <stdio.h>
#include <stdlib.h>
struct ALUNO{
    int ra;
    char nome[20];
    char curso[20];
};
void cadastrar_aluno(struct ALUNO* aluno, struct ALUNO dados_alunos[], int length);
void listar_alunos(struct ALUNO dados_alunos[10], int length);
void buscar_aluno(struct ALUNO dados_alunos[10], int length);
void alterar_aluno(struct ALUNO dados_alunos[10], int lenght);
int validRa(int ra,int ignore,struct ALUNO dados_alunos[10], int length);
void printA(struct ALUNO dados_alunos[], int i);

#define MENU "MENU:\n1 - Cadastrar aluno\n2 - Listar alunos\n3 - Buscar aluno\n4 - Alterar aluno\n5 - Sair \nSelecione uma opcao: "
#define MAXLENGTH 10
#define EXIT 5
#define PERGUNTA_NOME "digite o nome do aluno: "
#define PERGUNTA_RA "digite o RA do aluno: "
#define PERGUNTA_CURSO "digite o curso do aluno: "
int main(){
    struct ALUNO aluno;
    struct ALUNO* dados_alunos;
    dados_alunos = (struct ALUNO*)malloc(MAXLENGTH*sizeof(struct ALUNO));
    int opcao;
    int length = 0;
    int registros = 0;
    system("clear");
    do{
        printf("alunos registrados no sistema: %i\n",registros);
        printf("-----");
        printf("%s", MENU);
        scanf("%d", &opcao);
        system("clear");
        switch (opcao){
                case 1:
                    cadastrar_aluno(&aluno, dados_alunos, length);
                    length++;
                    registros++;
                    break;
                case 2:
                    listar_alunos(dados_alunos, length);
                    break;  
                case 3: 
                    buscar_aluno(dados_alunos, length);
                    break;  
                case 4: 
                    alterar_aluno(dados_alunos, length);
                    break;
                case EXIT:
                break;
                default:
                    printf("Opcao invalida!");
                    break;
            }
            getchar();
            system("clear");
    }while(opcao != EXIT);
    free(dados_alunos);
}
void cadastrar_aluno(struct ALUNO* aluno, struct ALUNO dados_alunos[], int length){
       printf("---- cadastrar alunos ----\n");
    do{
        printf(PERGUNTA_RA);
        scanf("%d", &aluno->ra);
        getchar();
    }while(validRa(aluno->ra, -1, dados_alunos, length));
    
    printf(PERGUNTA_NOME);
    scanf("%[^\n]", aluno->nome);
    getchar();
    printf(PERGUNTA_CURSO);
    scanf("%[^\n]", aluno->curso);
    getchar();
    if(length == MAXLENGTH - 1){
        struct ALUNO* dados_aluno_temp = (struct ALUNO*)malloc(MAXLENGTH*2*sizeof(struct ALUNO));
        for (int i = 0; i < MAXLENGTH;i++){
            dados_aluno_temp[i] = dados_alunos[i];
        }
        free(dados_alunos);
        dados_alunos = dados_aluno_temp;
        
    }
    dados_alunos[length] = *aluno;
}
void listar_alunos(struct ALUNO dados_alunos[10], int length){
    printf("---- Listar alunos ----\n");
    for(int i = 0; i < length; i++){
        printf("RA: %5i | nome: %-10s | Curso %10s\n",dados_alunos[i].ra, dados_alunos[i].nome, dados_alunos[i].curso);
		printf("----\n");
    }
    getchar();
}
void buscar_aluno(struct ALUNO dados_alunos[10], int length){
    int ra;
    printf("---- Buscar aluno ----\n");
    printf(PERGUNTA_RA);
    scanf("%d", &ra);
    for(int i = 0; i < length; i++){
        if(dados_alunos[i].ra == ra){
            printA(dados_alunos, i);
            getchar();
            return;
        }
    }
    printf("Aluno nao encontrado!");
    getchar();
}
void alterar_aluno(struct ALUNO dados_alunos[10], int lenght){
    int ra;
    int isInUse = 0;
    printf("---- Alterar dados do aluno ----\n");
    printf("Alunos armazenados:\n");
    for(int i = 0; i < lenght;i++){
        printf("RA:%5i -- Nome: %s\n", dados_alunos[i].ra,dados_alunos[i].nome);
    }
    printf(PERGUNTA_RA);
    scanf("%d", &ra);
    for(int i = 0; i < 10; i++){
        if(dados_alunos[i].ra == ra){
            printf("dados do aluno encontrado:\n");
            printf("----\n");
            printA(dados_alunos, i);
            printf("----\n");
            do{
                isInUse = 0;
                printf("Digite o novo RA do aluno: ");
                scanf("%d", &dados_alunos[i].ra);
                getchar();
                isInUse = validRa(ra,i, dados_alunos, lenght);
            }while(isInUse);
            printf("Digite o novo nome do aluno: ");
            scanf("%[^\n]", dados_alunos[i].nome);
            printf("Digite o novo curso do aluno: ");
            scanf("%s", dados_alunos[i].curso);
            break;
        }
        if (i > lenght){
            printf("Aluno nao encontrado!");
            break;
        }
    }
    getchar();
}

void excluir_aluno(struct ALUNO dados_aluno[10], int lenght){
    int ra = 0;
    printf("digite o RA do aluno: ");
    scanf("%d", &ra);
    for(int i = 0 ; i < lenght;i++){
        if (ra == dados_aluno[i].ra){
            if(i == lenght - 1){
                dados_aluno[i].ra = 0;
            }
        }
    }
}
void printA(struct ALUNO dados_alunos[], int i){
    printf("RA: %d\n", dados_alunos[i].ra);
    printf("Nome: %s\n", dados_alunos[i].nome);
    printf("Curso: %s\n", dados_alunos[i].curso);
}
//ignora o index na posição ignore e verifica se há algum valor armazenado em dados_alunos caso haja retorna 1 senão 0
int validRa(int ra, int ignore, struct ALUNO dados_alunos[10], int length){
    for(int i = 0; i < length;i++){
        if (i == ignore){
            continue;
        }
        if(dados_alunos[i].ra == ra){
            printf("RA em uso. Digite um outro RA \n");
            return 1;
        }
    }
    return 0;
}
