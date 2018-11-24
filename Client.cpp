#include "Graph.h"
#include "Heap.h"

int main()
{
	// Creation of an undirected graph (with a adjency matrix) using the file name "exampleUndirectedMatrix"
	Graph g;
	g.fileToGraph("exampleUndirectedMatrix.txt");

	cout << g << endl << "-------------------------------------------" << endl << endl;

	Graph g2;
	g2.fileToGraph("exampleDirectedList.txt");

	cout << g2 << endl;


	return 0;
}
