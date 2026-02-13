#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

/*
    ============================
    FUNÇÃO PARA INICIALIZAR TABULEIRO
    ============================
*/

void inicializarTabuleiro(int tab[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tab[i][j] = AGUA;
        }
    }

    // Inserindo alguns navios fixos
    tab[2][2] = NAVIO;
    tab[5][5] = NAVIO;
    tab[7][3] = NAVIO;
}

/*
    ============================
    CONSTRUIR CONE (5x5)
    ============================
    Forma:
        Linha 0 → 1 elemento
        Linha 1 → 3 elementos
        Linha 2 → 5 elementos
*/

void criarCone(int hab[TAM_HAB][TAM_HAB]) {

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            // Centro da matriz
            int centro = TAM_HAB / 2;

            // Expansão gradual
            if (j >= centro - i && j <= centro + i)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

/*
    ============================
    CONSTRUIR CRUZ
    ============================
*/

void criarCruz(int hab[TAM_HAB][TAM_HAB]) {

    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (i == centro || j == centro)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

/*
    ============================
    CONSTRUIR OCTAEDRO (LOSANGO)
    ============================
*/

void criarOctaedro(int hab[TAM_HAB][TAM_HAB]) {

    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            // Distância Manhattan
            int distancia = (i - centro);
            if (distancia < 0) distancia = -distancia;

            int distanciaCol = (j - centro);
            if (distanciaCol < 0) distanciaCol = -distanciaCol;

            if (distancia + distanciaCol <= centro)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

/*
    ============================
    SOBREPOR HABILIDADE
    ============================
*/

void aplicarHabilidade(int tab[TAM_TAB][TAM_TAB],
                       int hab[TAM_HAB][TAM_HAB],
                       int origemLinha,
                       int origemColuna) {

    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (hab[i][j] == 1) {

                int linhaTab = origemLinha - offset + i;
                int colunaTab = origemColuna - offset + j;

                // Verificação de limites
                if (linhaTab >= 0 && linhaTab < TAM_TAB &&
                    colunaTab >= 0 && colunaTab < TAM_TAB) {

                    tab[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

/*
    ============================
    EXIBIR TABULEIRO
    ============================
*/

void exibirTabuleiro(int tab[TAM_TAB][TAM_TAB]) {

    printf("\n===== TABULEIRO =====\n\n");

    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {

            if (tab[i][j] == AGUA)
                printf("~ ");
            else if (tab[i][j] == NAVIO)
                printf("N ");
            else if (tab[i][j] == HABILIDADE)
                printf("* ");
        }
        printf("\n");
    }
}

/*
    ============================
    FUNÇÃO PRINCIPAL
    ============================
*/

int main() {

    int tabuleiro[TAM_TAB][TAM_TAB];

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Pontos de origem definidos no código
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 7, 7);
    aplicarHabilidade(tabuleiro, octaedro, 2, 7);

    exibirTabuleiro(tabuleiro);

    return 0;
}
