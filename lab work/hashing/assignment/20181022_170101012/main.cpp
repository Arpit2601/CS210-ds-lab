
#include<bits/stdc++.h>
#include <list> 
using namespace std; 

//int size;
int initial_bucket_size;

list<int> *table; 
  
int hashFunction(int x,int initial_bucket_size) 
{ 
      return (x % initial_bucket_size); 
} 

bool searchHash(int key,int initial_bucket_size)
{
    int hashIndex=hashFunction(key, initial_bucket_size);
    list <int> :: iterator i;
    for(i=table[hashIndex].begin();i!=table[hashIndex].end();i++)
    {
        if(*i==key)
        {
            return true;
        }
    }
    return false;
}

void Hash(int initial_bucket_size) 
{ 
   
    table = new list<int>[initial_bucket_size]; 
} 

void insertItem(int key,int initial_bucket_size) 
{ 
    int index = hashFunction(key, initial_bucket_size); 
    table[index].push_back(key);  
} 
  
void deleteItem(int key,int initial_bucket_size) 
{ 
  int index = hashFunction(key, initial_bucket_size); 
  
  list <int> :: iterator i; 
  for (i = table[index].begin(); i != table[index].end(); i++) 
  { 
   
        if (*i == key) 
            break;
   } 
   
  
  if (i != table[index].end()) 
    table[index].erase(i); 
} 
  
void displayHash(int size,int initial_bucket_size) { 
    cout<<"Number of Keys "<<size<<endl;
    cout<<"Number of Buckets "<<initial_bucket_size<<endl;
    list <int> :: iterator it;
  for (int i = 0; i < initial_bucket_size; i++) 
  { 
    cout << "Bucket "<<i<<":"; 
    for (it= table[i].begin();it!=table[i].end();it++)
    {
        cout <<*it<<" "; 
    }
    cout << endl; 
  } 
} 
  
int main() 
{ 
   
    float load_factor;
    cin>>load_factor;
    int initial_bucket_size,x;
    int size=0;
    cin>>initial_bucket_size;
    Hash( initial_bucket_size);
    vector <int> items;
    float current_load_factor;
    while(cin>>x)
    {
        //cin>>x;
        items.push_back(x);
        size++;
        current_load_factor=(float)size/initial_bucket_size;
        //cout<<size<<endl;
        //cout<<current_load_factor<<endl;
        if(searchHash(x,initial_bucket_size))
        {
            items.pop_back();size--;
            cout<<"Key "<<x<<" already present. Status of hash table"<<endl;
            displayHash(size, initial_bucket_size);
            //cout<<endl;
        }
        else 
        {
            if(current_load_factor>load_factor)
            {
                //cout<<"load factor"<<endl;
                
                //cout<<initial_bucket_size<<endl;
                vector<int> :: iterator i;
                
                for(i=items.begin();i!=items.end();i++)
                {
                    deleteItem(*i, initial_bucket_size);
                }   
                initial_bucket_size=3*initial_bucket_size;
                Hash( initial_bucket_size);
            
                for(i=items.begin();i!=items.end();i++)
                {
                    insertItem(*i, initial_bucket_size);
                }
            }
            else
            {
                insertItem(x, initial_bucket_size);
            }
        }
    }

  return 0; 
} 
