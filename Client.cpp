#include "Graph.h"
#include "Heap.h"

int main()
{
	// Creation of graphs using .txt files
	vector<Graph> G;
	Graph g1, g2, g3, g4;
	g1.fileToGraph("Files/exampleUndirectedMatrix.txt");
	G.push_back(g1);
	g1.matrixToList();
	//g1.BFS(*g1.getVertexList()[0]);
	/*
	g2.fileToGraph("Files/exampleDirectedMatrix.txt");
	G.push_back(g2);	
	g3.fileToGraph("Files/exampleUndirectedList.txt");
	G.push_back(g3);
	g4.fileToGraph("Files/exampleDirectedList.txt");
	G.push_back(g4);
	g4.BFS(*g4.getVertexList()[0]);*/

	// Printing out a graph example of each type
	for (unsigned int i = 0; i < G.size(); i++)
	{
		cout << G[i];
	}

	return 0;
}
