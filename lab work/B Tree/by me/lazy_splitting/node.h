#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MIN_DEGREE 2

class node
{
    public:
        bool getLeaf();
        void setLeaf(bool value);

        int getNumKeys();
        void setNumKeys(int value);

        int getKeyAtIndex(int index);
        void setKeyAtIndex(int key,int index);

        node* getChildAtIndex(int index);
        void setChildAtIndex(node* child,int index);

        // node* getParent(node* child);


    private:
        bool isLeaf;
        int numKeys;
        int keys[2*MIN_DEGREE-1];
        node* children[2*MIN_DEGREE];
        // node* parent[2*MIN_DEGREE];
};

#endif