#include<stdio.h>
#include<stdlib.h>


typedef struct _node{
	int data;
	struct _node* next;
}node;

node* make_node(int x)
{
	node* p;
	p=(node*)malloc(sizeof(struct _node));
	p->next=NULL;
	p->data=x;
	return p;
}
node* search(node* list,int k)
{
	node* p;
	p=list;
	while(p!=NULL)
	{
		if(p->data==k){return p;}
		p=p->next;
	}
	return NULL;
}
node* insertAtStart(node* list,int x)
{
	node* p;
	p=make_node(x);
	p->next=list;
	list=p;
	return list;
}

void insertAfter(node* p,int x,int k)
{
	node* q;
	q=make_node(x);
	q->next=p->next;
	p->next=q;
}

node* insert(node* list,int x,int k)
{
	node* p;
	p=search(list,k);
	if(p==NULL)
	{
		list=insertAtStart(list,x);
	}
	else
	{
		insertAfter(p,x,k);
	}
	return list;
}


int main()
{
	node* head=make_node(8);
	struct _node* head1=head->next=make_node(7);
	head->next->next=make_node(6);
	 head=insert(head,5,9);

	printf("%d\n",head->data );
	printf("%d\n",head->next->next->data );
	
	return 0;
}