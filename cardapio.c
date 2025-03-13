#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

/* - o codigo deve ser executado no windows, pois a funcao Sleep() so funciona no windows
   - o codigo deve ser aberto com a codificação Wastern (ISO 8859-1)
     para que o set locale funcione adequeadamente

     código escrito por: João Carlos de Sousa Gurgel Rocha.
     Curso: Bacharelado em Tecnologia da Informação.
     componente curricular: Algoritmos e estruturas de dados I.
     intituição: Universidade Federal do Rual do Semi-Árido - UFERSA.
     campus: Pau dos ferros.

     revisado por: 
     -Chat gpt;
     aguardando novas revisões...

     contato:
     Github: Joaonuvem .
     email: João.carlosdesousagurgelrocha@gmail.com .

     descriação: O codigo abaixo simula um cardapio de um restaurante ficticio,
     onde o usuario pode escolher os itens do cardapio e adicionar ao pedido.
     O restaurante é novo, por isso dos poucos pedidos, concerteza não é graças a minha preguiça de fazer mais...
     Esté codigo foi feio para uma atividade avaliativa da disciplina de ALgoritmos e estruturas de dados I
     unidade 1.
     
     */

void jogo()
{
    int numeroEscolhido, palpite, tentativas = 0;

    srand(time(0));

    numeroEscolhido = rand() % 100 + 1;

    printf("Bem-vindo ao jogo da Adivinhaçãoo!\n");
    printf("Eu escolhe um número entre 1 e 100. Tente adivinhar qual é!\n");

    do
    {
        printf("Digite seu palpite(1-100): ");
        printf("Digite 0 para desistir: ");
        scanf("%d", &palpite);

        tentativas++;

        if (palpite == 0)
        {
            printf("VocÃª desistiu! O nÃºmero era %d.\n", numeroEscolhido);
            break;
        }

        else if (palpite > numeroEscolhido)
        {
            printf("ihhhh, errou, O nÃºmero escolhido é menor que %d. Tente novamente.\n", palpite);
        }
        else if (palpite < numeroEscolhido)
        {
            printf("ihhhh, errou, O número escolhido é maior que %d. Tente novamente.\n", palpite);
        }
        else
        {
            printf("Parabéns! VocÃª adivinhou o número em %d tentativas!\n", tentativas);
        }

    } while (palpite != numeroEscolhido);
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

    printf("\nAtualizaÃ§Ã£o de status concluÃ­da!\n");
}

typedef enum
{
    PENDENTE,
    EM_PREPARO,
    PRONTO,
    ENTREGUE
} StatusPedido;

typedef struct
{
    char nome[50];
    float preco;
    char descricao[200];
    char categoria[30];
} ItemCardapio;

typedef struct
{
    int idPedido;
    char nomeCliente[50];
    ItemCardapio *itens;
    int qtdItens;
    StatusPedido status;
} Pedido;

void exibirCardapioPorCategoria(ItemCardapio *cardapio, int qtdItens, int categoria)
{
    switch (categoria)
    {
    case 1:
        printf("Bebidas:\n");
        for (int i = 0; i < qtdItens; i++)
        {
            if (strcmp(cardapio[i].categoria, "Bebidas") == 0)
            {
                printf("%d - %s - R$ %.2f\n", i + 1, cardapio[i].nome, cardapio[i].preco);
            }
        }
        break;
    case 2:
        printf("Pratos Principais:\n");
        for (int i = 0; i < qtdItens; i++)
        {
            if (strcmp(cardapio[i].categoria, "Principal") == 0)
            {
                printf("%d - %s - R$ %.2f\n", i + 1, cardapio[i].nome, cardapio[i].preco);
            }
        }
        break;
    case 3:
        printf("Sobremesas:\n");
        for (int i = 0; i < qtdItens; i++)
        {
            if (strcmp(cardapio[i].categoria, "Sobremesa") == 0)
            {
                printf("%d - %s - R$ %.2f\n", i + 1, cardapio[i].nome, cardapio[i].preco);
            }
        }
        break;
    case 4:
        printf("Acompanhamentos:\n");
        for (int i = 0; i < qtdItens; i++)
        {
            if (strcmp(cardapio[i].categoria, "Acompanhamento") == 0)
            {
                printf("%d - %s - R$ %.2f\n", i + 1, cardapio[i].nome, cardapio[i].preco);
            }
        }
        break;
    case 5:
        printf("Entradas:\n");
        for (int i = 0; i < qtdItens; i++)
        {
            if (strcmp(cardapio[i].categoria, "Entrada") == 0)
            {
                printf("%d - %s - R$ %.2f\n", i + 1, cardapio[i].nome, cardapio[i].preco);
            }
        }
        break;
    default:
        printf("Categoria invÃ¡lida!\n");
        break;
    }
}

