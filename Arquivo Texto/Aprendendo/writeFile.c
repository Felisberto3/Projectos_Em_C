#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fin, *fout;
    int ch;

    // Testar a linha de comando

    if (argc != 3)
    {
        printf("Sintaxe: \n\n %s Origem Destino \n \n", argv[0]);
        exit(1);
    }

    // Abrir o arquivo de origem

    fin = fopen(argv[1], "rb");
    if (fin == NULL)
    {
        printf("Impossivel abrir o arquivo %s ", argv[1]);
        exit(2);
    }

    // Abrir arquivo de destino

    if ((fout = fopen(argv[2], "wb")) == NULL)
    {
        printf("Impossivel criar o arquivo %s \n ", argv[2]);
        exit(3);
    }

    while ((ch = fgetc(fin)) != EOF)
    {
        fputc(ch, fout);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
