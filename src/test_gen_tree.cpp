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

    g1.BFS(1);
    g1.exportGenTreeToTxt("data/genTree/grafo_1_bfs_1.txt");
    g1.BFS(2);
    g1.exportGenTreeToTxt("data/genTree/grafo_1_bfs_2.txt");
    g1.BFS(3);
    g1.exportGenTreeToTxt("data/genTree/grafo_1_bfs_3.txt");
    g1.DFS(1);
    g1.exportGenTreeToTxt("data/genTree/grafo_1_dfs_1.txt");
    g1.DFS(2);
    g1.exportGenTreeToTxt("data/genTree/grafo_1_dfs_2.txt");
    g1.DFS(3);
    g1.exportGenTreeToTxt("data/genTree/grafo_1_dfs_3.txt");

    Graph g2("data/grafo_2.txt", false, true);

    g2.BFS(1);
    g2.exportGenTreeToTxt("data/genTree/grafo_2_bfs_1.txt");
    g2.BFS(2);
    g2.exportGenTreeToTxt("data/genTree/grafo_2_bfs_2.txt");
    g2.BFS(3);
    g2.exportGenTreeToTxt("data/genTree/grafo_2_bfs_3.txt");
    g2.DFS(1);
    g2.exportGenTreeToTxt("data/genTree/grafo_2_dfs_1.txt");
    g2.DFS(2);
    g2.exportGenTreeToTxt("data/genTree/grafo_2_dfs_2.txt");
    g2.DFS(3);
    g2.exportGenTreeToTxt("data/genTree/grafo_2_dfs_3.txt");

    Graph g3("data/grafo_3.txt", false, true);

    g3.BFS(1);
    g3.exportGenTreeToTxt("data/genTree/grafo_3_bfs_1.txt");
    g3.BFS(2);
    g3.exportGenTreeToTxt("data/genTree/grafo_3_bfs_2.txt");
    g3.BFS(3);
    g3.exportGenTreeToTxt("data/genTree/grafo_3_bfs_3.txt");
    g3.DFS(1);
    g3.exportGenTreeToTxt("data/genTree/grafo_3_dfs_1.txt");
    g3.DFS(2);
    g3.exportGenTreeToTxt("data/genTree/grafo_3_dfs_2.txt");
    g3.DFS(3);
    g3.exportGenTreeToTxt("data/genTree/grafo_3_dfs_3.txt");

    Graph g4("data/grafo_4.txt", false, true);

    g4.BFS(1);
    g4.exportGenTreeToTxt("data/genTree/grafo_4_bfs_1.txt");
    g4.BFS(2);
    g4.exportGenTreeToTxt("data/genTree/grafo_4_bfs_2.txt");
    g4.BFS(3);
    g4.exportGenTreeToTxt("data/genTree/grafo_4_bfs_3.txt");
    g4.DFS(1);
    g4.exportGenTreeToTxt("data/genTree/grafo_4_dfs_1.txt");
    g4.DFS(2);
    g4.exportGenTreeToTxt("data/genTree/grafo_4_dfs_2.txt");
    g4.DFS(3);
    g4.exportGenTreeToTxt("data/genTree/grafo_4_dfs_3.txt");

    Graph g5("data/grafo_5.txt", false, true);

    g5.BFS(1);
    g5.exportGenTreeToTxt("data/genTree/grafo_5_bfs_1.txt");
    g5.BFS(2);
    g5.exportGenTreeToTxt("data/genTree/grafo_5_bfs_2.txt");
    g5.BFS(3);
    g5.exportGenTreeToTxt("data/genTree/grafo_5_bfs_3.txt");
    g5.DFS(1);
    g5.exportGenTreeToTxt("data/genTree/grafo_5_dfs_1.txt");
    g5.DFS(2);
    g5.exportGenTreeToTxt("data/genTree/grafo_5_dfs_2.txt");
    g5.DFS(3);
    g5.exportGenTreeToTxt("data/genTree/grafo_5_dfs_3.txt");

    Graph g6("data/grafo_6.txt", false, true);

    g6.BFS(1);
    g6.exportGenTreeToTxt("data/genTree/grafo_6_bfs_1.txt");
    g6.BFS(2);
    g6.exportGenTreeToTxt("data/genTree/grafo_6_bfs_2.txt");
    g6.BFS(3);
    g6.exportGenTreeToTxt("data/genTree/grafo_6_bfs_3.txt");
    g6.DFS(1);
    g6.exportGenTreeToTxt("data/genTree/grafo_6_dfs_1.txt");
    g6.DFS(2);
    g6.exportGenTreeToTxt("data/genTree/grafo_6_dfs_2.txt");
    g6.DFS(3);
    g6.exportGenTreeToTxt("data/genTree/grafo_6_dfs_3.txt");
    
    return 0;
}