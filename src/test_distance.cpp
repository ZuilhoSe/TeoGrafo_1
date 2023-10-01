#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include "grafos.h"

using namespace std;

int main(){

    ofstream fout("data/grafo_distances.txt", std::ios::app);

    if (!fout){
        cout<<endl;
        cout << "Erro ao abrir o arquivo." << endl;
        return 0;
    }

    Graph g1("data/grafo_1.txt", false, true);
    Graph g2("data/grafo_2.txt", false, true);
    Graph g3("data/grafo_3.txt", false, true);
    Graph g4("data/grafo_4.txt", false, true);
    Graph g5("data/grafo_5.txt", false, true);
    Graph g6("data/grafo_6.txt", false, true);

    
    fout << "                   " << "(10, 20)" << " " << "(10, 30)" << " " << "(20, 30)" << endl;

    int g1d1 = g1.calcDistance(10, 20);
    int g1d2 = g1.calcDistance(10, 30);
    int g1d3 = g1.calcDistance(20, 30);

    fout << "Distances Graph 1: " << g1d1 << "      " << g1d2 << "       " << g1d3 << endl;

    int g2d1 = g2.calcDistance(10, 20);
    int g2d2 = g2.calcDistance(10, 30);
    int g2d3 = g2.calcDistance(20, 30);

    fout << "Distances Graph 2: " << g2d1 << "      " << g2d2 << "       " << g2d3 << endl;

    int g3d1 = g3.calcDistance(10, 20);
    int g3d2 = g3.calcDistance(10, 30);
    int g3d3 = g3.calcDistance(20, 30);

    fout << "Distances Graph 3: " << g3d1 << "      " << g3d2 << "       " << g3d3 << endl;

    int g4d1 = g4.calcDistance(10, 20);
    int g4d2 = g4.calcDistance(10, 30);
    int g4d3 = g4.calcDistance(20, 30);

    fout << "Distances Graph 4: " << g4d1 << "      " << g4d2 << "       " << g4d3 << endl;
    
    int g5d1 = g5.calcDistance(10, 20);
    int g5d2 = g5.calcDistance(10, 30);
    int g5d3 = g5.calcDistance(20, 30);

    fout << "Distances Graph 5: " << g5d1 << "      " << g5d2 << "       " << g5d3 << endl;

    int g6d1 = g6.calcDistance(10, 20);
    int g6d2 = g6.calcDistance(10, 30);
    int g6d3 = g6.calcDistance(20, 30);

    fout << "Distances Graph 6: " << g6d1 << "      " << g6d2 << "       " << g6d3 << endl;

    fout.close();

    return 0;
}