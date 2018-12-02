#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>  // Used for strtok()
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Vertex
{
private:
    int id;
    int color,dist;//used in BFS
    int d,f;//used in DFS
    Vertex* pred;//used in BFS

public:
	// Constructor
    Vertex(int _id): id(_id), color(0), dist(0), d(0), f(0){};

	// Destructor
	~Vertex(){};

    // Getters
    int getId() const {return id;};



    // Ostream function
    friend ostream& operator<<(ostream &os, const Vertex &v);
};

#endif // VERTEX_H_INCLUDED
