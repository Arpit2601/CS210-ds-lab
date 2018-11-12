#include<bits/stdc++.h>
#include "node.h"
#include "Btree.h"
using namespace std;

Btree::Btree()
{
    root = new node();
    root->setLeaf(true);
    root->setNumKeys(0);
}

tuple<node*, int ,node*> Btree::search(node* x, int key,node* parent)
{
    int i=0;//cout<<x->getNumKeys()<<endl;
    while(i<=x->getNumKeys() && key>x->getKeyAtIndex(i)){i++;}//cout<<i<<endl;
    if(i<=x->getNumKeys() && key==x->getKeyAtIndex(i)){cout<<parent->getNumKeys();return make_tuple(x,i,parent);}
    else if(x->getLeaf()){return make_tuple(static_cast<node*>(NULL),0,static_cast<node*>(NULL));}
    else {parent=x;cout<<parent->getNumKeys();return search(x->getChildAtIndex(i), key,parent);}
}

void Btree::splitChild(node* x,int index)
{
    cout<<"Splitting node at index :"<<index<<endl;
    node* z = new node();
    node* y = x->getChildAtIndex(index);
    z->setLeaf(y->getLeaf());
    z->setNumKeys(MIN_DEGREE-1);
    for(int i=0;i<=MIN_DEGREE-2;i++)
    {
        z->setKeyAtIndex(y->getKeyAtIndex(i+MIN_DEGREE),i);
    }
    if(!y->getLeaf())
    {
        for(int j=0;j<=MIN_DEGREE-1;j++)
        {
            z->setChildAtIndex(y->getChildAtIndex(j+MIN_DEGREE),j);
        }
    }
    y->setNumKeys(MIN_DEGREE-1);
    for(int j=x->getNumKeys()+1;j>=index;j--)
    {
        x->setChildAtIndex(x->getChildAtIndex(j),j+1);
    }
    x->setChildAtIndex(z,index+1);
    for(int j=x->getNumKeys();j>index;j--)
    {
        x->setKeyAtIndex(x->getKeyAtIndex(j-1),j);
    }
    x->setKeyAtIndex(y->getKeyAtIndex(MIN_DEGREE-1),index);
    x->setNumKeys(x->getNumKeys()+1);
}

void Btree::insert(Btree* btree,int key)
{
    node* root=btree->root;
    if(root->getNumKeys()==2*MIN_DEGREE-1)
    {
        node* s=new node();
        btree->root=s;
        s->setLeaf(false);
        s->setNumKeys(0);
        s->setChildAtIndex(root,0);
        Btree::splitChild(s,0);
        Btree::insertNonFull(s,key);
    }
    else
    {
        Btree::insertNonFull(root,key);
    }
}

void Btree::insertNonFull(node* x,int key)
{
    cout<<"Insert node nonfull calles on "<<key<<endl;
    int i=x->getNumKeys();
    if(x->getLeaf())
    {
        while(i>0 && key<x->getKeyAtIndex(i-1))
        {
            x->setKeyAtIndex(x->getKeyAtIndex(i-1),i);
            i--;
        }
        x->setKeyAtIndex(key,i);
        x->setNumKeys(x->getNumKeys()+1);
    }
    else
    {
        while(i>0 && key<x->getKeyAtIndex(i-1))
        {
            i--;
        }
        i++;
        if(x->getChildAtIndex(i-1)->getNumKeys()==2*MIN_DEGREE-1)
        {
            Btree::splitChild(x,i-1);
            if(key>x->getKeyAtIndex(i-1)){i++;}
        }
        Btree::insertNonFull(x->getChildAtIndex(i-1),key);
    }
}

