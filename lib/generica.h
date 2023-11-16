#ifndef GENERICA_H
#define GENERICA_H

#include "instancias.h"

int generico(int graf[V][V], int e, int tam){
    int t;
    while (e < tam - 1){//e: aresta
        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++){
                e = safe(graf[i][100], tam);
            }
        }
    }
}

#endif