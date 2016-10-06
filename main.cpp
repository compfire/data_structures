#include "Sort.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


int main() {
    srand(time(NULL));
    Sort sorter;
    vector<int> nums;
    for(int i = 0; i < 5; i++) {
        nums.push_back(rand() % 10);
        cout << nums[i] << " ";
    }
    sorter.counting_sort(nums);
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";


    return 0;
}