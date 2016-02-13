#include "BST.h"

using namespace std;

void BST::BST()
{
    senti = new Node();
    senti -> parent = senti;
    senti -> left   = senti;
    senti -> right  = senti;
}

void BST::inorder(Node* node)
{

}

void BST::insert(int x)
{
    auto newNode = new Node;
    newNode -> key = x;
    if (emtpy())
    {
        senti -> left = newNode;
    }
    else
    {

    }
}
