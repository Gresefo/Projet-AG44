#The compilator
CXX=g++

#Error checking
CFLAGS=-W -Wall -I --ansi 


#Creation of the .exe
Graph: Client.o Graph.o Vertex.o Edge.o Heap.o
	$(CXX) -o $@ $^ $(CFLAGS)


#Creation of the .o
Client.o : Client.cpp Graph.cpp Vertex.cpp Edge.cpp Heap.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

Graph.o: Graph.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

Vertex.o: Vertex.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

Edge.o: Edge.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

Heap.o: Heap.cpp
	$(CXX) -o $@ -c $< $(CFLAGS) 



#To delete every file .o and the .exe
clean:
	rm -f *.o Graph
