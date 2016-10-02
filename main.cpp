#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<string> result;
    vector<pair<int, string>> static_contestants;

    bool is_plus = false, is_minus = false;
    char sign, first_sign = '0', last_sign = '0';
    string name;
    pair<int, string> static_member;
    for(int i = 0; i < n; i++) {
        cin >> sign >> name;
        if(first_sign == '0') {
            if(sign != '0')
                first_sign = sign;
        }
        if(sign != '0')
            last_sign = sign;
        if(sign == '+') {
            result.push_back(name);
            is_plus = true;
        }
        else if(sign == '-') {
            result.insert(result.begin(), name);
            is_minus = true;
        }
        else {
            static_member.first = i;
            static_member.second = name;
            static_contestants.push_back(static_member);
        }
    }

    if((is_plus != is_minus) || first_sign == '-' || last_sign == '+') {
        cout << "FAIL" << endl;
    }
    else {
        int static_amount = static_contestants.size();
        for(int i = 0; i < static_amount; i++) {
            result.insert(result.begin() + static_contestants[i].first, static_contestants[i].second);
        }
        cout << "OK" << endl;
        for(int i = 0; i < result.size(); i++)
            cout << result[i] << endl;
    }


    return 0;
}