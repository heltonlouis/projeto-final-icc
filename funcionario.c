/* Bibliotecas necessárias para rodar o programa*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int opcaoFuncionario, i = 0, j = 0, cont = 0;
int qtdPostos = 0, qtdVacinas = 0;
bool voltar = false;
char cadastrar;

/* Vacinas */
typedef struct
{
    char nome[50];
    int quantidade;
} Vacinas;
Vacinas vacinas[20];

/* Postos */
typedef struct
{
    char nome[50];
    char bairro[50];
    char logradouro[50];
    int vagas;
    Vacinas vacinas[20];
} Postos;
Postos postos[200];

typedef struct 
{
    int vagas;
    char data[100];
    int dia;
    int mes;
    int ano;
    Postos postos[200];
} Agendamento;
Agendamento agenda[200];


int funcionario(void)
{
    limpar_entrada();
    system("@cls||clear");

    do
    {
        menuFuncionario();
        switch (opcaoFuncionario)
        {
        case 1:
            system("@cls||clear");
            cadastrarPostos();
            system("@cls||clear");
            continue;
        case 2:
            system("@cls||clear");
            if (qtdPostos > 0)
            {
                listarPostos();
            }
            else
            {
                system("@cls||clear");
                printf("Não Existem Postos Cadastrados\n\n");
                sleep(1);
                printf("Volte ao Menu de funcionarios e cadastre os Postos!\n");
                printf("\nPressione Enter, para voltar ao menu anterior!");
                while (getchar() != '\n')
                    ;
            }
            system("@cls||clear");
            continue;
        case 3:
            system("@cls||clear");
            cadastrarVacinas();
            system("@cls||clear");
            continue;
        case 4:
            system("@cls||clear");
            if (qtdVacinas > 0)
            {
                listarVacinas();
            }
            else
            {
                system("@cls||clear");
                printf("Não Existem Vacinas Cadastradas em estoque\n\n");
                sleep(1);
                printf("Volte ao Menu de funcionarios e cadastre as Vacinas Recebidas no último lote\n");
                printf("\nPressione Enter, para voltar ao menu anterior!");
                while (getchar() != '\n')
                    ;
            }
            system("@cls||clear");
            continue;
        case 5:
            system("@cls||clear");
            vagasAgendamento();
            system("@cls||clear");
            continue;
        case 0:
            voltar = true;
            system("@cls||clear");
            break;
        default:
            printf("OPÇÃO INVÁLIDA! TENTE NOVAMENTE...\n");
            sleep(2);
            system("@cls||clear");
            continue;
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
    printf("[ 2 ] PARA LISTAR/EDITAR POSTOS CADASTRADOS\n");
    printf("[ 3 ] PARA CADASTRAR VACINAS\n");
    printf("[ 4 ] PARA LISTAR VACINAS CADASTRADAS\n");
    printf("[ 5 ] PARA CADASTRAR VAGAS DE AGENDAMENTO\n");
    printf("[ 0 ] PARA VOLTAR AO MENU ANTERIOR\n");
    printf("#################################################\n\n");

    printf("Opção: ");
    scanf("%d", &opcaoFuncionario);
    limpar_entrada();

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
        system("@cls||clear");
        printf("Quantos Postos deseja cadastrar? ");
        scanf("%d", &cont);
        limpar_entrada();

        system("@cls||clear");

        for (i = 0; i < cont; i++)
        {
            printf("Digite o nome do Posto: ");
            gets(&postos[qtdPostos].nome);

            printf("ENDEREÇO \n");
            printf("Bairro do Posto: ");
            gets(&postos[qtdPostos].bairro);

            printf("Logradouro do Posto: ");
            gets(&postos[qtdPostos].logradouro);

            qtdPostos++;
            system("@cls||clear");
        }

        do
        {
            printf("\nDeseja cadastrar um novo Posto? [s/n] ");
            scanf("%s", &cadastrar);
            limpar_entrada();

            if (cadastrar == 'n')
            {
                voltar = true;
                break;
            }
            else if (cadastrar == 's')
            {
                break;
            }
            else
            {
                printf("Opção Inválida, Tente novamente...\n");
                continue;
            }
        } while (true);

    } while (voltar == false);
    voltar = false;
    return 0;
}

int listarPostos()
{

    do
    {
        printf("################################################\n");
        printf("         LISTA DE POSTOS DE VACINAÇÃO\n");
        printf("################################################\n\n");

        printf("\n[ 0 ] PARA VOLTAR AO MENU ANTERIOR");
        for (i = 0; i < qtdPostos; i++)
        {
            printf("\n[ %d ] - PARA POSTO %s( BAIRRO: %s)", i + 1, postos[i].nome, postos[i].bairro);
        }

        printf("\n\nDigite o numero do posto que deseja editar: ");
        scanf("%d", &cont);

        if (cont == 0)
        {
            voltar = true;
            break;
        }

        for (i = 0; i < cont; i++)
        {
            if (cont == i + 1)
            {
                system("@cls||clear");
                entrarPosto(i); // função para entrar no posto
                break;
            }
        }
    } while (voltar == false);
    voltar = false;
}

int entrarPosto()
{
    do
    {
        printf("################################################\n");
        printf("POSTO: %s\n", postos[i].nome);
        printf("BAIRRO: %s\n", postos[i].bairro);
        printf("POSTO: %s\n\n", postos[i].logradouro);

        printf("[ 1 ] PARA EDITAR O POSTO\n");
        printf("[ 2 ] PARA CADASTRAR VACINAS NO POSTO\n");
        printf("[ 3 ] PARA LISTAR VACINAS CADASTRADAS NO POSTO\n");
        printf("[ 4 ] PARA VAGAS DE AGENDAMENTO NO POSTO\n");
        printf("[ 0 ] PARA VOLTAR AO MENU ANTERIOR\n");
        printf("################################################\n\n");

        printf("Digite uma opção: ");
        scanf("%d", &opcaoFuncionario);
        limpar_entrada();

        switch (opcaoFuncionario)
        {
        case 1:
            system("@cls||clear");
            editarPosto(i);
            system("@cls||clear");
            break;

        case 2:
            system("@cls||clear");
            if (qtdVacinas > 0)
            {
                addVacinasPosto(i);
            }
            else
            {
                system("@cls||clear");
                printf("Não Existem Vacinas Cadastradas em estoque\n\n");
                sleep(1);
                printf("Volte ao Menu de funcionarios e cadastre as Vacinas Recebidas no último lote\n");
                printf("\nPressione Enter, para voltar ao menu anterior!");
                while (getchar() != '\n');
            }
            system("@cls||clear");
            break;

        case 3:
            if (postos[i].vacinas[0].nome > 0) {
                listarVacinasPosto(i);
            } else {
                system("@cls||clear");
                printf("Não Existem Vacinas Cadastradas em estoque\n\n");
                sleep(1);
                printf("Volte ao Menu de funcionarios e cadastre as Vacinas Recebidas no último lote\n");
                printf("\nPressione Enter, para voltar ao menu anterior!");
                while (getchar() != '\n');
            }
            
            break;

        case 0:
            voltar = true;
            break;

        default:
            break;
        }

    } while (voltar == false);
    voltar = false;
}

// Editando o Posto
int editarPosto()
{
    i;
    printf("%d", i);
    do
    {
        printf("################################################\n");
        printf("[ 1 ] PARA EDITAR O NOME\n");
        printf("[ 2 ] PARA EDITAR O BAIRRO\n");
        printf("[ 3 ] PARA EDITAR RUA\n");
        printf("[ 0 ] PARA VOLTAR AO MENU ANTERIOR\n");
        printf("################################################\n");

        printf("\nDIGITE UMA OPÇÃO: ");
        scanf("%d", &opcaoFuncionario);
        limpar_entrada();

        switch (opcaoFuncionario)
        {
        case 1:
            system("@cls||clear");
            printf("Digite o novo nome de %s: ", postos[i].nome);
            gets(&postos[i].nome);
            system("@cls||clear");
            break;
        case 2:
            system("@cls||clear");
            printf("Digite o novo bairro de %s: ", postos[i].nome);
            gets(&postos[i].bairro);
            system("@cls||clear");
            break;
        case 3:
            system("@cls||clear");
            printf("Digite o novo nome de %s: ", postos[i].nome);
            gets(&postos[i].logradouro);
            system("@cls||clear");
            break;
        case 0:
            voltar = true;
            system("@cls||clear");
            break;
        default:
            printf("\nOPÇÃO INVÁLIDA! TENTE NOVAMENTE...\n");
            sleep(2);
            system("@cls||clear");
            break;
        }
    } while (voltar == false);
    voltar = false;
    system("@cls||clear");
}

int addVacinasPosto()
{
    int tipoVac, maisVac;
    bool jaExiste;

    do
    {
        printf("################################################\n");
        printf("Vacinas Disponíveis para aquisição!\n\n");

        for (j = 0; j < qtdVacinas; j++)
        {
            printf("[ %d ] - Tipo: %s, Quantidade: %d \n", j, vacinas[j].nome, vacinas[j].quantidade);
        }
        printf("################################################\n");

        printf("\nQuantos tipos de Vacina deseja cadastrar neste Posto? ");
        scanf("%d", &cont);
        limpar_entrada();

        for (j = 0; j < cont; j++)
        {
            printf("\nDigite numero correspondente ao tipo da Vacina: ");
            scanf("%d", &tipoVac);
            limpar_entrada();

            for (int k = 0; k < sizeof(postos[i].vacinas) / sizeof(postos[i].vacinas[0]); k++)
            {   
                // Comparar duas Strings de STRUCTS
                if (strcmp(vacinas, postos[i].vacinas[k].nome) == strcmp(vacinas[tipoVac].nome, vacinas[tipoVac].nome))
                {
                    jaExiste = true;
                    break;
                }
            }

            if (jaExiste == true)
            {
                printf("\nEste tipo de Vacina já existe neste posto...\n");
                printf("\nVolte ao menu anterior para atualizar a quantidade!");
                printf("\nPressione Enter, para voltar ao menu!");
                while (getchar() != '\n');
                system("@cls||clear");
                break;
            } else {
                printf("\nDigite a quantidade de vacinas para este posto: ");
                scanf("%d", &cont);
                limpar_entrada();

                if ( cont < vacinas[tipoVac].quantidade){
                    postos[i].vacinas[tipoVac].quantidade = cont;
                    strcpy(postos[i].vacinas[tipoVac].nome, vacinas[tipoVac].nome);
                    vacinas[tipoVac].quantidade -= cont;

                    printf("\nVacina Atualizada com sucesso!\n\n");

                } else {
                    printf("\nERRO: A quantidade inserida é maior que a quantidade em estoque!\n\n");
                    printf("\nPressione Enter, para continuar!");
                    while (getchar() != '\n');
                    system("@cls||clear");
                }
                
                break;
            }
        }

        do
        {
            printf("\nDeseja cadastrar outra vacina? [ s/n ] ");
            scanf("%s", &cadastrar);
            limpar_entrada();

            if (cadastrar == 'n')
            {
                system("@cls||clear");
                voltar = true;
                break;
            }
            else if (cadastrar == 's')
            {
                system("@cls||clear");
                break;
            }
            else
            {
                system("@cls||clear");
                printf("Opção Inválida, Tente novamente...\n");
                continue;
            }
        } while (true);

    } while (voltar == false);
    voltar = false;
}

int listarVacinasPosto() {

    do
    {
        printf("################################################\n");
        printf("       VACINAS CADASTRADAS NESTE POSTO\n");
        printf("################################################\n\n");

        printf("\n[ 0 ] PARA VOLTAR AO MENU ANTERIOR");
        for (j = 0; j < qtdVacinas; j++)
        {
            printf("\n[ %d ] Vacina: %s, quantidade: %d", j+1, postos[i].vacinas[j].nome, postos[i].vacinas[j].quantidade);
        }

        printf("\n\nDigite o numero do vacina que deseja editar: ");
        scanf("%d", &cont);

        if (cont == 0)
        {
            voltar = true;
            break;
        }

        for (j = 0; j < cont; j++)
        {
            if (cont == j+1)
            {
                system("@cls||clear");
                entrarVacina(i, j); // função para entrar no posto
                break;
            }
        }
    } while (voltar == false);
    voltar = false;
}

int entrarVacina() {
    do
    {
        printf("################################################\n\n");
        printf("Estoque Geral de %s é de %d\n\n", vacinas[j].nome, vacinas[j].quantidade);

        printf("No Posto: %s \n", postos[i].nome);
        printf("Vacina: %s, Quantidade: %d \n", postos[i].vacinas[j].nome, postos[i].vacinas[j].quantidade);
        printf("################################################\n\n");
        
        printf("\nAumentar Estoque do Posto");
        printf("\nDigite a quantidade adicional: ");
        scanf("%d", &cont);
        limpar_entrada();

        if (cont <= vacinas[j].quantidade) {
            postos[i].vacinas[j].quantidade += cont;
            vacinas[j].quantidade -= cont;

            printf("\nVacina Atualizada com sucesso!\n\n");
            break;

        } else {
            printf("\nERRO: A quantidade inserida é maior que a quantidade em estoque!\n\n");
            printf("\nPressione Enter, para continuar!");
            while (getchar() != '\n');
            system("@cls||clear");
            break;
        }


    } while (voltar == false);
    voltar = false;
}

int cadastrarVacinas()
{
    printf("################################################\n");
    printf("         CADASTRO DE VACINAS\n");
    printf("################################################\n\n");

    do
    {
        printf("Quantos Vacinas deseja cadastrar? ");
        scanf("%d", &cont);
        limpar_entrada();

        system("@cls||clear");

        for (i = 0; i < cont; i++)
        {
            printf("Digite o nome da Vacina: ");
            gets(&vacinas[qtdVacinas].nome);

            printf("Quantidade: ");
            scanf("%d", &vacinas[qtdVacinas].quantidade);

            qtdVacinas++;
            system("@cls||clear");
            limpar_entrada();
        }

        for (i = 0; i < qtdVacinas; i++)
        {
            printf("\nVacina %d: %s", i + 1, vacinas[i].nome);
        }

        do
        {
            printf("\nDeseja cadastrar uma nova Vacina? [s/n] ");
            scanf("%s", &cadastrar);
            if (cadastrar == 'n')
            {
                voltar = true;
                break;
            }
            else if (cadastrar == 's')
            {
                break;
            }
            else
            {
                printf("Opção Inválida, Tente novamente...\n");
                continue;
            }
        } while (true);

        limpar_entrada();

    } while (voltar == false);
    voltar = false;
    return 0;
}

int listarVacinas()
{
    do
    {
        printf("################################################\n");
        printf("         LISTA DE VACINAS CADASTRADAS\n");
        printf("################################################\n\n");

        printf("\n[ 0 ] PARA VOLTAR AO MENU ANTERIOR");
        for (i = 0; i < qtdVacinas; i++)
        {
            printf("\n[ %d ] - Vacina: %s, quantidade: %d", i+1, vacinas[i].nome, vacinas[i].quantidade);
        }

        printf("\n\nDigite uma opção de vacina ou 0 para sair: ");
        scanf("%d", &cont);

        if (cont == 0)
        {
            voltar = true;
            break;
        }

        for (j = 0; j < cont; j++)
        {
            if (cont == j+1)
            {
                system("@cls||clear");
                editarVacinas(j); // função para entrar no posto
                break;
            }
        }
    } while (voltar == false);
    voltar = false;

}

int editarVacinas() {
    do
    {
        printf("################################################\n\n");
        printf("Vacina: %s, Quantidade: %d \n", vacinas[j].nome, vacinas[j].quantidade);
        printf("################################################\n\n");
        
        printf("\nAumentar Estoque de Vacinas");
        printf("\nDigite a quantidade adicional: ");
        scanf("%d", &cont);
        limpar_entrada();

        vacinas[j].quantidade += cont;
        printf("\nVacina Atualizada com sucesso!\n\n");
        break;

    } while (voltar == false);
    voltar = false;
}

int vagasAgendamento(){
    do
    {
        printf("################## AGENDAMENTO ##################\n");
        printf("CONSTRUIR AGENDA DE CONSULTAS\n");
        printf("[ 0 ] PARA VOLTAR AO MENU ANTERIOR\n");
        printf("[ QUALQUER TECLA ] PARA CONTINUAR\n");
        printf("#################################################\n\n");

        printf("Opção: ");
        scanf("%d", &opcaoFuncionario);
        limpar_entrada();

        if (opcaoFuncionario == 0) {
            voltar = true;
            break;
        } else {
            for (i = 0; i < qtdPostos; i++)
            {
                printf("\n[ %d ] POSTO: %s, BAIRRO: %s", i, postos[i].nome, postos[i].bairro);
            }

            printf("\nEscolha o Posto: ");
            scanf("%d", &cont);
            limpar_entrada();

            i = 0;
            do
            {
                strcpy(agenda[i].postos, postos[cont].nome);

                printf("\nEscolha uma Data: ");
                sscanf(agenda[i].data, "%d/%d/%d", &agenda[i].dia, &agenda[i].mes, &agenda[i].ano );
                limpar_entrada();

                printf("\nInsira a quantidade de vagas para esta data: ");
                scanf("%d", &agenda[i].vagas);
                limpar_entrada();

                do
                {
                    printf("\nDeseja cadastrar outra data? [ s/n ] ");
                    scanf("%s", &cadastrar);
                    limpar_entrada();

                    if (cadastrar == 'n')
                    {
                        system("@cls||clear");
                        voltar = true;
                        break;
                    }
                    else if (cadastrar == 's')
                    {
                        system("@cls||clear");
                        break;
                    }
                    else
                    {
                        system("@cls||clear");
                        printf("Opção Inválida, Tente novamente...\n");
                        continue;
                    }
                } while (true);

                i++;
            } while (voltar == false);
            voltar = false;
        }

    } while (voltar == false);
    
}