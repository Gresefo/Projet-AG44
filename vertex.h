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
    public:

    int id;
    int x,y;

    Vertex(int _id): id(_id), x(0), y(0){};

    // Ostream function
    friend ostream& operator<<(ostream &os, const Vertex &v);
};

#endif // VERTEX_H_INCLUDED
