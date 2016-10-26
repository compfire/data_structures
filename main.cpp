#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cmath>

using namespace std;


int main() {
    stack<char> opers;
    map<char, short> opers_priority;
    opers_priority['('] = 0;
    opers_priority[')'] = 0;
    opers_priority['+'] = 1;
    opers_priority['-'] = 1;
    opers_priority['*'] = 2;
    opers_priority['/'] = 2;
    opers_priority['^'] = 3;
    vector<char> res;
    char c;
    while((c = getchar()) != '\n') {
        if(c - '0' <= 9 && c - '0' >= 0) {
            res.push_back(c);
            continue;
        }
        else if(c == ' ')
            continue;
        else {
            if(c == ')') {
                while(opers.top() != '(') {
                    res.push_back(opers.top());
                    opers.pop();
                }
                opers.pop();
            }
            else if(opers.empty() || opers_priority[opers.top()] < opers_priority[c] || c == '(')
                opers.push(c);
            else {
                while(!opers.empty() && opers_priority[opers.top()] > opers_priority[c]) {
                    res.push_back(opers.top());
                    opers.pop();
                }
                opers.push(c);
            }
        }
    }
    while(!opers.empty()) {
        res.push_back(opers.top());
        opers.pop();
    }

    stack<double> evaluator;
    double num1, num2;
    for(int i = 0; i < res.size(); i++) {
        c = res[i];
        if(c - '0' >= 0 && c - '0' <= 9)
            evaluator.push((double)(c - '0'));
        else {
            num2 = evaluator.top();
            evaluator.pop();
            num1 = evaluator.top();
            evaluator.pop();
            if(c == '+')
                evaluator.push(num1 + num2);
            else if(c == '-')
                evaluator.push(num1 - num2);
            else if(c == '*')
                evaluator.push(num1 * num2);
            else if(c == '/')
                evaluator.push(num1 / num2);
            else
                evaluator.push(pow(num1, num2));
        }
    }

    cout << evaluator.top() << endl;

    return 0;
}