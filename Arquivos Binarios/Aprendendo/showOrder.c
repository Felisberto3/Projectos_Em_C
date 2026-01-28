#include <stdio.h>
#include <stdlib.h>

int size = 10;

int main(int argc, char const *argv[])
{
    FILE *file;
    float v[size], x;
    int ordem;

    if ((file = fopen("BASE_DADOS", "wb+")) == NULL)
    {
        fprintf(stderr, "Erro: Arquivo nao validado");
        exit(1);
    }

    printf("Informa %d numeros reais: \n", size);

    for (int i = 0; i < size; i++)
    {
        printf("%dº numero: ", i + 1);
        scanf("%f", &v[i]);
    }

    if ((fwrite(v, sizeof(float), size, file)) != size)
        printf("Erro: Nao consiguimos escrever todos os numeros na base de dados. \n");

    printf("Informe uma ordem de 1 a %d : ", size);
    scanf("%d", &ordem);

    fseek(file, (ordem - 1) * sizeof(float), SEEK_SET);
    fread(&x, sizeof(float), 1, file);
    printf("\n%dº numero e : %.3f \n", ordem, x);

    rewind(file);
    fread(&x, sizeof(float), 1, file);
    printf("1º numero e: %.3f \n", x);

    fseek(file, -((long)sizeof(float)), SEEK_END);
    fread(&x, sizeof(float), 1, file);

    printf("O ultimo numero (%ld ) e: %.3f \n", ftell(file) / sizeof(float), x);

    return 0;
}
