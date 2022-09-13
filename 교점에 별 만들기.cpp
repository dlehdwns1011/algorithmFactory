#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

double CalX(vector<int> a, vector<int>b) {
    long BF = ((long)a[1] * (long)b[2]);
    long ED = ((long)a[2] * (long)b[1]);
    long AD = ((long)a[0] * (long)b[1]);
    long BC = ((long)a[1] * (long)b[0]);

    return ((double)(BF - ED) / (double)(AD - BC));
}

double CalY(vector<int> a, vector<int>b) {
    long EC = ((long)a[2] * (long)b[0]);
    long AF = ((long)a[0] * (long)b[2]);
    long AD = ((long)a[0] * (long)b[1]);
    long BC = ((long)a[1] * (long)b[0]);

    return ((double)(EC - AF) / (double)(AD - BC));
}

bool IsTruePolong(vector<pair<long, long> >& list, long x, long y) {
    for (auto l : list) {
        if (l.first == x && l.second == y) {
            return true;
        }
    }

    return false;
}

vector<string> MakreAnswer(vector<pair<long, long> >& list) {
    vector<string> answer;

    long maxX = list[0].first, minX = list[0].first;
    long maxY = list[0].second, minY = list[0].second;
    for (auto l : list) {
        long cx = l.first; long cy = l.second;
        if (cx > maxX) {
            maxX = cx;
        } else if (minX > cx) {
            minX = cx;
        }

        if (cy > maxY) {
            maxY = cy;
        } else if (minY > cy) {
            minY = cy;
        }
    }

    for (long index = 0; index < list.size(); ++index) {
        list[index].first -= minX;
        list[index].second -= minY;
    }

    for (long yindex = 0; yindex < maxY - minY + 1; ++yindex) {
        string strY = "";
        for (long xindex = 0; xindex < maxX - minX + 1; ++xindex) {
            if (IsTruePolong(list, xindex, yindex)) {
                strY += "*";
            } else {
                strY += ".";
            }
        }

        answer.push_back(strY);
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long, long> > list;

    for (long index = 0; index < line.size(); ++index) {
        for (long cindex = index + 1; cindex < line.size(); ++cindex) {
            auto x = CalX(line[index], line[cindex]);
            auto y = CalY(line[index], line[cindex]);

            long AD = ((long)line[index][0] * line[cindex][1]);
            long BC = ((long)line[index][1] * line[cindex][0]);

            if (AD - BC == 0) {
                continue;
            }

            if (x - (long long)x == 0 && y - (long long)y == 0) {
                list.push_back(make_pair((long)x, (long)y));
            }
        }
    }

    answer = MakreAnswer(list);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    auto re = solution({ {2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12} });

    for (auto a : re) {
        cout << a << endl;
    }
    return 0;
}


