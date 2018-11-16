#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    // while(cin>>x)
    // {
    //     int max_keys=x;

    // }

    int max_keys;
    cin>>max_keys;
    int degree=(max_keys+1)/2;
    int number_of_nodes;
    cin>>number_of_nodes;
    int node_id[number_of_nodes],parent_id[number_of_nodes],number_of_keys[number_of_nodes],number_of_children[number_of_nodes];
    for(int i=0;i<number_of_nodes;i++)
    {
        cin>>node_id[i]>>parent_id[i]>>number_of_keys[i]>>number_of_children[i];
    }
    //checking for min occupancy except for root
    for(int i=0;i<number_of_nodes;i++)
    {
        if(number_of_keys[i]<degree-1 && parent_id[i]!=0){cout<<"Not a valid B Tree"<<endl<<"Node id:"<<node_id[i]<<" does not have minimum occupancy"<<endl;return 0;}
    }
    // checking for children cout except for leaves
    for(int i=0;i<number_of_nodes;i++)
    {
        if(number_of_children[i]!=0 &&  number_of_children[i]!=number_of_keys[i]+1 ){cout<<"Not a valid B Tree "<<endl<<"Node id:"<<node_id[i]<<"does not satisfy the requirement that Children count = Key count + 1."<<endl;return 0;}
    }
    // checking for same depth
    int count=0;
    int node;
    int temp[10000],temp_id[10000];
    for(int i=1;i<=number_of_nodes;i++)
    {
        count=0;
        temp[10000]={0};temp_id[10000]={0};
        //temp_id stores the node_ids of the children i is parent of
        //temp stores their corresponding number of children
        for(int j=0;j<number_of_nodes;j++)
        {
            if(parent_id[j]==i){temp[count]=number_of_children[j];temp_id[count]=node_id[j];count++;}
        }
        if(count>1)
        {
            for(int a=0;a<count-1;a++)
            {
                for(int b=a+1;b<count;b++)
                {
                    node=0;
                    if(temp[a]==0 && temp[b]!=0)
                    {
                        for(int d=0;d<number_of_nodes;d++){if(parent_id[d]==temp_id[b]){node=node_id[d];}}
                        cout<<"Not a valid tree"<<endl<<"Node id:"<<temp_id[a]<<" and Node id:"<<node<<" are leaf nodes not at same level"<<endl;return 0;
                    }
                    else if(temp[b]==0 && temp[a]!=0)
                    {
                        for(int d=0;d<number_of_nodes;d++){if(parent_id[d]==temp_id[a]){node=node_id[d];}}
                        cout<<"Not a valid tree"<<endl<<"Node id:"<<temp_id[b]<<" and Node id:"<<node<<" are leaf nodes not at same level"<<endl;return 0;                    
                    }
                }
            }
        }
    }
    cout<<"This can be a Valid B Tree"<<endl;
    //return 0;

    

}