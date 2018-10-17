#include<bits/stdc++.h>
using namespace std;

typedef struct _stack
{
	char data;
	struct _stack* next;
}node;


void push(node** headref,char x)
{
	node* q=(node*)malloc(sizeof(node));
	q->data=x;
	q->next=(*headref)->next;
	*headref=q;
}


bool isEmpty(node** headref)
{
	if(*headref==NULL)
	{
		return true;
	}
	else return false;
}

char pop(node** headref)
{
	if(isEmpty(headref))
	{
		cout<<"trying to remove from empty stack"<<endl;
	}
	char z=(*headref)->data;
	node* temp=*headref;
	*headref=(*headref)->next;
	free(temp);
	return z;
}

string prefix_to_infix()
{
	
}

int main()
{

}