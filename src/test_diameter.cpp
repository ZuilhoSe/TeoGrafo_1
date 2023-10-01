#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include "grafos.h"

using namespace std;

int main(){
    ofstream fout("data/grafo_diameter.txt", std::ios::app);

    if (!fout){
        cout<<endl;
        cout << "Erro ao abrir o arquivo." << endl;
        return 0;
    }

    Graph g1("data/grafo_1.txt", false, true);
    int diameter1 = g1.calcDiameter();
    fout << "Diameter Graph 1: " << diameter1 << endl;
    g1.~Graph();

    Graph g2("data/grafo_2.txt", false, true);
    int diameter2 = g2.calcDiameter();
    fout << "Diameter Graph 2: " << diameter2 << endl;
    g2.~Graph();

    Graph g3("data/grafo_3.txt", false, true);
    int diameter3 = g3.calcDiameter();
    fout << "Diameter Graph 3: " << diameter3 << endl;
    g3.~Graph();

    Graph g4("data/grafo_4.txt", false, true);
    int diameter4 = g4.calcDiameter();
    fout << "Diameter Graph 4: " << diameter4 << endl;
    g4.~Graph();

    Graph g5("data/grafo_5.txt", false, true);
    int diameter5 = g5.calcDiameter();
    fout << "Diameter Graph 5: " << diameter5 << endl;
    g5.~Graph();

    Graph g6("data/grafo_6.txt", false, true);
    int diameter6 = g6.calcDiameter();
    fout << "Diameter Graph 6: " << diameter6 << endl;
    g6.~Graph();

    return 0;
}