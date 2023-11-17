#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

const int INF = INT_MAX;

// Função para implementar o algoritmo de Prim
void prim(int** mat, int vertices) { //** pois o numero de linhas e colunas nao e conhecido ainda
    int custos[vertices]; 
    int predecessores[vertices];
    bool visitado[vertices];

    // Inicialização
    for (int i = 0; i < vertices; ++i) {
        custos[i] = INF; // inicialmente, toda aresta possui custo infinito na MST
        predecessores[i] = -1; // inicialmente, nenhum vértice possui predecessor
        visitado[i] = false; // conjunto de vértices (cópia apenas para controle)
    }

    custos[0] = 0; // zerando a posição do vértice inicial

    while (true) {
        // Encontrar o vértice com o menor custo ainda não visitado
        int u = -1;
        for (int i = 0; i < vertices; ++i) {
            if (!visitado[i] && (u == -1 || custos[i] < custos[u])) {
                u = i; // menor custo ( como começa em infinito)
            }
        }

        if (u == -1) {
            break; // Todos os vértices foram visitados
        }

        visitado[u] = true;

        // Atualizar custos e predecessores para os vizinhos não visitados
        for (int v = 0; v < vertices; ++v) {
            if (!visitado[v] && mat[u][v] < custos[v]) {
                custos[v] = mat[u][v]; // atualiza o “custo do predecessor”
                predecessores[v] = u; // atualiza o predecessor
            }
        }
    }

    // Imprimir a Árvore Geradora Mínima
    printf("===================================\n");
    printf("         ALGORITMO DE PRIM\n");
    printf("===================================\n");

    printf("\n  Aresta\tPeso\n");
    for (int i = 1; i < vertices; ++i) {
        printf("  %d - %d \t %d\n", predecessores[i]+1, i+1, custos[i]);
    }
}

void executarAlgoritmoPrim(const char* filePath) {
    FILE *arquivo;
    int vertices, arestas; 

    arquivo = fopen(filePath, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(arquivo, "%d %d", &vertices, &arestas);

    // Aloca dinamicamente a matriz baseado nos vertices lidos
    int** matriz_adjacencia = (int**)malloc(vertices * sizeof(int*)); //sera usada para armazenar ponteiros

    for (int i = 0; i < vertices; ++i) { //armazena vertices inteiros em cada linha
        matriz_adjacencia[i] = (int*)malloc(vertices * sizeof(int)); //conforme vai tendo linhas, vai alocando memoria
    }

    // Inicializa a matriz com INF
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            matriz_adjacencia[i][j] = INF;
        }
    }

    // Preenche a matriz com as arestas e pesos do arquivo
    for (int i = 0; i < arestas; ++i) {
        int u, w, peso;
        fscanf(arquivo, "%d %d %d", &u, &w, &peso);
        matriz_adjacencia[u-1][w-1] = matriz_adjacencia[w-1][u-1] = peso; // supondo que os vértices são numerados a partir de 1
    }

    fclose(arquivo);

    prim(matriz_adjacencia, vertices);

    // Libera a memória alocada dinamicamente
    for (int i = 0; i < vertices; ++i) {
        free(matriz_adjacencia[i]);
    }
    free(matriz_adjacencia);
}