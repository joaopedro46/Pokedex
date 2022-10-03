#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "pokedex_base.h"

int main()
{
	printf("Alunos\n\nF·bio Antonelli\nJo„o Pedro\nLucas Tavares\n");
	printf("Aperte enter para continuar...\n");
	getchar();
    FILE *fp;
    fp = fopen("Pokedex.dat","ab");
    fclose(fp);
    setlocale(LC_ALL, "Portuguese");
    int op,id = get_id();
    int id_a_buscar;
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
                printf("Digite o ID que deseja buscar: ");
                scanf("%d", &id_a_buscar);
                list_id(id_a_buscar);
                break;
            case 5:
                break;

            default:
                printf("Op√ß√£o inv√°lida\n");
                system("pause");
                system("cls");
                break;
        }
    }
    //system("pause");
    return 0;
}
