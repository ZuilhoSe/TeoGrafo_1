#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "grafos.h"

using namespace std;

int main(){
    Graph g;
    g.createGraphFromTxt("data/grafo_1.txt", false, true');
    cout << "nVertices: " << g.getNVertices() << endl;
    cout << "nEdges: " << g.getNEdges() << endl;
    cout << "minDegree: " << g.getMinDegree() << endl;
    cout << "avgDegree: " << g.getAvgDegree() << endl;
    cout << "maxDegree: " << g.getMaxDegree() << endl;
    return 0;
}