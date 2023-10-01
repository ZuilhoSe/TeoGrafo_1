#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include "grafos.h"

using namespace std;

int main(){
    Graph g1("data/grafo_1.txt", false, true);
    Graph g2("data/grafo_2.txt", false, true);
    Graph g3("data/grafo_3.txt", false, true);
    Graph g4("data/grafo_4.txt", false, true);
    Graph g5("data/grafo_5.txt", false, true);
    Graph g6("data/grafo_6.txt", false, true);

    g1.exportConnectedComponentsToTxt("data/connectedComponents/grafo_1_cc.txt");
    g2.exportConnectedComponentsToTxt("data/connectedComponents/grafo_2_cc.txt");
    g3.exportConnectedComponentsToTxt("data/connectedComponents/grafo_3_cc.txt");
    g4.exportConnectedComponentsToTxt("data/connectedComponents/grafo_4_cc.txt");
    g5.exportConnectedComponentsToTxt("data/connectedComponents/grafo_5_cc.txt");
    g6.exportConnectedComponentsToTxt("data/connectedComponents/grafo_6_cc.txt");

    return 0;
}