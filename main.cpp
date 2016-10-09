#include "Sort.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


int main() {
    Sort sorter;
    srand(time(NULL));
    vector<int> nums;
    for(int i = 0; i < 10; i++) {
        nums.push_back(rand() % 300 + 200);
        cout << nums[i] << " ";
    }
    cout << endl;
    sorter.radix_sort(nums);
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";


    return 0;
}