#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);

    int to_search;
    cout << "Num to search: " << endl;
    cin >> to_search;

    vector<int> some_nums;
    for(int i = 1; i < 1000; i++)
        some_nums.push_back(i);

    int start = 0, end = some_nums.size();
    int mid;
    while(end - start > 1) {
        mid = (start + end) / 2;
        if(some_nums[mid] <= to_search)
            start = mid;
        else
            end = mid;
    }

    if(to_search == some_nums[start])
        cout << to_search << " is on index " << start;
    else
        cout << "Not found";
    cout << endl;

    return 0;
}