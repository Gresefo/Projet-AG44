#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include "Vertex.h"

class Edge
{
private:
    Vertex *src,*dst;
    int id;
    int weight;

public:
    // Constructor
    Edge(Vertex *_src, Vertex *_dst): src(_src), dst(_dst), weight(1){};
    Edge(const Edge &v);

    // Destructor, we consider that destroying an Edge doesn't affect the Vertexes
    inline ~Edge(){src = NULL;dst = NULL;};

    // Getters
    Vertex* getSrc(){return src;};
    Vertex* getDst(){return dst;};
    int getId(){return id;};
    int getWeight(){return weight;};
   


};

#endif // EDGE_H_INCLUDED



