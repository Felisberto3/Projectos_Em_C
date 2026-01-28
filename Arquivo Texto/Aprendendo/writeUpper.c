#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    char ch;

    switch (argc)
    {
    case 1:
        file = stdin;
        break;
    case 2:
        if ((file = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stdout, "Arquivo %s não encontrado \n ", argv[1]);
            exit(1);
        }
        break;
    default:
        fprintf(stdout, "Parametros incorrectos \n");
        exit(2);
        break;
    }

    while ((ch = fgetc(file)) != EOF)
        putchar(toupper(ch));

    fclose(file);

    return 0;
}
