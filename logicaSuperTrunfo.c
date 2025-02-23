#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char estado[50];
    char codigo[20];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

// Função para cadastrar os dados de uma carta
void cadastrar_carta(struct Carta *carta) {
    printf("\n--- Cadastro de Carta ---\n");
    printf("Estado: ");
    getchar(); // Limpar o buffer
    fgets(carta->estado, 50, stdin);
    carta->estado[strcspn(carta->estado, "\n")] = '\0'; // Remover o '\n' do final da string

    printf("Código da Carta: ");
    fgets(carta->codigo, 20, stdin);
    carta->codigo[strcspn(carta->codigo, "\n")] = '\0';

    printf("Nome da Cidade: ");
    fgets(carta->cidade, 50, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = '\0';

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para comparar as duas cartas
struct Carta comparar_cartas(struct Carta carta1, struct Carta carta2, char criterio[]) {
    if (strcmp(criterio, "populacao") == 0) {
        if (carta1.populacao > carta2.populacao) return carta1;
        else return carta2;
    } else if (strcmp(criterio, "area") == 0) {
        if (carta1.area > carta2.area) return carta1;
        else return carta2;
    } else if (strcmp(criterio, "pib") == 0) {
        if (carta1.pib > carta2.pib) return carta1;
        else return carta2;
    } else if (strcmp(criterio, "pontos_turisticos") == 0) {
        if (carta1.pontos_turisticos > carta2.pontos_turisticos) return carta1;
        else return carta2;
    } else if (strcmp(criterio, "densidade_populacional") == 0) {
        float densidade1 = carta1.populacao / carta1.area;
        float densidade2 = carta2.populacao / carta2.area;
        if (densidade1 < densidade2) return carta1; // Menor densidade vence
        else return carta2;
    } else {
        printf("Critério inválido!\n");
        struct Carta carta_vazia = {};
        return carta_vazia; // Retorna uma carta vazia caso o critério seja inválido
    }
}

// Função para exibir os dados de uma carta
void exibir_carta(struct Carta carta) {
    printf("\n--- Dados da Carta ---\n");
    printf("Cidade: %s\n", carta.cidade);
    printf("Estado: %s\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$%.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

int main() {
    struct Carta carta1, carta2;
    char criterio[50];

    // Cadastro das cartas
    printf("Cadastrar primeira carta de cidade:\n");
    cadastrar_carta(&carta1);
    printf("\nCadastrar segunda carta de cidade:\n");
    cadastrar_carta(&carta2);

    // Exibir as cartas cadastradas
    printf("\nExibindo as cartas cadastradas:\n");
    exibir_carta(carta1);
    exibir_carta(carta2);

    // Escolher o critério de comparação
    printf("\nDigite o critério de comparação (populacao, area, pib, pontos_turisticos, densidade_populacional): ");
    getchar(); // Limpar o buffer após o scanf
    fgets(criterio, 50, stdin);
    criterio[strcspn(criterio, "\n")] = '\0'; // Remover o '\n' do final da string

    // Comparar as cartas com base no critério
    struct Carta carta_vencedora = comparar_cartas(carta1, carta2, criterio);

    // Exibir o resultado
    if (carta_vencedora.populacao != 0) { // Verifica se a carta vencedora é válida
        printf("\nA carta vencedora é:\n");
        exibir_carta(carta_vencedora);
    } else {
        printf("Nenhuma carta vencedora, verifique o critério.\n");
    }

    return 0;
}
