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
    int id, x, y;

public:
	// Constructor
    Vertex(int _id): id(_id), x(0), y(0){};

    // Getters
    int getId(){return id;};
    int getX(){return x;};
    int getY(){return y;};



    // Ostream function
    friend ostream& operator<<(ostream &os, const Vertex &v);
};

#endif // VERTEX_H_INCLUDED
