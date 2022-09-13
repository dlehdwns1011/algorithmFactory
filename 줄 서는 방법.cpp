#include <iostream>

#include <string>
#include <vector>
#include <set>

using namespace std;

long memoryFactorial[20] = { 0, };
long long Factorial(int num) {
    if (memoryFactorial[num] != 0) {
        return memoryFactorial[num];
    }

    long result = 1;
    for (int index = num; index > 0; --index) {
        result = result * index;
    }

    memoryFactorial[num] = result;
    return result;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> numberVec;
    for (int i = 1; i <= n; ++i) {
        numberVec.emplace_back(i);
    }

    int minusCount = 1;
    long long remain = k - 1;
    while (numberVec.size() != 0) {
        long long nowIndex = remain / Factorial(n - minusCount);
        remain = remain % Factorial(n - minusCount);
        answer.emplace_back(numberVec[nowIndex]);
        numberVec.erase(numberVec.begin() + nowIndex, numberVec.begin() + nowIndex + 1);
        ++minusCount;

        if (remain == 0) {
            answer.insert(answer.end(), numberVec.begin(), numberVec.end());
            break;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    auto re = solution(21,20);

    for (auto a : re) {
        cout << a << " ";
    }
    return 0;
}


