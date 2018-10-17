#include<bits/stdc++.h>
using namespace std;

int a[15];
int heap_size=10;



void Max_Heapify(int i)
{
	int temp,largest;
	int l=2*i;			//remember that left is 2*i+1  and that right is 2*i
	int r=2*i+1;
	//int x=max(i,l,r);
	if(l<=heap_size&&a[l]>a[i])
	{
		largest=l;
	}
	else largest=i;
	if(r<=heap_size&&a[r]>a[largest]) 	//very important
	{
		largest=r;
	}

	if(largest!=i)
	{
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		Max_Heapify(largest);	
	} 
} 

// int max(int i,int l,int r)
// {
// 	int largest=i;
// 	if(l<=heap_size && a[l]>a[i])
// 	{
// 		largest=l;
// 	}
// 	else if(r<=heap_size && a[r]>a[i])
// 	{
// 		largest=r;
// 	}
// 	return largest;
// }


void build_heap_bottom_up()
{
	for(int i=heap_size/2;i>=1;i--)
	{
		Max_Heapify(i);
	}
}

int main()
{
	cout<<"start"<<endl;
	for(int i=1;i<11;i++)
	{
		cin>>a[i];
	}
	build_heap_bottom_up();
	for(int i=1;i<11;i++)
	{
		cout<<a[i]<<" ";
	}
}