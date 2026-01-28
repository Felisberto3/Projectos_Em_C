#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    char c;

    if ((file = fopen("dadosTeste.text", "rb+")) == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo! ");
    }

    fseek(file, 2, SEEK_SET);

    while ((c = getc(file)) != EOF)
    {
        printf("%c \n ", c);
    }

    fclose(file);

    return 0;
}
