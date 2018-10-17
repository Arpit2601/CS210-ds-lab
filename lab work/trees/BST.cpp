//search ,insertion ,deletion ,sequence validity,inorder,height,successor,predecessor,minimum,maximum,
//formation of tree from preorder and inorder,checking if trees are identical
//all in one
#include<bits/stdc++.h>
using namespace std;

struct _tree
{
	int data;
	struct _tree *left,*right,*parent;
};

struct _tree* newnode(int key)
{
	struct _tree* temp=(struct _tree*)malloc(sizeof(struct _tree));
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	return temp;
}

bool identical_trees(struct _tree* root,struct _tree* root1)
{
	struct _tree *p=root,*q=root1;
	if(p==NULL&&q==NULL){return true;}
	else if((p!=NULL&&q==NULL)||p==NULL&&q!=NULL){return false;}
	else
	{
		return (p->data==q->data&&identical_trees(p->left,q->left)&&identical_trees(p->right,q->right));
	}
}

int search_in_inorder(int in[],int x,int inend,int instrt)
{
	for(int i=instrt;i<=inend;i++)
	{
		if(in[i]==x){return i;}
	}
}
struct _tree* formation_from_inorder_and_preorder(int in[],int pre[],int instrt,int inend)
{
	static int preindex=0;
	if(instrt>inend){return NULL;}
	struct _tree* tnode=newnode(pre[preindex]);
	int inindex=search_in_inorder(in,pre[preindex],inend,instrt);
	preindex++;
	if(instrt==inend){return tnode;}
	tnode->left=formation_from_inorder_and_preorder(in,pre,instrt,inindex-1);
	tnode->right=formation_from_inorder_and_preorder(in,pre,inindex+1,inend);
	return tnode;
}

struct _tree* insert(struct _tree* root,int x)
{
	struct _tree* p=root;
	struct _tree* temp=NULL;
	if(p==NULL)
	{
		p=newnode(x);
		return p;
	}
	else 
	{
		while(p!=NULL)
		{
			temp=p;
			if(x>p->data)
			{
				p=p->right;
			}
			else if(x<p->data)
			{
				p=p->left;
			}
		}

		if(x>temp->data)
		{
			struct _tree* q=newnode(x);
			temp->right=q;
			q->parent=temp;
		}
		else if(x<temp->data)
		{
			struct _tree* q=newnode(x);
			temp->left=q;
			q->parent=temp;
		}
	}
}

void inorder(struct _tree* root)
{
	struct _tree* p=root;
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}

int height_of_tree(struct _tree* p)
{
	if(p==NULL)
	{
		return 0;
	}
	else 
	{
		int lheight=height_of_tree(p->left);
		int rheight=height_of_tree(p->right);

		if(lheight>rheight){return (lheight+1);}
		else return (rheight+1);
	}
}

struct _tree* search(struct _tree* root,int x)
{
	struct _tree* p=root;
	while(p!=NULL&&p->data!=x)
	{
		if(x<p->data){p=p->left;}
		else p=p->right;
	}
	return p;
}

int maximum(struct _tree* root)
{
	struct _tree* x=root;
	while(x->right!=NULL)
	{
		x=x->right;
	}
	return x->data;
}

int  minimum(struct _tree* root)
{
	struct _tree* x=root;
	while(x->left!=NULL)
	{
		x=x->left;
	}
	return x->data;
}

int sucessor(struct _tree* root,int x)
{
	struct _tree* p=search(root,x);
	if(p->right!=NULL)
	{
		return minimum(p->right);
	}
	else 
	{
		struct _tree* temp=p->parent;
		while(temp!=NULL&&p==temp->right)
		{
			p=temp;
			temp=p->parent;
		}
		return temp->data;
	}
}

int predecessor(struct _tree* root,int x)
{
	struct _tree* p=search(root,x);
	if(p->left!=NULL)
	{
		return maximum(p->left);
	}
	else
	{
		struct _tree* temp=p->parent;
		while(temp!=NULL&&p==temp->left)
		{
			p=temp;
			temp=p->parent;
		}
		return temp->data;
	}
}

