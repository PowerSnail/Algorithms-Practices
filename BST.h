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
    Node *senti;

public:
    BST();
    void  insert(int);
    void  remove(int);
    Node* find(int);
    Node* minimum();
    Node* maximum();
    bool  empty();
    Node* root();

};
