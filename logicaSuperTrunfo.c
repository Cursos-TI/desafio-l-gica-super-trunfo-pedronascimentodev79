#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Dados das cartas - 2 países
    char nomes[2][50] = {"Brasil", "Japão"};

    int populacoes[2] = {213000000, 125800000};     // População
    float areas[2] = {8515767.0, 377975.0};         // Área em km²
    float pibs[2] = {1.84, 5.06};                   // PIB em trilhões
    int pontosTuristicos[2] = {50, 80};             // Número de pontos turísticos
    float densidadeDemografica[2];                  // Densidade demográfica = população / área

    for (int i = 0; i < 2; i++) {
        densidadeDemografica[i] = populacoes[i] / areas[i];
    }

    int atributo1, atributo2;
    float valores[2][2]; // valores[país][atributo]
    float soma[2];       // soma dos dois atributos por país
    char *nomesAtributos[5] = {
        "População",
        "Área",
        "PIB",
        "Pontos Turísticos",
        "Densidade Demográfica"
    };

    printf("=== SUPER TRUNFO - PAÍSES ===\n");
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida! Encerrando programa.\n");
        return 1;
    }

    // Menu do segundo atributo (dinâmico)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            printf("%d - %s\n", i, nomesAtributos[i - 1]);
        }
    }
    printf("Digite a opção desejada: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida ou repetida! Encerrando programa.\n");
        return 1;
    }


    // Função auxiliar para retornar valor do atributo
    float getAtributo(int pais, int atributo) {
        switch (atributo) {
            case 1: return (float)populacoes[pais];
            case 2: return areas[pais];
            case 3: return pibs[pais];
            case 4: return (float)pontosTuristicos[pais];
            case 5: return densidadeDemografica[pais];
            default: return 0;
        }
    }

    // Preencher valores e somas
    for (int i = 0; i < 2; i++) {
        valores[i][0] = getAtributo(i, atributo1);
        valores[i][1] = getAtributo(i, atributo2);
        soma[i] = valores[i][0] + valores[i][1];
    }

    // Exibir os dados
    printf("\n--- Comparando %s vs %s ---\n", nomes[0], nomes[1]);

    for (int i = 0; i < 2; i++) {
        printf("\n%s:\n", nomes[i]);
        printf("%s: %.2f\n", nomesAtributos[atributo1 - 1], valores[i][0]);
        printf("%s: %.2f\n", nomesAtributos[atributo2 - 1], valores[i][1]);
        printf("Soma dos atributos: %.2f\n", soma[i]);
    }

    // Comparações
    int vencedor1 = (atributo1 == 5)
        ? (valores[0][0] < valores[1][0] ? 0 : (valores[0][0] > valores[1][0] ? 1 : -1))
        : (valores[0][0] > valores[1][0] ? 0 : (valores[0][0] < valores[1][0] ? 1 : -1));

    int vencedor2 = (atributo2 == 5)
        ? (valores[0][1] < valores[1][1] ? 0 : (valores[0][1] > valores[1][1] ? 1 : -1))
        : (valores[0][1] > valores[1][1] ? 0 : (valores[0][1] < valores[1][1] ? 1 : -1));

    printf("\n--- Resultado Individual dos Atributos ---\n");
    printf("%s: %s\n", nomesAtributos[atributo1 - 1],
           vencedor1 == -1 ? "Empate" : nomes[vencedor1]);
    printf("%s: %s\n", nomesAtributos[atributo2 - 1],
           vencedor2 == -1 ? "Empate" : nomes[vencedor2]);

    printf("\n--- Resultado Final ---\n");
    if (soma[0] > soma[1]) {
        printf("Vencedor da rodada: %s\n", nomes[0]);
    } else if (soma[1] > soma[0]) {
        printf("Vencedor da rodada: %s\n", nomes[1]);
    } else {
        printf("Empate!\n");
    }   

    return 0;
}
