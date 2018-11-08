#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include "Vertex.h"

class Edge{
    public:
    //attributs
    Vertex *src,*dst;
    int id;
    int w;

    //Constructeur

    Edge(Vertex *src, Vertex *dst, int w=1);

    //Methodes


};

#endif // EDGE_H_INCLUDED



