#include "edge.h"

edge::edge(vertex *_src,vertex *_dst, int _w){
    this->src = _src;
    this->dst = _dst;
    this->w = _w;
}
