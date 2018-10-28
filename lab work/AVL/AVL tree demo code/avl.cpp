#include "avl.h"
#include <algorithm>
using namespace std;

avl::avl()
{
    head=NULL;
}

avl::~avl()
{
    //dtor
}

void avl::inorderTraversal(node* tempNode){
  if(tempNode == NULL){
    return;
  }
  else{
    inorderTraversal(tempNode->getLeft());
    cout << tempNode->getKey();
    if (tempNode->getLeft()){
      cout << " (" << tempNode->getLeft()->getKey() << ")";
    }
    else{
      cout << " (-)";
    }
    if (tempNode->getRight()){
      cout << " (" << tempNode->getRight()->getKey() << ")";
    }
    else{
      cout << " (-)";
    }
    cout << endl;
    inorderTraversal(tempNode->getRight());
  return;
  }
}

bool avl::treeInsertNode(node* newNode){
  if(head == NULL){
    head = newNode;
    return true;
  }
  else{
    if(insertNode(newNode, head) >= 0){
      return true;
    }
    else{
      return false;
    }
  }
}

int avl::insertNode(node* newNode, node* headNode){
  node *parent;
  node *temp;
  temp = headNode;
  while(true){
    if(temp->getKey() == newNode->getKey()){
      cout << "Cannot insert duplicates for " << newNode->getKey() << endl;
      return false;
    }
    parent = temp;
    bool goLeft = temp->getKey() > newNode->getKey();
    temp = goLeft ? temp->getLeft() : temp->getRight();
    if (temp == NULL){
      if (goLeft){
        parent->setLeft(newNode);
        newNode->setParent(parent);
      }
      else{
        parent->setRight(newNode);
        newNode->setParent(parent);
      }
      rebalance(parent);
      break;
    }
  }
  return true;
}

void avl::rebalance(node* n){
//  cout << "Rebalance called on " << n->getKey() << endl;
  updateHeights(n);
  int balance_factor = n->getRHeight() - n->getLHeight();
//  cout << "BF " << balance_factor << endl;
  if (balance_factor == -2){
    if (n->getLeft()->getLHeight() >= n->getLeft()->getRHeight()){
      n = rotateRight(n);
    }
    else{
      n = rotateLeftThenRight(n);
    }
  }
  if (balance_factor == 2){
    if (n->getRight()->getRHeight() >= n->getRight()->getLHeight()){
      n = rotateLeft(n);
    }
    else{
      n = rotateRightThenLeft(n);
    }
  }
  if (n->getParent() != NULL){
    rebalance(n->getParent());
  }
  else{
    head = n;
  }
}


int avl::updateHeights(node *n){
  int height = -1;
  if (n != NULL){
    int l_height = updateHeights(n->getLeft());
    int r_height = updateHeights(n->getRight());
    int max_height = max(l_height, r_height);
    height = 1 + max_height;
    n->setLHeight(l_height);
    n->setRHeight(r_height);
//    cout << "Height of " << n->getKey() << " " << height << endl;
//    cout << "Left Height of " << n->getKey() << " " << n->getLHeight() << endl;
//    cout << "Right Height of " << n->getKey() << " " << n->getRHeight() << endl;
  }
  return height;
}

node* avl::deleteNode(node* victimNode){
  node* parent = victimNode->getParent();
  if (parent == NULL){
    parent = head;
  }

  node* child = victimNode->getLeft() != NULL ? victimNode->getLeft() : victimNode->getRight();

  if (head->getKey() == victimNode->getKey()){
    head = child;
  }
  else{
    if (parent->getLeft() == victimNode){
      parent->setLeft(child);
    }
    else{
      parent->setRight(child);
    }
    rebalance(parent);
  }
    return NULL;
}


node* avl::rotateRightThenLeft(node* n){
  n->setRight(rotateRight(n->getRight()));
  return rotateLeft(n);

}

node* avl::rotateLeftThenRight(node* n){
  n->setLeft(rotateLeft(n->getLeft()));
  return rotateRight(n);
}

node* avl::rotateRight(node* n){

}

node* avl::rotateLeft(node* n){

}

node* avl::searchKey(int keyValue, node* headNode){
  if(headNode == NULL){
    return NULL;
  }

  if(headNode->getKey() == keyValue){
    return headNode;
  }

  if(headNode->getKey() < keyValue){
    return searchKey(keyValue, headNode->getRight());
  }
  else{
    return searchKey(keyValue, headNode->getLeft());
  }
}

node* avl::treeSearchKey(int keyValue){
  return(searchKey(keyValue, head));
}

void avl::treeInorderTraversal(){
    inorderTraversal(head);
}
