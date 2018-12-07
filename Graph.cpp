#include "Graph.h"

using namespace std;

ostream& operator<<(ostream& os, const Graph& g)
{
    // Vertex list
    os << endl << "This Graph contains " << g.nbVertex << " vertex(es): ";
    if (g.vertexList.empty())
        os << endl << "The list of Vertexes is empty !" << endl;
    else
    {
        int size = g.vertexList.size();
        for (int i = 0; i < size; i++)
        {
            os << *g.vertexList[i] << ", ";
        }
        os << endl;
    }

    // Edge list
    if (g.edgeList.empty())
        os << "The list of Edges is empty !" << endl;
    else
    {
        cout << "Edge list: ";
        int size = g.edgeList.size();
        for (int i = 0; i < size; i++)
        {
            os << *g.edgeList[i] << " | ";
        }
        cout << endl;
    }

    // Directed or not
    if (g.isDirected)
        os << "It is a directed graph ";
    else
        os << "It is a non directed graph ";

    // Defined by a Matrix or a List
    if (g.isMatrix)
        os << "defined by an adjency matrix:" << endl;
    else
        os << "defined by an adjency list:" << endl;
    if (g.isMatrix)
    {
        for (int i = 0; i < g.nbVertex; i++)
        {
            for (int j = 0; j < g.nbVertex; j++)
            {
                cout << g.adjencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < g.nbVertex; i++)
        {
            cout << "V" << i + 1 << "->";
            int size = g.adjencyList[i].size();
            for (int j = 0; j < size; j++)
            {
                cout << "V" << g.adjencyList[i][j][0] << "(" << g.adjencyList[i][j][1] << ")->";
            }
            cout << endl;
        }
    }

    return os;
}


void Graph::fileToGraph(string myFile)
{
    string line;
    ifstream fichier(myFile.c_str(), ios::in);

    if(fichier)  // if the file succesfully opened
    {
        //The number of Vertices
        getline(fichier,line);
        nbVertex = atoi(line.c_str());  // atoi() convert a string in an int
        if (nbVertex < 0)
        {
            cerr << "Error: the number of vertex in the file is negative !" << endl;
            exit (EXIT_FAILURE);
        }


        //If the graph is directed or not
        getline(fichier,line);
        if (line.compare("o") == 0)     // string.compare() == 0 if it is the same string
            isDirected = true;
        else 
        {
            if (line.compare("n") == 0)
                isDirected = false;
            else
            {
                cerr << "Error: the file does not correctly indicate if the graph is directed or not !" << endl;
                exit (EXIT_FAILURE);
            }
        }


        //If the graph is described by a adjency list or matrix 
        getline(fichier,line);
        if (line.compare("m") == 0)
            isMatrix = true;
        else   
        {
            if (line.compare("l") == 0)
                isMatrix = false;
            else
            {
                cerr << "Error: the file does not indicate correctly if it use an adjency list or matrix !" << endl;
                exit (EXIT_FAILURE);
            }
        }


        // Filling the adjency matrix or list datas
        int i = 0;
        char* cstr = NULL;
        char* token = NULL;

        if (isMatrix)
        {
            vector<int> tmp;
            while(getline(fichier,line))
            {
                cstr = new char[line.length()];
                strcpy(cstr, line.c_str());
                token = strtok(cstr, ",; ");
                while(token != NULL)
                {
                    i = atoi(token);
                    if(i >= 0)
                    {
                        tmp.push_back(i);
                    }
                    else
                    {
                        cerr << "Error, there is a negative number !" << endl;
                        exit (EXIT_FAILURE);
                    }
                    token = strtok(NULL, ",; ");
                }
                delete cstr;
                cstr = NULL;

                adjencyMatrix.push_back(tmp);
                tmp.clear();
            }
        }

        else   // If the graph is defined by an adjency list

        {
            vector<vector<int> > tmp1;
            vector<int> tmp2;
            while(getline(fichier,line))
            {
                cstr = new char[line.length()];
                strcpy(cstr, line.c_str());
                token = strtok(cstr, ";, ");
                while(token != NULL)
                {
                    i = atoi(token);
                    if(i >= 0)
                    {
                        tmp2.push_back(i);
                    }
                    else
                    {
                        cerr << "Error, there is a negative number !" << endl;
                        exit (EXIT_FAILURE);
                    }
                    token = strtok(NULL, ";, ");
                    i = atoi(token);
                    if(i >= 0)
                    {
                        tmp2.push_back(i);
                    }
                    else
                    {
                        cerr << "Error, there is a negative weight !" << endl;
                        exit (EXIT_FAILURE);
                    }
                    tmp1.push_back(tmp2);
                    tmp2.clear();
                    token = strtok(NULL, ";, ");
                }
                delete[] cstr;
                cstr = NULL;

                adjencyList.push_back(tmp1);
                tmp1.clear();
            }
        }


        // Checking of the size of the adjency list or matrix
        if (isMatrix)
        {
            if ((unsigned int)nbVertex != adjencyMatrix.size())
            {
                cerr << "Error: the number of vertexes and the size of the adjency matrix don't correspond !" << endl;
                exit (EXIT_FAILURE);
            }

        }
        else
        {
            if ((unsigned int)nbVertex != adjencyList.size())
            {
                cerr << "Error: the number of vertexes and the size of the adjency list don't correspond !" << endl;
                exit (EXIT_FAILURE);
            }
        }


        // Filling the vertexes and edges list
        this->fillVertexList();
        this->fillEdgeList();


        fichier.close();  // closing of the file
    }

    else  // if the file did not opened correctly
    {
        cerr << "Error: while opening the file, the graph is empty !" << endl;
        exit (EXIT_FAILURE);
    }
}


void Graph::fillVertexList()
{
    for (int i = 1; i <= nbVertex; i++)
    {
        Vertex* v = new Vertex(i);
        vertexList.push_back(v);
    }
}


void Graph::fillEdgeList()
{
    int id = 1;
    if (isMatrix)
    { 
        for (int i = 0; i < nbVertex; i++)
        {
            for (int j = 0; j < i; j++)
            {   
                if (adjencyMatrix[i][j] != 0)
                {
                    Edge* e = new Edge(id, vertexList[i], vertexList[j]);
                    e->setWeight(adjencyMatrix[i][j]);
                    edgeList.push_back(e);
                    id++;
                }
            }
        }
    }
    else
    {
        int size = 0;
        for (int i = 0; i < nbVertex; i++)
        {
            size = adjencyList[i].size();
            for(int j = 0; j < size; j++)
            {
                Edge* e = new Edge(id, vertexList[i], vertexList[adjencyList[i][j][0] - 1]);
                e->setWeight(adjencyList[i][j][1]);
                edgeList.push_back(e);
                id++;
            }
        }
    }
}


void Graph::graphToFile(string myFile)
{
        ofstream fichier(myFile.c_str(), ios::out | ios::trunc);  // Opening in writting mode the file named myFile
 
        if(fichier)
        {
            fichier << nbVertex << endl;
            if (isDirected)
                fichier << "o" << endl;
            else
                fichier << "n" << endl;
            if (isMatrix)
                fichier << "m" << endl;
            else
                fichier << "l" << endl;
            if (isMatrix)
            {
                for (int i = 0; i < nbVertex; i++)
                {
                    for (int j = 0; j < nbVertex; j++)
                    {
                        fichier << adjencyMatrix[i][j];
                        if (j == nbVertex - 1)
                            fichier << ";";
                        else
                            fichier << ",";                    
                    }
                    if (i != nbVertex - 1)
                        fichier << endl;
                }
            }
            else
            {
                int size = 0;
                for (int i = 0; i < nbVertex; i++)
                {
                    size = adjencyList[i].size();
                    if (size == 0)
                        fichier << ";";
                    for (int j = 0; j < size; j++)
                    {
                        fichier << adjencyList[i][j][0] << "," << adjencyList[i][j][1] << ";";
                    }
                    if (i != nbVertex - 1)
                        fichier << endl;
                }
            }
 
            fichier.close();
        }
        else
        {
            cerr << "Impossible d'ouvrir le fichier !" << endl;
            exit (EXIT_FAILURE);
        }
}


int Graph::matrixToList() //FAIRE LE RETURN 0 SI PROBLEME
{
    if (isMatrix)
    {
        // Filling the adjencyList
        int i, j;
        vector<vector<int> > tmp1;
        vector<int> tmp2;
        for (i = 0; i < nbVertex; i++)
        {
            for (j = 0; j < nbVertex; j++)
            {
                if (adjencyMatrix[i][j] != 0)
                {
                    tmp2.push_back(j + 1);
                    tmp2.push_back(adjencyMatrix[i][j]);
                    tmp1.push_back(tmp2);
                    tmp2.clear();
                }
            }
            adjencyList.push_back(tmp1);
            tmp1.clear();
        }

        // Clearing the adjencyMatrix and switching the type of graph
        for (i = 0; i < nbVertex; i++)
        {
            adjencyMatrix[i].clear();
        }
        adjencyMatrix.clear();
        isMatrix = 0;
    }
    return 1;
}


int Graph::listToMatrix() //FAIRE LE RETURN 0 SI PROBLEME
{
    if (isMatrix == 0)
    {
        int i, j, k;

        // Fill the matrix with 0
        vector<int> tmp;
        for (i = 0; i < nbVertex; i++)
        {
            tmp.push_back(0);
        }
        for (i = 0; i < nbVertex; i++)
        {
            adjencyMatrix.push_back(tmp);
        }
        tmp.clear();

        // Fill the matrix with corrects values
        for (i = 0; i < nbVertex; i++)
        {
            int size = adjencyList[i].size();
            for (j = 0; j < size; j++)
            {
                adjencyMatrix[i][adjencyList[i][j][0] - 1] = adjencyList[i][j][1];
            }
        }

        // Delete the list and switch the type to matrix
        for (j = 0; j < nbVertex; j++)
        {
            int size = adjencyList[i].size();
            for (k = 0; k < size; k++)
            {
                adjencyList[j][k].clear();
            }
            adjencyList[j].clear();
        }
        adjencyList.clear();
        isMatrix = 1;
    }
    return 1;
}





/*



void Graph::BFS(Vertex & s)
{
    int nb(0);
    unsigned int i(0);
    for(i=0;i<vertexList.size();i++)
    {
        vertexList[i]->setcolor(0);
        vertexList[i]->setdist(1);
        vertexList[i]->setpred(NULL);
    }
    s.setcolor(1);
    s.setdist(0);
    vector<Vertex*> Q;
    vector<Vertex*>::iterator ite;
    Vertex* u(0),v(0);
    Q.push_back(&s);
    while ( Q.empty()==false)
    {
        u=Q.front();
        for(i=0;i<adjencyList[u->getId()-1][0].size();i++)
        {
            v=*vertexList[adjencyList[u->getId()-1][0][i]-1];
            if(v.getcolor()==0)
            {
                v.setcolor(1);
                v.setdist(u->getdist()+1);
                v.setpred(u);
                Q.push_back(&v);
                nb+=1;//nb est le nombre de vertex que l'on peut attendre en partant de s, à comparer avc nbvertex
            }
        }
        u->setcolor(2);
        ite=Q.begin();
        Q.erase(ite);

    }
    //sert sans dout a renvoyer un bredth first tree qu'il faudra construire; si on renvoie un vector c'est bon 
    //si on renvie un graph il faudra mettre filetograph en dehor de la classe ou faire un constructeur qui prend 
    //en paramètre un vector ss appeler filetograph
}


void Graph::DFS(Vertex & s)
{
    unsigned int i(0);
    int nb(0),time;
    for(i=0;i<vertexList.size();i++)
    {
        vertexList[i]->setcolor(0);
        vertexList[i]->setpred(NULL);
    }
    time=0;
    s.setd(time);
    for(i=0;i<adjencyList[s.getId()-1][0].size();i++)
    {
        if(vertexList[adjencyList[s.getId()-1][0][i]-1]->getcolor()==0)
        {
            DFS_Visit( *vertexList[adjencyList[s.getId()-1][0][i]-1]);
        }
        
    }
}

void Graph::DFS_Visit(Vertex & u)
{
    unsigned int i(0);
    Vertex* v;
    time=time+1;
    u.setd(time);
    u.setcolor(1);
    for(i=0;i<adjencyList[u.getId()-1][1].size();i++)
    {
        v=vertexList[adjencyList[u.getId()-1][0][i]-1];
        if(v->getcolor()==0)
        {

            v->setpred(&u);
            DFS_Visit(*v);
        }
    }
    u.setcolor(2);
    time+=1;
    u.setf(time);
}

vector<vertex*> Graph::Topological_Sort(Vertex &s)
{
    vector<Vertex*> Q, C(vertexList);
    Vertex* temp;
    DFS(s);
    for(int i=0;i<vertexList.size();i++)
    {
        temp=vertexList[i]
        for(int k=0;k>C.size();k++)
        {
            if(temp->getf() <C[k]->getf())
            {
                temp=C[k];
            }
        }
        Q.push_back(temp);
        C.erase(C.begin()+temp->getId()-1);
    }
    return Q;
}

void  Graph::SCC(Vertex& s)
{
    DFS(s);
    Grapg Gt=computeGT(vertexList);
    Gt.DFS(*Gt.getvertexList()[1]);
    Gt.invert();
}

void Graph::invert()
{
    for(int i=0;i<nbvertex;i++)
    {
        vertexList[i]->setf(2*nbvertex-1-vertexList[i]);
    }
    }


    Graph Graph::computeGT(Graph& g)
    {
    vector<vector<vector<int>>>  v=g.getadjencylist(),vt[g.getNbVertex()][2][0];
    for(int i=0;i<g.getNbVertex();i++)
    {
        if(v[i][0].empty==false)
        {
            for(int k=0;k<v[i].size();k++)
            {
                vt[v[i][0][k]][0].push_back(i+1);
                vt[v[i][0][k]][1].push_back(v[i][1][k]);
            }

        }

    }
    Graph gf();
    gf.setadjencyList(vt);

    return gf;
}


*/
