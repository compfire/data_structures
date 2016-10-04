//
// Created by danza on 3.10.2016.
//

#ifndef COMPLOOK_POLISHNOTATION_H
#define COMPLOOK_POLISHNOTATION_H

#include <vector>

using namespace std;


class PolishNotation {
public:
    double rpn_expression_evaluate_from_input();
    vector<char> in2rpn_from_input();
};


#endif //COMPLOOK_POLISHNOTATION_H
