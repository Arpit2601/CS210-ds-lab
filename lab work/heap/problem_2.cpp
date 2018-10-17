#include<bits/stdc++.h>
using namespace std;

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i+1;
}

int parent(int i)
{
	return i/2;
}

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int minimum(int A[],int i,int l,int r,int n)
{
	int smallest=i;
	if(A[smallest]>A[l] && l<=n)
	{
		smallest=l;
	}
	if(A[smallest]>A[r] && r<=n)
	{
		smallest=r;
	}
	return smallest;
}

void min_heapify(int A[],int i,int n)
{
	int l=left(i);int r=right(i);
	int x=minimum(A,i,l,r,n);
	if(x!=i)
	{
		swap(&A[i],&A[x]);
		min_heapify(A,x,n);
	}
}

void build_min_heap(int A[],int n)
{
	for(int i=n/2;i>=1;i--)
	{
		min_heapify(A,i,n);
	}
}

int get_minimum(int A[])
{
	return A[1];
}

void remove_min(int A[],int n)
{
	swap(&A[1],&A[n]);
	min_heapify(A,1,n-1);
	//return A[n];
}

int main()
{
	int lines_in_output=0;
	string ans[100]={""};
	int lines_in_input;
	cin>>lines_in_input;
	string a;	//input string
	int b;	//inout int
	int n=0;	//size of heap
	int A[lines_in_input+5];	//heap array
	while(lines_in_input--)
	{
		cin>>a;
		if(a=="insert")
		{
			cin>>b;
			n++;
			A[n]=b;
			build_min_heap(A,n);
			//lines_in_output++;
			ans[lines_in_output]="insert "+ to_string(b);
			lines_in_output++;
		}
		else if(a=="getMin")
		{
			cin>>b;
			if(b==get_minimum(A))
			{
				ans[lines_in_output]="getMin "+to_string(b);
				lines_in_output++;
				continue;
			}
			//cout<<n<<endl;
			//cout<<get_minimum(A)<<endl;
			while(b!=get_minimum(A)&&n>0)
			{
				remove_min(A,n);
				n--;
				ans[lines_in_output++]="removeMin";
			}
			n++;
			A[n]=b;
			build_min_heap(A,n);
			ans[lines_in_output++]="insert "+to_string(b);
			ans[lines_in_output++]="getMin "+to_string(b);
		}
		else if(a=="removeMin")
		{
			remove_min(A,n);
			n--;
			ans[lines_in_output++]="removeMin";
		}
	}
	cout<<lines_in_output<<endl;
	for(int i=0;i<lines_in_output;i++)
	{
		cout<<ans[i]<<endl;
	}
}