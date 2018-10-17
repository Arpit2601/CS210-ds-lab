#include<bits/stdc++.h>

using namespace std;

typedef struct _stack 
{
	char data;
	struct _stack* next;
}node;

node *head=NULL;

void push(node** headref,char x)
{
	node* q=(node*)malloc(sizeof(node));
	if(head==NULL){*headref=q;}
	q->data=x;
	q->next=*headref;
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

bool is_operand(char x)
{
	return (x>='a' && x<='z')||(x>='A' && x<='Z');
}

bool isgreater(node** headref,char x)
{
	char z=(*headref)->data;
	if(x=='^'){return true;}
	else if(x=='*' || x=='/')
	{
		if(z=='+'||z=='-'){return true;}
	}
	else if(x=='+'||x=='-')
	{
		if(z=='*'||z=='/'){return false;}
		else if(z=='+'||z=='-'){return true;}
	}
	return false;
}

void infix_to_postfix(string infix)
{
	for(int i=0;i<infix.length();i++)
	{
		if(is_operand(infix[i]))
		{
			cout<<infix[i];
		}

		else if(infix[i]=='(')
		{
			push(&head,infix[i]);
		}
		else if(infix[i]==')')
		{
			while(!isEmpty(&head)&&(head)->data!='(')
			{
				cout<<pop(&head);
			}
		}
		else
		{
			if(isEmpty(&head)){push(&head,infix[i]);}
			else if(isgreater(&head,infix[i]))
			{
				push(&head,infix[i]);
			}
			else if(!isgreater(&head,infix[i]))
			{
				while(!isgreater(&head,infix[i]))
				{
					cout<<pop(&head);
				}
				push(&head,infix[i]);
			}

		}

		
	}

	while(!isEmpty(&head))
	{
		cout<<pop(&head);
	}
}



int main()
{
	string infix="a+b*(c^d-e)^(f+g*h)-i";
	//string infix={'a','+','(','b','*','c',')'};
	infix_to_postfix(infix);
	return 0;
}