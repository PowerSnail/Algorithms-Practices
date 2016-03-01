#include "BST.h"

using namespace std;

int main()
{
    cout << "trying to build a BST Object" << endl;
    BST b;
    int numbers[] = {10, 1, 8, 33, 2, 10, 7, 23};
    cout << "trying to insert some numbers" << endl;
    for (auto c : numbers)
    {
        cout << "insert " << c << endl;
        b.insert(c);
        b.inorder();
    }

    cout << "post order " << endl;
    b.postOrder();
    cout << "pre order " << endl;
    b.preOrder();
    cout << "inorder iter" << endl;
    b.inorderIter();



    return 0;
}
