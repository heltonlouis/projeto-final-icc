/* Bibliotecas necessárias para rodar o programa*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int opcaoFuncionario, i=0, j=0, c=0, qtdPostos=0;
bool voltar = false;
// char postos[4][50];
char cadastrar;

/* Postos */
typedef struct
{
    char nome[50];
    char bairro[50];
    char logradouro[50];
} Postos;
Postos postos[200];

int funcionario(void)
{
    menuFuncionario();
    do
    {
        switch (opcaoFuncionario)
        {
        case 1:
            system("@cls||clear");
            cadastrarPostos();
            menuFuncionario();
            continue;
        case 2:
            printf("Entrou no 2 \n");
            sleep(2);
            system("@cls||clear");
            menuFuncionario();
            continue;
        case 3:
            printf("entrou no 3 \n");
            sleep(2);
            system("@cls||clear");
            menuFuncionario();
            break;
        case 0:
            voltar = true;
            system("@cls||clear");
            break;
        default:
            printf("OPÇÃO INVÁLIDA! TENTE NOVAMENTE...\n");
            sleep(2);
            system("@cls||clear");
            menuFuncionario();
        }

    } while (voltar == false);
    voltar = false;
    return 0;
}

int menuFuncionario(void)
{
    printf("############## ÁREA DO FUNCIONÁRIO ##############\n");
    printf("ESCOLHA UMA DAS OPÇÕES ABAIXO\n");
    printf("[ 1 ] PARA CADASTRAR POSTOS DE VACINAÇÃO\n");
    printf("[ 2 ] PARA LISTAR POSTOS CADASTRADOS\n");
    printf("[ 3 ] PARA CADASTRAR VACINAS\n");
    printf("[ 4 ] PARA CADASTRAR VAGAS DE AGENDAMENTO\n");
    printf("[ 0 ] PARA VOLTAR AO MENU ANTERIOR\n");
    printf("#################################################\n\n");

    printf("Opção: ");
    scanf("%d", &opcaoFuncionario);
    fflush(stdin);

    return 0;
}

int menuPostos(void)
{
    printf("################################################\n");
    printf("         CADASTRAR POSTOS DE VACINAÇÃO\n");
    printf("################################################\n\n");

    return 0;
}

int cadastrarPostos(void)
{
    menuPostos();
    do
    {
        printf("Quantos Postos deseja cadastrar? ");
        scanf("%d", &c);
        limpar_entrada();

        for (i=0; i<c; i++) {
            printf("Digite o nome do Posto: ");
            gets(&postos[qtdPostos].nome);

            printf("ENDEREÇO \n");
            printf("Bairro do Posto: ");
            gets(&postos[qtdPostos].bairro);

            printf("Logradouro do Posto: ");
            gets(&postos[qtdPostos].logradouro);

            qtdPostos++;
        }

        for (i=0; i<qtdPostos; i++) {
            printf("\nPosto %d: %s", i, postos[i].nome);
        }
        
        do {
            printf("\nDeseja cadastrar um novo Posto? [s/n] ");
            scanf("%s", &cadastrar);
            if( cadastrar == 'n' ) {
                voltar = true;
                break;
            } else if ( cadastrar == 's' ) {
                break;
            } else {
                printf("Opção Inválida, Tente novamente...\n");
                continue;
            }
        } while( true );

        limpar_entrada();
        
    } while (voltar == false);
    voltar = false;
    return 0;
}