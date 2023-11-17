#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "instancias.h"

int kruskal(int **mat, int v) {
    int custos[v], pred[v];
    bool visitado[v];

    while (){
        /* code */
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
    kruskal(mat, v);

    // Libera a memória alocada dinamicamente
    for (int i = 0; i < v; ++i) {
        free(mat[i]);
    }
    free(mat);
}

#endif