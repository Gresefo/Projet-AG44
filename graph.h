#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>  // Used for strtok()
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "Edge.h"


class Graph
{
private:

    int nbVertex;
    int nbEdge;  // Je pense pas qu'on ait besoin de le connaitre, il en parle pas dans l'enoncé
    bool isDirected;  // A boolean to know if the graph is directed (1) or not (0)
    bool isMatrix;  // A boolean to know if the structure of the graph is describe by a list (0) or by a matrix (1)

    Vertex *listVertex;    //V
    Edge *listEdge;    //E

    int ** adjencyList;
    vector<vector<int> > adjencyMactrix;

public:
    // Constructor with a file
    Graph(): nbVertex(0), nbEdge(0), isDirected(0), isMatrix(0), listVertex(NULL), listEdge(NULL), adjencyList(NULL){fileToGraph();}

    //Function that reads a file in order to create a graph
    void fileToGraph();

    // Ostream function
    friend ostream& operator<<(ostream &o, const Graph &g);

};


#endif // GRAPH_H_INCLUDED