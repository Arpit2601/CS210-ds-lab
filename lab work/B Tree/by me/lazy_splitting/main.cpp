#include<bits/stdc++.h>
#include "node.h"
#include "Btree.h"

using namespace std;


int main()
{
    Btree* t = NULL;
    t = new Btree();
    int key;
  int choice;
  node* searchResult,*searchResultParent;
  int searchResultIndex;
  ////////////////////////
  //input given by sir
    // cout<<"insert 10"<<endl;
    //  t->insertLazy(t,1); 
    // // // cout<<"insert 20"<<endl;
    // t->insertLazy(t,3); 
    // // // cout<<"insert 5"<<endl;
    // t->insertLazy(t,7); 
    // // // cout<<"insert 6"<<endl;
    // t->insertLazy(t,10); 
    // // // cout<<"insert 12"<<endl;
    // t->insertLazy(t,11); 
    // // // cout<<"insert 30"<<endl;
    // t->insertLazy(t,13); 
    // // // cout<<"insert 7"<<endl;
    // t->insertLazy(t,16); 
    // // // cout<<"insert 17"<<endl;
    // t->insertLazy(t,24);
    // t->insertLazy(t,14);
    // t->insertLazy(t,25);
    // t->insertLazy(t,26);
    // t->insertLazy(t,22);
    // t->insertLazy(t,15);
    // t->insertLazy(t,21);
    // t->insertLazy(t,20);
    // t->insertLazy(t,4);
    // t->insertLazy(t,5);
    // t->insertLazy(t,18); 
    // t->insertLazy(t,19);
    // t->insertLazy(t,2);
    // t->insertLazy(t,17);
    // t->insertLazy(t,12);
    // t->insertLazy(t,6);
    // t->traverse(t->root);
    // cout<<endl;
    // t->postOrderTraversal(t->root,0);


////////////////////////
//geeks for geeks input
    // t->insert(t,10); 
    // t->insert(t,20); 
    // t->insert(t,5); 
    // t->insert(t,6); 
    // t->insert(t,12); 
    // t->insert(t,30); 
    // t->insert(t,7); 
    // t->insert(t,17); 
    // t->insert(t,40); 
    // t->insert(t,50); 
    // t->insert(t,60); 
    // t->insert(t,8); 
    // t->traverse(t->root);
    // cout<<endl;
    // t->postOrderTraversal(t->root,0);
    // tie(searchResult, searchResultIndex,searchResultParent) = t->search(t->root, 10,NULL);
    // if(searchResult == NULL){
    //     cout << "Key " << searchResultIndex << " not found." << endl;
    // }
    // else{
    //     cout << "Key " << searchResultIndex << " found" << endl;
    //     cout<<"Keys parent has "<<searchResultParent->getNumKeys()<<" number of keys"<<endl;
    // }

//input for lazy insert as given in Drozdek
    t->insertLazy(t,6);
    t->insertLazy(t,12);
    t->insertLazy(t,20);
    t->insertLazy(t,30);
    t->insertLazy(t,2);
    t->insertLazy(t,3);
    t->insertLazy(t,4);
    t->insertLazy(t,5);
    t->insertLazy(t,7);
    t->insertLazy(t,8);
    t->insertLazy(t,10);
    t->insertLazy(t,1);
    t->insertLazy(t,9);
    t->insertLazy(t,11);
    t->insertLazy(t,13);
    t->insertLazy(t,14);
    t->insertLazy(t,15);
    t->insertLazy(t,16);
    t->insertLazy(t,17);
    t->insertLazy(t,18);
    t->insertLazy(t,19);
    t->insertLazy(t,31);
    t->insertLazy(t,32);
    t->insertLazy(t,33);
    t->traverse(t->root);cout<<endl;
    t->postOrderTraversal(t->root,0);

}