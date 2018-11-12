#include "Graph.h"
#include "Heap.h"

int main()
{
	// Creation of an undirected graph (with a adjency matrix) using the file name "exampleUndirectedMatrix"
	Graph g;
	cout << g << endl; 

	Vertex v1(1);
	cout << v1 << endl;

	g.addVertex(&v1);
	cout << g << endl;


	
	cout << "Hello World !" << endl;
	return 0;
}
