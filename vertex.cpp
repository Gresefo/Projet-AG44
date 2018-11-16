#include "Vertex.h"

ostream& operator<<(ostream& os, const Vertex &v)
{
	os << "V" << v.getId() << "[" << v.getX() << ";" << v.getY() << "]";
	return os;
}
