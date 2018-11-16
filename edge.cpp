#include "Edge.h"

Edge::Edge(const Edge &v)
{
	src = v.src;
	dst = v.dst;
	weight = v.weight;
}

ostream& operator<<(ostream& os, const Edge &e)
{
	os << "E" << e.getId() << "(V" << (*e.getSrc()).getId() << ";V" << (*e.getDst()).getId() << ";w=" << e.getWeight() << ")";
	return os;
}	
