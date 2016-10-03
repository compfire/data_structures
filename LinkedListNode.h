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
    void add(LinkedListNode* &root, int data);
    void print(LinkedListNode* root);
};


#endif //COMPLOOK_LINKEDLISTNODE_H
