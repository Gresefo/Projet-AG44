#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include "vertex.h"

class edge{
    public:
    //attributs
    vertex *src,*dst;
    int id;
    int w;

    //Constructeur

    edge(vertex *src,vertex *dst, int w=1);

    //Methodes


};

#endif // EDGE_H_INCLUDED



