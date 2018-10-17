#include<bits/stdc++.h>
using namespace std;

typedef struct _tree
{
	int data;
	struct _tree* left; 
	struct _tree* right;
} node;

node* newnode(int data)
{
	node* x=(node*)malloc(sizeof(node));
	x->data=data;
	x->left=NULL;
	x->right-NULL;
	return x;
}

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
void inorder(node* p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}

void pre_order(node* p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		pre_order(p->left);
		pre_order(p->right);
	}
}

void post_order(node* p)
{
	if(p!=NULL)
	{
		post_order(p->left);
		post_order(p->right);
		cout<<p->data<<" ";
	}
}

int main()
{
	//way to make a binary tree

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
	inorder(root);
	cout<<endl;
	pre_order(root);
	cout<<endl;
	post_order(root);

}
