#include <iostream>
#include <vector>
#include <ctime>
#include "IntervalTree.h"

using namespace std;


int main() {
    vector<int> in = {1, 2, 3, 4, 5};
    IntervalTree intertree(in);
    intertree.update(1, 100);
    cout << intertree.sum(1, 5) << endl;


    return 0;
}