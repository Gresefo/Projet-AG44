#include "Graph.h"
#include <algorithm>
#include <vector>
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
                delete cstr;
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


int Graph::matrixToList() 
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


int Graph::listToMatrix() 
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


void Graph::BFS(Vertex & s)
{

    int nb(0),size(0),swap(0),id;
    if(isMatrix==true)
    {
        this->matrixToList();//change le format pour qu'il soit adapté a la fonction
        swap=1;
    }

    for(unsigned int i=0;i<vertexList.size();i++)//initialise tout les vertex
    {
        vertexList[i]->setcolor(0);
        vertexList[i]->setdist(1);
        vertexList[i]->setpred(NULL);
    }
    s.setcolor(1);
    s.setdist(0);
    vector<Vertex*> Q;

    Vertex* u(0),*v(0);

    Q.push_back(&s);
    while ( Q.empty()==false)
    {
        u=Q.front();
        size=adjencyList[u->getId()-1].size();
        for(int i=0;i<size;i++)
        {
            id=adjencyList[u->getId()-1][i][0];
            v=vertexList[id-1];
            if(v->getcolor()==0)

            {

                v->setcolor(1);
                v->setdist(u->getdist()+1);
                v->setpred(u);
                Q.push_back(v);
                nb+=1;//nb est le nombre de vertex que l'on peut attendre en partant de s, à comparer avc nbvertex
            }
        }
        u->setcolor(2);
        Q.erase(Q.begin());
    }

    if(nb==nbVertex)
    {
        cout<<"All verticle are linked from the choosen one"<<endl;
    }
    else
    {
        cout<<"All verticles are not linked from the verticle :" << s <<endl;
    }
    if(swap==1)
    {
        this->listToMatrix();
    }

    //sert sans dout a renvoyer un bredth first tree qu'il faudra construire; si on renvoie un vector c'est bon
    //si on renvie un graph il faudra mettre filetograph en dehor de la classe ou faire un constructeur qui prend
    //en paramètre un vector ss appeler filetograph
}



void Graph::DFS(Vertex & s)
{

    int size(0);
    bool swap(0);
    if(isMatrix)
    {
        this->matrixToList();
        swap=1;
    }

    for(unsigned int i=0;i<vertexList.size();i++)
    {
        vertexList[i]->setd(-1);
        vertexList[i]->setf(-1);
        vertexList[i]->setcolor(0);
        vertexList[i]->setpred(NULL);
    }
    time=0;
    s.setd(time);
    s.setcolor(1);

    size=adjencyList[s.getId()-1].size();
    for(int i=0;i<size;i++)
    {
        if(vertexList[adjencyList[s.getId()-1][i][0]-1]->getcolor()==0)
        {
            DFS_Visit( *vertexList[adjencyList[s.getId()-1][i][0]-1]);
        }
    }
    s.setcolor(2);
    time+=1;
    s.setf(time);

    if(swap)
    {
        this->listToMatrix();
    }


}

void Graph::DFS_proc(Vertex & s)// same as dfs but without initialisation
{

    int size(0);
    bool swap(0);

    if(isMatrix)
    {
        this->matrixToList();
        swap=1;
    }

    time+=1;
    s.setd(time);

    s.setcolor(1);
    size=adjencyList[s.getId()-1].size();
    for(int i=0;i<size;i++)
    {
        if(vertexList[adjencyList[s.getId()-1][i][0]-1]->getcolor()==0)
        {
            DFS_Visit( *vertexList[adjencyList[s.getId()-1][i][0]-1]);
        }
    }
    s.setcolor(2);
    time+=1;
    s.setf(time);

    if(swap)
    {
        this->listToMatrix();
    }
}

