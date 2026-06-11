#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 10

typedef struct Aluno {
    char nome[40];
    int RA;
    float notas[2];
    float frequencia;
} Aluno;

int inserir_aluno(Aluno[], int);



int main(){
    Aluno lista_alunos[M];
    int cont = 0, opc;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Inserir aluno\n");
        printf("2. Remover aluno\n");
        printf("3. Visualizar alunos\n");
        printf("4. Buscar aluno por RA\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);
        while (opc > 4)
        {
            printf("Invalido. Digite novamente: ");
            scanf("%d", &opc);
        }

        switch (opc)
        {
        case 1:
            if (opc == 1){
            cont = inserir_aluno(lista_alunos, cont);
            }
            break;
        
        default:
            break;
        }
        
    } while (opc != 0);


}

int inserir_aluno(Aluno lista[], int cont){

    float faltas, frequencia;

    // Cadastrar o nome
    getchar();
    printf("Digite o nome: ");
    fgets(lista[cont].nome, 40, stdin);
    lista[cont].nome[strcspn(lista[cont].nome, "\n")] = '\0';

    // Cadastrar o RA
    printf("Digite o RA: ");
    scanf("%d", &lista[cont].RA);

    //Cadastrar notas
    for (int i = 0; i < 2; i++){
        printf("Digite a nota: ");
        scanf("%f", &lista[cont].notas[i]);
    }

    //Frequência
    printf("Digite o numero de aulas: ");
    scanf("%f", &frequencia);
    printf("Digite o numero de faltas: ");
    scanf("%f", &faltas);

    lista[cont].frequencia = 100 - ((faltas * 100) / frequencia);

    return cont + 1;////
} 