void Btree::postOrderTraversal(node* x,int depth)
{
    int nodesPresent = x->getNumKeys();
    if(x->getLeaf())
    {
        for(int j=nodesPresent-1;j>=0;j--)
        {
            cout<<string(depth+1,'-')<<x->getKeyAtIndex(j)<<endl;
        }
    }
    else
    {
        for(int j=nodesPresent;j>0;j--)
        {
            Btree::postOrderTraversal(x->getChildAtIndex(j),depth+1);
            cout<<string(depth+1,'-')<<x->getKeyAtIndex(j-1)<<endl;
        }
        Btree::postOrderTraversal(x->getChildAtIndex(0), depth + 1);
    }
}

// void Btree::inorderTraversal()

void Btree::traverse(node* x) 
{ 
    // There are n keys and n+1 children, travers through n keys 
    // and first n children 
    int i; 
    for (i = 0; i < x->getNumKeys(); i++) 
    { 
        // If this is not leaf, then before printing key[i], 
        // traverse the subtree rooted with child C[i]. 
        if (x->getLeaf() == false) 
            Btree::traverse(x->getChildAtIndex(i)); 
        cout << " " << x->getKeyAtIndex(i); 
    } 
  
    // Print the subtree rooted with last child 
    if (x->getLeaf() == false) 
    {
        Btree::traverse(x->getChildAtIndex(i));
    }
} 

