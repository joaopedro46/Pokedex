#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "pokedex_base.h"

int main()
{
    FILE *fp;
    fp = fopen("Pokedex.dat","ab");
    fclose(fp);
    setlocale(LC_ALL, "Portuguese");
    int op,id = get_id();
    while(op != 5)
    {
        menu();
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                registro(&id);
                break;
            case 2:
                list_all();
                break;
            case 3:
                int id_a_buscar;
                printf("Digite o ID que deseja buscar: ");
                scanf("%d", &id_a_buscar);
                list_id(id_a_buscar);
                break;
            case 4:
                //remove_pokemon();
                break;
            case 5:
                break;

            default:
                printf("Opção inválida\n");
                system("pause");
                system("cls");
                break;
        }
    }
    //system("pause");
    return 0;
}