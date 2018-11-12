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

tuple<node*, int> Btree::search(node* x, int key)
{
    int i=1;
    while(i<=x->getNumKeys() && key>x->getKeyAtIndex(i)){i++;}
    if(i<=x->getNumKeys() && key==x->getKeyAtIndex(i)){return make_tuple(x,i);}
    else if(x->getLeaf()){return make_tuple(static_cast<node*>(NULL),0);}
    else return search(x->getChildAtIndex(i), key);
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