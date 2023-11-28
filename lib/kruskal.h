#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "instancias.h"
class Kruskal {
public:
    // void mainKruskal(int a, int **mat, int order[], int u[], int w[]){
    //     int id[a];
    //     for (int i = 0; i < a; i++){
    //         id[i] = 0;
    //     }
        
    //     for (int i = 0; i < a; i++) {
    //         for (int j = 0; j < a; j++) {
    //             if (order[i] == mat[u[i]][w[j]]){
    //                 id[i] = i;
    //                 cout << "Here" <<endl;
    //             }
    //         }
    //     }
        
    //     for (int i = 0; i < a; i++){
    //         cout << id[i] <<endl;
    //         // cout << "Here\n";
    //         // int tmp;
    //         // tmp = u[id[i]];
    //         // u[id[i]] = u[i];
    //         // u[i] = tmp;
    //         // // swap;(u[id[i]], u[i]);

    //         // tmp = w[id[i]];
    //         // w[id[i]] = w[i];
    //         // w[i] = tmp;
    //         // swap(w[id[i]], w[i]);
    //     }
    // }

    void startKruskal(const char* filePath){
        FILE *file;
        int v, a;//v-> vertices a-> arestas

        file = fopen(filePath, "r");

        if (file == NULL) {
            cout << "Erro ao abrir o arquivo.\n";
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
        int u[a], w[a];
        int order[a]; //responsavel por armazenar os valores para a ordenação
        for (int i = 0; i < a; ++i) {
            int peso;
            fscanf(file, "%d %d %d", &u[i], &w[i], &peso);
            mat[u[i]-1][w[i]-1] = mat[u[i]-1][w[i]-1] = peso;
            order[i] = mat[u[i]-1][w[i]-1];
        }

        fclose(file);
        
        sort(order, order+a);
        
        // mainKruskal(a, mat, order, u, w);
        // for (int i = 0; i < a; i++){
        //     cout << "Pos: "<< order[i] <<endl;
        // }

        cout <<"\n  Aresta\tPeso" <<endl;
        for (int i = 0; i < a; ++i) {
            cout << u[i] << " - " << w[i] << "\t" << order[i] <<endl;
        }
        
        system("pause");

        // Libera a memória alocada dinamicamente
        // for (int i = 0; i < v; ++i) {
        //     free(mat[i]);
        // }
        // free(mat);
    }
};

#endif