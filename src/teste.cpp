#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "grafos.h"

using namespace std;

int main(){
    Graph g("data/grafo_teste.txt", true, false);
    cout << "NVertices: " << g.getNVertices() << endl;
    g.BFS(1);
    g.DFS(1);
    return 0;
}