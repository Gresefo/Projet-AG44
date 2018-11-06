#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>

#include "vertex.h"
#include "edge.h"


using namespace std;

class graph
{
    public:

    int nb_vertex;
    int nb_edge;
    int type_graph;  // orienter ou pas
    int type_structure;  // list ou matrice

    vertex *listvertex;    //V
    edge *listedge;    //E

    int ** matadj;
    vector<vector<int> > lstadj;


    graph();

    void file2graph();

};


#endif // GRAPH_H_INCLUDED
