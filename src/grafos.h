#include <iostream>
#include <string>
#include <vector>

typedef class Graph{
    private:
        int nVertices;
        bool adjMatrix;
        bool adjList;
        bool **Matrix;
        std::vector<int> *List;

    public:
        bool createGraphFromTxt(std::string sFilename, bool adjMatrix, bool adjList);
        
        // Adjacency Matrix related functions
        void createAdjMatrix(std::ifstream &fin);
        void addEdgeAdjMatrix(int v1, int v2);
        void removeEdgeAdjMatrix(int v1, int v2);
        void printAdjMatrix();

        // Adjacency List related functions
        void createAdjList(std::ifstream &fin);
        void addEdgeAdjList(int v1, int v2);
        void removeEdgeAdjList(int v1, int v2);
        void printAdjList();

} Graph;
