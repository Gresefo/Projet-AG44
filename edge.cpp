#include "Edge.h"

Edge::Edge(const Edge &v)
{
	src = v.src;
	dst = v.dst;
	weight = v.weight;
}
