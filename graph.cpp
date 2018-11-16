#include "Graph.h"


void Graph::fileToGraph()
{
    string myFile = "exampleUndirectedMatrix.txt";
    string line;
    ifstream fichier(myFile.c_str(), ios::in);

    if(fichier)  // if the file succesfully opened
    {
        //The number of Vertices
        getline(fichier,line);
        nbVertex = atoi(line.c_str());  // atoi() convert a string in an int
        if (nbVertex < 0)
        {
            cerr << "Error: the number of vertex in the file is negative !" << endl;
        }

        //If the graph is directed or not
        getline(fichier,line);
        if (line.compare("o") == 0)		// string.compare() == 0 if it is the same string
            isDirected = true;
        else if (line.compare("n") == 0)
            isDirected = false;
        else
            cerr << "Error: the file does not correctly indicate if the graph is directed or not !" << endl;

        //If the graph is described by a adjency list or matrix 
        getline(fichier,line);
        if (line.compare("m") == 0)
            isMatrix = true;
        else if (line.compare("l") == 0)
            isMatrix = false;
        else
            cerr << "Error: the file does not indicate correctly if it use an adjency list or matrix !" << endl;


        if (isDirected)
        {
            // Filling the adjency matrix datas
            if (isMatrix)
            {

                while (getline(fichier,line))
                {
                    //j'y arrive pas, meme avec strtok() 
                }
            }

            //Filling the adjency list datas
            else
            {
                
            }
        }
        else
        {
            //Filling the adjency matrix datas
            if (isMatrix)
            {

            }

            //Filling the adjency list datas
            else
            {

            }
        }



        fichier.close();  // closing of the file
    }

    else  // if the file did not opened correctly
        cerr << "Error: while opening the file, the graph is empty !" << endl;
}




ostream& operator<<(ostream& os, const Graph& g)
{
    os << "This Graph contains " << g.nbVertex << " vertex(es)." << endl;

    if (g.isDirected)
        os << "It is a directed graph ";
    else
        os << "It is a non directed graph ";

    if (g.isMatrix)
        os << "defined by an adjency matrix :" << endl;
    else
        os << "defined by an adjency list :" << endl;

    if (g.listVertex.empty())
        os << "The list of Vertexes is empty !" << endl;
    else
    {
        os << "Vertex list: ";
        for (unsigned int i = 0; i < g.listVertex.size(); i++)
        {
            os << *g.listVertex[i] << ", ";
        }
        os << endl;
    }

    if (g.listEdge.empty())
        os << "The list of Edges is empty !" << endl;
    else
    {
        for (unsigned int i = 0; i < g.listEdge.size(); i++)
        {
			cout << "Edge list: ";
            os << *g.listEdge[i] << ", ";
        }
        os << endl;
    }

    if (g.isMatrix)
    {
        cout << "Adjency matrix :" << endl;
        for (int i = 0; i < g.nbVertex; i++)
        {
            for (int j = 0; j < g.nbVertex; j++)
            {
                cout << g.adjencyMatrix[i][j] << ",";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Adjency list :" << endl;
        for (int i = 0; i < g.nbVertex; i++)
        {

        }

    }


    return os;
}

void Graph::addEdge(Edge* e)
{
    listEdge.push_back(e);
    if (isMatrix)   // Cette fonction est elle necessaire ou est ce qu'on modifiera un graph uniquement à partir du fichier ????
    {
        if (isDirected)
        {

        }
        else
        {

        }
    }
}
