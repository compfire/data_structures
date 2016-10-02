//
// Created by danza on 23.9.2016.
//

#include <iostream>
#include "BstNode.h"
#include <queue>
#include <stack>

using namespace std;


BstNode* BstNode::get_new_node(int data) {
    BstNode* new_node = new BstNode();
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

void BstNode::insert(BstNode* &root, int data) {
    if(root == NULL)
        root = get_new_node(data);
    else if(data <= root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

void BstNode::print(BstNode* root) {
    if(root == NULL)
        return;
    else {
        cout << root->data << endl;
        print(root->left);
        print(root->right);
    }
}

BstNode* BstNode::find_min(BstNode *root) {
    if(root->left == NULL)
        return root;
    else
        find_min(root->left);
}

void BstNode::remove(BstNode *root, int data) {
    if(root == NULL)
        return;
    if(data < root->data)
        remove(root->left, data);
    else if(data > root->data)
        remove(root->right, data);
    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL) {
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL) {
            BstNode *temp = root;
            root = root->left;
            delete temp;
        }
        else {
            BstNode* min_node = find_min(root->right);
            root->data = min_node->data;
            remove(root->right, min_node->data);
        }
    }
}

bool BstNode::contains(BstNode *root, int data) {
    if(root == NULL)
        return false;
    else if(data < root->data)
        contains(root->left, data);
    else if(data > root->data)
        contains(root->right, data);
    else
        return true;
}


int BstNode::find_max(BstNode *root) {
    if(root->right == NULL) {
        cout << "Tree is empty" << endl;
        return -1;
    }
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int BstNode::get_data(BstNode *get_from) {
    return get_from->data;
}

BstNode* BstNode::get_node(BstNode *root, int direction) {
    if(direction)
        return root->right;
    return root->left;
}

int BstNode::find_height(BstNode *root) {
    if(root == NULL)
        return -1;
    return(max(find_height(root->left), find_height(root->right)) + 1);
}

void BstNode::bfs_print_all(BstNode *root, int order) {
    if(root == NULL)
        return;
    switch(order) {
        case 0:
            cout << root->data << ", ";
            bfs_print_all(root->left, 0);
            bfs_print_all(root->right, 0);
            break;
        case 1 :
            bfs_print_all(root->left, 1);
            cout << root->data << " ,";
            bfs_print_all(root->right, 1);
            break;
        case 2:
            bfs_print_all(root->left, 2);
            bfs_print_all(root->right, 2);
            cout << root->data << ", ";
    }
}

void BstNode::dfs_print_all(BstNode *root) {
    if(root == NULL)
        return;
    queue<BstNode*> nodes_to_process;
    nodes_to_process.push(root);
    while(!nodes_to_process.empty()) {
        cout << nodes_to_process.front()->data << ", ";
        if (nodes_to_process.front()->left != NULL)
            nodes_to_process.push(nodes_to_process.front()->left);
        if (nodes_to_process.front()->right != NULL)
            nodes_to_process.push(nodes_to_process.front()->right);
        nodes_to_process.pop();
    }
}