void exibirPedido(Pedido pedido)
{
    printf("\nPedido ID: %d\n", pedido.idPedido);
    printf("Cliente: %s\n", pedido.nomeCliente);
    printf("Status: %s\n", pedido.status == PENDENTE ? "Pendente" : pedido.status == EM_PREPARO ? "Em PreparaÃ§Ã£o"
                                                                : pedido.status == PRONTO       ? "Pronto"
                                                                                                : "Entregue");
    printf("Itens do pedido:\n");
    for (int i = 0; i < pedido.qtdItens; i++)
    {
        printf("  %s - R$ %.2f\n", pedido.itens[i].nome, pedido.itens[i].preco);
    }
    printf("\n");
}

void adicionarCliente(Pedido **pedidos, int *qtdClientes)
{
    (*qtdClientes)++;
    *pedidos = realloc(*pedidos, (*qtdClientes) * sizeof(Pedido));

    Pedido *novoPedido = &(*pedidos)[*qtdClientes - 1];
    novoPedido->idPedido = *qtdClientes;
    printf("\nDigite o nome do cliente %d: ", *qtdClientes);
    getchar();
    fgets(novoPedido->nomeCliente, 50, stdin);
    novoPedido->nomeCliente[strcspn(novoPedido->nomeCliente, "\n")] = 0;
    novoPedido->qtdItens = 0;
    novoPedido->itens = NULL;

    printf("Cliente adicionado com sucesso!\n");
}

