#include <stdio.h>

int main() {
    // Variaveis da Carta 1
    char estado1, codigo1[4], cidade1[50];
    unsigned long int populacao1;
    float area1, pib1, densidade1, pibPerCapita1;
    int pontos1;

    // Variaveis da Carta 2
    char estado2, codigo2[4], cidade2[50];
    unsigned long int populacao2;
    float area2, pib2, densidade2, pibPerCapita2;
    int pontos2;

    // Cadastro Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado: ");
    scanf(" %c", &estado1);
    printf("Codigo: ");
    scanf("%s", codigo1);
    printf("Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("Populacao: ");
    scanf("%lu", &populacao1);
    printf("Area: ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontos1);

    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    // Cadastro Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado: ");
    scanf(" %c", &estado2);
    printf("Codigo: ");
    scanf("%s", codigo2);
    printf("Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("Populacao: ");
    scanf("%lu", &populacao2);
    printf("Area: ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontos2);

    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    int a1, a2;
    float v1c1 = 0, v1c2 = 0, v2c1 = 0, v2c2 = 0;

    // Primeiro menu
    printf("\n===== Escolha o PRIMEIRO atributo =====\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    scanf("%d", &a1);

    // Segundo menu dinamico
    printf("\n===== Escolha o SEGUNDO atributo =====\n");
    for (int i = 1; i <= 6; i++) {
        if (i != a1) {
            switch (i) {
                case 1: printf("1 - Populacao\n"); break;
                case 2: printf("2 - Area\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turisticos\n"); break;
                case 5: printf("5 - Densidade Demografica\n"); break;
                case 6: printf("6 - PIB per Capita\n"); break;
            }
        }
    }
    scanf("%d", &a2);

    if (a1 == a2) {
        printf("Erro: atributos iguais\n");
        return 0;
    }

    // Captura dos valores do primeiro atributo
    switch (a1) {
        case 1: v1c1 = populacao1; v1c2 = populacao2; break;
        case 2: v1c1 = area1; v1c2 = area2; break;
        case 3: v1c1 = pib1; v1c2 = pib2; break;
        case 4: v1c1 = pontos1; v1c2 = pontos2; break;
        case 5: v1c1 = densidade1; v1c2 = densidade2; break;
        case 6: v1c1 = pibPerCapita1; v1c2 = pibPerCapita2; break;
        default: printf("Opcao invalida\n"); return 0;
    }

    // Captura dos valores do segundo atributo
    switch (a2) {
        case 1: v2c1 = populacao1; v2c2 = populacao2; break;
        case 2: v2c1 = area1; v2c2 = area2; break;
        case 3: v2c1 = pib1; v2c2 = pib2; break;
        case 4: v2c1 = pontos1; v2c2 = pontos2; break;
        case 5: v2c1 = densidade1; v2c2 = densidade2; break;
        case 6: v2c1 = pibPerCapita1; v2c2 = pibPerCapita2; break;
        default: printf("Opcao invalida\n"); return 0;
    }

    // Ajuste da regra da densidade
    float soma1 = (a1 == 5 ? -v1c1 : v1c1) + (a2 == 5 ? -v2c1 : v2c1);
    float soma2 = (a1 == 5 ? -v1c2 : v1c2) + (a2 == 5 ? -v2c2 : v2c2);

    printf("\n===== Resultado Final =====\n");
    printf("%s soma: %.2f\n", cidade1, soma1);
    printf("%s soma: %.2f\n", cidade2, soma2);

    printf("\nResultado: %s\n",
        soma1 > soma2 ? cidade1 :
        soma2 > soma1 ? cidade2 :
        "Empate"
    );

    return 0;
}
