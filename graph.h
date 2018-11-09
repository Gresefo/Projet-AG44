#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#include "Edge.h"


using namespace std;

class Graph
{
private:

    int nb_vertex;
    int nb_edge;  // Je pense pas qu'on ait besoin de le connaitre, il en parle pas dans l'enoncé
    bool isDirected;  // A boolean to know if the graph is directed (1) or not (0)
    bool isMatrix;  // A boolean to know if the structure of the graph is describe by a list (0) or by a matrix (1)

    Vertex *listVertex;    //V
    Edge *listEdge;    //E

    int ** adjencyList;
    vector<vector<int> > adjencyMactrix;

public:

    Graph(): nb_vertex(0), nb_edge(0), isDirected(0), isMatrix(0), listVertex(NULL), listEdge(NULL), adjencyList(NULL){fileToGraph();};

    void fileToGraph();

};


#endif // GRAPH_H_INCLUDED