void atualizarStatusPedido(Pedido *pedidos, int qtdClientes)
{
    int idPedido;
    printf("Digite o ID do pedido que deseja atualizar o status: ");
    scanf("%d", &idPedido);

    if (idPedido > 0 && idPedido <= qtdClientes)
    {
        Pedido *pedido = &pedidos[idPedido - 1];
        int novoStatus;
        printf("Escolha o novo status para o pedido (0 - Pendente, 1 - Em PreparaÃ§Ã£o, 2 - Pronto, 3 - Entregue): ");
        scanf("%d", &novoStatus);

        exibir_tela_de_carregamento(50);

        if (novoStatus >= 0 && novoStatus <= 3)
        {
            pedido->status = (StatusPedido)novoStatus;
            printf("Status do pedido %d atualizado para %s.\n", pedido->idPedido,
                   novoStatus == PENDENTE ? "Pendente" : novoStatus == EM_PREPARO ? "Em PreparaÃ§Ã£o"
                                                     : novoStatus == PRONTO       ? "Pronto"
                                                                                  : "Entregue");
        }
        else
        {
            printf("Status invÃ¡lido!\n");
        }
    }
    else
    {
        printf("Pedido nÃ£o encontrado!\n");
    }
}
void removerItem(Pedido *pedido, int index)
{
    if (index < 0 || index >= pedido->qtdItens)
    {
        printf("Índice inválido!\n");
        return;
    }

    for (int i = index; i < pedido->qtdItens - 1; i++)
    {
        pedido->itens[i] = pedido->itens[i + 1];
    }

    pedido->qtdItens--;
    pedido->itens = realloc(pedido->itens, pedido->qtdItens * sizeof(ItemCardapio));
    printf("Item removido com sucesso!\n");
}
int main()
{

    setlocale(LC_ALL, "Portuguese");

    int qtdItensCardapio = 42;
    int op;

    ItemCardapio *cardapio = (ItemCardapio *)malloc(qtdItensCardapio * sizeof(ItemCardapio));

    // bebidas(nÃ£o alcolicas, nÃ£o beba, faz mal)

    strcpy(cardapio[0].nome, "Ãgua");
    cardapio[0].preco = 3.00;
    strcpy(cardapio[0].descricao, "Ãgua mineral.");
    strcpy(cardapio[0].categoria, "Bebidas");

    strcpy(cardapio[1].nome, "CafÃ©");
    cardapio[1].preco = 4.00;
    strcpy(cardapio[1].descricao, "CafÃ© expresso.");
    strcpy(cardapio[1].categoria, "Bebidas");

    strcpy(cardapio[2].nome, "Coca Cola");
    cardapio[2].preco = 5.00;
    strcpy(cardapio[2].descricao, "latinha de refrigerante de cola.");
    strcpy(cardapio[2].categoria, "Bebidas");

    strcpy(cardapio[3].nome, "Coca Cola 0");
    cardapio[3].preco = 5.00;
    strcpy(cardapio[3].descricao, "latinha de refrigerante de cola sem aÃ§Ãºcar.");
    strcpy(cardapio[3].categoria, "Bebidas");

    strcpy(cardapio[4].nome, "Suco de Uva");
    cardapio[4].preco = 4.50;
    strcpy(cardapio[4].descricao, "Suco natural de uva.");
    strcpy(cardapio[4].categoria, "Bebidas");

    strcpy(cardapio[5].nome, "Suco de Laranja");
    cardapio[5].preco = 4.50;
    strcpy(cardapio[5].descricao, "Suco natural de laranja.");
    strcpy(cardapio[5].categoria, "Bebidas");

    strcpy(cardapio[6].nome, "Suco de MaracujÃ¡");
    cardapio[6].preco = 4.50;
    strcpy(cardapio[6].descricao, "Suco natural de maracujÃ¡.");
    strcpy(cardapio[6].categoria, "Bebidas");

    strcpy(cardapio[7].nome, "Suco de Abacaxi");
    cardapio[7].preco = 4.50;
    strcpy(cardapio[7].descricao, "Suco natural de abacaxi.");
    strcpy(cardapio[7].categoria, "Bebidas");

    // pratos principais

    strcpy(cardapio[8].nome, "Picanha ao Molho Barbecue");
    cardapio[8].preco = 50.50;
    strcpy(cardapio[8].descricao, "Picanha ao molho barbecue.");
    strcpy(cardapio[8].categoria, "Principal");

    strcpy(cardapio[9].nome, "Feijoada");
    cardapio[9].preco = 40.50;
    strcpy(cardapio[9].descricao, "Feijoada completa.");
    strcpy(cardapio[9].categoria, "Principal");

    strcpy(cardapio[10].nome, "HambÃºrguer de Siri");
    cardapio[10].preco = 30.50;
    strcpy(cardapio[10].descricao, "HambÃºrguer de siri feito por uma esponja.");
    strcpy(cardapio[10].categoria, "Principal");

    strcpy(cardapio[11].nome, "Creatina de Frango");
    cardapio[11].preco = 20.50;
    strcpy(cardapio[11].descricao, "Pote de Creatina com gosto de frago");

    strcpy(cardapio[12].nome, "Peixe Frito");
    cardapio[12].preco = 30.50;
    strcpy(cardapio[12].descricao, "Nemo frito com limÃ£o.");
    strcpy(cardapio[12].categoria, "Principal");

    strcpy(cardapio[13].nome, "Carne de Carneiro");
    cardapio[13].preco = 40.50;
    strcpy(cardapio[13].descricao, "Carne de carneiro assada.");
    strcpy(cardapio[13].categoria, "Principal");

    strcpy(cardapio[14].nome, "Carnier");
    cardapio[14].preco = 40.50;
    strcpy(cardapio[14].descricao, "Carne de sol com queijo coalho .");

    strcpy(cardapio[15].nome, "Coxas de Frango");
    cardapio[15].preco = 30.50;
    strcpy(cardapio[15].descricao, "Coxas de frango assadas com limÃ£o.");
    strcpy(cardapio[15].categoria, "Principal");

    // sobremesas

    strcpy(cardapio[16].nome, "Pudim");
    cardapio[16].preco = 12.00;
    strcpy(cardapio[16].descricao, "Pudim de leite condensado.");
    strcpy(cardapio[16].categoria, "Sobremesa");

    strcpy(cardapio[17].nome, "Sorvete de Baunilha");
    cardapio[17].preco = 6.50;
    strcpy(cardapio[17].descricao, "Potinho de sorvete de baunilha.");
    strcpy(cardapio[17].categoria, "Sobremesa");

    strcpy(cardapio[18].nome, "Sorvete de Chocolate");
    cardapio[18].preco = 6.50;
    strcpy(cardapio[18].descricao, "Potinho de sorvete de chocolate.");
    strcpy(cardapio[18].categoria, "Sobremesa");

    strcpy(cardapio[19].nome, "sorvete de morango(sÃ©rio?morango cara?)");
    cardapio[19].preco = 6.50;
    strcpy(cardapio[19].descricao, "Potinho de sorvete de morango.");
    strcpy(cardapio[19].categoria, "Sobremesa");

    strcpy(cardapio[20].nome, "Bolo de Chocolate");
    cardapio[20].preco = 7.50;
    strcpy(cardapio[20].descricao, "Fatia de bolo de chocolate.");
    strcpy(cardapio[20].categoria, "Sobremesa");

    strcpy(cardapio[21].nome, "Torta de LimÃ£o");
    cardapio[21].preco = 8.50;
    strcpy(cardapio[21].descricao, "Fatia de torta de limÃ£o.");
    strcpy(cardapio[21].categoria, "Sobremesa");

    strcpy(cardapio[22].nome, "Mousse de MaracujÃ¡");
    cardapio[22].preco = 9.50;
    strcpy(cardapio[22].descricao, "Potinho de mousse de maracujÃ¡.");
    strcpy(cardapio[22].categoria, "Sobremesa");

    strcpy(cardapio[23].nome, "Goiabada com queijo");
    cardapio[23].preco = 10.50;
    strcpy(cardapio[23].descricao, "goiaba e queijo, esperava oque?");

    strcpy(cardapio[24].nome, "Doce de leite");
    cardapio[24].preco = 9.00;
    strcpy(cardapio[24].descricao, "Potinho de Doce de leite caseiro");

    // acompanhamentos

    strcpy(cardapio[25].nome, "Arroz");
    cardapio[25].preco = 5.50;
    strcpy(cardapio[25].descricao, "PorÃ§Ã£o de arroz branco.");
    strcpy(cardapio[25].categoria, "Acompanhamento");

    strcpy(cardapio[26].nome, "FeijÃ£o");
    cardapio[26].preco = 6.50;
    strcpy(cardapio[26].descricao, "PorÃ§Ã£o de feijÃ£o preto com verduras.");
    strcpy(cardapio[26].categoria, "Acompanhamento");

    strcpy(cardapio[27].nome, "Batata Frita");
    cardapio[27].preco = 7.50;
    strcpy(cardapio[27].descricao, "PorÃ§Ã£o de batata frita(feita na air fraier bilipisbalita).");
    strcpy(cardapio[27].categoria, "Acompanhamento");

    strcpy(cardapio[28].nome, "Salada verde");
    cardapio[28].preco = 8.50;
    strcpy(cardapio[28].descricao, "Salada de alface, tomate e cenoura.");
    strcpy(cardapio[28].categoria, "Acompanhamento");

    strcpy(cardapio[29].nome, "Farofa");
    cardapio[29].preco = 5.50;
    strcpy(cardapio[29].descricao, "Farofa de mandioca temperada.");
    strcpy(cardapio[29].categoria, "Acompanhamento");

    strcpy(cardapio[30].nome, "MacarrÃ£o com Queijo Ralado");
    cardapio[30].preco = 10.50;
    strcpy(cardapio[30].descricao, "MacarrÃ£o com molho de tomate e queijo ralado.");
    strcpy(cardapio[30].categoria, "Acompanhamento");

    strcpy(cardapio[31].nome, "Macarronada");
    cardapio[31].preco = 10.50;
    strcpy(cardapio[31].descricao, "MacarrÃ£o com molho de tomate e carne moÃ­da.");
    strcpy(cardapio[31].categoria, "Acompanhamento");

    strcpy(cardapio[32].nome, "Capim");
    cardapio[32].preco = 0.50;
    strcpy(cardapio[32].descricao, "Capim");
    strcpy(cardapio[32].categoria, "Acompanhamento");

    // entradas

    strcpy(cardapio[33].nome, "Caldo");
    cardapio[33].preco = 5.50;
    strcpy(cardapio[33].descricao, "Caldo de carne com legumes.");
    strcpy(cardapio[33].categoria, "Entrada");

    strcpy(cardapio[34].nome, "Canja de Galinha");
    cardapio[34].preco = 5.50;
    strcpy(cardapio[34].descricao, "Canja de galinha com legumes.");
    strcpy(cardapio[34].categoria, "Entrada");

    strcpy(cardapio[35].nome, "Vinagrete");
    cardapio[35].preco = 4.00;
    strcpy(cardapio[35].descricao, "Vinagrete de tomate, cebola e pimentÃ£o.");
    strcpy(cardapio[35].categoria, "Entrada");

    strcpy(cardapio[36].nome, "Sopa");
    cardapio[36].preco = 4.50;
    strcpy(cardapio[36].descricao, "Sopa de carne, verduras e macarrÃ£o.");
    strcpy(cardapio[36].categoria, "Entrada");

    strcpy(cardapio[37].nome, "Mini Tomates");
    cardapio[37].preco = 3.50;
    strcpy(cardapio[37].descricao, "Mini tomates salgados.");
    strcpy(cardapio[37].categoria, "Entrada");

    strcpy(cardapio[38].nome, "Doce de Goiaba");
    cardapio[38].preco = 5.00;
    strcpy(cardapio[38].descricao, "porÃ§Ã£o de barrinhas de goiaba[10 unidades]");
    strcpy(cardapio[38].categoria, "Entrada");

    strcpy(cardapio[39].nome, "Salgadinhos");
    cardapio[39].preco = 8.00;
    strcpy(cardapio[39].descricao, "porÃ§Ã£o de salgadinhos pequenos[15 unidades]");
    strcpy(cardapio[39].categoria, "Entrada");

    strcpy(cardapio[40].nome, "Torradas Marinhas");
    cardapio[40].preco = 6.00;
    strcpy(cardapio[40].descricao, "Torradas especiais feitas com molho de agua viva");
    strcpy(cardapio[40].categoria, "Entrada");

    strcpy(cardapio[41].nome, "PÃ£o de Queijo");
    cardapio[41].preco = 7.00;
    strcpy(cardapio[41].descricao, "PÃ£o de queijo fresquin[8 unidades].");
    strcpy(cardapio[41].categoria, "Entrada");

    int qtdClientes = 0;
    Pedido *pedidos = NULL;

    int opcao;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Adicionar novo cliente\n");
        printf("2. Finalizar pedidos\n");
        printf("3. Atualizar status do pedido\n");
        printf("4. jogar um joguinho da adivinhação");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            adicionarCliente(&pedidos, &qtdClientes);

            Pedido *pedido = &pedidos[qtdClientes - 1];
            int categoria;
            int op;
            while (1)
            {
                printf("\n1. Adicionar item\n2. Remover item\n3. Finalizar pedido\nEscolha uma opção: ");
                scanf("%d", &op);
                if (op == 1)
                {

                    printf("\nEscolha a categoria do cardÃ¡pio:\n");
                    printf("1. Bebidas\n2. Principal\n3. Sobremesa\n4. Acompanhamento\n5. Entrada\n");
                    printf("Escolha uma categoria: ");
                    scanf("%d", &categoria);

                    exibirCardapioPorCategoria(cardapio, qtdItensCardapio, categoria);

                    printf("Escolha o item para adicionar ao pedido (0 para finalizar): ");
                    int escolha;
                    scanf("%d", &escolha);

                    if (escolha == 0)
                    {
                        break;
                    }

                    if (escolha > 0 && escolha <= qtdItensCardapio)
                    {
                        pedido->itens = realloc(pedido->itens, (pedido->qtdItens + 1) * sizeof(ItemCardapio));
                        pedido->itens[pedido->qtdItens] = cardapio[escolha - 1];
                        pedido->qtdItens++;
                        printf("Item adicionado com sucesso!\n");
                    }
                    else
                    {
                        printf("OpÃ§Ã£o invÃ¡lida!\n");
                    }
                }
                else if (op == 2)
                {
                    int index;
                    printf("Digite o Ã­ndice do item que deseja remover: ");
                    scanf("%d", &index);
                    removerItem(pedido, index);
                }
                else if (op == 3)
                {
                    pedido->status = PENDENTE;
                    printf("\nPedido finalizado:\n");
                    exibirPedido(*pedido);
                    break;
                }
                else
                {
                    printf("OpÃ§Ã£o invÃ¡lida!\n");
                }
            }

            pedido->status = PENDENTE;
            printf("\nPedido finalizado:\n");
            exibirPedido(*pedido);
        }
        else if (opcao == 2)
        {

            printf("\nFinalizando todos os pedidos...\n");
            for (int i = 0; i < qtdClientes; i++)
            {
                exibirPedido(pedidos[i]);
            }
            break;
        }
        else if (opcao == 3)
        {
            atualizarStatusPedido(pedidos, qtdClientes);
        }
        else if (opcao == 4)
        {
            jogo();
        }
        else if (opcao == 0)
        {
            printf("Muito obrigado por utilizar esse pseudo programa que de belo nÃ£o tem nada, atÃ© um outro dia, amigo!\n");
            break;
        }
        else
        {
            printf("OpÃ§Ã£o invÃ¡lida!\n");
        }
    }

    for (int i = 0; i < qtdClientes; i++)
    {
        free(pedidos[i].itens);
    }
    free(pedidos);
    pedidos = NULL;
    free(cardapio);
    cardapio = NULL;

    return 0;
}
