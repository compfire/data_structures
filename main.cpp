#include <iostream>
#include "BstNode.h"

using namespace std;


int main() {
    BstNode bst;
    BstNode* root = NULL;
    bst.insert(root, 15);
    bst.insert(root, 3);
    bst.insert(root, 25);
    bst.insert(root, 7);
    bst.remove(root, 15);

    if(bst.contains(root, 25))
        cout << "In";
    else
        cout << "Not in";
    cout << endl;
    return 0;
}