#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa
{
    char nome[20];
    int idade;
    struct Pessoa *next;

} pessoas;

void push(pessoas **primeiraPessoa)
{
    pessoas *pessoa = malloc(sizeof(pessoas));

    printf("Informa o nome: ");
    scanf("%s", (*pessoa).nome);

    printf("Informa a idade: ");
    scanf("%d", &(*pessoa).idade);

    pessoa->next = *primeiraPessoa;

    *primeiraPessoa = pessoa;

    printf("Adicionado com sucesso\n");
}

void print(pessoas *ultimaPessoa)
{

    printf("%-20s %-5s \n", "Nome", "Idade");
    while (ultimaPessoa != NULL)
    {
        printf("%-20s %-5i \n", ultimaPessoa->nome, ultimaPessoa->idade);
        ultimaPessoa = ultimaPessoa->next;
    }

    printf("\n\n ");
}

void pop(pessoas **pessoaNoTop)
{
    pessoas *tmp = *pessoaNoTop;

    if (*pessoaNoTop == NULL)
    {
        printf("Lista vazia! \n");
        return;
    }

    *pessoaNoTop = (**pessoaNoTop).next;
    free(tmp);
    printf("Deletado com Sucesso \n");
}
int main(int argc, char const *argv[])
{
    int escolha;
    pessoas *primeiraPessoa = malloc(sizeof(pessoas));

    while (1)
    {
        printf("O que pretendes? \n");
        printf("\t1-inserir Pessoa. \n ");
        printf("\t2-mostrar Pessoa. \n ");
        printf("\t3-Deletar Pessoa: \n");
        printf("\t0- Sair \n");
        scanf("%i", &escolha);

        switch (escolha)
        {
        case 1:
            push(&primeiraPessoa);
            break;
        case 2:
            print(primeiraPessoa);
            break;
        case 3:
            pop(&primeiraPessoa);
            break;

        default:
            printf("Escolha Errada! \n");
            exit(1);
            break;
        }
    }

    return 0;
}
