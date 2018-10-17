#include<bits/stdc++.h>
using namespace std;

int parent(int i)
{
	return i/2;
}
int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return 2*i+1;
}

void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

int maximum(int A[],int i,int l,int r,int n)
{
	int largest=i;
	if(l<=n && A[l]>A[largest])
	{
		largest=l;
	}
	if(r<=n && A[r]>A[largest])
	{
		largest=r;
	}
	return largest;
}

void max_heapify(int A[],int i,int n)
{
	int l=left(i),r=right(i);
	int x=maximum(A,i,l,r,n);
	if(x!=i)
	{
		swap(&A[i],&A[x]);
		max_heapify(A,x,n);
	}
}

void build_heap_Floyd(int A[],int n)
{
	for(int i=n/2;i>=1;i--)
	{
		max_heapify(A,i,n);
	}
}

void heap_sort(int A[],int n)
{
	for(int i=n;i>=1;i--)
	{
		swap(&A[i],&A[1]);
		max_heapify(A,1,i-1);	//take care of the size as it is decreasing by 1 everytime 
	}
}

void move_up(int A[],int i)
{
	while(A[i]>A[parent(i)] && i>1)
	{
		swap(&A[i],&A[parent(i)]);
		i=parent(i);
	}
}

void build_heap_william(int A[],int n)
{
	for(int i=2;i<=n;i++)
	{
		move_up(A,i);
	}
}

int search(int A[],int n,int key)
{
	for(int i=1;i<=n;i++)
	{
		if(A[i]==key){return i;}
	}
	return -1;
}

void insert(int A[],int n,int key)
{
	A[n]=key;
	move_up(A,n);
}

void deletion(int A[],int x,int n)
{
	swap(&A[x],&A[n]);
	if(A[x]>A[parent(x)]){move_up(A,x);}
	else{max_heapify(A,x,n);}
}


int extract_maximum(int A[],int n)
{
	int x=A[1];
	A[1]=A[n];
	max_heapify(A,1,n-1);
	return x;
}


void increase_key(int A[],int index)
{
	A[index]++;
	move_up(A,index);
}

int main()
{
	int A[100];
	cout<<"enter the initial numbers in heap"<<endl;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	

	//floyd
	build_heap_Floyd(A,n);
	cout<<endl<<"using floyd method :";
	for(int i=1;i<n+1;i++)
	{
		cout<<A[i]<<" ";
	}
	

	//william
	build_heap_william(A,n);
	cout<<endl<<"using william method :";
	for(int i=1;i<n+1;i++)
	{
		cout<<A[i]<<" ";
	}


	//insertion
	cout<<endl<<"enter the number to be inserted :";
	int key;
	cin>>key;
	int x=search(A,n,key);
	if(x!=-1){cout<<"key already present in the heap "<<endl;}
	else{n++;insert(A,n,key);}
	

	//deletion
	cout<<endl<<"enter the key to be deleted :";
	cin>>key;
	x=search(A,n,key);
	if(x==-1){cout<<"key not present in heap "<<endl;}
	else{deletion(A,x,n);n--;}


	//extract maximum
	int max=extract_maximum(A,n);
	n--;
	cout<<"the maximum number in heap is :"<<max;

	//increase key
	cout<<endl<<"enter the key to be increased :";
	cin>>key;
	int index=search(A,n,key);
	if(x==-1){cout<<"key not present in heap "<<endl;}
	else{increase_key(A,index);}


	//heap_union
	cout<<endl<<"enter the size of second heap :";
	int m;
	cin>>m;
	for(int i=n+1;i<=n+m;i++)
	{
		cin>>A[i];
	}
	build_heap_Floyd(A,n+m);

	//sorting
	heap_sort(A,n+m);
	cout<<endl<<"sorted heap :";
	for(int i=1;i<=n+m;i++)
	{
		cout<<A[i]<<" ";
	}

	
}