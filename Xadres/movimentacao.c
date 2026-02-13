#include <stdio.h>

/*
    ============================
    FUNÇÃO RECURSIVA - TORRE
    ============================
    A Torre se move em linha reta.
    Aqui vamos simular movimento para CIMA.
    A função imprime "Cima" e chama ela mesma
    até o número de casas chegar a 0.
*/

void moverTorre(int casas) {
    if (casas <= 0) {
        return; // Caso base da recursão (para quando acabar)
    }

    printf("Cima\n");
    moverTorre(casas - 1); // Chamada recursiva diminuindo 1 casa
}


/*
    ============================
    FUNÇÃO RECURSIVA - RAINHA
    ============================
    A Rainha pode se mover como Torre ou Bispo.
    Aqui vamos simular movimento para DIREITA.
*/

void moverRainha(int casas) {
    if (casas <= 0) {
        return;
    }

    printf("Direita\n");
    moverRainha(casas - 1);
}


/*
    ============================
    FUNÇÃO RECURSIVA + LOOPS
    ============================
    BISPO
    O bispo se move na diagonal.
    Precisamos usar:
        - Recursividade
        - Loop externo (vertical)
        - Loop interno (horizontal)
*/

void moverBispo(int casas) {

    if (casas <= 0) {
        return; // Caso base
    }

    /*
        Loop externo → Movimento vertical
        Loop interno → Movimento horizontal
    */

    for (int vertical = 1; vertical <= 1; vertical++) {

        for (int horizontal = 1; horizontal <= 1; horizontal++) {

            printf("Cima\n");
            printf("Direita\n");
        }
    }

    moverBispo(casas - 1); // Chamada recursiva
}


/*
    ============================
    LOOPS COMPLEXOS - CAVALO
    ============================
    Movimento em L:
        2 casas para CIMA
        1 casa para DIREITA

    Usaremos loops aninhados,
    múltiplas variáveis,
    continue e break.
*/

void moverCavalo() {

    int movimentosVerticais = 2;
    int movimentosHorizontais = 1;

    for (int v = 1; v <= movimentosVerticais; v++) {

        if (v <= 0) {
            continue; // Apenas exemplo de controle
        }

        printf("Cima\n");

        if (v == movimentosVerticais) {

            for (int h = 1; h <= movimentosHorizontais; h++) {

                printf("Direita\n");

                if (h == movimentosHorizontais) {
                    break; // Encerra após 1 movimento horizontal
                }
            }
        }
    }
}


/*
    ============================
    FUNÇÃO PRINCIPAL
    ============================
*/

int main() {

    // Quantidade de casas definidas diretamente no código
    int casasTorre = 3;
    int casasBispo = 2;
    int casasRainha = 4;

    printf("=== Movimento da Torre ===\n");
    moverTorre(casasTorre);

    printf("\n");

    printf("=== Movimento do Bispo ===\n");
    moverBispo(casasBispo);

    printf("\n");

    printf("=== Movimento da Rainha ===\n");
    moverRainha(casasRainha);

    printf("\n");

    printf("=== Movimento do Cavalo ===\n");
    moverCavalo();

    return 0;
}
