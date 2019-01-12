#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include "Vertex.h"

class Edge
{
private:
    Vertex* src;
    Vertex* dst;
    int id;
    int weight;

public:
    // Constructor
    Edge(int _id, Vertex *_src, Vertex *_dst): src(_src), dst(_dst), id(_id), weight(1){};
    Edge(const Edge &v);

    // Destructor, we consider that destroying an Edge doesn't affect the Vertexes
    inline ~Edge(){src = NULL;dst = NULL;};

    // Getters
    Vertex* getSrc() const {return src;};
    Vertex* getDst() const {return dst;};
    int getId() const {return id;};
    int getWeight() const {return weight;};

    // Setters
    void setWeight(int w){weight = w;};

    // Ostream function
    friend ostream& operator<<(ostream& os, const Edge &e);

    //
    //bool est_inferieur(Edge &a, Edge &b);
    bool operator<(Edge &b);
};

#endif // EDGE_H_INCLUDED