#include "node.h"
using namespace std;

bool node::getLeaf()
{
    return isLeaf;
}

void node::setLeaf(bool value)
{   
    isLeaf=value;
}

int node::getNumKeys()
{
    return numKeys;
}

void node::setNumKeys(int value)
{
    numKeys=value;
}

int node::getKeyAtIndex(int index)
{
    return keys[index];
}

void node::setKeyAtIndex(int key,int index)
{
    keys[index]=key;
}

node* node::getChildAtIndex(int index)
{
    return children[index];
}

void node::setChildAtIndex(node* child,int index)
{
    children[index]=child;
}