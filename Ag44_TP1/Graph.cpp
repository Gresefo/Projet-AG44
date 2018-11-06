#include <iostream>
#include "Graph.h"

using namespace std;

graph::graph(int n)
{
    int i,y;
    for(i=0,i<n,i++)
    {
        for(y=0,y<n,y++)
        {
            m_g[i][y]=0;
        }
    }
}


void graph::voisin(int l,int c);
{
    m_g[l-1][c-1]=1;
}
