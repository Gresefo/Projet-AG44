#include "Vertex.h"

ostream& operator<<(ostream& os, const Vertex &v)
{
	os << "V" << v.id;
	return os;
}
