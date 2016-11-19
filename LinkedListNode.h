//
// Created by danza on 2.10.2016.
//

#ifndef COMPLOOK_LINKEDLISTNODE_H
#define COMPLOOK_LINKEDLISTNODE_H


class LinkedListNode {
private:
    int data;
    LinkedListNode* next;
public:
    LinkedListNode* get_new_node(int data);
    void insert(LinkedListNode* &root, int data);
    void remove(LinkedListNode* &root, int index);
    void print(LinkedListNode* root);
};


#endif //COMPLOOK_LINKEDLISTNODE_H
