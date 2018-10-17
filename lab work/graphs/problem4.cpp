#include<bits/stdc++.h>
using namespace std;

//queue start
struct node
{
	int key;
	struct node* next;
};

struct Queue
{
	struct node* front,*rear;
};

struct Queue* create_queue()
{
	struct Queue* temp=(struct Queue*)malloc(sizeof(struct Queue));
	temp->front=temp->rear=NULL;
	return temp;
}

void push(struct Queue* q,int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->key=data;
	if(q->rear==NULL)
	{
		q->rear=q->front=temp;
	}
	q->rear->next=temp;
	q->rear=temp;
}

void pop(struct Queue* q)
{
	struct node* temp=q->front;
	q->front=q->front->next;
	if(q->front==NULL)
	{
		q->rear=NULL;
	}
	free(temp);
}

int top(struct Queue* q)
{
	return q->front->key;
}

bool queue_empty(struct Queue* q)
{
	if(q->front==NULL)
	{
		return true;
	}
	return false;
}

//queue finish

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
	for(int i=0;i<vertices+1;i++)
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
	struct node_of_vertex* temp1=create_node(u);
	if(g->list[v]==NULL)
	{
		g->list[v]=temp1;
	}
	else
	{
		struct node_of_vertex* temp2=g->list[v];
		temp1->next=temp2;
		g->list[v]=temp1;
	}

}

bool BFS(struct graph* g,struct Queue* q,int vertices,int src,int color[])
{
	color[src]=1;
	push(q,src);
	while(!queue_empty(q))
	{
		int x=top(q);
		cout<<x<<endl;
		pop(q);
		struct node_of_vertex* temp=g->list[x];
		while(temp!=NULL)
		{
			if(color[temp->data]==-1)
			{
				push(q,temp->data);
				color[temp->data]=1-color[x];
				temp=temp->next;
			}
			else if(color[temp->data]==1 ||color[temp->data]!=color[x])
			{
				temp=temp->next;
			}
			else if(color[temp->data]==color[x])
			{
				cout<<"not possible"<<endl;
				return false; 
			}
		}
	}
	return true;
}


int main()
{
	struct Queue* q=create_queue();
	
	int vertices,edges;
	cin>>vertices>>edges;
	struct graph* g=create_graph(vertices);
	int src,dest,a;
	cin>>src>>dest;
	add_edge(g,src,dest);
	
	for(int i=0;i<edges-1;i++)
	{
		cin>>a>>dest;
		add_edge(g,a,dest);
	}
	int color[vertices+1];
	for(int i=0;i<=vertices;i++)
	{
		color[i]=-1;
	}
	if(BFS(g,q,vertices,src,color))
	{
		for(int i=1;i<=vertices;i++)
		{
			if(color[i]==1)
			{
				cout<<i<<" is a good guy"<<endl;
			}
			else
				cout<<i<<" is a bad guy"<<endl;
		}
	}

}