#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>

class Node
{
    Node* left, right, parent;
    int   key;
    bool  red;
}

class RedBlackTree
{
private:
    Node *nil;

public:
    RedBlackTree();
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
    void  insert(int);
    void  insert(Node*);
    void  remove(int);
    void  remove(Node*);
    void  transplant(Node*, Node*);
    bool  empty();
    Node* newNode();

    // Red Black Tree specific
}

#endif
