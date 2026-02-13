#include <stdio.h>
#include <string.h>

/*
    ============================
    ESTRUTURA DA CARTA
    ============================
*/

typedef struct {
    char nome[50];
    int populacao;
    int area;
    int pib;
    int densidade;
} Carta;


/*
    ============================
    FUNÇÃO PARA MOSTRAR MENU
    ============================
*/

void mostrarMenu(int atributoBloqueado) {

    printf("\nEscolha um atributo:\n");

    if (atributoBloqueado != 1)
        printf("1 - Populacao\n");

    if (atributoBloqueado != 2)
        printf("2 - Area\n");

    if (atributoBloqueado != 3)
        printf("3 - PIB\n");

    if (atributoBloqueado != 4)
        printf("4 - Densidade Demografica\n");

    printf("Opcao: ");
}


/*
    ============================
    FUNÇÃO PARA OBTER VALOR
    ============================
*/

int obterValor(Carta carta, int atributo) {

    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.densidade;
        default: return 0;
    }
}


/*
    ============================
    FUNÇÃO PARA NOME DO ATRIBUTO
    ============================
*/

char* nomeAtributo(int atributo) {

    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Densidade Demografica";
        default: return "Invalido";
    }
}


/*
    ============================
    FUNÇÃO PARA COMPARAR
    ============================
*/

int comparar(int valor1, int valor2, int atributo) {

    // Regra especial para Densidade
    if (atributo == 4) {
        return (valor1 < valor2) ? 1 :
               (valor2 < valor1) ? 2 : 0;
    }

    // Regra normal
    return (valor1 > valor2) ? 1 :
           (valor2 > valor1) ? 2 : 0;
}


/*
    ============================
    FUNÇÃO PRINCIPAL
    ============================
*/

int main() {

    // Cartas pré-cadastradas
    Carta carta1 = {"Brasil", 214000000, 8516000, 1800, 25};
    Carta carta2 = {"Canada", 38000000, 9985000, 2000, 4};

    int atributo1, atributo2;

    printf("=== SUPER TRUNFO - COMPARACAO AVANCADA ===\n");

    // Escolha do primeiro atributo
    do {
        mostrarMenu(0);
        scanf("%d", &atributo1);

        if (atributo1 < 1 || atributo1 > 4)
            printf("Opcao invalida! Tente novamente.\n");

    } while (atributo1 < 1 || atributo1 > 4);

    // Escolha do segundo atributo (menu dinâmico)
    do {
        mostrarMenu(atributo1);
        scanf("%d", &atributo2);

        if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1)
            printf("Opcao invalida ou repetida! Tente novamente.\n");

    } while (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1);


    /*
        ============================
        COMPARAÇÃO
        ============================
    */

    int valor1_attr1 = obterValor(carta1, atributo1);
    int valor2_attr1 = obterValor(carta2, atributo1);

    int valor1_attr2 = obterValor(carta1, atributo2);
    int valor2_attr2 = obterValor(carta2, atributo2);

    int resultado1 = comparar(valor1_attr1, valor2_attr1, atributo1);
    int resultado2 = comparar(valor1_attr2, valor2_attr2, atributo2);

    int soma1 = valor1_attr1 + valor1_attr2;
    int soma2 = valor2_attr1 + valor2_attr2;

    /*
        ============================
        EXIBIÇÃO DOS RESULTADOS
        ============================
    */

    printf("\n=== RESULTADO DA RODADA ===\n\n");

    printf("Pais 1: %s\n", carta1.nome);
    printf("Pais 2: %s\n\n", carta2.nome);

    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %d\n", carta1.nome, valor1_attr1);
    printf("%s: %d\n\n", carta2.nome, valor2_attr1);

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %d\n", carta1.nome, valor1_attr2);
    printf("%s: %d\n\n", carta2.nome, valor2_attr2);

    printf("Soma %s: %d\n", carta1.nome, soma1);
    printf("Soma %s: %d\n\n", carta2.nome, soma2);

    // Decisão final usando operador ternário
    printf("Vencedor: %s\n",
        (soma1 > soma2) ? carta1.nome :
        (soma2 > soma1) ? carta2.nome :
        "Empate!"
    );

    return 0;
}
