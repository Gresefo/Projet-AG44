#include "Edge.h"

Edge::Edge(Vertex *_src, Vertex *_dst, int _w){
    this->src = _src;
    this->dst = _dst;
    this->w = _w;
}
