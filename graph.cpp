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
        if (line.compare("o"))
            isDirected = true;
        else if (line.compare("n"))
            isDirected = false;
        else
            cerr << "Error: the file does not correctly indicate if the graph is directed or not !" << endl;

        //If the graph is described by a adjency list or matrix 
        getline(fichier,line);
        if (line.compare("m"))
            isMatrix = true;
        else if (line.compare("l"))
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

    if (g.listVertex == NULL)
        os << "The list of vertexes is empty !" << endl;
    else
    {
         
    }

    if (g.listEdge == NULL)
        os << "The list of Edges is empty !" << endl;
    else
    {
        
    }


    return os;
}