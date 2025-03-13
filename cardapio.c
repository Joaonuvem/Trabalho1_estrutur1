#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>



enum pizzas
{
    calabresa,
    portuguesa,
    frango,
    calafranco,
    frango_ao_catupiry,
    marguerita,
    quatroqueijos,
    palmito,
    chocolate,
    banana_com_brigadeiro,
    morango_com_cocolate_branco,
    brigadeiro,
};
enum categorias
{
    bebida,
    principal,
    sobremesa,
    acompanhamento,
    entrada,
};
struct alimento
{
    char nome[50];
    float preco;
    int quantidade;
    char descricao[100];
    enum categorias categoria;
};

struct alimentoveg
{
    char nome[50];
    float preco;
    int quantidade;
    char descricao[100];
    enum categorias categoria;
};

void jogo()
{
    int numeroEscolhido, palpite, tentativas = 0;

    srand(time(0));

    numeroEscolhido = rand() % 100 + 1;

    printf("Bem-vindo ao jogo da Adivinhação!\n");
    printf("Eu escolhi um número entre 1 e 100. Tente adivinhar qual é!\n");

    do
    {
        printf("Digite seu palpite(1-100): ");
        printf("Digite 0 para desistir: ");
        scanf("%d", &palpite);

        tentativas++; 

        if (palpite == 0)
        {
            printf("Você desistiu! O número era %d.\n", numeroEscolhido);
            break;
        }

        else if (palpite > numeroEscolhido)
        {
            printf("O número escolhido é menor que %d. Tente novamente.\n", palpite);
        }
        else if (palpite < numeroEscolhido)
        {
            printf("O número escolhido é maior que %d. Tente novamente.\n", palpite);
        }
        else
        {
            printf("Parabéns! Você adivinhou o número em %d tentativas!\n", tentativas);
        }

    } while (palpite != numeroEscolhido);
}

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int quantidade;

    struct alimento comida;

    int logico;

    printf("Para acessar o cardapio, digite 1:\n");
    printf("para acessar o cardapio vegano, digite 2:\n");
    printf("para jogar jogo da adivinhação, digite 3:\n");
    printf("para sair, digite 0:\n");

    scanf("%d", &logico);
    if (logico == 1)
    {
        /* code */
    }
    else if (logico == 2)
    {
        /* code */
    }
    else if (logico == 3)
    {
        jogo();
    }
    else if (logico == 0)
    {
        /* code */
    }
    

    cardapio(quantidade, comida);

    return (0);
}
