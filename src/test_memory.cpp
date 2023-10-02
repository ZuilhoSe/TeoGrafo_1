
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include "grafos.h"

using namespace std;

double getMemoryUsageMBList(std::vector<int> *List, int nVertices) {
    double sizeInMB = 0;
    sizeInMB += sizeof(List);    
    sizeInMB += sizeof(int) * nVertices;
    for (int i = 0; i < nVertices; i++){
        sizeInMB += sizeof(int) * List[i].size();
    }
    sizeInMB /= 1024 * 1024;

    return sizeInMB;
}

double getMemoryUsageMBMatrix(bool **Matrix, int nVertices) {
    double sizeInMB = 0;
    sizeInMB += sizeof(Matrix);
    sizeInMB += sizeof(bool) * nVertices;
    for (int i = 0; i < nVertices; i++){
        sizeInMB += sizeof(bool) * nVertices;
    }
    sizeInMB /= 1024 * 1024;

    return sizeInMB;
}

int main(){
    Graph g1("data/grafo_2.txt", true, false);
    
    cout << "Memory usage: " << getMemoryUsageMBMatrix(g1.Matrix, g1.getNVertices()) << " MB" << endl;

    return 0;
}
