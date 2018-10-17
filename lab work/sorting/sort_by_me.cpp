#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void print_array(int a[],int n)
{
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
}

void bubble_sort(int a[],int n)
{
    cout<<"By bubble sort:"<<endl;
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[j+1]){swap(&a[j],&a[j+1]);print_array(a,n);cout<<endl;}
            
        }
       
    }
}

void insertion_sort(int a[],int n,int l,int r)
{
    cout<<"By insertion sort:"<<endl;
    int x;
    for(int i=0;i<r-l;i++)
    {
        x=a[i+1];
        while(x<a[i] && i>=0)
        {
            swap(&a[i],&a[i+1]);
            i--;
            print_array(a,n);cout<<endl;
        }
        
    }
}

void selection_sort_unstable(int a[],int n)
{
    cout<<"By selection sort and swapping:"<<endl;
    int min,min_index;
    for(int i=0;i<n;i++)
    {
        min=a[i];
        for(int j=i;j<n;j++)
        {
            if(a[j]<=min){min=a[j];min_index=j;}
        }
        swap(&a[i],&a[min_index]);
        print_array(a,n);cout<<endl;
    }
}

void selection_sort_stable(int a[],int n)
{
    cout<<"By selection sort and shifting:"<<endl;
    int min_index,min;
    for(int i=0;i<n-1;i++)
    {
        min=a[i];min_index=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<min){min=a[j];min_index=j;}
        }
        if(min_index!=i)
        {
            for(int k=min_index;k>i;k--)
            {
                swap(&a[k],&a[k-1]);
            }
        }
        print_array(a,n);cout<<endl;
    }
}

void merge_sort_top_down(int l,int r,int a[],int n)
{
    if((r-l)<1){return ;}
    cout<<"sorting from "<<l<<" to "<<r<<endl;
    int mid=(r+l)/2;
    merge_sort_top_down(l,mid,a,n);
    merge_sort_top_down(mid+1,r,a,n);
    
    int buffer[r-l+1];
    int buffer_index,index1=l,index2=(l+r)/2+1;

    for(buffer_index=0;buffer_index<=r-l;buffer_index++)
    {
        if(index1<=(l+r)/2)
        {
            if(index2<=r)
            {
                if(a[index1]>a[index2])
                {
                    buffer[buffer_index]=a[index2];
                    index2++;
                }
                else
                {
                    buffer[buffer_index]=a[index1];
                    index1++;
                }
            }
            else
            {
                buffer[buffer_index]=a[index1];
                index1++;
            }
        }
        else
        {
            buffer[buffer_index]=a[index2];
            index2++;
        }
    }
    for(int i=0;i<r-l+1;i++)
    {
        a[i+l]=buffer[i];
    }
    print_array(a,n);cout<<endl;
    cout<<"sorting finished from "<<l<<" to "<<r<<endl;
}

void merge(int a[],int l,int r,int mid)
{
    int temp[r-l+1];
    int index1=l,index2=mid+1,i=0;
    while(index1<=mid && index2<=r)
    {
        if(a[index1]<a[index2]){temp[i++]=a[index1++];}
        else temp[i++]=a[index2++];
    }
    while(index1<=mid && i<=(r-l+1)){temp[i++]=a[index1++];}
    while(index2<=r && i<=(r-l+1)){temp[i++]=a[index2++];}

    for(int i=0;i<r-l+1;i++){a[l+i]=temp[i];}
}

void merge_sort_bottom_up(int a[],int l,int r,int n)
{
    int i;
    for(int size=1;size<=n;size*=2)
    {
        for(int i=0;i<n;i+=2*size)
        {
            merge(a,i,min(i+2*size-1,n-1),i+size-1);
            cout<<"merge from "<<i<<" to "<<min(i+2*size-1,n-1)<<endl;
            print_array(a,n);cout<<endl;
        }
        //if(i>=n){merge(a,i-size-1,n-1);print_array(a,n);}
    }
}

int partition(int a[],int l,int r,int n)
{
    int pivot=a[l];
    int j=l+1;
    for(int i=l+1;i<=r;i++)
    {
        if(a[i]<pivot){swap(&a[i],&a[j]);j++;print_array(a,n);cout<<endl;}
    }
    swap(&a[j-1],&a[l]);
    return j-1;
}

void quicksort(int a[],int l,int r,int n)
{
    //if(r-l<5){insertion_sort(a,n,l,r);return ;}
    if(r>l)
    {
        cout<<"Partition from "<<l<<" to "<<r<<endl;
        int p=partition(a,l,r,n);
        print_array(a,n);
        cout<<endl;
        quicksort(a,l,p-1,n);
        quicksort(a,p+1,r,n);
    }
}

int main()
{
    auto start=high_resolution_clock::now();
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    //bubble_sort(a,n);
    //insertion_sort(a,n);
    //selection_sort_unstable(a,n);
    //selection_sort_stable(a,n);
    // merge_sort_top_down(0,n-1,a,n);
    // print_array(a,n);
    // merge_sort_bottom_up(a,0,n-1,n);
    // print_array(a,n);
    quicksort(a,0,n-1,n);
    auto finish=high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(finish - start); 
    cout<<duration.count()<<endl;
}

//for random numbers in a given range= max to min
//use 
// int y=max-min+1
// int x = rand()%y + min