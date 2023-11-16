#ifndef GENERICA_H
#define GENERICA_H

#include "instancias.h"

int generico(vector<Aresta> aresta, int n){
    int cost = 0;
    std::vector<int> tree_id(n);
    std::vector<Aresta> result;
    for (int i = 0; i < n; i++)
        tree_id[i] = i;

    sort(aresta.begin(), aresta.end());

    for (Aresta e : aresta) {
        if (tree_id[e.origem] != tree_id[e.destino]) {
            cost += e.peso;
            result.push_back(e);

            int old_id = tree_id[e.origem], new_id = tree_id[e.destino];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }
}

#endif