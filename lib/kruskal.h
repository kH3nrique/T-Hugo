#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "instancias.h"

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void kruskal(int **mat, int v, int a) {
    int pesos[a], pred[a];
    bool visitado[v];

    int low = 999;
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            if (mat[i][j] <= low){
                pesos[i] = mat[i][j];
                low = mat[i][j];
            }
        }
    }
    
    heapSort(pesos, a);
    int spm[a];//armazena a posição em que 
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            if (mat[i][j] == pesos[i]){
                
            }
        }
    }
    
}

void startKruskal(const char* filePath){
    FILE *file;
    int v, a;//v-> vertices a-> arestas

    file = fopen(filePath, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(file, "%d %d", &v, &a);

    // Aloca dinamicamente a matriz baseado nos vertices lidos
    int** mat = (int**)malloc(v * sizeof(int*));
    for (int i = 0; i < v; i++){
        mat[i] = (int*)malloc(v*sizeof(int));
    }
    
    //inicia matriz vazia
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            mat[i][j] = INF;
        }
    }

    //preenche a matriz
    for (int i = 0; i < a; ++i) {
        int u, w, peso;
        fscanf(file, "%d %d %d", &u, &w, &peso);
        mat[u-1][w-1] = mat[w-1][u-1] = peso; // supondo que os vértices são numerados a partir de 1
    }

    fclose(file);
    kruskal(mat, v, a);

    // Libera a memória alocada dinamicamente
    for (int i = 0; i < v; ++i) {
        free(mat[i]);
    }
    free(mat);
}

#endif