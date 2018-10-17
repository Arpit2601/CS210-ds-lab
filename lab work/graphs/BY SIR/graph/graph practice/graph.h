#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class Graph{

	int v;
	bool adj[20][20];
	//int *distance_from_s=new int[this->v],*bfsOrder=new int[this->v];
	
	public:
		Graph(int vcount);
		int get_v();
		//int* get_distance();
		void addEdge(int source, int dest);
		void deleteEdge(int source, int dest);
		void BFS(int s);

};


	// int* Graph::get_distance()
	// {
	// 	return this->distance_from_s;
	// }

	int Graph::get_v()
	{
		return this->v;
	}

	Graph::Graph(int vcount){
		this->v=vcount;
		for(int i=0; i<v;i++){

			for(int j=0; j<v; j++){
				adj[i][j]=false;
			}
		}


	}


	void Graph::addEdge(int source, int dest){
		adj[source][dest]=true;
		adj[dest][source]=true;
	}

	void Graph::deleteEdge(int source, int dest){
		adj[source][dest]=false;
		adj[dest][source]=false;
	}

	void Graph::BFS(int s){
		bool *visited= new bool[this->v];
		int *bfsOrder= new int[this->v];
		int *distance_from_s=new int[this->v];
		for(int i=0;i<v;i++)
		{
			visited[i]=false;distance_from_s[i]=0;bfsOrder[i]=0;
		}
		//int q[100];
		//int front=0;
		//int back=0;
		int x;
		queue <int> q;
		q.push(s);
		visited[s]=true;
		//q[front]=s;
		int count=0;
		while(!q.empty()){
			x=q.front();
			q.pop();
			visited[x]=true;
			bfsOrder[count]=x;
			count++;
			for(int j=0;j<20;j++)
			{
				if(adj[x][j]==true && visited[j]==false)
				{
					q.push(j);
					distance_from_s[j]=distance_from_s[x]+1;
				}
			}
		}
	for(int i=0;i<10;i++)
	{
		cout<<distance_from_s[i]<<" ";
	}cout<<endl;
	
	for(int i=0;i<10;i++)
	{
		cout<<bfsOrder[i]<<" ";
	}
	cout<<endl;
	
}
	











