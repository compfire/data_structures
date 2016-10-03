//
// Created by danza on 2.10.2016.
//

#include<iostream>
#include "LinkedListNode.h"

using namespace std;


LinkedListNode* LinkedListNode::get_new_node(int data) {
    LinkedListNode* new_node = new LinkedListNode();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void LinkedListNode::add(LinkedListNode* &root, int data) {
    if(root == NULL) {
        root = get_new_node(data);
    }
    add(root->next, data);
}

void LinkedListNode::print(LinkedListNode *root) {
    if(root == NULL)
        return;
    cout << root->data << ", ";
    print(root->next);
}























