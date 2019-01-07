#include "Vertex.h"

ostream& operator<<(ostream& os, const Vertex &v)
{
	os << "V" << v.id;
	return os;
}

bool operator==(Vertex &v1, Vertex &v2)
	{ return &v1 == &v2; }


