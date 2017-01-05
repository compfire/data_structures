//
// Created by danza on 23.9.2016.
//

#ifndef DATA_STRUCTURES_PLAYGROUND_BSTNODE_H
#define DATA_STRUCTURES_PLAYGROUND_BSTNODE_H

class BstNode {
private:
    BstNode *left;
    BstNode* right;
    int data;
public:
    BstNode* get_new_node(int data);
    void insert(BstNode* &root, int data);
    void print(BstNode* root);
    void remove(BstNode* root, int data);
    BstNode* find_min(BstNode* root);
    bool contains(BstNode* root, int data);
    int find_max(BstNode* root);
    int find_height(BstNode* root);
    int get_data(BstNode* get_from);
    BstNode* get_node(BstNode* root, int direction);
    void dfs_print_all(BstNode* root, int order);
    void bfs_print_all(BstNode* root);
};


#endif //DATA_STRUCTURES_PLAYGROUND_BSTNODE_H
