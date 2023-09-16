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

    if (fin.fail()) 
    {
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
    int token;
    int counter = 0;
    int v1;
    int v2;

    while (readNextToken(token, fin)){   
        if (counter == 0){
            Matrix = new bool*[nVertices];
            for (int i = 0; i < nVertices; i++){
            Matrix[i] = new bool[nVertices];
            for (int j = 0; j < nVertices; j++)
                Matrix[i][j] = false;
            }
            counter++;
        }
        
        counter++;

        if(counter%2 == 0){
            v1 = token;
        }else{
            v2 = token;
            addEdgeAdjMatrix(v1, v2);
        }
    }
}

/**
 * AdjList functions
 */

void Graph::addEdgeAdjList(int v1, int v2){
    // TODO
}

void Graph::removeEdgeAdjList(int v1, int v2){
    // TODO
}

void Graph::printAdjList(){
    // TODO
}

void Graph::createAdjList(ifstream &fin){
    vector <int> adjList[nVertices];
    int token;
    int counter = 0;
    int v1;
    int v2;

    while (readNextToken(token, fin)){   

        if(counter%2 == 0){
            v1 = token;
        }else{
            v2 = token;
            cout << v1 << " " << v2 << endl;
        }
        counter++;

    }
}

/**
 * Graph functions
 */

bool Graph::createGraphFromTxt(std::string sFilename, bool adjMatrix, bool adjList){

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
        printAdjMatrix();
    }

    if(adjList){
        createAdjList(fin);
        // printAdjList();
    }

    fin.close();
    return true;
}

int main(){
    Graph g;
    g.createGraphFromTxt("data/grafo_teste.txt", false, true);
    return 0;
}