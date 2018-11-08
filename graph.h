#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>

#include "Edge.h"


using namespace std;

class Graph
{
    public:

    int nb_vertex;
    int nb_edge;
    int type_graph;  // orienter ou pas
    int type_structure;  // list ou matrice

    Vertex *listvertex;    //V
    Edge *listedge;    //E

    int ** matadj;
    vector<vector<int> > lstadj;


    Graph();

    void file2graph();

};


#endif // GRAPH_H_INCLUDED
