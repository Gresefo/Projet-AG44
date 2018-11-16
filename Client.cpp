#include "Graph.h"
#include "Heap.h"

int main()
{
	// Creation of an undirected graph (with a adjency matrix) using the file name "exampleUndirectedMatrix"
	Graph g;

	Vertex v1(1), v2(2), v3(3), v4(4);

	Edge e1(1, &v1, &v2), e2(2,&v1,&v3), e3(3,&v2,&v3), e4(4,&v2,&v4);

	g.addEdge(&e1);
	g.addEdge(&e2);
	g.addEdge(&e3);
	g.addEdge(&e4);

	g.addVertex(&v1);
	g.addVertex(&v2);
	g.addVertex(&v3);
	g.addVertex(&v4);
	cout << g << endl;


	
	cout << "Hello World !" << endl;
	return 0;
}
