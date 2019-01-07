#include "Graph.h"
#include "Heap.h"

int main()
{
	// Creation of graphs using .txt files
	vector<Graph> G;
	vector<Vertex> Q;
	Graph g1, g2, g3, g4;
	g1.fileToGraph("Files/exampleUndirectedMatrix.txt");
	//g1.BFS(*g1.getVertexList()[0]);
	//g1.DFS(*g1.getVertexList()[0]);
	//Q=g1.Topological_Sort(*g1.getVertexList()[0]);
	//Graph g5=g1.SCC(*g1.getVertexList()[0]);
	G.push_back(g1);




	//g1.BFS(*g1.getVertexList()[0]);

	/*
	g2.fileToGraph("Files/exampleDirectedMatrix.txt");
	g2.BFS(*g2.getVertexList()[0]);
	G.push_back(g2);*/

	g3.fileToGraph("Files/exampleUndirectedList.txt");
	G.push_back(g3);

//	g3.DIJKSTRA(Vertex)
	/*g4.fileToGraph("Files/exampleDirectedList.txt");

    vector<Edge*> T=g4.Kruskal();
	G.push_back(g4);/*
	g4.BFS(*g4.getVertexList()[0]);*/


	// Printing out a graph example of each type
	for (unsigned int i = 0; i < G.size(); i++)
	{
		cout << G[i];
	}
	for(unsigned int k=0;k<Q.size();k++)
	{
		cout << Q[k] << " ";
	}
	cout << endl;
	/*for(int i=0;i<T.size();i++)
    {
        cout<< "edge :" << T[i]->getSrc()->getId() << "/" << T[i]->getDst()->getId() << "/" << T[i]->getWeight() << endl;
    }*/

	return 0;
}