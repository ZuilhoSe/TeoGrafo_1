#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "grafos.h"

using namespace std;

int main(){
    Graph g("data/grafo_teste.txt", false, true);
    g.exportConnectedComponentsToTxt("data/grafo_teste_info.txt");
    return 0;
}