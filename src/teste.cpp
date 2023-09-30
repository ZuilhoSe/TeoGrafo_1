#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "grafos.h"

using namespace std;

int main(){
    Graph g("data/grafo_teste.txt", false, true);
    g.exportInfoToTxt("data/grafo_teste_info.txt");
    g.BFS(1);
    return 0;
}