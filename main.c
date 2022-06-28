#include <stdio.h>
#include <stdbool.h>
#include "funcionario.c"
#include "paciente.c"


int main()
{
    int escolhaUsuario;
    bool final = true;

    printf("********************************\n");
    printf("COVID - 19\n");

    do
    {
        printf(" Digie 1 para paciente\n");
        printf(" Digie 2 para funcionario\n");

        scanf("%d", &escolhaUsuario);
        switch (escolhaUsuario)
        {
        case 1:
            system("@cls||clear");
            paciente();
            break;

        case 2:
            system("@cls||clear");
            funcionario();
            break;

        default:
            system("@cls||clear");
            printf(" Opção Inválida \n");
            break;
        }

    } while (final == true);

    return 0;
}