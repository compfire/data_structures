//
// Created by danza on 3.10.2016.
//

#include <iostream>
#include <stack>
#include "PolishNotation.h"

using namespace std;


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
        }
    }

    return opers.top();
}
