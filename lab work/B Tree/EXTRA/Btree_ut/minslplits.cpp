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

struct ret{
	int median;
	node * c;
};

class Btree{
	public:
		node * root;
		Btree(){
			root= new node;
		}
		void postOrderTraversal(node *,int);
		ret MERGE(node * x, int data, bool lmerge,bool rmerge);
		ret split_child(node * x,int data); // splits x and adds data, return new node and median value
		ret insert(node * x,int data,bool lmerge,bool rmerge); // returns new node and median value
		//void insert_nonfull(node * x,int data);
};

void Btree::postOrderTraversal(node* subtree, int depth){
  // Print the vertical tree for debugging.
  // The number of times '-' illustrate the depth of the node within the tree.
  // Please check the provided test case.
  int nodesPresent = subtree->nkeys;
  if (subtree->isleaf){
    for (int j = nodesPresent - 1; j >= 0; j--){
      cout <<  std::string(depth + 1, '-') << subtree->key[j] << endl;
    }
  }
  else{
    for (int j = nodesPresent; j > 0; j--){
      Btree::postOrderTraversal(subtree->C[j], depth + 1);
      cout <<  std::string(depth + 1, '-') << subtree->key[j-1] << endl;
    }
    Btree::postOrderTraversal(subtree->C[0], depth + 1);
  }
}


ret Btree::MERGE(node * x, int data, bool lmerge,bool rmerge){
			ret reto;
			reto.c=x;
			int buffern[2*t];
			int buffn,in;
			in=buffn=0;
			bool isdatan=false;
			while(buffn<2*t){

				if(isdatan || (in<x->nkeys && x->key[in]<data )){
					buffern[buffn++]=x->key[in++];
				}
				else{
					buffern[buffn++]=data;
					isdatan=true;
				}
			}
			if(lmerge){
				for(in=1;in<2*t;in++){
					x->key[in-1]=buffern[in];
				}
				reto.median=buffern[0];
			}
			else{
				for(in=0;in<2*t-1;in++){
					x->key[in]=buffern[in];
				}
				reto.median=buffern[2*t-1];
			}
			return reto;
}

ret Btree::split_child(node * x,int data){
	ret  reto;
	bool isdata;
	int buffer[2*t];
	int buff,i;
	i=buff=0;
	isdata=false;
	while(buff<2*t){

		if(isdata || (i<x->nkeys && x->key[i]<data )){
			buffer[buff++]=x->key[i++];
		}
		else{
			buffer[buff++]=data;
			isdata=true;
		}
	}
	node * z=new node;
	for(i=0;i<t;i++){
		x->key[i]=buffer[i];
	}

	for(i=0;i<t-1;i++){
		z->key[i]=buffer[t+1+i];
	}
	z->nkeys=t-1;
	z->isleaf=x->isleaf;
	x->nkeys=t;
	reto.c=z;
	reto.median=buffer[t];
	return reto;
}

