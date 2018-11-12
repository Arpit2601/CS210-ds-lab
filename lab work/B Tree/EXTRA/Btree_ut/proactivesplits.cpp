# include <iostream>

using namespace std;

# define t 2
class node{
	public:
		int nkeys;
		int key[2*t-1];
		node * C[2*t];
		bool isleaf;
		node(){
			this->nkeys=0;
			this->isleaf=true;
		}
};

class Btree{
	public:
		node * root;
		Btree(){
			root= new node;
		}
		void split_child(node * x,int i);
		void insert(Btree * T,int data);
		void insert_nonfull(node * x,int data);

};

void Btree::split_child(node * x,int index){
	node * y=x->C[index];
	node * z=new node;
	z->nkeys=t-1;
	z->isleaf=y->isleaf;
	int i;
	for(i=0;i<t-1;i++){
		z->key[i]=y->key[i+t];
	}
	for(i=0;i<=t-1;i++){
		z->C[i]=y->C[i+t];
	}
	y->nkeys=t-1;
	for(i=x->nkeys;i>index+1;i--){
		x->key[i]=x->key[i-1];
	}
	for(i=x->nkeys+1;i>index;i--){
		x->C[i]=x->C[i-1];
	}
	x->nkeys=x->nkeys+1;
	x->key[index]=y->key[t-1];
	x->C[index+1]=z;
}

void Btree::insert_nonfull(node * x,int data){
	int i;
	if(x->isleaf){
		i=x->nkeys-1;
		while(i>=0 && data <x->key[i]){
			x->key[i+1]=x->key[i];
			i--;
		}
		x->key[i+1]=data;
		x->nkeys++;
	}
	else{
		i=0;
		while(i<x->nkeys && data>x->key[i]){
			i++;
		}
		if(x->C[i]->nkeys==(2*t-1)){
			split_child(x,i);
			if(data>x->key[i]){
				i++;
			}
		}

		
		insert_nonfull(x->C[i],data);
	}
}


void Btree::insert(Btree * T,int data){
	node * r=T->root;
	if(T->root->nkeys==(2*t-1)){
		node * p=new node;
		T->root=p;
		p->isleaf=false;
		p->C[0]=r;
		split_child(p,0);
		insert_nonfull(p,data);
	}
	else{
		insert_nonfull(r,data);
	}	
}





int main(){
	Btree * T;
	int c,x;
	
	
	while(1){
		cout<<"ENTER YOUR CHOICE\n";
		cin>>c;
		switch (c){
			case 1:
				T=new Btree;
				break;
			case 2:
				cout<<"enter a key value\n";
				cin>>x;
				T->insert(T,x);
				break;
			default:
				return 0;		
		}
	}	
	cout<<"value is "<<T->root->nkeys;

	return 0;
}