#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int left = 1;
    int right = enemy.size() + 1;
    int mid = (left + right) / 2;

    while (1) {
        priority_queue<int> pq(enemy.begin(), enemy.begin() + mid);

        for (int kCount = 0; kCount < k; ++kCount) {
            pq.pop();
        }

        long enemys = 0;
        int size = pq.size();
        for (int index = 0; index < size; ++index) {
            enemys += pq.top();
            pq.pop();
        }

        if (n < enemys) {
            right = mid;
        } else {
            left = mid + 1;
            answer = mid;
        }

        mid = (left + right) / 2;
        if (left >= right) {
            break;
        }
    }

    return answer;
}


int main() {
    auto result = solution(7,3, { 4, 2, 4, 5, 3, 3, 1 });

    cout << result << endl;
    /*for (auto unit : result) {
        cout << unit << endl;
    }*/
    
    return 0;
}
