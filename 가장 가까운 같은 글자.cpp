#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> record;

    int index = 0;
    for (char unitS : s) {
        auto findS = record.find(unitS);
        if (record.find(unitS) == record.end()) {
            answer.push_back(-1);
            record.insert(make_pair(unitS, index));
        } else {
            answer.push_back(index - (*findS).second);
            (*findS).second = index;
        }

        ++index;
    }

    return answer;
}

int main() {
    auto result = solution("foobar");

    //cout << result << endl;
    for (auto unit : result) {
        cout << unit << endl;
    }
    
    return 0;
}
