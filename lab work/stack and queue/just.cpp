#include<bits/stdc++.h>
using namespace std;



typedef struct _stack
{
	int data;
	struct _stack*next;
} node;


node* head=NULL;

void push(node** headref,int x)
{
	node* q=(node*)malloc(sizeof(node));
	if(head==NULL){head=q;}
	q->data=x;
	q->next=(*headref)->next;
	*headref=q;
}

// bool isEmpty(node** headref)
// {
// 	if(*headref==NULL){return true;}
// 	else return false;
// }

int pop(node** headref)
{
	//if(isEmpty(headref)){cout<<"a";}
	node*temp=*headref;
	int x=(*headref)->data;
	(*headref)=(*headref)->next;
	free(temp);
	return x;
}


int postfix_answer(string str)
{
	
	for(int i=0;i<str.size();i++)
	{
		if(isdigit(str[i])){push(&head,str[i]-'0');}
		else 
		{
			int x=pop(&head);
			int y=pop(&head);
			if(str[i]=='+'){push(&head,x+y);}
			else if(str[i]=='-'){push(&head,y-x);}
			else if(str[i]=='*'){push(&head,x*y);}
			else if(str[i]=='/'){push(&head,y/x);}

		}
	}
	cout<< pop(&head);
	return pop(&head);

}

int main()
{
	string str="23+";
	cout<<postfix_answer(str);
}