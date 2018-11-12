#include<bits/stdc++.h>
#include "node.h"
#include "Btree.h"

using namespace std;


int main()
{
    Btree* t = NULL;
    t = new Btree();
    // cout<<"insert 10"<<endl;
    t->insert(t,1); 
    // cout<<"insert 20"<<endl;
    t->insert(t,3); 
    // cout<<"insert 5"<<endl;
    t->insert(t,7); 
    // cout<<"insert 6"<<endl;
    t->insert(t,10); 
    // cout<<"insert 12"<<endl;
    t->insert(t,11); 
    // cout<<"insert 30"<<endl;
    t->insert(t,13); 
    // cout<<"insert 7"<<endl;
    t->insert(t,16); 
    // cout<<"insert 17"<<endl;
    t->insert(t,24);
    t->insert(t,14);
    t->insert(t,25);
    t->insert(t,26);
    t->insert(t,22);
    t->insert(t,15);
    t->insert(t,21);
    t->insert(t,20);
    t->insert(t,4);
    t->insert(t,5);
    t->insert(t,18); 
    t->insert(t,19);
    t->insert(t,2);
    t->insert(t,17);
    t->insert(t,12);
    t->insert(t,6);
    t->traverse(t->root);
    cout<<endl;
    t->postOrderTraversal(t->root,0);
}