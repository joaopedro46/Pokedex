#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define tamanho 10
/*
4. Faça um programa para gerenciar uma agenda de contatos. Para cada
contato armazene o nome, o telefone e o aniversário (dia e mês).
programa deve permitir
(a) inserir contato.
(b) remover contato.
(c) pesquisar um contato pelo nome.
(d) listar todos os contatos.
(e) listar os contatos cujo nome inicia com uma dada letra.
(f) imprimir os aniversariantes do mês.
Sempre que o programa for encerrado, os contatos devem ser
armazenados em um arquivo binário. Quando o programa iniciar, os
contatos devem ser inicializados com os dados contidos neste
arquivo binário.
*/
struct add_Ctt
{
    char nome_ctt[50], num_ctt[13];
    int dia_ctt, mes_ctt, ano_ctt;
};
struct add_Ctt add[tamanho];
int opcao = 0, ultimo = 0;

void clean_stdin(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    FILE *agenda;
    agenda = fopen("/home/antonelli345/Documentos/Agenda.txt", "w");

    do
    {
        printf("\n===================================================");
        printf("\n|1-Adicionar contato.                             |");
        printf("\n|2-Remover contato.                               |");
        printf("\n|3-Ver contatos.                                  |");
        printf("\n|4-Ver contatos com letra inicial específica.     |");
        printf("\n|5-Aniversariantes do mês.                        |");
        printf("\n|0-Sair.                                          |");
        printf("\n===================================================");
        printf("\n\n\nDigite uma opção: ");

        scanf("%d", &opcao);
        system("cls || clear");

        switch (opcao)
        {
        case 0:
            system("cls || clear");
            printf("Saindo do menu...\n");
            for (int i = 0; i < ultimo; i++)
            {
                if ((strcmp("deletado", add[i].nome_ctt)) != 0){
                    printf("work here");
                    fwrite(&add[i], sizeof(add), 1, agenda);
                }
            }
            break;
        case 1: // inserir contato
            system("cls || clear");

            printf("\n===================================================");
            printf("\nDigite o nome do contato: ");
            clean_stdin();
            gets(add[ultimo].nome_ctt);

            //   fprintf(agenda, add[ultimo].nome_ctt);
            printf("\n===================================================");
            printf("\nDigite o numero do contato: ");
            gets(add[ultimo].num_ctt);
            //  fprintf(agenda, add[ultimo].num_ctt);
            printf("\n===================================================");
            printf("\nDigite o dia do nascimento: ");
            scanf("%d", &add[ultimo].dia_ctt);

            //   fprintf(agenda, add[ultimo].dia_ctt);
            printf("===================================================");
            printf("\nDigite o mês do nascimento: ");
            clean_stdin();
            scanf("%d", &add[ultimo].mes_ctt);
            //  fprintf(agenda, add[ultimo].mes_ctt);
            printf("\n===================================================");
            printf("\nDigite o ano do nascimento: ");
            scanf("%d", &add[ultimo].ano_ctt);
            //   fprintf(agenda, add[ultimo].ano_ctt);
            printf("\n===================================================");
            ultimo++;
            break;
        case 2: // remover contato
            system("cls || clear");
            getchar();
            printf("Digite o nome deletado: ");
            char deletado[30];
            gets(deletado);
            for (int i = 0; i < ultimo; i++)
            {
                if (
                    (strcmp(deletado, add[i].nome_ctt)) == 0)
                {
                    strcpy(add[i].nome_ctt, "deletado");
                    break;
                }
            }
            break;
        case 3: // listar todos os contatos.
            system("cls || clear");
            // printf("%s", add->nome_ctt[1]);
            for (int i = 0; i < ultimo; i++)
            {
                // printf("%s", add->nome_ctt[1]);
                printf("%s %s %d/%d/%d\n", add[i].nome_ctt, add[i].num_ctt, add[i].dia_ctt, add[i].mes_ctt, add[i].ano_ctt);
            }

            break;
        case 4: // listar os contatos cujo nome inicia com uma dada letra.
            system("cls || clear");
            getchar();
            printf("Digite a letra procurada: ");
            char inicial;
            inicial = getchar();
            for (int i = 0; i < ultimo; i++)
            {
                // if ((strcmp(inicial, add[i].nome_ctt)) == 0)

                if (inicial == add[i].nome_ctt[0])
                {
                    printf("\n%s %s %d/%d/%d\n", add[i].nome_ctt, add[i].num_ctt, add[i].dia_ctt, add[i].mes_ctt, add[i].ano_ctt);
                    //fwrite(add[i].nome_ctt);
                    break;
                }
            }
            break;
        case 5:
            system("cls || clear");
            printf("Digite o mês desejado: ");
            int mes_desejado;
            scanf("%d", &mes_desejado);
            for (int i = 0; i < tamanho; i++)
            {
                if (add[i].mes_ctt == mes_desejado)
                {   
                    //printf("work here");
                    printf("\nAniversariante do mês é: \n%s no dia %d\n", add[i].nome_ctt, add[i].dia_ctt);
                }
                   
            }      
                break;
            
            default:
                system("cls || clear");
                /*printf("\n===================================================");
                printf("\n|1-Adicionar contato.                             |");
                printf("\n|2-Remover contato.                               |");
                printf("\n|3-Ver contatos.                                  |");
                printf("\n|4-Ver contatos com letra inicial específica.     |");
                printf("\n|5-Aniversariantes do mês.                        |");
                printf("\n|0-Sair.                                          |");
                printf("\n===================================================");
                printf("\n\n\nDigite uma opção: ");*/
                printf("\n Digite um valor válido: ");
                break;
            }
    } while (opcao != 0);
    fclose(agenda);
    return 0;
}