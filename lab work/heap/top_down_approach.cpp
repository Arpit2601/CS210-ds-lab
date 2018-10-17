#include<bits/stdc++.h>
using namespace std;

int heap_size=1;
int a[100];
void insert(int x)
{
	int temp;
	heap_size++;
	a[heap_size]=x;
	int i=heap_size;
	
	while(i>1 && a[i]>a[i/2])
	{
		temp=a[i];
		a[i]=a[i/2];
		a[i/2]=temp;
		i=i/2;
	}
}

void build_max_heap(int array_size)
{
	for(int i=2;i<=array_size;i++)
	{
		
		insert(a[i]);
	}
}


int main()
{
	int array_size,x;
	
	cout<<"enter the initial array_size  of heap of heap"<<endl;
	cin>>array_size;
	cout<<"enter initial elements of heap"<<endl;
	
	cin>>a[1];
	for(int i=2;i<=array_size;i++)
	{
		cin>>a[i];
	}
	build_max_heap(array_size);
	for(int i=1;i<=heap_size;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"enter the element to be inserted"<<endl;
	cin>>x;
	insert(x);
	cout<<endl;
	for(int i=1;i<=heap_size;i++)
	{
		cout<<a[i]<<" ";
	}

}