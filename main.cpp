#include "Sort.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


int main() {
    srand(time(NULL));
    Sort sorter;
    vector<int> nums;
    for(int i = 0; i < 10; i++)
        nums.push_back(rand() % 30);

    sorter.quick_sort(nums, 0, nums.size() - 1);
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";


    return 0;
}