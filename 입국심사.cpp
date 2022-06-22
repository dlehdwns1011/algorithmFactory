#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool isOK(int n, long long nowTime, vector<int>& times) {
    long long sum = 0;
    for (int time : times) {
        sum += nowTime / time;
    }

    if (sum >= n) {
        return true;
    }

    return false;
}

long long solution(int n, vector<int> times) {
    long long start = 0;
    long long end = (long long)times[times.size() - 1] * n;

    while (start + 1 < end) {
        long long nowIndex = (end + start) / 2;
        if (isOK(n, nowIndex, times)) {
            end = nowIndex;
        } else {
            start = nowIndex;
        }
    }

    return end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution(6, { 7,10 });
}
