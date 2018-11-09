#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "Edge.h"


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
    // Constructor without a file
    Graph(): nb_vertex(0), nb_edge(0), isDirected(0), isMatrix(0), listVertex(NULL), listEdge(NULL), adjencyList(NULL){};
    // Constructor with a file, and the variable "myFile" contains the name of the file
    Graph(string myFile): nb_vertex(0), nb_edge(0), isDirected(0), isMatrix(0), listVertex(NULL), listEdge(NULL), adjencyList(NULL)
        {fileToGraph(myFile);};

    void fileToGraph(string myFile);

};


#endif // GRAPH_H_INCLUDED