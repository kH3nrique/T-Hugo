#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "instancias.h"

using namespace std;

struct Arestas {
    int vertice1, vertice2, peso;

    Arestas(int v1, int v2, int p) : vertice1(v1), vertice2(v2), peso(p) {}

    bool operator<(const Arestas &outra) const {
        return peso < outra.peso;
    }
};

int buscar(vector<int> &subset, int i) {
    if (subset[i] == -1)
        return i;
    return buscar(subset, subset[i]);
}

void unir(vector<int> &subset, int v1, int v2) {
    int v1_set = buscar(subset, v1);
    int v2_set = buscar(subset, v2);
    subset[v1_set] = v2_set;
}

void kruskal(vector<Arestas> &arestas, int Vertice) {
    vector<Arestas> arvore;
    int tamanho_arestas = arestas.size();
    int Arestas = 0;

    // Ordena as arestas pelo menor peso (S)
    sort(arestas.begin(), arestas.end());

    // cria uma floresta com |V(T)| árvores independentes)
    vector<int> subset(Vertice, -1);

    // enquanto |E(T)| < |V(G)| – 1 faça
    while (Arestas < Vertice - 1 && Arestas < tamanho_arestas) {
        //  remova uma aresta (i,j) de peso mínimo de S;
        int v1 = buscar(subset, arestas[Arestas].vertice1);
        int v2 = buscar(subset, arestas[Arestas].vertice2);

        if (v1 != v2) { // Se v1 e v2 não estão no mesmo grupo, a aresta não criará um ciclo.
            // se (i,j) conecta duas componentes distintas em T // verificar ciclo → DFS!
            arvore.push_back(arestas[Arestas]); // Adiciona a aresta atual ao vetor arvore (MST).
            unir(subset, v1, v2); // E(T) ← (i,j);
        } else {
            // senão descarte (i,j) para evitar a formação de ciclos.
        }

        Arestas++; // Avança para a próxima aresta
    }

    int size_arvore = arvore.size();

    cout << "===================================\n";
    cout << "         ALGORITMO DE KRUSKAL\n";
    cout << "===================================\n";

    cout << "\n  Aresta\tPeso\n";
    // mostra as arestas selecionadas com seus respectivos pesos
    for (int i = 0; i < size_arvore; i++) {
        int v1 = arvore[i].vertice1 + 1;
        int v2 = arvore[i].vertice2 + 1;
        cout << "  " << v1 << " - " << v2 << "           " << arvore[i].peso << std::endl;
    }

    // Verificar vértices não visitados e adicionar a menor aresta conectada
    for (int i = 0; i < Vertice; i++) {
        if (buscar(subset, i) != buscar(subset, 0)) {
            // Encontrou um vértice não visitado, adicione a menor aresta
            int menorAresta = INT_MAX;
            int v1, v2;

            for (int j = 0; j < tamanho_arestas; j++) {
                if (buscar(subset, arestas[j].vertice1) != buscar(subset, arestas[j].vertice2)) {
                    if (arestas[j].peso < menorAresta) {
                        menorAresta = arestas[j].peso;
                        v1 = arestas[j].vertice1 + 1;
                        v2 = arestas[j].vertice2 + 1;
                    }
                }
            }

            cout << "  " << v1 << " - " << v2 << "           " << menorAresta << "" << std::endl;
        }
    }
}

void kruskalMain(const string &filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo.\n";
        exit(1);
    }

    int Vertice;
    file >> Vertice;
    int a;
    file >> a;

    vector<Arestas> arestas;

    for (int i = 0; i < a; i++) {
        int u, w, peso;
        file >> u >> w >> peso;
        arestas.emplace_back(u - 1, w - 1, peso);
    }

    kruskal(arestas, Vertice); // roda o algoritmo de Kruskal
	system("pause");
}

#endif
