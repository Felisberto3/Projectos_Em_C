#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    char ch;

    if (argc != 2)
    {
        printf("Argumentos incorrectos: Arquivo Arquivo \n");
        exit(1);
    }

    if ((file = fopen(argv[1], "r+")) == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    int c;
    int contador = 0;
    int numeroLinha = 1;

    printf("%d: ", numeroLinha);

    while ((c = fgetc(file)) != EOF)
    {
        contador++;
        putchar(c); // mostra o caractere

        if (c == '\n')
        {
            printf("(%d caracteres)\n", contador);
            contador = 0;
            numeroLinha++;
            printf("%d: ", numeroLinha);
        }
    }

    return 0;
}
