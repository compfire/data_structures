//
// Created by danza on 23.9.2016.
//

#ifndef DATA_STRUCTURES_PLAYGROUND_BSTNODE_H
#define DATA_STRUCTURES_PLAYGROUND_BSTNODE_H


class BstNode {
private:
    int data;
    BstNode* left;
    BstNode* right;
public:
    BstNode* get_new_node(int data);
    void insert(BstNode* &root, int data);
    bool contains(BstNode* root, int data);
    BstNode* remove(BstNode* &root, int data);
    BstNode* find_min(BstNode* root);
};


#endif //DATA_STRUCTURES_PLAYGROUND_BSTNODE_H
