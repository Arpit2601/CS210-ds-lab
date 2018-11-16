#include<iostream>
#include<vector>
#include<queue>

using namespace std;



struct Graph{
	int v;
	bool **adj;
	public:

		Graph(int vcount);
		void addEdge(int u,int v);
		void deleteEdge(int u,int v);
		vector<int> BFS(int s);
		vector<int> DFS(int s);
		void DFSUtil(int s,vector<bool> &visited,vector<int> &dfs);
		bool DFS_connected_components(int s,int dest);
		int countComponents();
		void DFSUtil_to_count_components(int s,bool visited[]);
		bool isSameComponent(int v1, int v2);
		bool DFS_same_connected_components(int v1,int v2);
		bool DFSUtil_same_connected_components(int s, vector<int> &dfs, vector<bool> &visited,int dest);
		
};

Graph::Graph(int vcount){
	this->v = vcount;
	this->adj=new bool*[vcount];
	for(int i=0;i<vcount;i++)
		this->adj[i]=new bool[vcount];
	for(int i=0;i<vcount;i++)
		for(int j=0;j<vcount;j++)
			adj[i][j]=false;
}

void Graph::addEdge(int u,int w){
	this->adj[u][w]=true;
	this->adj[w][u]=true;
}

void Graph::deleteEdge(int u,int w){
	this->adj[u][w]=false;
	this->adj[w][u]=false;
}

vector<int> Graph::BFS(int s){
	vector<bool> visited(this->v);
	vector<int> bfs;
	queue<int> que;
	que.push(s);
	visited[s]=true;
	while(!que.empty()){
		bfs.push_back(que.front());
		for(int i=0;i<this->v;i++){
			if(adj[que.front()][i]==true && visited[i]==false){
				visited[i]=true;
				que.push(i);
			}
		}
		que.pop();
	}
	return bfs;
}

bool Graph::DFSUtil_same_connected_components(int s, vector<int> &dfs, vector<bool> &visited,int dest){
	visited[s]=true;
	dfs.push_back(s);
	if(s==dest){return true;}
	for(int i=0;i<this->v;i++){
		if(this->adj[s][i]==true && visited[i]==false)
		// {	if(i==dest)
		// 	{
		// 		return true;
		// 	}
			DFSUtil_same_connected_components(i,dfs,visited,dest);
		}
	
	//return false;
}

void Graph::DFSUtil(int s,vector<bool> &visited,vector<int> &dfs){
	visited[s]=true;
	dfs.push_back(s);
	for(int i=0;i<this->v;i++)
	{
		if(adj[s][i]==true && visited[i]==false)
		{
			DFSUtil(i,visited,dfs);
		}
	}
}

vector<int> Graph::DFS(int s){
	vector<bool> visited(this->v);
	vector<int> dfs(this->v);
	for(int i=0;i<this->v;i++)
	{
		if(visited[i]==false)
		{
			DFSUtil(i,visited,dfs);
		}
	}
	return dfs;
}


bool Graph::DFS_same_connected_components(int s,int dest){
	vector<bool> visited(this->v);
	vector<int> dfs;
	if(DFSUtil_same_connected_components(s,dfs,visited,dest))
	{
		return true;
	}
	return false;
}

//dfs_util to count components
void Graph::DFSUtil_to_count_components(int each_vertex,bool visited[]){
	visited[each_vertex]=true;
	for(int i=0;i<this->v;i++)
	{
		if(this->adj[each_vertex][i]==true && visited[i]==false)
		{
			DFSUtil_to_count_components(i,visited);
		}
	}
} 

//function to count components
int Graph::countComponents(){
//write this function using either BFS or DFS
	// Mark all the vertices as not visited 
    bool *visited = new bool[this->v]; 
	int count=0;

    for(int each_vertex = 0; each_vertex < this->v; each_vertex++) 
        visited[each_vertex] = false; 
  
    for (int each_vertex=0; each_vertex< this->v; each_vertex++) 
    { 
        if (visited[each_vertex] == false) 
        { 
			count++;
            DFSUtil_to_count_components(each_vertex, visited); 
        } 
    }
    return count;
}



bool Graph::isSameComponent(int v1, int v2){
//write this function using either BFS or DFS
	
	vector<int> bfs=BFS(v1);
	vector<int>::iterator it;
	for( it=bfs.begin();it!=bfs.end();it++)
	{
		if(*it==v2){return true;}
	}
	return false;
	
}


