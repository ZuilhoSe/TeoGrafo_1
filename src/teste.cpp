#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "grafos.h"

using namespace std;

int main(){
    Graph g("data/grafo_teste.txt", false, true);
    cout << "NVertices: " << g.getNVertices() << endl;
    cout << "MedianDegree: " << g.getMedianDegree() << endl;
    return 0;
}