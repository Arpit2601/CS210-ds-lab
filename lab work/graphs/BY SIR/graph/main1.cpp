#include<fstream>
#include <iostream>
#include <vector>
#include "Graph.h"

//How to compile code:  g++ main.cpp
//How to run code: ./a.out < input1

using namespace std;

int main(int argc,char* argv[])
{
    ifstream f;
    f.open(argv[1]);
    int choice;
    Graph* g=NULL;

do{
	cout<<"1. Create new graph"<<endl;
	cout<<"2. Add a new edge to the graph"<<endl;
	cout<<"3. Delete an edge from the graph"<<endl;
	cout<<"4. BFS of graph"<<endl;
	cout<<"5. DFS of graph"<<endl;
	cout<<"Any other choice to exit"<<endl;
	cout<<"Enter your choice:";
	f>>choice;
	cout<<"You entered "<<choice<<endl;
	switch(choice){
		case 1:
			if(g!=NULL){
				delete g;
			}
			int vcount;
			cout<<"How many vertices in your graph? ";
			f>>vcount;
			g = new Graph(vcount);
			//create graph with zero edges
			//vertices are labeled as 0, 1, 2...vcount-1
			//it is a simple undirected unweighted graph
			break;

		case 2:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}

			int v1, v2;
			cout<<"Enter first endpoint of edge";
			f>>v1;
			cout<<"Enter second endpoint of edge";
			f>>v2;
			g->addEdge(v1,v2);
			break;

		case 3:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
			//int v1, v2;
			cout<<"Enter first endpoint of edge";
			f>>v1;
			cout<<"Enter second endpoint of edge";
			f>>v2;
			g->deleteEdge(v1,v2);
			break;

		case 4:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
		    int source;
		    cout<<"Enter source vertex for BFS";
		    f>>source;
		    cout<<"BFS Traversal from "<<source<<" : ";
		    {
		    	vector<int> bfs = g->BFS(source);
			    for(int i=0;i<bfs.size();i++)
			    	cout<<bfs[i]<<" ";
			    cout<<endl;
			}
		    break;

		case 5:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
		    //int source;
		    cout<<"Enter source vertex for DFS";
		    f>>source;
		    cout<<"DFS Traversal from "<<source<<" : ";
		    {
		    	vector<int> dfs = g->DFS(source);
			    for(int i=0;i<dfs.size();i++)
			    	cout<<dfs[i]<<" ";
			    cout<<endl;
			}
		    //DFS can be performed with multiple sources as well. However we will stick to the convention that DFS starts from a source and covers only reachable vertices
			break;



		default:
			return(0);
	}

}while(true);

return 0;
}
