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
        int nConnectedComponents = 0;
        bool adjMatrix;
        bool adjList;
        bool **Matrix;
        std::vector<int> *List;
        

    public:
        // Graph functions
        Graph(std::string sFilename, bool adjMatrix, bool adjList){
            this->createGraphFromTxt(sFilename, adjMatrix, adjList);
        };
        ~Graph(){
            if (this->adjMatrix){
                for (int i = 0; i < this->nVertices; i++){
                    delete[] this->Matrix[i];
                }
                delete[] this->Matrix;
            }
            if (this->adjList){
                delete[] this->List;
            }
        };
        bool createGraphFromTxt(std::string sFilename, bool adjMatrix, bool adjList);
        int getNVertices();
        int getNEdges();
        int getMinDegree();
        int getMaxDegree();
        int getAvgDegree();
        int getMedianDegree();
        std::vector<int> returnNeighbors(int v, bool mode);
        void BFS(int v);
        void DFS(int v);
        int calcDistance(int v1, int v2);
        int calcDiameter();
        void getConnectedComponents();
        int getNConnectedComponents();

        std::vector<int> *CC;
        std::vector<int> nodesFather;
        std::vector<int> nodesDegree;
        std::vector<int> nodesLevel;
        
        // Adjacency Matrix related functions
        void createAdjMatrix(std::ifstream &fin);
        void addEdgeAdjMatrix(int v1, int v2);
        void removeEdgeAdjMatrix(int v1, int v2);
        void printAdjMatrix();
        int getMinDegreeAdjMatrix();
        int getMaxDegreeAdjMatrix();
        int getMedianDegreeAdjMatrix();
        void BFSAdjMatrix(int v);
        void DFSAdjMatrix(int v);

        // Adjacency List related functions
        void createAdjList(std::ifstream &fin);
        void addEdgeAdjList(int v1, int v2);
        void removeEdgeAdjList(int v1, int v2);
        void printAdjList();
        int getMinDegreeAdjList();
        int getMaxDegreeAdjList();
        int getMedianDegreeAdjList();
        void BFSAdjList(int v);
        void DFSAdjList(int v);

        //TXT related functions
        void exportInfoToTxt(std::string sFilename);
        void exportGenTreeToTxt(std::string sFilename);
        void exportConnectedComponentsToTxt(std::string sFilename);

} Graph;
