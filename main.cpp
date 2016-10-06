#include "PolishNotation.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


int main() {
    srand(time(NULL));
    PolishNotation pn;
    vector<char> rpn;
    rpn = pn.in2rpn_from_input();
    for(int i = 0; i < rpn.size(); i++)
        cout << rpn[i];

    return 0;
}