#include<bits/stdc++.h>
using namespace std;

//stack start
typedef struct _stack
{
	int data;
	struct _stack* next;
}node;

node* top=NULL;

int top_value()
{
	node* temp=top;
	int data=temp->data;
	return data;
}

bool stack_empty()
{
	if(top==NULL)
	{
		return true;
	}
	return false;
}
void pop()
{
	if(top==NULL){cout<<"empty stack"<<endl;}
	else 
	{
		node* temp=top;
		//int data=temp->data;
		top=top->next;
		free(temp);
		//return data;
	}
}

void push(int data)
{
	node* q=(node*)malloc(sizeof(node));
	q->data=data;
	q->next=NULL;
	if(top==NULL){top=q;}
	else
	 {
		q->next=top;
		top=q;
	}
}
//stack finish

//graph start

struct node_of_vertex
{
	int data;
	struct node_of_vertex* next;
};

struct graph
{
	int numvertices;
	struct node_of_vertex** list;
};

struct graph* create_graph(int vertices)
{
	struct graph* g=(struct graph*)malloc(sizeof(struct graph));
	g->numvertices=vertices+1;
	g->list=(struct node_of_vertex**)malloc((vertices+1)*sizeof(struct node_of_vertex*));
	for(int i=0;i<vertices;i++)
	{
		g->list[i]=NULL;
	}
	return g;
}

struct node_of_vertex* create_node(int data)
{
	struct node_of_vertex* temp=(struct node_of_vertex*)malloc(sizeof(struct node_of_vertex));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

void add_edge(struct graph* g,int u,int v)
{
	struct node_of_vertex* temp=create_node(v);
	if(g->list[u]==NULL)
	{
		g->list[u]=temp;
	}
	else
	{
		struct node_of_vertex* temp1=g->list[u];
		temp->next=temp1;
		g->list[u]=temp;
	}
	

}

void add_edge_reverse_graph(struct graph* g_reverse,int u,int v)
{
	struct node_of_vertex* temp=create_node(u);
	if(g_reverse->list[v]==NULL)
	{
		g_reverse->list[v]=temp;
	}
	else
	{
		struct node_of_vertex* temp1=g_reverse->list[v];
		temp->next=temp1;
		g_reverse->list[v]=temp;
	}
	

}

void DFS_visit(struct graph* g,int src,int visited[])
{
	visited[src]=1;
	//cout<<src<<endl;
	
	struct node_of_vertex* temp=g->list[src];
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
		{
			DFS_visit(g,temp->data,visited);
		}
		temp=temp->next;
	}
	push(src);
	
}

void DFS_util(struct graph* g_reverse,int src,int visited[])
{
	visited[src]=1;
	cout<<src<<" ";
	struct node_of_vertex* temp=g_reverse->list[src];
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
		{
			DFS_util(g_reverse,temp->data,visited);
		}
		temp=temp->next;
	}
	//cout<<endl;
}

void SCC(struct graph* g_reverse,int visited[],int vertices)
{

	for(int i=0;i<vertices;i++)
	{
		visited[i]=0;
	}
	while(!stack_empty())
	{
		//cout<<"sd"<<endl;
		int x=top_value();
		pop();
		if(visited[x]==0)
		{
			//cout<<"df"<<endl;
			DFS_util(g_reverse,x,visited);
			cout<<endl;
		}
		//cout<<endl;
	}
}


void DFS(struct graph* g,int vertices,int visited[])
{
	for(int i=0;i<vertices;i++)
	{
		if(visited[i]==0)
		{
			DFS_visit(g,i,visited);
		}
	}
}


int main()
{
	//struct Queue* q=create_queue();
	
	int vertices,edges;
	cin>>vertices>>edges;
	struct graph* g=create_graph(vertices);
	struct graph* g_reverse=create_graph(vertices);
	int src,dest,a;
	cin>>src>>dest;
	add_edge(g,src,dest);
	add_edge_reverse_graph(g_reverse,src,dest);
	for(int i=0;i<edges-1;i++)
	{
		cin>>a>>dest;
		add_edge(g,a,dest);
		add_edge_reverse_graph(g_reverse,a,dest);
	}
	//cout<<"a0"<<endl;
	int visited[vertices+1]={0};
	DFS(g,vertices,visited);
	SCC(g_reverse,visited,vertices);
}