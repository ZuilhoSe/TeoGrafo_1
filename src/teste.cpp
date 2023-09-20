#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "grafos.h"

using namespace std;

int main(){
    Graph g("data/grafo_teste.txt", true, false);
    g.printAdjMatrix();
    std::vector<int> neighbors = g.returnNeighbors(8);
    g.BFS(4);
    return 0;
}