void Btree::insertLazy(Btree* tree,int key)
{
    node* root=tree->root;
    node* x=root;
    node* parent,*temp,*searchResult;//cout<<key<<endl;
    int searchResultIndex,flag;
    // int flag=0;
    while(!x->getLeaf())
    {
        //flag=1;
        cout<<"a"<<key<<endl;
        for(int i=0;i<x->getNumKeys();i++)
        {
            if(x->getKeyAtIndex(i)>key)
            {
                parent=x;
                x=x->getChildAtIndex(i);
                break;
            }
            else if(i==(x->getNumKeys()-1) && key>x->getKeyAtIndex(i)){parent=x;x=x->getChildAtIndex(i+1);break;}
        }
    }
    while(true)
    {
        int index=0;//i is the index you have to add the key
        while(index<x->getNumKeys() && x->getKeyAtIndex(index)<key){index++;}//if full and key is largest then give index 2*MIN_DEGREE-1
        //if node is not full
        if(x->getNumKeys()!=2*MIN_DEGREE-1)
        {
            cout<<"b"<<key<<endl;
            for(int j=x->getNumKeys()-1;j>=index;j--)
            {
                x->setKeyAtIndex(x->getKeyAtIndex(j),j+1);
            }
            x->setKeyAtIndex(key,index);
            // cout<<index<<endl;
            // cout<<x->getNumKeys()<<endl;
            if(!x->getLeaf())
            {
                for(int i=0;i<temp->getNumKeys();i++){cout<<temp->getKeyAtIndex(i)<<" ";}cout<<endl;
                for(int i=x->getNumKeys();i>=index+1;i--){x->setChildAtIndex(x->getChildAtIndex(i),i+1);}
                x->setChildAtIndex(temp,index+1);
                for(int i=0;i<x->getNumKeys()+1;i++){cout<<x->getKeyAtIndex(i)<<" ";}cout<<endl;
                // for(int i=0;i<temp->getNumKeys();i++){cout<<temp->getKeyAtIndex(i)<<" ";}cout<<endl;
            }
            x->setNumKeys(x->getNumKeys()+1);
            return ;
        }
        //if node is full
        //first split
        //then check for root
        else if(x->getNumKeys()==2*MIN_DEGREE-1)
        {
            //finding the parent of node x
            node* temp1=tree->root;
            flag=0;
            while(true)
            {
                for(int i=0;i<temp1->getNumKeys();i++)
                {
                    if(temp1->getKeyAtIndex(i)>x->getKeyAtIndex(0))
                    {
                        parent=temp1;
                        temp1=temp1->getChildAtIndex(i);
                        break;
                    }
                    else if(temp1->getKeyAtIndex(i)==x->getKeyAtIndex(0)){flag=1;break;}
                    else if(i==(temp1->getNumKeys()-1) && x->getKeyAtIndex(0)>temp1->getKeyAtIndex(i)){parent=temp1;temp1=temp1->getChildAtIndex(i+1);break;}
                }
                if(flag==1){break;}
            }   
            cout<<"c"<<key<<endl;
            node* z=new node();
            z->setLeaf(x->getLeaf());
            z->setNumKeys(MIN_DEGREE-1);
            //keys distribution
            for(int i=MIN_DEGREE;i<2*MIN_DEGREE-1;i++)
            {
                z->setKeyAtIndex(x->getKeyAtIndex(i),i-MIN_DEGREE);
            }
            
            // if()tie(searchResult, searchResultIndex,parent) = tree->search(tree->root, x->getKeyAtIndex(0),NULL);
            //children distribution
            if(!x->getLeaf())
            {
                z->setChildAtIndex(temp,0);
                for(int i=1;i<=MIN_DEGREE-1;i++)
                {
                    z->setChildAtIndex(x->getChildAtIndex(i+MIN_DEGREE),i);
                }
                //node* w=z->getChildAtIndex(0);
                
                int i=1;
                while(i<=z->getNumKeys() && z->getChildAtIndex(0)->getKeyAtIndex(0)>z->getChildAtIndex(i)->getKeyAtIndex(0)){i++;}
                cout<<i<<endl;
                if(i>1){for(int j=1;j<i;j++){z->setChildAtIndex(z->getChildAtIndex(j),j-1);}z->setChildAtIndex(temp,i-1);}
                
            }
            x->setNumKeys(MIN_DEGREE);
            //putting key at right position
            if(key<z->getKeyAtIndex(0))
            {
                int k=0;
                while(k<x->getNumKeys() && x->getKeyAtIndex(k)<key){k++;}
                for(int a=x->getNumKeys()-1;a>=k;a--){x->setKeyAtIndex(x->getKeyAtIndex(a),a+1);}
                x->setKeyAtIndex(key,k);x->setNumKeys(x->getNumKeys()+1);
            }
            else if(key>z->getKeyAtIndex(0))
            {
                int k=0;
                while(k<z->getNumKeys() && z->getKeyAtIndex(k)<key){k++;}
                for(int a=z->getNumKeys()-1;a>=k;a--){z->setKeyAtIndex(z->getKeyAtIndex(a),a+1);}
                z->setKeyAtIndex(key,k);z->setNumKeys(MIN_DEGREE);
            }
            //taking out the middle element
            if(x->getNumKeys()==MIN_DEGREE+1){key=x->getKeyAtIndex(MIN_DEGREE);x->setNumKeys(MIN_DEGREE);}
            else if(z->getNumKeys()==MIN_DEGREE)
            {
                key=z->getKeyAtIndex(0);
                for(int i=1;i<z->getNumKeys();i++){z->setKeyAtIndex(z->getKeyAtIndex(i),i-1);}
                z->setNumKeys(z->getNumKeys()-1);
            }
            temp=z;//to be used in next iteration
            //for checking the key distribution
            //if(temp->getKeyAtIndex(0)==32)cout<<temp->getChildAtIndex(0)->getKeyAtIndex(0)<<endl;
            for(int i=0;i<x->getNumKeys();i++){cout<<x->getKeyAtIndex(i)<<" ";}cout<<endl;
            for(int i=0;i<temp->getNumKeys();i++){cout<<temp->getKeyAtIndex(i)<<" ";}cout<<endl<<key<<endl;
            //checking for root
            if(x==tree->root)
            {
                cout<<"d"<<endl;
                node* newroot=new node();
                newroot->setKeyAtIndex(key,0);
                newroot->setChildAtIndex(x,0);newroot->setChildAtIndex(z,1);
                newroot->setNumKeys(1);
                tree->root=newroot;
                return ; 
            }

            else if(x!=tree->root)
            {
                x=parent;//cout<<temp->getKeyAtIndex(0);
            }
           
        }
        
    }
}