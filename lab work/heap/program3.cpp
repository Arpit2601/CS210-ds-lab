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
	int n;
	int A[100];
	cin>>n;
	for(int i=1;i<=10;i++)
	{
		cin>>A[i];
	}
	build_heap_Floyd(A,n);
	int k;
	cin>>k;
	int temp[k];
	for(int i=0;i<k;i++)
	{
		temp[i]=extract_maximum(A,n);
		n--;
	}
	cout<<temp[k-1];
	return 0;
}