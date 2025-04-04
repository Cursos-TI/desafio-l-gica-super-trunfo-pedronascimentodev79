#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Dados da cidade 1
    char nome1[50];
    int populacao1, pontosTuristicos1;
    float area1, pib1, densidade1, pibPerCapita1;

    // Dados da cidade 2
    char nome2[50];
    int populacao2, pontosTuristicos2;
    float area2, pib2, densidade2, pibPerCapita2;

    int opcao;

    // Cadastro da cidade 1
    printf("🔹 Cadastro da Carta 1:\n");
    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // Cadastro da cidade 2
    printf("\n🔹 Cadastro da Carta 2:\n");
    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Menu de seleção
    printf("\n📋 Selecione o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (MENOR vence)\n");
    printf("6 - PIB per Capita\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    printf("\n📊 Resultado da Comparação:\n");

    if (opcao == 1) {
        if (populacao1 > populacao2) {
            printf("✔ População: %s venceu\n", nome1);
        } else if (populacao2 > populacao1) {
            printf("✔ População: %s venceu\n", nome2);
        } else {
            printf("✔ População: Empate\n");
        }
    } else if (opcao == 2) {
        if (area1 > area2) {
            printf("✔ Área: %s venceu\n", nome1);
        } else if (area2 > area1) {
            printf("✔ Área: %s venceu\n", nome2);
        } else {
            printf("✔ Área: Empate\n");
        }
    } else if (opcao == 3) {
        if (pib1 > pib2) {
            printf("✔ PIB: %s venceu\n", nome1);
        } else if (pib2 > pib1) {
            printf("✔ PIB: %s venceu\n", nome2);
        } else {
            printf("✔ PIB: Empate\n");
        }
    } else if (opcao == 4) {
        if (pontosTuristicos1 > pontosTuristicos2) {
            printf("✔ Pontos Turísticos: %s venceu\n", nome1);
        } else if (pontosTuristicos2 > pontosTuristicos1) {
            printf("✔ Pontos Turísticos: %s venceu\n", nome2);
        } else {
            printf("✔ Pontos Turísticos: Empate\n");
        }
    } else if (opcao == 5) {
        if (densidade1 < densidade2) {
            printf("✔ Densidade Populacional: %s venceu\n", nome1);
        } else if (densidade2 < densidade1) {
            printf("✔ Densidade Populacional: %s venceu\n", nome2);
        } else {
            printf("✔ Densidade Populacional: Empate\n");
        }
    } else if (opcao == 6) {
        if (pibPerCapita1 > pibPerCapita2) {
            printf("✔ PIB per Capita: %s venceu\n", nome1);
        } else if (pibPerCapita2 > pibPerCapita1) {
            printf("✔ PIB per Capita: %s venceu\n", nome2);
        } else {
            printf("✔ PIB per Capita: Empate\n");
        }
    } else {
        printf("❌ Opção inválida.\n");
    }

    return 0;
}
