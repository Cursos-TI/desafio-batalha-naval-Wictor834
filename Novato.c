int main() {
    int tabuleiro[10][10];
    const int TAM_NAVIO = 3;

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definição das posições iniciais dos navios
    int linhaH = 3, colunaH = 2; // Navio horizontal
    int linhaV = 1, colunaV = 7; // Navio vertical

    // Posicionando o navio horizontal 
    if (colunaH + TAM_NAVIO <= 10) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Posiciona o navio vertical 
    int sobreposicao = 0;
    if (linhaV + TAM_NAVIO <= 10) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (sobreposicao == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("Erro: navios sobrepostos!\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibir o cabeçalho das colunas (A-J)
    printf("\n    ");
    for (char letra = 'A'; letra < 'A' + 10; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Exibindo o tabuleiro com numeração das linhas (1 e 10)
    for (int i = 0; i < 10; i++) {
        printf("%2d | ", i + 1); // linha numerada
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}