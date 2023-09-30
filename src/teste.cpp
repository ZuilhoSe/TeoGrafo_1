#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "grafos.h"

using namespace std;

int main(){
    Graph g("data/grafo_teste.txt", false, true);
    g.BFS(1);
    cout << g.calcDistance(1, 5);
    return 0;
}