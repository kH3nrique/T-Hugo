#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "instancias.h"
class Arestas{
	int vertice1, vertice2, peso;
public:
	Arestas(int v1, int v2, int peso){
		vertice1 = v1;
		vertice2 = v2;
		this->peso = peso;
	}

	int obterVertice1(){
		return vertice1;
	}

	int obterVertice2(){
		return vertice2;
	}

	int obterPeso(){
		return peso;
	}

	// sobrescrita do operador "<"
	bool operator < (const Arestas& Arestas2) const{
		return (peso < Arestas2.peso);
	}
};

class Kruskal{
public:
    int V; // número de vértices
	vector<Arestas> Arestass; // vetor de Arestas

	// função que adiciona uma Arestas
	void adicionarArestas(int v1, int v2, int peso)
	{
		Arestas Arestas(v1, v2, peso);
		Arestass.push_back(Arestas);
	}

	// função que busca o subconjunto de um elemento "i"
	int buscar(int subset[], int i)
	{
		if(subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	// função para unir dois subconjuntos em um único subconjunto
	void unir(int subset[], int v1, int v2)
	{
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	/// função que roda o algoritmo de Kruskal
	void kruskal(){
		vector<Arestas> arvore;
		int size_arestas = Arestass.size();

		// ordena as arestas pelo menor peso
		sort(Arestass.begin(), Arestass.end());

		// aloca memória para criar "V" subconjuntos
		int * subset = new int[V];

		// inicializa todos os subconjuntos como conjuntos de um único elemento
		memset(subset, -1, sizeof(int) * V);

		for(int i = 0; i < size_arestas; i++){
			int v1 = buscar(subset, Arestass[i].obterVertice1());
			int v2 = buscar(subset, Arestass[i].obterVertice2());

			if(v1 != v2)
			{
				// se forem diferentes é porque NÃO forma ciclo, insere no vetor
				arvore.push_back(Arestass[i]);
				unir(subset, v1, v2); // faz a união
			}
		}

		int size_arvore = arvore.size();

		// mostra as arestas selecionadas com seus respectivos pesos
		for(int i = 0; i < size_arvore; i++){
			char v1 = 'A' + arvore[i].obterVertice1();
			char v2 = 'A' + arvore[i].obterVertice2();
			cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << endl;
		}
	}

    void mainKruskal(){
        FILE *file;
        int v, a;//v-> vertices a-> arestas

        file = fopen("C:\\Users\\henri\\CODE\\Faculdade\\Grafos\\T-Hugo\\graph.txt", "r");

        if (file == NULL) {
            cout << "Erro ao abrir o arquivo.\n";
            exit(1);
        }

        fscanf(file, "%d %d", &v, &a);
        int u[a], w[a], peso;
        //g(v); // grafo
        
        // adiciona as arestas
        for (int i = 0; i < a; i++){
            fscanf(file, "%d %d %d", &u[i], &w[i], &peso);
            adicionarArestas(u[i] - 1, w[i] - 1, peso);
        }
        
        kruskal(); // roda o algoritmo de Kruskal
        system("pause");
    }

};

#endif