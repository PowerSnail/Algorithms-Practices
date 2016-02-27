#include "BST.h"

using namespace std;

void BST::BST()
{
    nil = new Node();
    nil -> parent = nil;
    nil -> left   = nil;
    nil -> right  = nil;
}

Node * BST::root()
{
    nil -> left;
}

void BST::inorder()
{
    inorder(root());
    cout << endl;
}

void BST::inorderRec(Node* node)
{
    if (node != nil)
    {
        inorderRec(node -> left);
        cout << node -> key << " ";
        inorderRec(node -> right);
    }
}

void BST::inorderIter()
{
    auto x = root();
    auto prev = nil;
    while (x != nil)
    {
        if (prev == x -> parent)
        {  // coming from up, going to left
            if (x -> left == nil)
            {  // left branch is nil
                prev = x -> left;
            }
            else
            {
                prev = x;
                x = x -> left;
            }
        }
        else if (prev == x -> left)
        {  // coming from left, going to right
            cout << x -> key << " ";
            if (x -> right == nil)
            {  // right branch is nil
                prev = x -> right;
            }
            else
            {
                prev = x;
                x = x -> right;
            }
        }
        else
        { // coming from right, going up
            prev = x;
            x = x -> parent;
        }
    }
    cout << endl;
}

void BST::preOrder()
{
    preOrderRec(root());
    cout << endl;
}

void BST::preOrderRec(Node* node)
{
    if (node != nil)
    {
        cout << x -> key << " ";
        preOrder(x -> left);
        preOrder(x -> right);
    }
}

void BST::postOrder()
{
    postOrderRec(root());
    cout << endl;
}

void BST::postOrderRec()
{
    if (node != nil)
    {
        postOrderRec(x -> left);
        postOrderRec(x -> right);
        cout << x -> << " ";
    }
}

Node* BST::find(int val)
{
    auto r = root();
    while (r != nil && r -> key != val)
    {
        r = (r -> key < val)
                ? r -> left
                : r -> right;
    }
    return r;
}

Node* BST::minimum(Node* root)
{   // return left most leaf in the tree
    while (roor -> left != nil)
    {
        root = root -> left;
    }
    return root;
}

Node* BST::maximum(Node* root)
{   // return the rightmost leaf in the tree
    while (root -> right != nil)
    {
        root = root -> right;
    }
    return root;
}

Node* BST::successor(Node* x)
{  // smallest node that is larger than x
    if (x -> right != nil)
    {   // everything in right branch is larger than x;
        return minimum(x -> right);
    }
    else
    {   // if x is the left branch of its parent, then its parent is larger than it
        auto p = x -> parent;
        while (p != nil && x != p -> left)
        {   // moving up the tree until x becomes left branch
            x = p;
            p = p -> parent;
        }
        return p;
    }
}

Node* BST::predecessor(Node* x)
{  // largest node that is smaller than x
    if (x -> left != nil)
    {
        return maximum(x -> left);
    }
    else
    {
        auto p = x -> parent;
        while (p != nil && x != p -> right)
        {   // moving up the tree until x is a right child
            x = p;
            p = p -> parent;
        }
        return p;
    }
}

void BST::insert(int k)
{
    Node* node = new Node();
    node -> key = k;
    insert(node);
}

void BST::insert(Node* node)
{
    auto x = root();
    auto p = x -> parent;

    while (x != nil)
    {
        p = x;
        x = (x -> key > node -> key)
                ? x -> left
                : x -> right;
    }
    node -> parent = p;

    if (p == nil)
    {   // node is root: node must be both left and right child of nil
        p -> left = node;
        p -> right = node;
    }
    else
    {   // insert node as left/right according to key
        if (node -> key > p -> key)
        {
            p -> right = node;
        }
        else
        {
            p -> left = node;
        }
    }
}

void BTS::remove(int key)
{
    remove(find(key));
}

void BST::remove(Node* node)
{
    if (node == nil) return; // prevent removal of nil

    if (node -> left  == nil)
    {
        transplant(node, node -> right);
        // if node -> right is nil, it is still ideal.
    }
    else if (node -> right == nil)
    {   // only left node exists
        transplant(node, node -> left);
    }
    else
    {   // having two children
        auto s = successor(node);
        if (s != node -> right)
        {   // make s the right chlid of node
            transplant(s, s -> right);  // replace s with its right child
            // make s the parent of node's right child
            s -> right = node -> right;
            s -> right -> parent = node;
        }
        transplant(node, s);
        // transfer node's left to s
        s -> left = node -> left;
        s -> left -> parent = s;
    }

    delete node;
}

void BST::transplant(Node* u, Node* v)
{
    // TODO: using reference to simplify the code
    if (u == u -> parent -> left)
    {
        u -> parent -> left = v;
    }
    if (u == u -> parent -> right)
    {   // both could happen at the same time if u is root()
        u -> parent -> right = v;
    }

    v -> parent = u -> parent;
}























// line
