#include <iostream>
#include <vector>
#include "Heap.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    Heap my_heap;
    my_heap.add_element(43);
    cout << my_heap.get_max() << endl;

    return 0;
}
