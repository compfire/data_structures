#include <iostream>
#include <vector>
#include <ctime>
#include "LinkedListNode.h"

using namespace std;


int main() {
    srand(time(NULL));
    LinkedListNode ll;
    LinkedListNode* root = NULL;
    for(int i = 1 ; i <= 10; i++)
        ll.insert(root, i);
    ll.remove(root, 20);
    ll.print(root);



    return 0;
}