#include <stdio.h>
#include <windows.h>  // Para usar a função Sleep

void exibir_tela_de_carregamento(int tempo_total) {
    int i;
    int progresso = 0;
    
    printf("Carregando...\n");

    // Barra de progresso: percorre o tempo total de carregamento
    for (i = 0; i <= tempo_total; i++) {
        // Calcula a porcentagem de progresso
        progresso = (i * 100) / tempo_total;
        
        // Exibe a barra de progresso
        printf("\r[");
        for (int j = 0; j < 50; j++) {
            if (j < (progresso / 2)) { // 50 espaços na barra, cada 2% é representado por 1 espaço
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("] %d%%", progresso);
        
        // Atraso de 100 milissegundos para simular o carregamento
        Sleep(100); // 100 milissegundos
    }

    printf("\nCarregamento concluído!\n");
}

int main() {
    int tempo_total = 100; // Total de "passos" para o carregamento

    exibir_tela_de_carregamento(tempo_total);

    return 0;
}
