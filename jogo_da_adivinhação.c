#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jogo(){
    
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
    jogo();
    return 0;
}
