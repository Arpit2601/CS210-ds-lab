#include<bits/stdc++.h>
#include<fstream>
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

int minimmum(int A[],int i,int l,int r,int n)
{
	int smallest=i;
	if(l<=n && A[l]<A[smallest])
	{
		smallest=l;
	}
	if(r<=n && A[r]<A[smallest])
	{
		smallest=r;
	}
	return smallest;
}

void min_heapify(int A[],int i,int n)
{
	int l=left(i),r=right(i);
	int x=minimmum(A,i,l,r,n);
	if(x!=i)
	{
		swap(&A[i],&A[x]);
		min_heapify(A,x,n);
	}
}

void build_heap_Floyd(int A[],int n)
{
	for(int i=n/2;i>=1;i--)
	{
		min_heapify(A,i,n);
	}
}


void move_up(int A[],int i)
{
	while(A[i]<A[parent(i)] && i>1)
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

int extract_minimum(int A[],int n)
{
	int x=A[1];
	A[1]=A[n];
	min_heapify(A,1,n-1);
	return x;
}

int main()
{
	ifstream myfile("read.txt");
	//myfile.open();
	//int n=getline(myfile,n);
	int n;
	myfile>>n;
	int A[n+5];
	int i=1;
	int x;
	//cout<<n<<endl;
	while(myfile>>x)
	{
		A[i]=x;
	//	cout<<x<<endl;
		i++;
	}
	build_heap_william(A,n); //replace william by floyd for part 2
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cout<<extract_minimum(A,n)<<" ";
		n--;
	}
}