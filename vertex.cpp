#include "Vertex.h"

ostream& operator<<(ostream& os, const Vertex &v)
{
	os << "| " << v.id << " | " << v.x << " | " << v.y << " |" << endl;
	return os;
}