//
// Created by danza on 19.11.2016.
//

#ifndef COMPLOOK_INTERVALTREE_H
#define COMPLOOK_INTERVALTREE_H

using namespace std;


class IntervalTree {
    vector<int> interval_tree;
    int n;
public:
    IntervalTree(vector<int> &invec);
    void update(int index, int value);
    int sum(int from, int to);
};


#endif //COMPLOOK_INTERVALTREE_H
