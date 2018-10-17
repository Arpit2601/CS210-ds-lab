#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct _node
{
	int data;
	struct _node* left;
	struct _node* right;
	bool rightThread;
}node;

node* createNode(int x)
{
	node* p=(node*)malloc(sizeof(struct _node));
	p->data=x;
	p->right=NULL;
	p->left=NULL;
	p->rightThread=false;
	return p;
}

node* search(int x,node* p)
{
	if(p->data==x)
		return p;
	if(p->left!=NULL){
		if(search(x,p->left)!=NULL)
			return search(x,p->left);
	}
	if(p->right!=NULL&&p->rightThread==false){
		if(search(x,p->right)!=NULL&&p->rightThread==false)
			return search(x,p->right);
	}
	return NULL;                                                                                                                
}

void setleft(node* p,node* q)
{
	if(p->left==NULL){
		p->left=q;
		q->right=p;
		q->rightThread=true;
	}
	else {
		cout<<"Element already exists"<<endl;
		exit(1);
	}
}

 node* leftmost( node *n)
{
    if (n == NULL)
       return NULL;
 
    while (n->left != NULL)
        n = n->left;
 
    return n;
}

void setRight(node* p,node* q)
{
	if(p->right==NULL||p->rightThread==true){                                        
		
			q->right=p->right;
			p->right=q;
			p->rightThread=false;
			q->rightThread=true;
	}
	else if(p->right!=NULL) {
		cout<<"Element already exists"<<endl;
		exit(2);
	}
}



void inorder( node *root)
{
     node *cur = leftmost(root);
    while (cur != NULL)
    {
        printf("%d ", cur->data);
 
        // If this node is a thread node, then go to
        // inorder successor
        if (cur->rightThread)
            cur = cur->right;
        else // Else go to the leftmost child in right subtree
            cur = leftmost(cur->right);
    }
}

void preorder(struct _node* p)
{
	while()
	{
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->left;
	}
	while(p->rightThread==true)
	{
		p=p->right;
	}
	p=p->right;
	}
}

int main()
{
	cout<<"Number of elements"<<endl;
	int num;
	cin>>num;

	node* root=NULL;
	cout<<"Enter root element"<<endl;
	int r;
	cin>>r;
	root=createNode(r);

	cout<<"Enter the elements in num1,num2,L/R format"<<endl;

	for(int i=0;i<num-1;i++)
	{
		int a,b;
		cin>>a>>b;
		char c;
		cin>>c;

		if(c=='R'||c=='r'){
			node* p=search(a,root);
			node* q=createNode(b);
			setRight(p,q);
		}
		else{
			node* p=search(a,root);
			node* q=createNode(b);
			setleft(p,q);
		}
	}
	
	inorder(root);
}