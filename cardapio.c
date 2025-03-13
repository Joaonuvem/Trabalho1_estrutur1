#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>


void printcardapio() {
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

    switch (categoria) {
        case 1: 
            num_items = 5;
            itens = (struct alimento *)malloc(num_items * sizeof(struct alimento));
            if (itens == NULL) {
                printf("Erro de alocação de memória!\n");
                return;
            }
            
            snprintf(itens[0].nome, sizeof(itens[0].nome), "Refrigerante");
            snprintf(itens[1].nome, sizeof(itens[1].nome), "Suco");
            snprintf(itens[2].nome, sizeof(itens[2].nome), "Água");
            snprintf(itens[3].nome, sizeof(itens[3].nome), "Chá");
            snprintf(itens[4].nome, sizeof(itens[4].nome), "Café");

            break;

        case 2: 
            num_items = 5;
            itens = (struct alimento *)malloc(num_items * sizeof(struct alimento));  
            if (itens == NULL) {
                printf("Erro de alocação de memória!\n");
                return;
            }
            // Definindo os itens
            snprintf(itens[0].nome, sizeof(itens[0].nome), "Prato do dia");
            snprintf(itens[1].nome, sizeof(itens[1].nome), "Prato vegetariano");
            snprintf(itens[2].nome, sizeof(itens[2].nome), "Prato vegano");
            snprintf(itens[3].nome, sizeof(itens[3].nome), "Prato sem glúten");
            snprintf(itens[4].nome, sizeof(itens[4].nome), "Prato sem lactose");

            break;

        case 3: 
            num_items = 5;
            itens = (struct alimento *)malloc(num_items * sizeof(struct alimento));  
            if (itens == NULL) {
                printf("Erro de alocação de memória!\n");
                return;
            }

            snprintf(itens[0].nome, sizeof(itens[0].nome), "Pudim");
            snprintf(itens[1].nome, sizeof(itens[1].nome), "Sorvete");
            snprintf(itens[2].nome, sizeof(itens[2].nome), "Bolo");
            snprintf(itens[3].nome, sizeof(itens[3].nome), "Torta");
            snprintf(itens[4].nome, sizeof(itens[4].nome), "Mousse");

            break;

        case 4:
            num_items = 5;
            itens = (struct alimento *)malloc(num_items * sizeof(struct alimento));
            if (itens == NULL) {
                printf("Erro de alocação de memória!\n");
                return;
            }
            
            snprintf(itens[0].nome, sizeof(itens[0].nome), "Arroz");
            snprintf(itens[1].nome, sizeof(itens[1].nome), "Feijão");
            snprintf(itens[2].nome, sizeof(itens[2].nome), "Batata frita");
            snprintf(itens[3].nome, sizeof(itens[3].nome), "Salada");
            snprintf(itens[4].nome, sizeof(itens[4].nome), "Farofa");

            break;

        case 5: 
            num_items = 5;
            itens = (struct alimento *)malloc(num_items * sizeof(struct alimento));  
            if (itens == NULL) {
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
    for (int i = 0; i < num_items; i++) {
        printf("%d - %s\n", i + 1, itens[i].nome);
    }

    
    free(itens);
}

void exibir_tela_de_carregamento(int tempo_total) {
    int i;
    int progresso = 0;
    
    printf("...\n");

    for (i = 0; i <= tempo_total; i++) {

        progresso = (i * 100) / tempo_total;
        
        printf("\r[");
        for (int j = 0; j < 50; j++) {
            if (j < (progresso / 2)) { 
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("] %d%%", progresso);
        
        Sleep(100); 
    }

    printf("\nCarregamento concluído!\n");
}

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
    struct alimento pedido;
    int *ptr = &quantidade;
    int logico;
    int *ptr2 = &logico;

    printf("Para acessar o cardapio, digite 1:\n");
    printf("para acessar o cardapio vegano, digite 2:\n");
    printf("para jogar jogo da adivinhação, digite 3:\n");
    printf("para sair, digite 0:\n");

    scanf("%d", ptr2);
    if (logico == 1)
    {
        printcardapio();
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
    


    return (0);
}
