#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <vector>
#include <fstream>  // Used for file managment
#include <iostream>
#include <string>
#include <cstring>  // Used for strtok()
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Vertex
{
private:
    int id;
    int color,dist;//used in BFS
    int d,f;//used in DFS
    Vertex* pred;//used in BFS
    int distance; //used in relax
    Vertex* predecessor;//used in init single source


public:
    // Constructor
    Vertex(int _id): id(_id), color(0), dist(0), d(0), f(0), pred(0){};
    Vertex():id(-1), color(0), dist(0), d(0), f(0), pred(0){};
    // Destructor
    ~Vertex(){};

    // Getters
    int getId() const {return id;};
    int getcolor()const{return color;};
    int getdist()const{return dist;};
    int getd()const{return d;};
    int getf()const{return f;};
    Vertex* getpred()const{return pred;};

    //Setters
    void setcolor(int i){color=i;};
    void setdist(int i){dist=i;};
    void setpred(Vertex* u){pred=u;};
    void setd(int i){d=i;};
    void setf(int i){f=i;};



    // Ostream function
    friend ostream& operator<<(ostream &os, const Vertex &v);
};

#endif // VERTEX_H_INCLUDED