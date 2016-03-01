#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

using namespace std;

class Node
{
public:
    Node *left, *right, *parent;
    int key;
};

class AVLTree
{
private:
    Node *nil;

public:
    AVLTree();
    Node* root();

    // Traversals
    void inorder();
    void inorderRec(Node*);
    void inorderIter();
    void preOrder();
    void preOrderRec(Node*);
    void postOrder();
    void postOrderRec(Node*);

    // Search Operations
    Node* find(int);
    Node* minimum(Node*);
    Node* maximum(Node*);
    Node* successor(Node*);
    Node* predecessor(Node*);

    // Element Operation
    void insert(int);
    void insert(Node*);
    void remove(int);
    void remove(Node*);
    void transplant(Node*, Node*);
    bool empty();

    // AVL Tree specific
};


#endif
