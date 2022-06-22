#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool visit[300000] = { false, };
vector<vector<int>> child;

long long dfs(vector<int>& a, vector<vector<int>>& edges, int level, int now, long long& result) {
    long long nowResult = 0;
    for (int nowChild : child[now]) {
        if (visit[nowChild] == false) {
            if (edges[nowChild][0] == now) {
                visit[nowChild] = true;
                long long vDfs = dfs(a, edges, level + 1, edges[nowChild][1], result);
                nowResult += vDfs;

                long long v = vDfs > 0 ? vDfs : vDfs * -1;
                result += v;
            } else if (edges[nowChild][1] == now) {
                visit[nowChild] = true;
                long long vDfs = dfs(a, edges, level + 1, edges[nowChild][0], result);
                nowResult += vDfs;

                long long v = vDfs > 0 ? vDfs : vDfs * -1;
                result += v;
            }
        }
    }

    return nowResult + a[now];
}


long long solution(vector<int> a, vector<vector<int>> edges) {
    int aSize = a.size();
    long long sum = 0;
    int min = 1000000;
    int minIndex = -1;
    for (int s = 0; s < aSize; ++ s) {
        sum += a[s];
        if (min > a[s]) {
            min = a[s];
            minIndex = s;
        }
    }

    if (sum != 0) {
        return -1;
    }

    child.resize(a.size());
    for (int i = 0; i < edges.size(); ++i) {
        int x = edges[i][0];
        int y = edges[i][1];
        child[x].push_back(i);
        child[y].push_back(i);
    }

    long long result = 0;
    dfs(a, edges, 1, minIndex, result);

    return result;
}

int main() {
    cout << solution({ -2, 8, -5, -5, -3, 0, 5, 2 }, { {0, 1} ,{0, 2},{1, 3},{1, 4},{1, 5},{2, 6},{2, 7} });
}
