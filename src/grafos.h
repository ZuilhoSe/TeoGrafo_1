#include <iostream>
#include <string>

typedef struct Node{
    int id;
    Node *next;
} Node;

typedef struct List{
    Node *head;
    Node *tail;
} List;

typedef class Graph{
    private:
        int nVertices;
        bool adjMatrix;
        bool adjList;
        bool **Matrix;
    public:
        bool createGraphFromTxt(std::string sFilename, bool adjMatrix, bool adjList);
        
        // Adjacency Matrix related functions
        void createAdjMatrix(std::ifstream &fin);
        void addEdgeAdjMatrix(int v1, int v2);
        void removeEdgeAdjMatrix(int v1, int v2);
        void printAdjMatrix();

        // Adjacency List related functions

} Graph;
