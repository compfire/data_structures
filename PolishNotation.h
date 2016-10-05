//
// Created by danza on 3.10.2016.
//

#ifndef COMPLOOK_POLISHNOTATION_H
#define COMPLOOK_POLISHNOTATION_H

#include <vector>
#include <map>

using namespace std;


class PolishNotation {
private:
    map<char, int> operators_priority;
public:
    PolishNotation();
    double rpn_expression_evaluate_from_input();
    vector<char> in2rpn_from_input();
    vector<char> in2rpn(vector<char> in);
};


#endif //COMPLOOK_POLISHNOTATION_H
