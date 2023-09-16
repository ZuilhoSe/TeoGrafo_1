#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "grafos.h"

using namespace std;

/**
 * Aux functions
 */
bool readNextToken(int& token, ifstream& fin){
    char nextChar;
    fin >> nextChar;

    fin.unget(); 
    fin >> token;

    if(fin.fail()){
        return false;
    }

    return true;
}

/**
 * AdjMatrix functions
 */
void Graph::addEdgeAdjMatrix(int v1, int v2){
    Matrix[v1][v2] = true;
    Matrix[v2][v1] = true;
}

void Graph::removeEdgeAdjMatrix(int v1, int v2){
    Matrix[v1][v2] = false;
    Matrix[v2][v1] = false;
}

int Graph::getMinDegreeAdjMatrix(){
    int min = nVertices;
    for(int i = 0; i < nVertices; i++){
        int degree = 0;
        for(int j = 0; j < nVertices; j++){
            if(Matrix[i][j]){
                degree++;
            }
        }
        if(degree < min){
            min = degree;
        }
    }
    return min;
}

int Graph::getMaxDegreeAdjMatrix(){
    int max = 0;
    for(int i = 0; i < nVertices; i++){
        int degree = 0;
        for(int j = 0; j < nVertices; j++){
            if(Matrix[i][j]){
                degree++;
            }
        }
        if(degree > max){
            max = degree;
        }
    }
    return max;
}

void Graph::printAdjMatrix(){
    // Print the matrix, not recommended for large graphs
    for(int i = 0; i < nVertices; i++){
        cout << i << " : ";
        for(int j = 0; j < nVertices; j++)
            cout << Matrix[i][j] << " ";
        cout << "\n";
    }
}

void Graph::createAdjMatrix(ifstream &fin){
    Matrix = new bool*[nVertices];
    for(int i = 0; i < nVertices; i++){
        Matrix[i] = new bool[nVertices];
        for(int j = 0; j < nVertices; j++){
            Matrix[i][j] = false;
        }
    }

    int token;
    int counter = 0;
    int v1;
    int v2;

    while (readNextToken(token, fin)){   
        if(counter%2 == 0){
            v1 = token;
        }else{
            v2 = token;
            nEdges++;
            addEdgeAdjMatrix(v1-1, v2-1);
        }
        counter++;
    }
}

void Graph::BFSAdjMatrix(int v){
    //TODO
}

/**
 * AdjList functions
 */
void Graph::addEdgeAdjList(int v1, int v2){
    List[v1].push_back(v2);
    List[v2].push_back(v1);
}

void Graph::removeEdgeAdjList(int v1, int v2){
    //TODO
}

int Graph::getMinDegreeAdjList(){
    int min = nVertices;
    for(int i = 0; i < nVertices; i++){
        if(List[i].size() < min){
            min = List[i].size();
        }
    }
    return min;
}

int Graph::getMaxDegreeAdjList(){
    int max = 0;
    for(int i = 0; i < nVertices; i++){
        if(List[i].size() > max){
            max = List[i].size();
        }
    }
    return max;
}

void Graph::printAdjList(){
    // Print the list, not recommended for large graphs
    for(int i = 0; i < nVertices; i++){
        cout << i << " -> ";
        for(int v: List[i]){
            cout << v << " ";
        }
        cout << endl;
    }
}

void Graph::createAdjList(ifstream &fin){
    List = new vector<int>[nVertices];

    int token;
    int counter = 0;
    int v1;
    int v2;

    while (readNextToken(token, fin)){
        if(counter%2 == 0){
            v1 = token;
        }else{
            v2 = token;
            nEdges++;
            addEdgeAdjList(v1-1, v2-1);
        }
        counter++;
    }
}

void Graph::BFSAdjList(int v){
    //TODO
}

/**
 * Graph functions
 */
bool Graph::createGraphFromTxt(std::string sFilename, bool makeMatrix, bool makeList){
    adjMatrix = makeMatrix;
    adjList = makeList;

    ifstream fin(sFilename);
  
    if (!fin){
        cout<<endl;
        cout << "Erro ao abrir o arquivo." << endl;
        return false;
    }

    cout << "Arquivo aberto!" << endl;
    cout << "Lendo o arquivo..." << endl;

    nVertices = fin >> nVertices ? nVertices : 0;    
    
    if(adjMatrix){
        createAdjMatrix(fin);
    }

    if(adjList){
        createAdjList(fin);
    }

    fin.close();
    return true;
}

int Graph::getNVertices(){
    return nVertices;
}

int Graph::getNEdges(){
    return nEdges;
}

int Graph::getMinDegree(){
    if(minDegree == -1){
        if (adjMatrix){
            minDegree = getMinDegreeAdjMatrix();
        }else if(adjList){
            minDegree = getMinDegreeAdjList();
        }
    }
    return minDegree;
}

int Graph::getAvgDegree(){
    if(avgDegree == -1){
        avgDegree = 2*nEdges/nVertices;
    }
    return avgDegree;
}

int Graph::getMaxDegree(){
    if(maxDegree == -1){
        if (adjMatrix){
            maxDegree = getMaxDegreeAdjMatrix();
        }else if(adjList){
            maxDegree = getMaxDegreeAdjList();
        }
    }
    return maxDegree;
}

void Graph::BFS(int v){
    if (adjMatrix){
        BFSAdjMatrix(v);
    }else if(adjList){
        BFSAdjList(v);
    }
}