#include<bits/stdc++.h>
using namespace std;

typedef struct _stack
{
	int data;
	struct _stack* next;
}node;

node* top=NULL;

// returns the top value in the stack
int top_value()
{
	node* temp=top;
	int data=temp->data;
	return data;
}

int pop()
{
	if(top==NULL){cout<<"empty stack"<<endl;}
	else {
		node* temp=top;
		int data=temp->data;
		top=top->next;
		free(temp);
		return data;
	}
}

void push(int data)
{
	node* q=(node*)malloc(sizeof(node));
	q->data=data;
	q->next=NULL;
	if(top==NULL){top=q;}
	else {
		q->next=top;
		top=q;
	}
}

int evaluate(string str)
{
	int data=-1,operand1,operand2;
	for(int i=0;i<str.length();i++)
	{
		if(isdigit(str[i]))
		{
			data=(data==-1)?0:data;
			data=10*data+(str[i]-48);
			continue;
		}
		if(data!=-1){push(data);}
		if(str[i]=='+' || str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			operand1=pop();
			operand2=pop();
			 //if (operand1 == -1 || operand2 == -1)
                 		// break;
			switch(str[i])
			{
				case '+':
						push(operand2+operand1);
						break;
				case '-':
						push(operand2-operand1);
						break;
				case '*':
						push(operand1*operand2);
						break;
				case '/':
						push(operand2/operand1);
						break;				
			}
		}
		data=-1;
	}

	int answer=pop();
	return answer;

}

int main()
{
	char str[100];
	fgets(str, 100,stdin);
	cout<<evaluate(str);
}
