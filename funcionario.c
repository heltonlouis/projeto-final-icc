#include <stdio.h>
#include <stdbool.h>

int funcionario()
{
    bool sair = false;
    int opcaoFuncionario;

    printf("Área do Funcionario\n\n");
    printf("Digite uma das opções abaixo: \n");

    printf("[ 1 ] Para cadastrar postos de vacinação\n");
    printf("[ 2 ] Para cadastrar vacinas\n");
    printf("[ 3 ] Para cadastrar vagas de agendamento\n");

    do
    {

        scanf("%d", &opcaoFuncionario);

        switch (opcaoFuncionario)
        {
        case 1:
            system("@cls||clear");
            cadastrarPostos();
            break;
        case 2:
            printf("entrou no 2\n");
            break;
        case 3:
            printf("entrou no 3\n");
            break;
        default:
            printf(" Opção Inválida \n\n");
            printf("[ 1 ] Para cadastrar postos de vacinação\n");
            printf("[ 2 ] Para cadastrar vacinas\n");
            printf("[ 3 ] Para cadastrar vagas de agendamento\n");
            break;
        }

    } while (sair == false);
}

int cadastrarPostos()
{
    bool sair =  false;
    char nomePosto [10][50];
    char continuar[1];
    do
    {
        printf("CADASTRAR POSTOS");
        
        /* printf("\nDigite o Nome do Posto: ");
        gets(nomePosto); */

        printf("Deseja cadastrar outro Posto? [s/n] ");
        gets(&continuar[0]);

        if ( continuar == "n")
        {
            sair = true;
        }
        

    } while ( sair == false );

    return 0;
}