ret Btree::insert(node * x,int data,bool lmerge,bool rmerge){
	ret reto,reti;
	int i;
	bool oplmerge=false;
	bool oprmerge=false;
	if(x->isleaf){
		if(x->nkeys==(2*t-1) && !(lmerge || rmerge)){
			reto=split_child(x,data);
			if(this->root==x){
				node * z=new node;
				z->key[0]=reto.median;
				z->C[0]=x;
				z->C[1]=reto.c;
				z->nkeys=1;
				z->isleaf=false;
				this->root=z;
			}
			return reto; // in this case reti=reto
		}
		else if(x->nkeys!=(2*t-1)){
			// --- find rp and insert ---
			i=x->nkeys-1;
			while(i>=0 && data <x->key[i]){
				x->key[i+1]=x->key[i];
				i--;
			}
			x->key[i+1]=data;
			x->nkeys++;
			reto.c=NULL; // indicates no action on its parent
			return reto;
		}
		else{
			//--- merge----
			reto=MERGE(x,data,lmerge,rmerge);
			return reto;
		}
	}
	else{
		for(i=0;i<x->nkeys && data > x->key[i];i++);
		if(i>0 && x->C[i-1]->nkeys<(2*t-1)){
			oplmerge=true;
		}
		if(i<x->nkeys && x->C[i+1]->nkeys<(2*t-1)){
			oprmerge=true;
		}
		reti=insert(x->C[i],data,oplmerge,oprmerge);
		if(reti.c!=NULL && !(oplmerge || oprmerge)){
			if(x->nkeys==(2*t-1) && !(lmerge || rmerge)){
				reto=split_child(x,reti.median);
				//----redistribute children keys----
				node * buffer[2*t+1];
				bool isdata;
				int buff;
				i=buff=0;
				node * y= reto.c;
				isdata=false;
				while(buff<=2*t){

					if(isdata || (i<2*t && x->C[i]->key[0] < reti.c->key[0]) ){
						buffer[buff++]=x->C[i++];
					}
					else{
						buffer[buff++]=reti.c;
						isdata=true;
					}
				}

				for(i=0;i<t+1;i++){
					x->C[i]=buffer[i];
				}
				for(i=0;i<t;i++){
					y->C[i]=buffer[i+t+1];
				}
				if(this->root==x){
					node * z=new node;
					z->key[0]=reto.median;
					z->C[0]=x;
					z->C[1]=reto.c;
					z->isleaf=false;
					z->nkeys=1;
					this->root=z;
				}
				return reto;
			}
			else if(x->nkeys<(2*t-1)){
				//---find rp and insert---
				i=x->nkeys-1;
				while(i>=0 && reti.median <x->key[i]){
					x->key[i+1]=x->key[i];
					i--;
				}
				x->key[i+1]=reti.median;

				// change children keys
				i=x->nkeys;
				while(i>=0 && reti.c->key[0]<x->C[i]->key[0]){
					x->C[i+1]=x->C[i];
					i--;
				}
				x->C[i+1]=reti.c;
				x->nkeys++;
				reto.c=NULL;
				return reto;
			}
			else{
				// -- merge to accomodate reti.median
				reto=MERGE(x,reti.median,lmerge,rmerge);
				// --- change children keys
				bool isdata;
				int buff;
				i=buff=0;
				node * buffer[2*t+1];
				isdata=false;
				while(buff<=2*t){

					if(isdata || (i<2*t && x->C[i]->key[0] < reti.c->key[0]) ){
						buffer[buff++]=x->C[i++];
					}
					else{
						buffer[buff++]=reti.c;
						isdata=true;
					}
				}

				if(lmerge){
					reto.c=buffer[0];
					for(i=1;i<=2*t;i++){
						x->C[i-1]=buffer[i];
					}

				}
				else{ // rmerge
					reto.c=buffer[2*t];
					for(i=0;i<2*t;i++){
						x->C[i]=buffer[i];
					}
				}
				//------------------------
				return reto;//returns the dangling pointer
			}

		}
		else if(reti.c==NULL){
			reto.c=NULL;
			return reto;
		}
		else{
			// swap with left or right

			if(oplmerge){
						for(i=0;i<x->nkeys && reti.median>x->key[i];i++);
						i--;
						x->C[i]->key[x->C[i]->nkeys++]=x->key[i];
						x->C[i]->C[x->C[i]->nkeys]=reti.c;
						x->key[i]=reti.median;
			}
			else{ //swap with right
				int j;
				for(i=0;i<x->nkeys && reti.median>x->key[i];i++);
				node * rchild=x->C[i+1];
				for(j=rchild->nkeys-1;j>=0;j--){
					rchild->key[j+1]=rchild->key[j];
				}
				for(j=rchild->nkeys;j>=0;j--){
					rchild->C[j+1]=rchild->C[j];
				}
				rchild->C[0]=reti.c;
				rchild->key[0]=x->key[i];
				x->key[i]=reti.median;
				rchild->nkeys++;

			}
			reto.c=NULL;
			return reto;

		}


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
				T->insert(T->root,x,false,false);
				T->postOrderTraversal(T->root,0);
				break;

			case 3:
					T->postOrderTraversal(T->root,0);
					break;
			default:
				//cout<<"value is "<<T->root->nkeys;
				return 0;
		}
	}
}
