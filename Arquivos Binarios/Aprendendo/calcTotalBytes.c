
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *file;

    if (argc != 2)
    {
        printf("Erro de parametro: Deve ter 2 argumentos!");
        exit(1);
    }

    if ((file = fopen(argv[1], "rb")) == NULL)
    {
        printf("Arquivo informado nao exite");
        exit(1);
    }

    fseek(file, 0, SEEK_END);

    long numeroTotalBytes = ftell(file);
    printf("Existem %ld total de bytes \n ", numeroTotalBytes);

    return 0;
}
