#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    time_t atual;
    time(&atual);
    struct tm *data_atual = localtime(&atual);
    printf("%d/%d/%d\n",data_atual->tm_mday,data_atual->tm_mon + 1,data_atual->tm_year+1900);
    
}