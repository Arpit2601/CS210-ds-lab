#include<bits/stdc++.h>
using namespace std;


 struct _tree
{
	int data;
	struct _tree* right;
	struct _tree* left;
};


 struct _stack
{
	struct _tree* tree_node;;
	struct _stack* next;
};

struct _tree* newnode(int data)
{
	struct _tree* x=(struct _tree*)malloc(sizeof(struct _tree));
	x->data=data;
	x->left=NULL;
	x->right-NULL;
	return x;
}

struct _stack* top=NULL;

struct _tree* search(int a,struct _tree* root)
{
	if(root->data==a)
	{
		return root;
	}
	if(root->left!=NULL)
	{
		if(search(a,root->left)!=NULL)
			{
				return search(a,root->left);
			}
	}
	if(root->right!=NULL)
	{
		if(search(a,root->right)!=NULL){return search(a,root->right);}
	}
	return NULL;
}

void set_right(struct _tree* q,struct _tree* p)
{
	if(q->right==NULL)
	{
		q->right=p;
	}
	else 
	{
		cout<<"element already exists";
		exit(0);
	}
}

void set_left(struct _tree* q,struct _tree* p)
{
	if(q->left==NULL)
	{
		q->left=p;
	}
	else 
	{
		cout<<"element already exists";
		exit(0);
	}
}

void push(struct _tree* p)
{
	struct _stack* q=(struct _stack*)malloc(sizeof(struct _stack));
	q->tree_node=p;
	q->next=NULL;

	if(top==NULL)
	{
		top=q;
	}
	else 
	{
		q->next=top;
		top=q;
	}
}

struct _tree* pop()
{
	if(top==NULL){cout<<"pop from empty stack!"<<endl;}
	struct _stack* temp=top;
	top=top->next;
	struct _tree* x=temp->tree_node;
	free(temp);
	return x;
}

bool stack_empty()
{
	if(top==NULL){return true;}
	else return false;
}

void inorder_using_stack(struct _tree* p)
{
	struct _tree* x;
	do
		{
			while(p!=NULL)
			{
				push(p);p=p->left;
			}
			if(!stack_empty())
			{
				p=pop();cout<<p->data<<" ";p=p->right;
			}
		}
		while(!stack_empty()||p!=NULL);
}

void preorder_using_stack(struct _tree* p)
{
	//if(top==NULL){cout<<"njhj"<<endl;}
	do
	{
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			push(p->right);
			p=p->left;
		}
		if(!stack_empty())
		{
			p=pop();
		}
		
	}while(!stack_empty()||p!=NULL);
}


/*void postorder_using_stack(struct _tree* p)
{
	struct _tree* temp;
	
	do
	{
		while(p!=NULL)
		{
			push(p);	
			p=p->left;
		}
		if(!stack_empty())
		{
			p=pop();
			temp=p;
			p=p->right;
			if(p!=NULL)
			{
				push(temp);
			}
			else if(p==NULL)
			{
				cout<<temp->data<<" ";
				if(!stack_empty()&&top->tree_node->right==temp)
				{
					top->tree_node->right=NULL;
				}
			}
		} 
			
	}while(!stack_empty()||p!=NULL);
}*/
void postorder_using_stack(struct _tree* p)
{
	struct _tree* q=p;
	while(p!=NULL)
	{
		while(p->left!=NULL)
		{
			push(p);
		}
		while(p->right==NULL||p->right==q)
		{
			q=p;
			cout<<q->data<<" ";
			if(!stack_empty()){p=pop();}
		}
		push(p);
		p=p->right;
	}
}
		

int main()
{

	// struct _tree* root=newnode(18);
	// root->left=newnode(2);
	// root->left->left=newnode(8);
	// root->right=newnode(3);
	// root->right->right=newnode(12);
	// struct _tree* q=root->right->left=newnode(10);
	// q->right=newnode(9);
	// q->left=newnode(7);
	// struct _tree* p=q->left->right=newnode(81);
	// p->left=newnode(1);
	// p->left->right=newnode(20);
	
	
	cout<<"enter the number of elements"<<endl;
	int num;
	cin>>num;

	struct _tree* root;
	cout<<"enter the root element"<<endl;
	int r;
	cin>>r;
	root=newnode(r);
	cout<<"enter the elements in parent child l/r format"<<endl;
	for(int i=0;i<num-1;i++)
	{
		int a,b;
		char c;
		cin>>a>>b;
		cin>>c;
		if(c=='R'||c=='r')
		{
			struct _tree* q=search(a,root);
			struct _tree* p=newnode(b);
			set_right(q,p);
		}
		else if(c=='l'||c=='L')
		{
			struct _tree* q=search(a,root);
			struct _tree* p=newnode(b);
			set_left(q,p);
		}
	}
	cout<<"Inorder"<<endl;
	inorder_using_stack(root);cout<<endl;
	cout<<"preorder"<<endl;
	preorder_using_stack(root);cout<<endl;
	cout<<"post_order"<<endl;
	postorder_using_stack(root);cout<<endl;
}
