#include "Graph.h"


//std::stoi(string, nullptr , 10)
void Graph::fileToGraph(){
    string myFile = "fileGraph.txt";  // I store in the string myFile the name of the file to open
    string line;
    ifstream fichier(myFile.c_str(), ios::in);

    if(fichier)  // if the file succesfully opened
    {
        //The number of Vertices
        getline(fichier,line);
        nb_vertex = stoi(line, nullptr, 10);  // stoi() convert a string in an int
        if (nb_vertex < 0)
        {
            cerr << "Error: the number of vertex in the file is negative !" << endl;
        }

        //If the graph is directed or not
        getline(fichier,line);
        if (line == "o")
            isDirected = true;
        else if (line == "n")
            isDirected = false;
        else
            cerr << "Error: the file does not correctly indicate if the graph is directed or not !" << endl;

        //If the graph is described by a adjency list or matrix 
        getline(fichier,line);
        if (line == "m")
            isMatrix = true;
        else if (line == "l")
            isMatrix = false;
        else
            cerr << "Error: the file does not indicate correctly if it use an adjency list or matrix !" << endl;



        fichier.close();  // closing of the file
    }

    else  // if the file did not opened correctly

        cerr << "Error: while opening the file, the graph is empty !" << endl;
}
