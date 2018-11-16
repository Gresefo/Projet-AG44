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

	// Destructor
	~Vertex(){};

    // Getters
    int getId() const {return id;};
    int getX() const {return x;};
    int getY() const {return y;};



    // Ostream function
    friend ostream& operator<<(ostream &os, const Vertex &v);
};

#endif // VERTEX_H_INCLUDED
