#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "Edge.h"

class Graph
{
private:

    int nbVertex;
    int nbEdge;  // Je pense pas qu'on ait besoin de le connaitre, il en parle pas dans l'enoncé
    bool isDirected;  // A boolean to know if the graph is directed (1) or not (0)
    bool isMatrix;  // A boolean to know if the structure of the graph is describe by a list (0) or by a matrix (1)

    vector<Vertex*> vertexList; // The Graph's Vertex list
    vector<Edge*> edgeList; // The Graph's Edge list

    vector<vector<vector<int> > > adjencyList;
    vector<vector<int> > adjencyMatrix;

public:
    // Constructor with a file
    Graph(): nbVertex(0), nbEdge(0), isDirected(0), isMatrix(0){};

    //Function that reads a file in order to create a graph
    void fileToGraph(string myFile);

    //Destructor
    ~Graph(){}; //Clear tous les vectors

    // Getters
    int getNbVertex(){return nbVertex;};
    bool getIsDirected(){return isDirected;};
    bool getIsMatrix(){return isMatrix;};
    vector<Vertex*> getListVertex(){return vertexList;};

    // Fill the vertexes list
    void fillVertexList();

    // Fill the edges list
    void fillEdgeList();

    // Ostream function
    friend ostream& operator<<(ostream &os, const Graph &g);

};


#endif // GRAPH_H_INCLUDED
