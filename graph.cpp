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
        else 
        {
            if (line.compare("n") == 0)
                isDirected = false;
            else
                cerr << "Error: the file does not correctly indicate if the graph is directed or not !" << endl;
        }


        //If the graph is described by a adjency list or matrix 
        getline(fichier,line);
        if (line.compare("m") == 0)
            isMatrix = true;
        else   
        {
            if (line.compare("l") == 0)
                isMatrix = false;
            else
                cerr << "Error: the file does not indicate correctly if it use an adjency list or matrix !" << endl;
        }


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


        // Checking of the size of the adjency list or matrix
        if (isMatrix)
        {
            if ((unsigned int)nbVertex != adjencyMatrix.size())
                cerr << "Error: the number of vertexes and the size of the adjency matrix don't correspond !" << endl;
        }
        else
        {
            if ((unsigned int)nbVertex != adjencyList.size())
                cerr << "Error: the number of vertexes and the size of the adjency list don't correspond !" << endl;
        }


        // Filling the vertexes and edges list
        this->fillVertexList();
        this->fillEdgeList();


        fichier.close();  // closing of the file
    }

    else  // if the file did not opened correctly
        cerr << "Error: while opening the file, the graph is empty !" << endl;
}


void Graph::fillVertexList()
{
    for (int i = 1; i <= nbVertex; i++)
    {
        Vertex* v = new Vertex(i);
        vertexList.push_back(v);
    }
}


void Graph::fillEdgeList()
{
    int id = 1;
    if (isMatrix)
    { 
        for (int i = 0; i < nbVertex; i++)
        {
            for (int j = 0; j < i; j++)
            {   
                if (adjencyMatrix[i][j] != 0)
                {
                    Edge* e = new Edge(id, vertexList[i], vertexList[j]);
                    e->setWeight(adjencyMatrix[i][j]);
                    edgeList.push_back(e);
                    id++;
                }
            }
        }
    }
    else
    {

    }
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

    if (g.vertexList.empty())
        os << endl << "The list of Vertexes is empty !" << endl;
    else
    {
        os << endl << "Vertex list: ";
        for (unsigned int i = 0; i < g.vertexList.size(); i++)
        {
            os << *g.vertexList[i] << ", ";
        }
        os << endl;
    }

    if (g.edgeList.empty())
        os << endl << "The list of Edges is empty !" << endl;
    else
    {
        cout << endl << "Edge list: " << endl;
        for (unsigned int i = 0; i < g.edgeList.size(); i++)
        {
            os << *g.edgeList[i] << endl;
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
        cout << endl << "Adjency list :" << endl;
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


