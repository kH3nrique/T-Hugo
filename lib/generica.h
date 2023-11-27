#ifndef GENERICA_H
#define GENERICA_H

#include "instancias.h"

#define INF numeric_limits<int>::max()

struct Aresta {
    int origem, destino, peso;
};

typedef vector<vector<int>> MatrixAdjacente;

void inicializagrafo(MatrixAdjacente &grafo, int vertices) {
    grafo.resize(vertices, vector<int>(vertices, INF));
}

void AdicionarAresta(MatrixAdjacente &grafo, int u, int v, int peso) {
    grafo[u][v] = grafo[v][u] = peso;
}

void MostrarArvore(const vector<Aresta> &resultado) {

    for (const Aresta &aresta : resultado) {
        cout << "  " << aresta.origem + 1 << " - " << aresta.destino + 1 << "          " << aresta.peso << endl;
    }
}

bool formaCiclo(const vector<Aresta> &resultado, int novoV, int inicio) {
    // Verifica se adicionar a aresta forma um ciclo
    for (const Aresta &aresta : resultado) {
        if ((aresta.origem == novoV && aresta.destino == inicio) ||
            (aresta.origem == inicio && aresta.destino == novoV)) {
            return true;
        }
    }
    return false;
}

int encontrarProximoVertice(const MatrixAdjacente &grafo, const vector<bool> &visitado, int currentVertex) {
    int vertices = grafo.size();
    int nextVertex = -1;
    int minPeso = INF;

    for (int i = 0; i < vertices; ++i) {
        if (!visitado[i] && grafo[currentVertex][i] < minPeso) {
            nextVertex = i;
            minPeso = grafo[currentVertex][i];
        }
    }

    return nextVertex;
}

void AlgoritimoGenerico(const MatrixAdjacente &grafo, int startVertex) {
    int vertices = grafo.size();
    vector<bool> visitado(vertices, false);
    vector<Aresta> resultado;
    stack<int> pilha;

    pilha.push(startVertex);
    visitado[startVertex] = true;

    while (!pilha.empty() && resultado.size() < vertices - 1) {
        int u = pilha.top();
        int v = encontrarProximoVertice(grafo, visitado, u);

        if (v == -1) {
            // Se não há mais arestas disponíveis para esse vértice, desempilhar
            pilha.pop();
        } else {
            // Se a adição da aresta não forma um ciclo, adicionar à árvore e empilhar o novo vértice
            if (!formaCiclo(resultado, v, startVertex)) {
                resultado.push_back({u, v, grafo[u][v]});
                visitado[v] = true;
                pilha.push(v);
            }
        }
    }

    MostrarArvore(resultado);

    // Verificar se todos os vértices foram visitados
    for (int i = 0; i < vertices; ++i) {
        if (!visitado[i]) {
            int nextVertex = encontrarProximoVertice(grafo, visitado, i);
            if (nextVertex != -1) {
                // Continue a busca pelo caminho mais curto a partir do último vértice visitado
                cout << "Continuando a busca a partir do vértice " << i + 1 << endl;
                pilha.push(i);
                visitado[i] = true;
                while (!pilha.empty() && resultado.size() < vertices - 1) {
                    int u = pilha.top();
                    int v = encontrarProximoVertice(grafo, visitado, u);

                    if (v == -1) {
                        // Se não há mais arestas disponíveis para esse vértice, desempilhar
                        pilha.pop();
                    } else {
                        // Se a adição da aresta não forma um ciclo, adicionar à árvore e empilhar o novo vértice
                        if (!formaCiclo(resultado, v, startVertex)) {
                            resultado.push_back({u, v, grafo[u][v]});
                            visitado[v] = true;
                            pilha.push(v);
                        }
                    }
                }
                MostrarArvore(resultado);
            }
        }
    }
}

void executarAlgoritmo() {
    string filePath = "C:\\Users\\gabri\\OneDrive\\Documentos\\Quarto periodo\\Trabalho Hugo\\graph.txt";
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
        return;
    }

    int vertices, Arestas;
    file >> vertices >> Arestas;

    MatrixAdjacente matrixAdjacente;
    inicializagrafo(matrixAdjacente, vertices);

    int u, v, peso;
    for (int i = 0; i < Arestas; ++i) {
        file >> u >> v >> peso;
        AdicionarAresta(matrixAdjacente, u - 1, v - 1, peso);
    }

    file.close();

    int startVertex;

    printf("===================================\n");
    printf("         ALGORITMO GENERICO\n");
    printf("===================================\n");

    cout << "Digite o vertice de inicio: ";
    cin >> startVertex;

    printf("\n  Aresta\tPeso\n");

    if (startVertex < 1 || startVertex > vertices) {
        cout << "Vertice de inicio invalido." << endl;
        return;
    }

    AlgoritimoGenerico(matrixAdjacente, startVertex - 1);
}

#endif