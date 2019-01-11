#include "Graph.h"
//#include "Heap.h"

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


	g2.fileToGraph("Files/exampleDirectedMatrix.txt");
	//g2.BFS(*g2.getVertexList()[0]);
	//g2.computeGT();

	/*g2.DFS(*g2.getVertexList()[2]);
	for(int s=0;s<g2.getVertexList().size();s++)
    {
        cout << "Vertex g2 tmp num :" << s+1 << " d " << g2.getVertexList()[s]->getd() << " f " << g2.getVertexList()[s]->getf() << endl;
    }*/


    //vector<vector<Vertex*> > R=g2.SCC(*g2.getVertexList()[0]);


    G.push_back(g2);



    /*vector<Vertex*> V=g2.Topological_Sort(*g2.getVertexList()[0]);
	for(int k=0;k<V.size();k++)
    {
        cout<< "topological sort" <<  *V[k] << " avc finish time :" << V[k]->getf() <<   endl;
    }*/

	/*vector<vector<Vertex*> > R=g2.SCC(*g2.getVertexList()[0]);
	for(int j=0;j<R.size();j++)
    {
        cout << "component num :" << j+1 << endl;
        for(int z=0;z<R[j].size();z++)
        {
            cout << R[j][z] << " "  ;
        }
        cout << endl;
    }*/

	//g3.fileToGraph("Files/exampleUndirectedList.txt");
	//G.push_back(g3);
	//g3.Prim(*g3.getVertexList()[0]);

//	g3.DIJKSTRA(Vertex)
	g4.fileToGraph("Files/exampleDirectedList.txt");
    vector<vector<Vertex*> > R2=g4.SCC((*g4.getVertexList()[0]));
    for (int e=0;e<R2.size();e++)
    {
        cout<< "component nuber :" << e+1 ;
        for(int t=0;t<R2[e].size();t++)
        {
            cout << "  " << *R2[e][t];
        }
        cout << endl;
    }
    //vector<Edge*> T=g4.Kruskal();
	G.push_back(g4);
	//g4.BFS(*g4.getVertexList()[0]);

	/*vector<Edge*> R=g4.Kruskal();
    for(int z=0;z<R.size();z++)
    {
            cout << *R[z]->getSrc() << " / " << *R[z]->getDst() << endl;
    }
    g4.Prim(*g4.getVertexList()[0]);*/



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
