#include <iostream>
#include "BstNode.h"

using namespace std;


int main() {
    BstNode bst;
    BstNode* root;
    root = NULL;
    bst.insert(root, 8);
    bst.insert(root, 3);
    bst.insert(root, 45);
    bst.insert(root, 27);
    bst.insert(root, 9);
    bst.insert(root, 34);
    bst.insert(root, 23);
    bst.insert(root, 11);
    bst.insert(root, 2);
    bst.insert(root, 6);

    bst.bfs_print_all(root, 0);
    cout << endl;
    bst.bfs_print_all(root, 1);
    cout << endl;
    bst.bfs_print_all(root, 2);
    cout << endl;

    return 0;
}