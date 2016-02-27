#include <iostream>

using namespace std;

class Node
{
public:
    Node *left, *right, *parent;
    int key;
};

class BST
{
private:
    Node *nil;

public:
    BST();
    Node* root();

    // Traversals
    void inorder();
    void inorderRec(Node*);
    void inorderIter();
    void preOrder();
    void preOrderRec(Node*);
    void postOrder();
    void postOrderRec();

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
    void transplant(Node*, Node*)
    bool empty();
};
