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

    g1.exportInfoToTxt("data/info_1.txt");
    g2.exportInfoToTxt("data/info_2.txt");
    g3.exportInfoToTxt("data/info_3.txt");
    g4.exportInfoToTxt("data/info_4.txt");
    g5.exportInfoToTxt("data/info_5.txt");
    g6.exportInfoToTxt("data/info_6.txt");

    return 0;
}