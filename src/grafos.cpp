#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <queue>
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

std::vector<int> Graph::returnNeighbors(int v){
    v = v-1;
    vector<int> neighbors;
    for(int i = 0; i < nVertices; i++){
        if(Matrix[v][i]){
            neighbors.push_back(i+1);
        }
    }
    return neighbors;
}

void Graph::BFSAdjMatrix(int v){
    vector<bool> visited(nVertices, false);
    vector<int> degree(nVertices, 0);
    vector<int> father(nVertices, -1);
    vector<int> queue;
    vector<int> neighbors;

    visited[v-1] = true;
    degree[v-1] = 0;
    father[v-1] = 0;
    queue.push_back(v-1);

    while(queue.size() > 0){
        int f = queue[0];
        queue.erase(queue.begin());

        neighbors = returnNeighbors(f+1);
        degree[f] = neighbors.size();

        for (int i = 0; i < neighbors.size(); i++){
            int w = neighbors[i];
            if(visited[w-1] == false){
                visited[w-1] = true;
                queue.push_back(w-1);
                father[w-1] = f+1;
            }
        }
    }

    cout << "Finalizado" << endl;
    for (int i = 0; i < nVertices; i++){
        cout << i+1 << " " << degree[i] << " " << father[i] << endl;
    }
}   

void Graph::DFSAdjMatrix(int v){
    vector<bool> visited(nVertices, false);
    vector<int> degree(nVertices, 0);
    vector<int> father(nVertices, -1);
    vector<int> queue;
    vector<int> neighbors;

    visited[v-1] = true;
    degree[v-1] = 0;

    queue.push_back(v-1);    

    while(queue.size() > 0){
        int f = queue[0];
        queue.erase(queue.begin());

        if(visited[f]==0){
            visited[f] = true;
            neighbors = returnNeighbors(f+1);
            for (int i = neighbors.size()-1; i >= 0; i--){
                int w = neighbors[i]-1;
                queue.push_back(w);
                if(!visited[w]){
                    degree[w] = degree[f]+1;
                    father[w] = f+1;
                }
            }
        }
    }

    cout << "Finalizado" << endl;

    for (int i = 0; i < nVertices; i++){
        cout << i+1 << " " << degree[i] << " " << father[i] << endl;
    }
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

void Graph::DFSAdjList(int v){
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

void Graph::DFS(int v){
    if (adjMatrix){
        DFSAdjMatrix(v);
    }else if(adjList){
        DFSAdjList(v);
    }
}

int Graph::calcDistance(int v1, int v2){
    int distance = 0;

    if(adjMatrix){
        //TODO
    }else if(adjList){
        //TODO
    }

    return distance;
}

int Graph::calcDiameter(){
    if(diameter == -1){
        //TODO
    }
    return diameter;
}