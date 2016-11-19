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

void LinkedListNode::insert(LinkedListNode* &root, int data) {
    if(root == NULL) {
        root = get_new_node(data);
        return;
    }
    insert(root->next, data);
}

void LinkedListNode::remove(LinkedListNode *&root, int index) {
    LinkedListNode* act_node = root;
    for(int i = 0; i < index - 1; i++) {
        act_node = act_node->next;
        if(act_node == NULL) return;
    }
    LinkedListNode* temp = act_node->next;
    act_node->next = act_node->next->next;
    delete(temp);
}

void LinkedListNode::print(LinkedListNode *root) {
    if(root == NULL)
        return;
    cout << root->data << ", ";
    print(root->next);
}