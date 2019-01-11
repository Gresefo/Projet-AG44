#include "Edge.h"

Edge::Edge(const Edge &v)
{
	src = v.src;
	dst = v.dst;
	weight = v.weight;
}

ostream& operator<<(ostream& os, const Edge &e)
{
	os << "E" << e.id << "(V" << (*e.src).getId() << ";V" << (*e.dst).getId() << ";w=" << e.weight << ")";
	return os;
}

bool Edge::operator<(Edge &b)
{
	return (weight<b.weight);
}
