//
// Created by danza on 23.9.2016.
//

#include <iostream>
#include "BstNode.h"

BstNode* BstNode::get_new_node(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = 0;
    return newNode;
}

void BstNode::insert(BstNode* &root, int data) {
    if(root == NULL)
        root = get_new_node(data);
    else if(data <= root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

bool BstNode::contains(BstNode* root, int data) {
    if(root == NULL)
        return false;
    else if(data == root->data)
        return true;
    else if(data <= root->data)
        contains(root->left, data);
    else
        contains(root->right, data);
}

BstNode* BstNode::find_min(BstNode *root) {
    if(root->left == NULL)
        return root;
    else
        find_min(root->left);
}

BstNode* BstNode::remove(BstNode* &root, int data) {
    if (root == NULL)
        return root;
    else if(data < root->data)
        remove(root->left, data);
    else if(data > root->data)
        remove(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if (root->left == NULL) {
            BstNode *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            BstNode *temp = root;
            root = root->left;
            delete temp;
        } else {
            BstNode *min = find_min(root->right);
            root->data = min->data;
            remove(root->right, min->data);
        }
    }
}