void Graph::DFS_Visit(Vertex & u)
{

    unsigned int i(0);
    Vertex* v;
    time=time+1;
    u.setd(time);
    u.setcolor(1);
    for(i=0;i<adjencyList[u.getId()-1].size();i++)
    {
        v=vertexList[adjencyList[u.getId()-1][i][0]-1];
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

vector<Vertex*> Graph::Topological_Sort(Vertex &s)
{
    bool swap(0);
    if(isMatrix)
    {
        this->matrixToList();
        swap=1;
    }
    vector<Vertex*> Q,C(vertexList);
    Vertex* temp;
    DFS(s);
    DFSutil(s);



    int size = vertexList.size();

    int ite;
    while(C.empty()==false)
    {
        ite=0;
        temp=C[0];
        int size = C.size();
        for(int k=0;k<size;k++)
        {
            if(temp->getf() <C[k]->getf())
            {

                temp=C[k];
                ite=k;
            }
        }
        Q.push_back(temp);
        C.erase(C.begin()+ite);
    }
    if(swap)
    {
        this->listToMatrix();
    }
    return Q;
}

void Graph::DFSutil(Vertex &s)//run dfs for every vertex to make sure there isnt any vertex left without being computed
{
    this->DFS(s);
    for(unsigned int i=0;i<vertexList.size();i++)
    {
        if(vertexList[i]->getcolor()==0)
        {
            this->DFS_proc(*vertexList[i]);
        }
    }
}

vector<vector<Vertex*> > Graph::SCC(Vertex& s)
 {
    Vertex* temp;
    bool swap(0);
    if(isMatrix)
    {
        this->matrixToList();
        swap=1;
    }
    vector<int> supp;
    vector<Vertex*> Q(this->Topological_Sort(s));
    vector<vector<Vertex*> > R;
    vector<Vertex*> intermediaire;

    this->computeGT();

    while(Q.empty()==false)
    {
        temp=Q[0];
        intermediaire.push_back(vertexList[Q[0]->getId()-1]);

        DFS(*temp);

        for(unsigned int i=1;i<Q.size();i++)
        {
            if(Q[i]->getcolor()==2)
            {
                intermediaire.push_back(vertexList[Q[i]->getId()-1]);
                supp.push_back(i);
            }
        }

        int taille(supp.size());
        for(int z=taille;z>0;z--)
        {
            Q.erase(Q.begin()+supp[z-1]);
        }

        R.push_back(intermediaire);
        Q.erase(Q.begin());

        intermediaire.clear();
        supp.clear();
    }
    for (unsigned int e=0;e<R.size();e++)
    {
        cout<< "component nuber :" << e+1 ;
        for(unsigned int t=0;t<R[e].size();t++)
        {
            cout << "  " << *R[e][t];
        }
        cout << endl;
    }
    this->computeGT();

    if(swap)
    {
        this->listToMatrix();
    }
    return R;
}


vector<Vertex*>::iterator Graph::find_it(vector<Vertex*> Q,Vertex& v)
{
    int size = Q.size();
    for(int i=0;i<size;i++)
    {
        if(Q[i]==&v)
        {
            return Q.begin()+i;
        }
    }
    return Q.end();
}

void Graph::invert()
{
    for(int i=0;i<nbVertex;i++)
    {
        vertexList[i]->setf(2*nbVertex-vertexList[i]->getf()/*-1*/);
    }
}


 void Graph::computeGT()
 {
    bool swap(0);
    if(isMatrix==false)
    {
        this->listToMatrix();//change le format pour qu'il soit adapté a la fonction
        swap=1;
    }
    vector<Vertex*> vlist(getVertexList());
    vector<vector< int > >  v(adjencyMatrix),vt;//

    vector<vector<int> > temp2,init2;
    vector<int> temp1,init1;
    for(int s=0;s<nbVertex;s++)
    {
        init1.push_back(0);

    }
    for(int j=0;j<nbVertex;j++)
    {
        vt.push_back(init1);

    }
    for(int i=0;i<nbVertex;i++)
    {
            for(int k=0;k<nbVertex;k++)
            {
                vt[k][i]=v[i][k];
            }
    }
    cout<<endl;

    this->setadjencyMatrix(vt);

    if(swap)
    {
        this->matrixToList();
    }
 }

void Graph::init_Single_Src(Vertex &s)
{
    int upperbound(1);
    unsigned int i;
    for( i=0;i<edgeList.size();i++)
    {
        upperbound+=edgeList[i]->getWeight();
    }
    for( int t=0;t<vertexList.size();t++)
    {
        vertexList[t]->setdist(upperbound);
        vertexList[t]->setpred(vertexList[t]);
    }
    s.setdist(0);
}

void Graph::relax(Vertex &u,Vertex &v,int w)
{
    bool found(0);
    Edge* e(0);
    /*for(unsigned int i=0;i<edgeList.size();i++)
    {
        if(edgeList[i]->getSrc()==&u && edgeList[i]->getDst()==&v)
            {
                found=1;
                e=edgeList[i];
            }
    }*/
    //if(found==1)
    //{
      //  cout << "u.getdist =" << u.getdist() << "/ v.dist" << v.getdist() << "/ poid" << w << endl;
        if(v.getdist()>u.getdist()+w)
        {
            v.setdist(u.getdist()+w);
            v.setpred(&u);
        }
    //}
    /*else
    {
        cerr<< "error, edge not found" << endl;
    }*/

}

 bool Graph::BELLMAN_FORD(Vertex &s)
 {
     bool swap(0);
     if(isMatrix)
     {
         this->matrixToList();
         swap=1;
     }
    this->init_Single_Src(s);

    for(unsigned int i(1);i<vertexList.size();i++)

    {
        for(unsigned int k(0);k<edgeList.size();k++)
        {
            relax(*edgeList[k]->getSrc(),*edgeList[k]->getDst(),edgeList[k]->getWeight());
        }
    }
        for(unsigned int k=1;k<edgeList.size();k++)
        {
            if(edgeList[k]->getDst()->getdist()>edgeList[k]->getSrc()->getdist()+edgeList[k]->getWeight())
            {
                if(swap)
                {
                    this->listToMatrix();
                }
                return false;
            }
        }
        if(swap)
        {
            this->listToMatrix();
        }

        return true;
 }


Vertex* extract_Mini(vector<Vertex *> &Q)
{
    Vertex* u(Q[0]);
    int ite(0);
    for(unsigned int i=1;i<Q.size();i++)
    {
        if(Q[i]->getdist()<u->getdist())
        {
            u=Q[i];
            ite=i;
        }
    }
    Q.erase(Q.begin()+ite);
    return u;
}



vector<Vertex *> Graph::DIJKSTRA(Vertex &s)
{
    bool swap(0);
     if(isMatrix==true)
    {
        this->matrixToList();//change le format pour qu'il soit adapté a la fonction
        swap=1;
    }
    init_Single_Src(s);
    Vertex *u;
    std::vector<Vertex *> S,Q(vertexList);
    while(Q.empty()==false)
    {
        u=extract_Mini(Q);
        S.push_back(u);
        for(unsigned int i(0);i<adjencyList[u->getId()-1].size();i++)
        {
            relax(*u,*vertexList[adjencyList[u->getId()-1][i][0]-1],adjencyList[u->getId()-1][i][1]);
        }
    }
    if(swap)
    {
        this->listToMatrix();
    }

    return S;
}


void Graph::Prim(Vertex &s)
{
    bool swap(0);
     if(isMatrix==true)
    {
        this->matrixToList();//change le format pour qu'il soit adapté a la fonction
        swap=1;
    }
    int upperbound;
    Vertex *u,*v;
    int size = edgeList.size();
    for(int i=0;i<size;i++)
    {
        upperbound+=edgeList[i]->getWeight();
    }
    size = vertexList.size();
    for(int i=0;i<size;i++)
    {
        vertexList[i]->setpred(0);
        vertexList[i]->setdist(upperbound+1);
    }
    s.setdist(0);
    vector<Vertex*> Q(vertexList);
    while(Q.empty()==false)
    {
        u=extract_Mini(Q);
        for(unsigned int i=0;i<adjencyList[u->getId()-1].size();i++)
        {
            v=vertexList[adjencyList[u->getId()-1][i][0]-1];
            vector<Vertex*>::iterator it = find_it(Q, *Q[i]);
            if (it != Q.end() || Q[Q.size()-1]==Q[i])
            {
             if(adjencyList[u->getId()-1][i][1]<v->getdist())
                {
                    v->setpred(u);
                    v->setdist(adjencyList[u->getId()-1][i][1]);
                }
            }
        }
    }
    if(swap)
    {
        this->listToMatrix();
    }
}

Vertex* Graph::find_set(Vertex& v)
{
    if(&v==v.getpred())
    {
        return &v;
    }
    else
    {
        return find_set(*v.getpred());
    }
}

void Graph::union_set(Vertex &u, Vertex &v) {
    v.setpred(u.getpred());
}


vector<Edge*> Graph::Kruskal()
{
    Vertex *u,*v;
    vector<Edge*> T;
    int size = vertexList.size();
    for(int i=0;i<size;i++)
    {
        vertexList[i]->setpred(vertexList[i]);
    }
    vector<Edge *> G(edgeList);

    sort(G);
    size = G.size();
    for(int i=0;i<size;i++)
    {
        u=find_set(*G[i]->getSrc());
        v=find_set(*G[i]->getDst());
        if(u->getId() != v->getId())
        {
            T.push_back(G[i]);
            union_set(*u,*v);
        }
    }
    return T;
}

void sort(vector<Edge*> &G)
{
    bool inorder(false);
    int taille=G.size();
    Edge *temp ;
    while(!inorder)
    {
        inorder=true;
        for(int i=0;i<taille-1;i++)
        {
            if(G[i]->getWeight()>G[i+1]->getWeight())
            {
                temp=G[i+1];
                G[i+1]=G[i];
                G[i]=temp;
                inorder =false;
            }
        }
        taille--;
    }
}