#include "Graph.h"
#include "Heap.h"

#include <iostream>

using namespace std;

int main()
{
	// Creation of an undirected graph (with a adjency matrix) using the file name "exampleUndirectedMatrix"
	Graph("exampleUndirectedMatrix.txt") g; 


	
	cout << "Hello World !" << endl;
	return 0;
}