void delete_node(struct _tree* root,int x)
{
	struct _tree* p=search(root,x);
	if(p==NULL){cout<<"key not found"<<endl;return ;}
	else
	{
		if(p->left==NULL&&p->right==NULL)
		{	
			if(p->parent->left==p){p->parent->left=NULL;}
			else p->parent->right=NULL;
			return ;
		}
		else if(p->left!=NULL&&p->right==NULL)
		{
			p->data=p->left->data;
			p->left=NULL;
			free(p->left);
		}
		else if(p->left==NULL&&p->right!=NULL)
		{
			p->data=p->right->data;
			p->right=NULL;
			free(p->right);
		}
		else
		{
			int s=sucessor(root,x);//data to be copied at the node to be deleted
			struct _tree* temp=search(root,s);//this node has to be deleted
			p->data=s;
			if(temp->left==NULL&&temp->right==NULL)
			{	
				if(temp->parent->left==temp){temp->parent->left=NULL;}
				else temp->parent->right=NULL;
				return ;
			}
			else if(temp->left!=NULL&&temp->right==NULL)
			{
				temp->data=temp->left->data;
				temp->left=NULL;
				free(temp->left);
			}
			else if(temp->left==NULL&&temp->right!=NULL)
			{
				temp->data=temp->right->data;
				temp->right=NULL;
				free(temp->right);
			}
		}
	}
}

bool is_sequence_valid(int a[],int min,int max,int n,int key)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]>max||a[i]<min)
		{
			return false;
		}
		if(a[i]<key)
		{
			min=a[i]+1;
		}
		if(a[i]>key)
		{
			max=a[i]-1;
		}
		
	}
	return true;
}

int main()
{
	struct _tree* root=NULL;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	struct _tree* p=NULL;
	int key;
	cout<<"enter the key to be searched "<<endl;
	cin>>key;
	p=search(root,key);
	if(p!=NULL){cout<<p->data<<" is already present in tree"<<endl;}
	else 
	{
		insert(root,key);
		cout<<"key is not present in the tree hence added "<<endl;
	}
	inorder(root);
	cout<<endl;
	cout<<height_of_tree(root);
	cout<<endl;

	cout<<minimum(root)<<" is the minimum element in the tree"<<endl;
	cout<<maximum(root)<<" is the maximum element in the tree"<<endl;

	cout<<"successor of 50 is "<<sucessor(root,50)<<endl;
	cout<<"successor of 30 is"<<sucessor(root,30)<<endl;
	cout<<"successor of 40 is"<<sucessor(root,40)<<endl;
	cout<<"predecessor of 50 is "<<predecessor(root,50)<<endl;
	cout<<"predecessor of 30 is"<<predecessor(root,30)<<endl;
	cout<<"predecessor of 40 is"<<predecessor(root,40)<<endl;
	cout<<"enter the key to be deleted"<<endl;
	int x;cin>>x;
	delete_node(root,x);
	inorder(root);
	cout<<endl;
	cout<<height_of_tree(root);
	cout<<endl;

	// cout<<"number of terms in the sequence"<<endl;
	// int num;cin>>num;
	// int a[num],b[num];
	// for(int i=0;i<num;i++)
	// {
	// 	cin>>a[i];
	// 	b[i]=a[i];
	// }
	// sort(b,b+num);
	// if(is_sequence_valid(a,b[0],b[num-1],num,a[num-1])){cout<<"the given sequence is valid"<<endl;}
	// else cout<<"sequence is invalid"<<endl;

	struct _tree* root1=NULL;
	root1=insert(root1,50);
	insert(root1,30);
	insert(root1,20);
	insert(root1,40);
	insert(root1,70);
	insert(root1,60);
	insert(root1,80);
	insert(root1,90);
	if(identical_trees(root,root1)){cout<<"yes"<<endl;}

	cout<<"formation of tree"<<endl;
	int in[]={20,30,40,50,60,70,80,90};
	int pre[]={50,30,20,40,70,60,80,90};
	int length=sizeof(in)/sizeof(in[0]);
	struct _tree* root2=formation_from_inorder_and_preorder(in,pre,0,length-1);
	inorder(root2);cout<<endl;
	cout<<height_of_tree(root2);
}