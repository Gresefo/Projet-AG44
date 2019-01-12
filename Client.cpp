#include "Graph.h"
#include <string>
//#include "Heap.h"

int main()
{
	// Creation of graphs using .txt files
	vector<Graph> G;
	vector<Vertex> Q;
	int taille;
    int nb(0);
    vector<Edge*> K;
	vector<Vertex*> R;
	vector<vector<Vertex* > > D;
	Graph g1, g2, g3, g4,g;
	g1.fileToGraph("Files/exampleUndirectedMatrix.txt");
    g2.fileToGraph("Files/exampleDirectedMatrix.txt");
    g3.fileToGraph("Files/exampleUndirectedList.txt");
    g4.fileToGraph("Files/exampleDirectedList.txt");
    cout << "Please chose the graph from the List Below" << endl;
    cout << "   1 :Files/exampleUndirectedMatrix.txt" << endl;
	cout << "   2 :Files/exampleDirectedMatrix.txt" << endl;
	cout << "   3 :Files/exampleUndirectedList.txt" << endl;
	cout << "   4 :Files/exampleDirectedList.txt" << endl;
	int answer;
	cin >> answer;

	switch(answer)
	{
        case 1:g.fileToGraph("Files/exampleUndirectedMatrix.txt");
        break;
        case 2:g.fileToGraph("Files/exampleDirectedMatrix.txt");
        break;
        case 3:g.fileToGraph("Files/exampleUndirectedList.txt");
        break;
        case 4:g.fileToGraph("Files/exampleDirectedList.txt");
        break;
        default: cout << "error, this choice is not available" << endl;
            break;
	}
	cin.ignore();

	cout<< "AFFICHAGE GRAPH" << endl;
	cout<<g<<endl<<endl<<endl;

	cout << "Which algorithm do you want to use?" << endl;
	cout << "   1 : Breadth-first search" << endl;
	cout << "   2 : Depth-first-search" << endl;
	cout << "   3 : Topological_Sort" << endl;
	cout << "   4 : Strongly_Related" << endl;
	cout << "   5 : Kruskal" << endl;
	cout << "   6 : Prim" << endl;
	cout << "   7 : Bellman-Ford" << endl;
	cout << "   8 : Dijkstra" << endl;

	cin >> answer;
	int vertexid;
	switch(answer)
	{
    case 1:cout << "Please type in the id of the vertex you want to use the algorithm on." << endl;
            cin >>vertexid;
            if(vertexid>0 && vertexid<=g.getNbVertex())
            {
                g.BFS(*g.getVertexList()[vertexid-1]);
            }
            else
            {
                cout<< "Error,no verticle found" << endl;

            }

        break;
    case 2: cout << "Please type in the id of the vertex you want to use the algorithm on." << endl;
    cin>>vertexid;
            if(vertexid>0 && vertexid<=g.getNbVertex())
            {

                g.DFS(*g.getVertexList()[vertexid-1]);
                for(int i=0; i<g.getNbVertex();i++)
                {

                    cout << "Here are the entry and finishing times of the different Vertex reacheable from the one you've chosen" << endl;

                    if(g.getVertexList()[i]->getd() != -1)
                    {
                        nb++;
                        cout << "Vertex :" << *g.getVertexList()[i] << " entry time :" << g.getVertexList()[i]->getd() << "finishing time :" << g.getVertexList()[i]->getd() << endl;
                    }
                    if(nb==0)
                    {
                        cout << "No verticle reachabme" << endl;
                    }


                }
            }
            else
            {
                cout<< "Error,no verticle found" << endl;

            }
            nb=0;
        break;
    case 3:cout << "Please type in the id of the vertex you want to use the algorithm on." << endl;
        cin>>vertexid;
        if(vertexid>0 && vertexid<=g.getNbVertex())
            {
                R=g.Topological_Sort(*g.getVertexList()[vertexid-1]);
                cout << "Here is the result of the topological sort" << endl;
                taille=R.size();
                for(int k=0;k<taille;k++)
                {
                    cout << *R[k] << " / ";
                }
                cout << endl;
            }
            else
            {
                cout<< "Error,no verticle found" << endl;

            }
            taille=0;
            R.clear();
        break;
    case 4:if(g.getIsDirected()==false)
            {
            cout << "Please type in the id of the vertex you want to use the algorithm on." << endl;
            cin>>vertexid;
            if(vertexid>0 && vertexid<=g.getNbVertex())
            {

                D=g.SCC(*g.getVertexList()[vertexid-1]);
                taille=D.size();
                cout << "Here are the different component in the Graph" << endl;
                for(int j=0;j<taille;j++)
                {
                    cout << "component num :" << j+1 << endl;
                    for(int z=0;z<D[j].size();z++)
                    {
                        cout << *D[j][z] << " "  ;
                    }
                    cout << endl;
                }

            }
            else
            {
                cout<< "Error,no verticle found" << endl;

            }
            D.clear();
            }
            else
            {
                cout<<"Error, the Graph must Be directed" << endl;
            }

        break;
    case 5:cout << "Please type in the id of the vertex you want to use the algorithm on." << endl;
    cin>>vertexid;
        if(vertexid>0 && vertexid<=g.getNbVertex())
            {
                K=g.Kruskal();
                cout << "Here are the edges used to build the Kruskal Mst" << endl;
                taille=K.size();
                for(int i=0;i<taille;i++)
                {
                    cout<< "Edge sources/destinations :" << *K[i]->getSrc() << "->" << *K[i]->getDst() << endl;
                }
            }
            else
            {
                cout<< "Error,no verticle found" << endl;

            }
            K.clear();
        break;
    case 6:cout << "Please type in the id of the vertex you want to use the algorithm on." << endl;
    cin>>vertexid;
        if(vertexid>0 && vertexid<=g.getNbVertex())
            {
                g.Prim(*g.getVertexList()[vertexid-1]);
                cout << "Here are the vertex with their parents computed(reachable) by the Prim's algorithm" << endl;
                cout << "Vertex source :" <<*g.getVertexList()[vertexid-1] << endl;
                for(int y=0;y<g.getNbVertex();y++)
                {
                    if(g.getVertexList()[y]->getpred()!=0)
                    {


                    cout << "Vertex :" << *g.getVertexList()[y] << " Parent :" << *g.getVertexList()[y]->getpred() << endl;
                    nb++;
                    }
                    if(nb==0)
                    {
                        cout<< "Error, no Verticle reachable" << endl;
                    }
                }

                }
            else
            {
                cout<< "Error,no verticle found" << endl;

            }
            nb=0;
        break;
    case 7:cout << "Please type in the id of the vertex you want to use the algorithm on." << endl;
    cin>>vertexid;
        if(vertexid>0 && vertexid<=g.getNbVertex())
            {
                g.BELLMAN_FORD(*g.getVertexList()[vertexid-1]);
                cout << "Here are the Vertex and their Parent reachable from the Vertex you've chosen" << endl;
                for(int y=0;y<g.getNbVertex();y++)
                {
                    if(g.getVertexList()[y]->getpred()->getId()!=g.getVertexList()[y]->getId())
                    {
                    cout << "Vertex :" << *g.getVertexList()[y] << " Parent :" << *g.getVertexList()[y]->getpred() << endl;
                    nb++;
                    }

                }
                if(nb==0)
                    {
                        cout<< "Error, no Verticle reachable" << endl;
                    }

            }
            else
            {
                cout<< "Error,no verticle found" << endl;

            }
            nb=0;
        break;
    case 8:cout << "Please type in the id of the vertex you want to use the algorithm on." << endl;
    cin>>vertexid;
        if(vertexid>0 && vertexid<=g.getNbVertex())
            {
                g.DIJKSTRA(*g.getVertexList()[vertexid-1]);
                cout << "Here are the Vertex and their Parent reachable from the Vertex you've chosen" << endl;
                for(int y=0;y<g.getNbVertex();y++)
                {
                    if(g.getVertexList()[y]->getpred()!=0)
                    {
                    cout << "Vertex :" << *g.getVertexList()[y] << " Parent :" << *g.getVertexList()[y]->getpred() << endl;
                    nb++;
                    }

                }
                if(nb==0)
                    {
                        cout<< "Error, no Verticle reachable" << endl;
                    }
            }
            else
            {
                cout<< "Error,no verticle found" << endl;
            }
            nb=0;
        break;
    default:
        break;
	}



	return 0;
}
