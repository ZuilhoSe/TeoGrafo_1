#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include "grafos.h"
#include <random>

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

bool comparePair(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

vector<int> sortArrayWithIndexes(const vector<int>& arr) {
    vector<pair<int, int>> indexedArray;
    vector<int> sortedArray;
    vector<int> indexes;

    // Populate the indexedArray with pairs of (element, index)
    for (int i = 0; i < arr.size(); i++) {
        indexedArray.push_back({arr[i], i});
    }

    // Sort the indexedArray based on elements
    sort(indexedArray.begin(), indexedArray.end(), comparePair);

    // Extract the sorted elements
    for (const auto& pair : indexedArray) {
        sortedArray.push_back(pair.first);
    }

    // Extract the indexes
    for (const auto& pair : indexedArray) {
        indexes.push_back(pair.second);
    }

    return indexes;
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

int Graph::getMedianDegreeAdjMatrix(){
    vector<int> degrees;

    for(int i = 0; i < nVertices; i++){
        int degree = 0;
        for(int j = 0; j < nVertices; j++){
            if(Matrix[i][j]){
                degree++;
            }
        }
        degrees.push_back(degree);
    }

    sort(degrees.begin(), degrees.end());

    if (degrees.size() % 2 == 0){
        return (degrees[degrees.size()/2] + degrees[degrees.size()/2 - 1])/2;
    }

    return degrees[degrees.size()/2];
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

std::vector<int> Graph::returnNeighbors(int v, bool mode){
    v = v-1;
    vector<int> neighbors;
    
    if (mode){
        for(int i = 0; i < List[v].size(); i++){
            neighbors.push_back(List[v][i]);
        }
        return neighbors;
    }else{
        for(int i = 0; i < nVertices; i++){
            if(Matrix[v][i]){
                neighbors.push_back(i+1);
            }
        }
    }

    return neighbors;
}

void Graph::BFSAdjMatrix(int v){
    vector<bool> visited(nVertices, false);
    vector<int> degree(nVertices, 0);
    vector<int> father(nVertices, -1);
    vector<int> level(nVertices, -1);
    vector<int> queue;
    vector<int> neighbors;

    visited[v-1] = true;
    degree[v-1] = 0;
    father[v-1] = 0;
    level[v-1] = 0;
    queue.push_back(v-1);

    while(queue.size() > 0){
        int f = queue[0];
        queue.erase(queue.begin());

        neighbors = returnNeighbors(f+1, false);
        degree[f] = neighbors.size();

        for (int i = 0; i < neighbors.size(); i++){
            int w = neighbors[i];
            if(visited[w-1] == false){
                visited[w-1] = true;
                queue.push_back(w-1);
                father[w-1] = f+1;
                level[w-1] = level[f]+1;
            }
        }
    }

    this->exportGenTreeToTxt("data/grafo_teste_gen_tree.txt");
    cout << "BFS Finalizada!" << endl;

    this->nodesDegree = degree;
    this->nodesFather = father;
    this->nodesLevel = level;

    //for(int j = 0; j < nVertices; j++){
    //   cout << "Vertice: " << j+1 << " | Pai: " << father[j] << " | Level: " << level[j] << endl;
    //}
}   

void Graph::DFSAdjMatrix(int v){
    vector<bool> visited(nVertices, false);
    vector<int> degree(nVertices, 0);
    vector<int> father(nVertices, -1);
    vector<int> level(nVertices, -1);
    vector<int> stack;
    vector<int> neighbors;

    father[v-1] = 0;
    degree[v-1] = 0;
    level[v-1] = 0;
    stack.push_back(v-1);

    while(stack.size() > 0){
        int f = stack[stack.size()-1];
        stack.pop_back();

        if(visited[f] == false){
            visited[f] = true;
            neighbors = returnNeighbors(f+1, false);
            degree[f] = neighbors.size();

            for(int i = neighbors.size()-1; i >= 0; i--){
                int w = neighbors[i];
                if(visited[w-1] == false){
                    stack.push_back(w-1);
                    father[w-1] = f+1;
                    level[w-1] = level[f]+1;
                }
            }
        }
    }

    this->nodesDegree = degree;
    this->nodesFather = father;
    this->nodesLevel = level;

    this->exportGenTreeToTxt("data/grafo_teste_gen_tree.txt");
    cout << "DFS Finalizada!" << endl;
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

int Graph::getMedianDegreeAdjList(){
    vector<int> degrees;

    for(int i = 0; i < nVertices; i++){
        degrees.push_back(List[i].size());
    }

    sort(degrees.begin(), degrees.end());

    if (degrees.size() % 2 == 0){
        return (degrees[degrees.size()/2] + degrees[degrees.size()/2 - 1])/2;
    }

    return degrees[degrees.size()/2];
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
    vector<bool> visited(nVertices, false);
    vector<int> degree(nVertices, 0);
    vector<int> father(nVertices, -1);
    vector<int> level(nVertices, -1);
    vector<int> queue;
    vector<int> neighbors;

    visited[v-1] = true;
    degree[v-1] = 0;
    father[v-1] = 0;
    level[v-1] = 0;
    queue.push_back(v-1);

    while(queue.size() > 0){
        int f = queue[0];
        queue.erase(queue.begin());

        neighbors = returnNeighbors(f+1, true);
        degree[f] = neighbors.size();

        while(neighbors.size() > 0){
            int w = neighbors[0];
            neighbors.erase(neighbors.begin());

            if(visited[w] == false){
                visited[w] = true;
                queue.push_back(w);
                father[w] = f+1;
                level[w] = level[f]+1;
            }
        }
    }

    this->nodesDegree = degree;
    this->nodesFather = father;
    this->nodesLevel = level;
    
    this->exportGenTreeToTxt("data/grafo_teste_gen_tree.txt");
    cout << "BFS Finalizada!" << endl;
    //for(int j = 0; j < nVertices; j++){
    //    cout << "Vertice: " << j+1 << " | Pai: " << father[j] << " | Grau: " << degree[j] << endl;
    //}
}

void Graph::DFSAdjList(int v){
    vector<bool> visited(nVertices, false);
    vector<int> degree(nVertices, 0);
    vector<int> father(nVertices, -1);
    vector<int> level(nVertices, -1);
    vector<int> stack;
    vector<int> neighbors;

    father[v-1] = 0;
    degree[v-1] = 0;
    level[v-1] = 0;
    stack.push_back(v-1);

    while(stack.size() > 0){
        int f = stack[stack.size()-1];
        stack.pop_back();

        if(visited[f] == false){
            visited[f] = true;
            neighbors = returnNeighbors(f+1, true);
            degree[f] = neighbors.size();

            while(neighbors.size() > 0){
                int w = neighbors[neighbors.size()-1];
                neighbors.pop_back();

                if(visited[w] == false){
                    stack.push_back(w);
                    father[w] = f+1;
                    level[w] = level[f]+1;
                }
            }
        }
    }

    this->nodesDegree = degree;
    this->nodesFather = father;
    this->nodesLevel = level;

    this->exportGenTreeToTxt("data/grafo_teste_gen_tree.txt");
    cout << "DFS Finalizada!" << endl;
    //for(int j = 0; j < nVertices; j++){
    //    cout << "Vertice: " << j+1 << " | Pai: " << father[j] << " | Grau: " << degree[j] << endl;
    //}
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
    cout << "Arquivo lido!" << endl;
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

int Graph::getMedianDegree(){
    if(medianDegree == -1){
        if(adjMatrix){
            medianDegree = getMedianDegreeAdjMatrix();
        }else if(adjList){
            medianDegree = getMedianDegreeAdjList();
        }
    }
    return medianDegree;
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

    this->BFS(v1);

    int current = v2;
    while(current != v1){
        current = nodesFather[current-1];
        if (current == -1){
            return current;
        }
        distance++;
    }


    return distance;
}

int Graph::calcDiameter(){
    if(diameter == -1){
        if(nVertices < 1000){
            int max = 0;
            for(int i = 0; i < nVertices; i++){
                for(int j = 0; j < nVertices; j++){
                    int distance = calcDistance(i+1, j+1);
                    if(distance > max){
                        max = distance;
                    }
                }
            }
            diameter = max;
        }else{
            int max = 0;
            std::random_device rd;
            std::mt19937 mt(rd()); // Mersenne Twister pseudo-random number generator
            std::uniform_int_distribution<int> distribution(1, nVertices); // Generate integers between 1 and 100

            for(int i = 0; i < 1000; i++){
                int randomNum = distribution(mt);
                this->BFS(randomNum);
                for(int j = 0; j < nVertices; j++){
                    int distance = nodesLevel[j];
                    if(distance > max){
                        max = distance;
                    }
                }
            }
            diameter = max;
        }
    }
    return diameter;
}

void Graph::getConnectedComponents(){
    CC = new vector<int>[nVertices];
    vector<bool> CCvisited(nVertices, false);

    int compConex = 0;

    for(int i = 0; i < nVertices; i++){
        if(CCvisited[i] == false){
            BFS(i+1);
            for(int j = 0; j < nVertices; j++){
                if(nodesFather[j] != -1){
                    CC[compConex].push_back(j+1);
                    CCvisited[j] = true;
                }
            }
            compConex++;
        }
    }
    nConnectedComponents = compConex;
}

int Graph::getNConnectedComponents(){
    return nConnectedComponents;
}

void Graph::exportInfoToTxt(string sFilename){
    ofstream fout(sFilename);

    if (!fout){
        cout<<endl;
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    fout << "Numero de vertices: " << nVertices << endl;
    fout << "Numero de arestas: " << nEdges << endl;
    fout << "Grau minimo: " << getMinDegree() << endl;
    fout << "Grau medio: " << getAvgDegree() << endl;
    fout << "Grau maximo: " << getMaxDegree() << endl;
    fout << "Grau mediano: " << getMedianDegree() << endl;

    fout.close();
}

void Graph::exportGenTreeToTxt(string sFilename){
    ofstream fout(sFilename);

    if (!fout){
        cout<<endl;
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    for(int i = 0; i < nVertices; i++){
        fout << "Vertice: " << i+1 << " | Pai: " << nodesFather[i] << " | Level: " << nodesLevel[i] << endl;
    }

    fout.close();
}

void Graph::exportConnectedComponentsToTxt(string sFilename){
    this->getConnectedComponents();

    vector<int> sizes(nConnectedComponents);

    for (int i = 0; i < nConnectedComponents; i++){
        sizes[i] = CC[i].size();
        cout << "Componente " << i+1 << " tem tamanho " << sizes[i] << endl;
    }

    vector<int> indexes = sortArrayWithIndexes(sizes);

    ofstream fout(sFilename);

    if (!fout){
        cout<<endl;
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    fout << "Numero de componentes conexas: " << nConnectedComponents << endl;
    for (int i = nConnectedComponents-1; i >= 0; i--){
        fout << "Componente " << nConnectedComponents-i << " tem tamanho " << sizes[indexes[i]] << endl;
        fout << "Vertices: ";
        for (int j = 0; j < CC[indexes[i]].size(); j++){
            fout << CC[indexes[i]][j] << " ";
        }
        fout << endl;
        fout << endl;
    }

}