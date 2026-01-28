#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *ascii;
    int distancia;
    char x;

    printf("Informa o caracter: ");
    scanf("%c", &x);
    printf("Informe a distancia: ");
    scanf("%d", &distancia);

    printf("%c", *ascii);

    if ((ascii = malloc(distancia * sizeof(char) + 1)) == NULL)
    {
        printf("Erro de memoria");
        return 1;
    }

    for (int i = 0; i < distancia; i++)
    {
        ascii[i] = x + i;
    }

    ascii[distancia] = '\0';

    printf("%s", ascii);

    free(ascii);
    return 0;
}
