#include "Vertex.h"

ostream& operator<<(ostream& os, const Vertex &v)
{
	os << "V" << v.id << "[" << v.x << ";" << v.y << "]";
	return os;
}
