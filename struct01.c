#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 10

typedef struct Aluno
{
    char nome[40];
    int RA;
    float notas[2];
    float media;
    float frequencia;
} Aluno;

int inserir_aluno(Aluno[], int);
int remover_aluno(Aluno[], int);
void visualizar_alunos(Aluno[], int);
void buscar_aluno(Aluno[], int);

int main()
{
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
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opc);
        while (opc > 4)
        {
            printf("\nInvalido. Digite novamente: ");
            scanf("%d", &opc);
        }

        switch (opc)
        {
        case 1:
            cont = inserir_aluno(lista_alunos, cont);
            break;
        case 2:
            cont = remover_aluno(lista_alunos, cont);
            break;
        case 3:
            visualizar_alunos(lista_alunos, cont);
            break;
        case 4:
            buscar_aluno(lista_alunos, cont);
            break;
        default:
            break;
        }

    } while (opc != 0);
    return 1;
}

// Função para registrar alunos
int inserir_aluno(Aluno lista[], int cont)
{
    float faltas, frequencia;
    float notas_media = 0;

    printf("\n--- Registro de aluno ---\n");

    // Cadastrar o nome
    getchar();
    printf("\nDigite o nome: ");
    fgets(lista[cont].nome, 40, stdin);
    lista[cont].nome[strcspn(lista[cont].nome, "\n")] = '\0';

    // Cadastrar o RA
    printf("Digite o RA: ");
    scanf("%d", &lista[cont].RA);
    while (lista[cont].RA < 100000 || lista[cont].RA > 999999)
    {
        printf("Invalido. O RA deve conter 6 digitos. \nDigite novamente: ");
        scanf("%d", &lista[cont].RA);
    }

    // Verificação se o RA já foi registrado
    for(int i = 0; i < cont; i++){
        while(lista[i].RA == lista[cont].RA){
            printf("Invalido. Esse RA ja foi registrado. \nDigite novamente: ");
            scanf("%d", &lista[cont].RA);
        }
    }

    // Cadastrar notas
    for (int i = 0; i < 2; i++)
    {
        printf("Digite a nota: ");
        scanf("%f", &lista[cont].notas[i]);
        while (lista[cont].notas[i] < 0 || lista[cont].notas[i] > 10)
        {
            printf("Invalido. Digite novamente: ");
            scanf("%f", &lista[cont].notas[i]);
        }
    }

    //Cálculo de média
    for (int i = 0; i < 2; i++)
    {
        notas_media += lista[cont].notas[i];
    }
    lista[cont].media = notas_media / 2;

    // Frequência
    printf("Digite o numero de aulas: ");
    scanf("%f", &frequencia);
    printf("Digite o numero de faltas: ");
    scanf("%f", &faltas);
    while (faltas > frequencia || faltas < 0)
    {
        printf("Invalido. Digite novamente: ");
        scanf("%f", &faltas);
    }
    lista[cont].frequencia = 100 - ((faltas * 100) / frequencia);

    return cont + 1;
}

int remover_aluno(Aluno lista[], int cont)
{
    int RA_remocao, aux = -1;
    char confirmacao;
    
    printf("\n--- Remover aluno ---\n");
    printf("Digite o RA do aluno que deseja excluir: ");
    scanf("%d", &RA_remocao);
    while (RA_remocao < 100000 || RA_remocao > 999999)
    {
        printf("\nInvalido. O RA deve conter 6 digitos. \nDigite novamente: ");
        scanf("%d", &RA_remocao);
    }

    //Verificação se o RA digitado foi registrado
    for (int i = 0; i < cont; i++)
    {
        if (lista[i].RA == RA_remocao)
        {
            aux = i;
            break;
        }
    }

    if (aux != -1) 
    {
        printf("\nAluno encontrado: ");
        printf("\n...%s", lista[aux].nome);
        printf("\nRA: %d", lista[aux].RA);
        printf("\nMedia: %.2f", lista[aux].media);
        printf("\nFrequencia: %.1f%%\n", lista[aux].frequencia);

        printf("\nCerteza que deseja excluir o aluno dos registros? (S/N): ");
        scanf(" %c", &confirmacao);
        
        while (confirmacao != 'S' && confirmacao != 's' && confirmacao != 'N' && confirmacao != 'n')
        {
            printf("Invalido. (S/N): ");
            scanf(" %c", &confirmacao);
        }
        
        if (confirmacao == 's' || confirmacao == 'S')
        {
            for (int i = aux; i < cont - 1; i++)
            {
                lista[i] = lista[i + 1];
            }
            printf("\nAluno removido com sucesso!\n");
            return cont - 1; 
        }
        else
        {
            printf("\nRemocao de aluno cancelada!\n");
            return cont; 
        }
    }
    

    printf("\nAluno nao encontrado!\n");
    return cont;
}


// Função para visualizar os alunos registrados
void visualizar_alunos(Aluno lista[], int cont)
{
    printf("\n--- Lista de alunos ---\n");
    for (int i = 0; i < cont; i++)
    {
        printf("\n...%s", lista[i].nome);
        printf("\n%d", lista[i].RA);
        printf("\nMedia: %.2f", lista[i].media);
        printf("\nFrequencia: %.1f %\n", lista[i].frequencia);

        if (lista[i].media < 6 || lista[i].frequencia < 75.0)
        {
            printf("Status: Reprovado!\n");
        }
        else
        {
            printf("Status: Aprovado!\n");
        }
    }
}

// Função para buscar alunos através do RA
void buscar_aluno(Aluno lista[], int cont)
{
    int RA_busca, enc = -1;

    printf("\n--- Busca de aluno ---");
    printf("\nDigite o RA do aluno: ");
    scanf("%d", &RA_busca);
    while (RA_busca < 100000 || RA_busca > 999999)
    {
        printf("\nInvalido. O RA deve conter 6 digitos. \nDigite novamente: ");
        scanf("%d", &RA_busca);
    }

    for (int i = 0; i < cont; i++)
    {
        if (lista[i].RA == RA_busca)
        {
           enc = i;
           break;
        }
    }

    if (enc != -1){
            printf("\nAluno encontrado: ");
            printf("\n...%s", lista[enc].nome);
            printf("\n%d", lista[enc].RA);
            printf("\nMedia: %.2f", lista[enc].media);
            printf("\nFrequencia: %.1f%\n", lista[enc].frequencia);
    }
    if (enc == -1){
        printf("\nAluno nao encontrado!");
    }
}