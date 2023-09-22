#include <iostream>
#include <string>
#include <vector>

typedef class Graph{
    private:
        int nVertices;
        int nEdges = 0;
        int minDegree = -1;
        int maxDegree = -1;
        int avgDegree = -1;
        int medianDegree = -1;
        int diameter = -1;
        int connectedComponents = -1;
        bool adjMatrix;
        bool adjList;
        bool **Matrix;
        std::vector<int> *List;

    public:
        // Graph functions
        Graph(std::string sFilename, bool adjMatrix, bool adjList){
            this->createGraphFromTxt(sFilename, adjMatrix, adjList);
        };
        bool createGraphFromTxt(std::string sFilename, bool adjMatrix, bool adjList);
        int getNVertices();
        int getNEdges();
        int getMinDegree();
        int getMaxDegree();
        int getAvgDegree();
        int getMedianDegree();
        std::vector<int> returnNeighbors(int v);
        void BFS(int v);
        void DFS(int v);
        int calcDistance(int v1, int v2);
        int calcDiameter();

        // Adjacency Matrix related functions
        void createAdjMatrix(std::ifstream &fin);
        void addEdgeAdjMatrix(int v1, int v2);
        void removeEdgeAdjMatrix(int v1, int v2);
        void printAdjMatrix();
        int getMinDegreeAdjMatrix();
        int getMaxDegreeAdjMatrix();
        void BFSAdjMatrix(int v);
        void DFSAdjMatrix(int v);

        // Adjacency List related functions
        void createAdjList(std::ifstream &fin);
        void addEdgeAdjList(int v1, int v2);
        void removeEdgeAdjList(int v1, int v2);
        void printAdjList();
        int getMinDegreeAdjList();
        int getMaxDegreeAdjList();
        void BFSAdjList(int v);
        void DFSAdjList(int v);

} Graph;
