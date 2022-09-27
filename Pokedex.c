#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "pokedex_base.h"

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    struct tm *teste1;
    int op = 0;
    while(op != 5)
    {
        menu();
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                registro();
                break;
            case 2:
                list_all();
                break;
            //case 3:
            //case 4:
            case 5:
                break;

            default:
                printf("Opção inválida\n");
                system("pause");
                system("cls");
                break;
        }
    }
    system("pause");
    return 0;
}