#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    int adj[10][10];
    
    public:
        Graph(int vcount);
        void addEdge(int src,int dest);
        void dfs();
        void dfs_visit(string color[],int discovery[],int final_time[],int src);
};

Graph::Graph(int vcount)
{
    this->v=vcount;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            adj[i][j]=false;
        }
    }
}
void Graph::addEdge(int src,int dest)
{
    adj[src][dest]=true;
}
int time1=0;
void Graph::dfs_visit(string color[],int discovery[],int final_time[],int src)
{
    time1++;
    color[src]="gray";
    discovery[src]=time1;
    for(int j=0;j<7;j++)
    {
        if(adj[src][j]==true && color[j]=="white")
        {
            cout<<j<<" ";
            dfs_visit(color,discovery,final_time,j);
        }
    }
    time1++;color[src]="black";final_time[src]=time1;
}

void Graph::dfs()
{
    int *discovery = new int[this->v];
    int *final_time = new int[this->v];
    string *color = new string[this->v];
    for(int i=0;i<7;i++)
    {
        color[i]="white";discovery[i]=0;final_time[i]=0;
    }
    
    for(int i=0;i<7;i++)
    {
        if(color[i]=="white")
        {
            cout<<i<<" ";
            dfs_visit(color,discovery,final_time,i);
        }
    }
    cout<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<discovery[i]<<" ";
    }cout<<endl;

    for(int i=0;i<7;i++)
    {
        cout<<final_time[i]<<" ";
    }cout<<endl;

}

