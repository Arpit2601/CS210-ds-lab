#ifndef BTREE_H
#define BTREE_H
#include<bits/stdc++.h>
using namespace std;

class Btree
{
    public:
        Btree();
        node* root;
        void insert(Btree*, int key);
        void splitChild(node* x, int index);
        void insertNonFull(node* x,int key);
        tuple<node* , int> search(node* x,int key);
        void postOrderTraversal(node* x,int depth);
        void inorderTraversal(node* x);
        void traverse(node* x);
        
};
#endif