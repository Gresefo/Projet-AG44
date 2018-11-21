#include "Graph.h"


void Graph::fileToGraph(string myFile)
{
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

        // Filling the adjency matrix or list datas
        int i = 0;
        char* cstr = NULL;
        char* token = NULL;
        vector<int> tmp;

        while(getline(fichier,line))
        {
            cstr = new char[line.length()];
            strcpy(cstr, line.c_str());
            token = strtok(cstr, ",; ");
            while(token != NULL)
            {
                i = atoi(token);
                if(i >= 0)
                {
                    tmp.push_back(i);
                }
                else
                {
                    cerr << "Error, there is a negative number !" << endl;
                }
                token = strtok(NULL, ",; ");

            }
            delete cstr;
            cstr = NULL;

            if (isMatrix)
                adjencyMatrix.push_back(tmp);
            else
                adjencyList.push_back(tmp);

            tmp.clear();
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
        os << "defined by an adjency matrix." << endl;
    else
        os << "defined by an adjency list." << endl;

    if (g.listVertex.empty())
        os << endl << "The list of Vertexes is empty !" << endl;
    else
    {
        os << endl << "Vertex list: ";
        for (unsigned int i = 0; i < g.listVertex.size(); i++)
        {
            os << *g.listVertex[i] << ", ";
        }
        os << endl;
    }

    if (g.listEdge.empty())
        os << endl << "The list of Edges is empty !" << endl;
    else
    {
		cout << endl << "Edge list: " << endl;
        for (unsigned int i = 0; i < g.listEdge.size(); i++)
        {
            os << *g.listEdge[i] << endl;
        }
    }

    if (g.isMatrix)
    {
        cout << endl << "Adjency matrix :" << endl;
        for (int i = 0; i < g.nbVertex; i++)
        {
            for (int j = 0; j < g.nbVertex; j++)
            {
                cout << g.adjencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Adjency list :" << endl;
        for (int i = 0; i < g.nbVertex; i++)
        {
            for (unsigned int j = 0; j < g.adjencyList[i].size(); j++)
            {
                cout << g.adjencyList[i][j] << "->";
            }
            cout << endl;
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
