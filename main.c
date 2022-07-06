/* Bibliotecas necessárias para rodar o programa*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* incluindo as funções em outros arquivos*/
#include "funcionario.c"
#include "paciente.c"
int funcionario(void);
int paciente(void);

/* Escopo para variáveis globais*/
int opcao;
bool sair = false;

int main(void)
{
    menuPrincipal();

    do{
        switch (opcao)
        {
        case 1:
            system("@cls||clear");
            paciente();
            system("@cls||clear");
            menuPrincipal();
            continue;
        case 2:
            system("@cls||clear");
            funcionario();
            system("@cls||clear");
            menuPrincipal();
            continue;
        case 0:
            sair = true;
            break;
        default:
            printf("OPÇÃO INVÁLIDA! TENTE NOVAMENTE...\n");
            sleep(2);
            system("@cls||clear");
            menuPrincipal();
        }

    } while (sair == false);

    return 0;
}

int menuPrincipal(void)
{
    printf("############## VACINAÇÃO CONTRA COVID-19 ##############\n");
    printf("ESCOLHA UMA DAS OPÇÕES ABAIXO\n");
    printf("[ 1 ] PARA AGENDAR VACINAÇÃO\n");
    printf("[ 2 ] PARA ACESSAR COMO FUNCIONÁRIO\n");
    printf("[ 0 ] PARA ENCERRAR O PROGRAMA\n");
    printf("########################################################\n\n");

    printf("Opção: ");
    scanf("%d", &opcao);

    return 0;
}