#include ".\lib\Prim.h"

using namespace std;

int main() {
    int choice;

    do {
        system("cls");
        cout << "===================================" << endl;
        cout << "IMPLEMENTACAO DE ALGORITMOS DE IDENTIFICACAO DE ARVORES GERADORAS DE CUSTO MINIMO" << endl;
        cout << "===================================\n" << endl;
        cout << "1. Algoritmo Generico para deteccao de MSTs" << endl;
        cout << "2. Algoritmo de Kruskal" << endl;
        cout << "3. Algoritmo de Prim" << endl;
        cout << "0. Sair" << endl;
        cout << "\nEscolha uma opcao: ";
        cin >> choice;

        // Executar a opção escolhida
        switch (choice) {
            case 1:
                //Algoritimo Generico
                break;
            case 2:
                //Algoritimo de Kruskal
                break;
            case 3:
                system("cls");

                executarAlgoritmoPrim("C:\\Users\\gabri\\OneDrive\\Documentos\\Quarto periodo\\Trabalho Hugo\\graph.txt");

                getchar(); getchar();
                system("cls");
                break;
            case 0:
                cout << "Saindo do programa. Ate mais!" << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while (choice != 0);

    return 0;
}