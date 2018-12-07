#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "Edge.h"

class Graph
{
private:

    int nbVertex;
    int time; // Used in DFS
    bool isDirected;  // A boolean to know if the graph is directed (1) or not (0)
    bool isMatrix;  // A boolean to know if the structure of the graph is describe by a list (0) or by a matrix (1)

    vector<Vertex*> vertexList; // The Graph's Vertex list
    vector<Edge*> edgeList; // The Graph's Edge list

    vector<vector<vector<int> > > adjencyList;
    vector<vector<int> > adjencyMatrix;

public:
    // Constructor with a file
    Graph(): nbVertex(0), time(0), isDirected(0), isMatrix(0){};

    //Destructor
    ~Graph()
    {
        unsigned int i, j;
        // Clear Edge List
        edgeList.clear();

        // Clear Vertex List
        vertexList.clear();

        // Clear adjency Matrix
        for (i = 0; i < adjencyMatrix.size(); i++)
        {
            adjencyMatrix[i].clear();
        }
        adjencyMatrix.clear();

        // Clear adjency List
        for (i = 0; i < adjencyList.size(); i++)
        {
            for (j = 0; j < adjencyList[i].size(); j++)
            {
                adjencyList[i][j].clear();
            }
            adjencyList[i].clear();
        }
        adjencyList.clear();
    };

    /*Graph(vector<vector<vector<int> > > &v,Graph &g)
    {
        Graph();
        adjencyList=v;
        listToMatrix(v);
	

    } ; */

    // Function that reads a file in order to create a graph
    void fileToGraph(string myFile);

    // Create a file and save the information of a graph
    void graphToFile(string myFile);

    // Getters
    int getNbVertex(){return nbVertex;};
    bool getIsDirected(){return isDirected;};
    bool getIsMatrix(){return isMatrix;};
    vector<vector<vector<int> > > getadjencylist(){return adjencyList;};
    vector<Vertex*> getVertexList(){return vertexList;};

	// Setters
	void setAdjencyList(vector<vector<vector<int> > > &l){adjencyList=l;};

    // Add a vertex
    /*void addVertex(Vertex* v)
    {
        nbVertex++;
        vertexList.push_back(v);
    };*/

    // Fill the vertex/edge list using the adjency matrix/list. Are needed in fileToGraph()
    void fillVertexList();
    void fillEdgeList();

    // Switch the description type of a graph from matrix to list or list to matrix
    // Return 1 if succesful, 0 if not
    int matrixToList();
    int listToMatrix();

    // Ostream function
    friend ostream& operator<<(ostream &os, const Graph &g);

    // search algrithms
    void BFS(Vertex &src);
    void DFS(Vertex &src);
    void DFS_Visit(Vertex&);
    vector<Vertex*> Topological_Sort(Vertex& s);
    void invert(void);

};


#endif // GRAPH_H_INCLUDED