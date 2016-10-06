//
// Created by danza on 3.10.2016.
//

#include <iostream>
#include <stack>
#include <map>
#include <cmath>
#include "PolishNotation.h"

using namespace std;


PolishNotation::PolishNotation() {
    operators_priority['('] = 0;
    operators_priority[')'] = 0;
    operators_priority['+'] = 1;
    operators_priority['-'] = 1;
    operators_priority['*'] = 2;
    operators_priority['/'] = 2;
    operators_priority['^'] = 3;
}

double PolishNotation::rpn_expression_evaluate_from_input() {
    char c;
    stack<double > opers;
    double num1, num2;
    while((c = getchar()) != '\n') {
        if(c - '0' >= 0 && c - '0' <= 9)
            opers.push((double)(c - '0'));
        else {
            num1 = opers.top();
            opers.pop();
            num2 = opers.top();
            opers.pop();
            if(c == '+')
                opers.push(num2 + num1);
            else if(c == '-')
                opers.push(num2 - num1);
            else if(c == '*')
                opers.push(num2 * num1);
            else if(c == '/')
                opers.push(num2 / num1);
            else if(c == '^')
                opers.push(pow(num2, num1));
        }
    }

    return opers.top();
}

vector<char> PolishNotation::in2rpn_from_input() {
    stack<char> operators;
    vector<char> result;
    char c, out_c;
    while ((c = getchar()) != '\n') {
        if(c == ' ')
            continue;
        if ((c >= 97 && c <= 122) || c - '0' >= 0 && c - '0' <= 9)
            result.push_back(c);
        else {
            if (c == ')') {
                while (operators.top() != '(') {
                    result.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();
            } else if (operators.empty() || operators_priority[operators.top()] < operators_priority[c] || c == '(')
                operators.push(c);
            else {
                while (!operators.empty() && operators_priority[operators.top()] > operators_priority[c]) {
                    out_c = operators.top();
                    operators.pop();
                    result.push_back(out_c);
                }
                operators.push(c);
            }
        }
    }

    int operators_size = operators.size();
    for (int j = 0; j < operators_size; j++) {
        result.push_back(operators.top());
        operators.pop();
    }

    return result;
}

vector<char> PolishNotation::in2rpn(vector<char> in) {
    stack<char> operators;
    vector<char> result;
    for(int i = 0; i < in.size(); i++) {
        if((in[i] - '0' >= 0 && in[i] - '0' <= 9) || in[i] >= 97 && in[i] <= 122)
            result.push_back(in[i]);
        else {
            if(in[i] == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    result.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();
                continue;
            }
            else if(operators.empty() || operators_priority[in[i]] > operators_priority[operators.top()])
                operators.push(in[i]);
            else {
                while(!operators.empty() && operators_priority[operators.top()] >= operators_priority[in[i]]) {
                    result.push_back(operators.top());
                    operators.pop();
                }
            }
        }
    }
    while(!operators.empty()) {
        result.push_back(operators.top());
        operators.pop();
    }
    return result;
}
