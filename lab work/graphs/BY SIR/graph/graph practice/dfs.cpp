#include<bits/stdc++.h>
#include "dfs.h"
using namespace std;

int main()
{
    Graph *g=new Graph(7);
    g->addEdge(0,1);
    g->addEdge(1,2);
    g->addEdge(3,2);
    g->addEdge(3,1);
    g->addEdge(3,4);
    g->addEdge(4,5);
    g->addEdge(6,5);
    g->addEdge(5,0);
    g->dfs();
}