#include <fstream>
#include <iostream>
#include <string>

#include "Graph.h"

using namespace std;

Graph::Graph(){

    nb_vertex=0;
    nb_edge=0;

    file2graph();


}

//std::stoi(string, nullptr , 10)
void Graph::file2graph(){
    string mon_fichier = "test.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
    string line;
    ifstream fichier(mon_fichier.c_str(), ios::in);

    if(fichier)  // si l'ouverture a réussi

    {

        // instructions
        getline(fichier,line);
        fichier.close();  // je referme le fichier

    }

    else  // sinon

        cerr << "Erreur à l'ouverture !" << endl;
}
