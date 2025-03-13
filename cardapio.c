#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

enum categorias
{
    bebida,
    principal,
    sobremesa,
    acompanhamento,
    entrada,
};
enum status
{
    pendente,
    em_preparo,
    pronto,
    entregue,
};
struct pedido
{
    int aidi;
    char cliente[100];
    struct alimento *itens;
    int num_itens;
    enum status status;
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

void printcardapio()
{
    int categoria = 0;

    printf("Cardápio:\n");
    printf("1 - Bebidas\n");
    printf("2 - Principal\n");
    printf("3 - Sobremesa\n");
    printf("4 - Acompanhamento\n");
    printf("5 - Entrada\n");
    printf("Escolha a categoria: ");
    scanf("%d", &categoria);

    int num_items = 0;
    struct alimento *itens = NULL;

    switch (categoria)
    {
    case 1:
        num_items = 8;
        itens = (struct alimento *)malloc(num_items * sizeof(struct alimento));
        if (itens == NULL)
        {
            printf("Erro de alocação de memória!\n");
            return;
        }

        snprintf(itens[0].nome, sizeof(itens[0].nome), "agua");
        snprintf(itens[1].nome, sizeof(itens[1].nome), "café");
        snprintf(itens[2].nome, sizeof(itens[2].nome), "coca cola");
        snprintf(itens[3].nome, sizeof(itens[3].nome), "coca cola 0");
        snprintf(itens[4].nome, sizeof(itens[4].nome), "suco de uva");
        snprintf(itens[5].nome, sizeof(itens[5].nome), "suco de maracujá");
        snprintf(itens[6].nome, sizeof(itens[6].nome), "suco de abacaxi");
        snprintf(itens[7].nome, sizeof(itens[7].nome), "suco de laranja");

        break;

    case 2:
        num_items = 7;
        itens = (struct alimento *)malloc(num_items * sizeof(struct alimento));
        if (itens == NULL)
        {
            printf("Erro de alocação de memória!\n");
            return;
        }
        snprintf(itens[0].nome, sizeof(itens[0].nome), "picanha ao molho barbecue");
        snprintf(itens[1].nome, sizeof(itens[1].nome), "feijoada");
        snprintf(itens[2].nome, sizeof(itens[2].nome), "hamburger de siri");
        snprintf(itens[3].nome, sizeof(itens[3].nome), "Creatina de frango");
        snprintf(itens[4].nome, sizeof(itens[4].nome), "peixe frito");
        snprintf(itens[5].nome, sizeof(itens[5].nome), "carne de carneiro");
        snprintf(itens[6].nome, sizeof(itens[6].nome), "carne de sol com queijo coalho");
        snprintf(itens[7].nome, sizeof(itens[7].nome), "coxas de frango assadas com limão");

        break;

    case 3:
        num_items = 5;
        itens = (struct alimento *)malloc(num_items * sizeof(struct alimento));
        if (itens == NULL)
        {
            printf("Erro de alocação de memória!\n");
            return;
        }

        snprintf(itens[0].nome, sizeof(itens[0].nome), "Pudim");
        snprintf(itens[1].nome, sizeof(itens[1].nome), "Sorvete de baunilha");
        snprintf(itens[2].nome, sizeof(itens[2].nome), "Bolo de chocolate");
        snprintf(itens[3].nome, sizeof(itens[3].nome), "Torta de limao");
        snprintf(itens[4].nome, sizeof(itens[4].nome), "Mousse de maracuja");

        break;

    case 4:
        num_items = 7;
        itens = (struct alimento *)malloc(num_items * sizeof(struct alimento));
        if (itens == NULL)
        {
            printf("Erro de alocação de memória!\n");
            return;
        }

        snprintf(itens[0].nome, sizeof(itens[0].nome), "Arroz");
        snprintf(itens[1].nome, sizeof(itens[1].nome), "Feijão");
        snprintf(itens[2].nome, sizeof(itens[2].nome), "Batata frita");
        snprintf(itens[3].nome, sizeof(itens[3].nome), "Salada");
        snprintf(itens[4].nome, sizeof(itens[4].nome), "Farofa");
        snprintf(itens[5].nome, sizeof(itens[5].nome), "Macarrão com queijo ralado");
        snprintf(itens[6].nome, sizeof(itens[6].nome), "macarronada");

        break;

    case 5:
        num_items = 5;
        itens = (struct alimento *)malloc(num_items * sizeof(struct alimento));
        if (itens == NULL)
        {
            printf("Erro de alocação de memória!\n");
            return;
        }

        snprintf(itens[0].nome, sizeof(itens[0].nome), "Caldo");
        snprintf(itens[1].nome, sizeof(itens[1].nome), "Canja");
        snprintf(itens[2].nome, sizeof(itens[2].nome), "Salada");
        snprintf(itens[3].nome, sizeof(itens[3].nome), "Sopa");
        snprintf(itens[4].nome, sizeof(itens[4].nome), "Brusqueta");

        break;

    default:
        printf("Categoria inválida!\n");
        return;
    }

    printf("Itens da categoria escolhida:\n");
    for (int i = 0; i < num_items; i++)
    {
        printf("%d - %s\n", i + 1, itens[i].nome);
    }

    free(itens);
}

void exibir_tela_de_carregamento(int tempo_total)
{
    int i;
    int progresso = 0;

    printf("...\n");

    for (i = 0; i <= tempo_total; i++)
    {

        progresso = (i * 100) / tempo_total;

        printf("\r[");
        for (int j = 0; j < 50; j++)
        {
            if (j < (progresso / 2))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("] %d%%", progresso);

        Sleep(100);
    }

    printf("\nCarregamento concluído!\n");
}

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
    struct alimento pedido;
    int *ptr = &quantidade;
    int logico = 1;
    int *ptr2 = &logico;

    do
    {

        printf("Para acessar o cardapio, digite 1:\n");
        printf("para acessar o cardapio vegano, digite 2:\n");
        printf("para jogar jogo da adivinhação, digite 3:\n");
        printf("para seguir com o programa, digite 4:\n");
        printf("para sair, digite 0:\n");

        scanf("%d", ptr2);
        if (logico == 1)
        {
            printcardapio();
        }
        else if (logico == 2)
        {
        }
        else if (logico == 3)
        {
            jogo();
        }
        else if (logico == 0)
        {
            printf("Muito obrigato por utilizar\nesse pseudo programa que de belo não tem nada,\naté um outro dia, amigo!\n");
        return 0;
        }
    } while (logico != 4);

    printf("digite a quantidade de itens que deseja pedir:\n");
    scanf("%d", &quantidade);

    struct pedido *clienti = (struct pedido *)malloc(quantidade * sizeof(struct pedido));
    if (clienti == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return 1;
    } else{
      printf("Digite os dados do seu pedido:\n");
        for (int i = 0; i < quantidade; i++)
        {
            printf("Digite o nome do cliente: ");
            scanf("%s", clienti[i].cliente);
            printf("Digite o número de itens do pedido: ");
            scanf("%d", &clienti[i].num_itens);
            clienti[i].itens = (struct alimento *)malloc(clienti[i].num_itens * sizeof(struct alimento));
            if (clienti[i].itens == NULL)
            {
                printf("Erro de alocação de memória!\n");
                return 1;
            }
            for (int j = 0; j < clienti[i].num_itens; j++)
            {
                printf("Digite o nome do item %d: ", j + 1);
                scanf("%s", clienti[i].itens[j].nome);
                printf("Digite o preço do item %d: ", j + 1);
                scanf("%f", &clienti[i].itens[j].preco);
                printf("Digite a quantidade do item %d: ", j + 1);
                scanf("%d", &clienti[i].itens[j].quantidade);
                printf("Digite a descrição do item %d: ", j + 1);
                scanf("%s", clienti[i].itens[j].descricao);
                printf("Digite a categoria do item %d: ", j + 1);
                scanf("%d", &clienti[i].itens[j].categoria);
            }
        }

    }



    return (0);
}
