#include <stdio.h>

int main() {
    // Declaração das variáveis da Carta 1
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos1;
    float densidade1;
    float pibPerCapita1;
    float superPoder1;

    // Declaração das variáveis da Carta 2
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos2;
    float densidade2;
    float pibPerCapita2;
    float superPoder2;

    // Entrada de dados da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado: ");
    scanf(" %c", &estado1);

    printf("Codigo: ");
    scanf("%s", codigo1);

    printf("Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (km²): ");
    scanf("%f", &area1);

    printf("PIB (bilhoes): ");
    scanf("%f", &pib1);

    printf("Pontos Turisticos: ");
    scanf("%d", &pontos1);

    // Calculos da Carta 1
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    superPoder1 =
        (float)populacao1 +
        area1 +
        (pib1 * 1000000000.0) +
        pontos1 +
        pibPerCapita1 +
        (1.0 / densidade1);


    // Entrada de dados da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado: ");
    scanf(" %c", &estado2);

    printf("Codigo: ");
    scanf("%s", codigo2);

    printf("Cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km²): ");
    scanf("%f", &area2);

    printf("PIB (bilhoes): ");
    scanf("%f", &pib2);

    printf("Pontos Turisticos: ");
    scanf("%d", &pontos2);

    // Cálculos da Carta 2
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    superPoder2 =
        (float)populacao2 +
        area2 +
        (pib2 * 1000000000.0) +
        pontos2 +
        pibPerCapita2 +
        (1.0 / densidade2);

    

    // Menu interativo
    int opcao;

    printf("\n===== Menu de Comparacao =====\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("Escolha um atributo: ");
    scanf("%d", &opcao);

    printf("\n===== Resultado =====\n");
    printf("Carta 1: %s (%c)\n", cidade1, estado1);
    printf("Carta 2: %s (%c)\n\n", cidade2, estado2);

    switch (opcao) {
        case 1:
            printf("Atributo: Populacao\n");
            printf("%s: %lu\n", cidade1, populacao1);
            printf("%s: %lu\n", cidade2, populacao2);

            if (populacao1 > populacao2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (populacao2 > populacao1)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Atributo: Area\n");
            printf("%s: %.2f\n", cidade1, area1);
            printf("%s: %.2f\n", cidade2, area2);

            if (area1 > area2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (area2 > area1)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f\n", cidade1, pib1);
            printf("%s: %.2f\n", cidade2, pib2);

            if (pib1 > pib2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (pib2 > pib1)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d\n", cidade1, pontos1);
            printf("%s: %d\n", cidade2, pontos2);

            if (pontos1 > pontos2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (pontos2 > pontos1)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.2f\n", cidade1, densidade1);
            printf("%s: %.2f\n", cidade2, densidade2);

            // Regra invertida
            if (densidade1 < densidade2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (densidade2 < densidade1)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        case 6:
            printf("Atributo: PIB per Capita\n");
            printf("%s: %.2f\n", cidade1, pibPerCapita1);
            printf("%s: %.2f\n", cidade2, pibPerCapita2);

            if (pibPerCapita1 > pibPerCapita2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (pibPerCapita2 > pibPerCapita1)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opcao invalida!\n");
    }

    return 0;
}
