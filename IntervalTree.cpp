//
// Created by danza on 19.11.2016.
//

#include <bits/stdc++.h>
#include "IntervalTree.h"

using namespace std;

IntervalTree::IntervalTree(vector<int> &invec) {
    n = invec.size();
    unsigned int msb = invec.size();
    while(msb - (msb & -msb))
        msb -= (msb & -msb);
    if(msb != invec.size())
        msb = (msb << 1);
    interval_tree.resize(2 * msb);
    for(int i = 0; i < interval_tree.size(); i++)
        interval_tree[i] = 0;
    for(int i = 0; i < invec.size(); i++)
        interval_tree[interval_tree.size() - invec.size() - 1 + i] = invec[i];
    for(int i = interval_tree.size() - 1; i > 1; i -= 2)
        interval_tree[i / 2] = interval_tree[i] + interval_tree[i - 1];
}


void IntervalTree::update(int index, int value) {
    int act = interval_tree.size() - 1 - n;
    do {
        interval_tree[act] += value;
    } while(act /= 2);
}

int IntervalTree::sum(int from, int to) {
    int a = interval_tree.size() - n + from - 3;
    int b = interval_tree.size() - n + to - 1;
    int result = 0;
    while(a != b) {
        if(a % 2 == 0)
            result += interval_tree[a + 1];
        if(b % 2 == 1)
            result += interval_tree[b - 1];
        a /= 2;
        b /= 2;
    }
    return result -= (interval_tree[a / 2] + interval_tree[a / 2 + 1]);
}