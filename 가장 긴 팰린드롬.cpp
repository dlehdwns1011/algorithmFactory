#include <iostream>
#include <string>
using namespace std;
int oddCheck(int center, string& s) {
    int result = 1;
    for (int index = 1; index <= s.size(); ++index) {
        if (center - index < 0 || center + index >= s.size()) {
            break;
        }

        if (s[center - index] != s[center + index]) {
            break;
        }
        result += 2;
    }

    return result;
}

int evenCheck(int center, string& s) {
    int result = 0;
    for (int index = 0; index < s.size(); ++index) {
        if (center - index < 0 || center + index > s.size()) {
            break;
        }

        if (s[center - index] != s[center + index + 1]) {
            break;
        }
        result += 2;
    }

    return result;
}

int solution(string s)
{
    int result = 1;
    for (int center = 0; center < s.size() ; ++center) {
        int r_odd = oddCheck(center, s);
        int r_even = evenCheck(center, s);
        result = (r_odd > result) ? r_odd : result;
        result = (r_even > result) ? r_even : result;
    }
    
    return result;
}
