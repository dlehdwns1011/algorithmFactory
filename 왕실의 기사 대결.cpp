#include <cstring>
#include <memory.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int L, N, Q;
int arr[41][41];
int knights[31][6];
int knightsPosition[41][41];
stack<int> fight;
std::queue<pair<int, int> > queueKnight;
int totalCount = 0;

int GetTrapCount(int r, int c, int h, int w) {
    int result = 0;
    for (int xi = 0; xi < h; ++xi) {
        for (int yi = 0; yi < w; ++yi) {
            if (arr[r + xi][c + yi] == 1) {
                ++result;
            }
        }
    }

    return result;
}


bool MoveKnight(int k, int dir) {
    int x = knights[k][0];
    int y = knights[k][1];
    int h = knights[k][2];
    int w = knights[k][3];
    ++totalCount;

    bool visit[31] = { false, };
    int goX = 0; int goY = 0;
    if (dir == 0) {
        // 상
        for (int index = y; index < y + w; ++index) {
            goX = x - 1;
            goY = index;

            if (goX < 1 || goX > L || goY < 1 || goY > L) {
                return false;
            } else if (arr[goX][goY] == 2) {
                return false;
            } else if (knightsPosition[goX][goY] != 0 && knightsPosition[goX][goY] != k) {
                // 기사가 있음
                if (!visit[knightsPosition[goX][goY]] && knights[knightsPosition[goX][goY]][4] > 0) {
                    queueKnight.push(make_pair(knightsPosition[goX][goY], dir));
                    visit[knightsPosition[goX][goY]] = true;
                }
                
            }
        }
    } else if (dir == 1) {
        // 우
        for (int index = x; index < x + h; ++index) {
            goX = index;
            goY = y + w;

            if (goX < 1 || goX > L || goY < 1 || goY > L) {
                return false;
            } else if (arr[goX][goY] == 2) {
                return false;
            } else if (knightsPosition[goX][goY] != 0 && knightsPosition[goX][goY] != k) {
                // 기사가 있음
                if (!visit[knightsPosition[goX][goY]] && knights[knightsPosition[goX][goY]][4] > 0) {
                    queueKnight.push(make_pair(knightsPosition[goX][goY], dir));
                    visit[knightsPosition[goX][goY]] = true;
                }
            }
        }
    } else if (dir == 2) {
        // 하
        for (int index = y; index < y + w; ++index) {
            goX = x + h;
            goY = index;

            if (goX < 1 || goX > L || goY < 1 || goY > L) {
                return false;
            } else if (arr[goX][goY] == 2) {
                return false;
            } else if (knightsPosition[goX][goY] != 0 && knightsPosition[goX][goY] != k) {
                // 기사가 있음
                if (!visit[knightsPosition[goX][goY]] && knights[knightsPosition[goX][goY]][4] > 0) {
                    queueKnight.push(make_pair(knightsPosition[goX][goY], dir));
                    visit[knightsPosition[goX][goY]] = true;
                }
            }
        }
    } else if (dir == 3) {
        // 좌
        for (int index = x; index < x + h; ++index) {
            goX = index;
            goY = y - 1;

            if (goX < 1 || goX > L || goY < 1 || goY > L) {
                return false;
            } else if (arr[goX][goY] == 2) {
                return false;
            } else if (knightsPosition[goX][goY] != 0 && knightsPosition[goX][goY] != k) {
                // 기사가 있음
                if (!visit[knightsPosition[goX][goY]] && knights[knightsPosition[goX][goY]][4] > 0) {
                    queueKnight.push(make_pair(knightsPosition[goX][goY], dir));
                    visit[knightsPosition[goX][goY]] = true;
                }
            }
        }
    }

    fight.push(k);
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> L >> N >> Q;
    for (int index = 1; index <= L; ++index) {
        for (int index2 = 1; index2 <= L; ++index2) {
            cin >> arr[index][index2];
        }
    }

    for (int count = 1; count <= N; ++count) {
        cin >> knights[count][0] >> knights[count][1] >> knights[count][2] >> knights[count][3] >> knights[count][4];
        knights[count][5] = knights[count][4];

        for (int xi = 0; xi < knights[count][2]; ++xi) {
            for (int yi = 0; yi < knights[count][3]; ++yi) {
                int x = knights[count][0] + xi;
                int y = knights[count][1] + yi;
                knightsPosition[x][y] = count;
            }
        }
    }

    for (int qCount = 0; qCount < Q; ++qCount) {
        int knight, dir;
        cin >> knight >> dir;
        
        while (!fight.empty()) { fight.pop(); }

        if (knights[knight][4] > 0) {
            totalCount = 0;
            queueKnight.push(make_pair(knight, dir));

            while (!queueKnight.empty()) {
                pair<int, int> now = queueKnight.front();
                queueKnight.pop();
                MoveKnight(now.first, now.second);
            }
            
        }

        if (totalCount != 0 && totalCount == fight.size()) {
            while (!fight.empty()) {
                int k = fight.top();
                fight.pop();
                bool isFirst = false;
                int x = knights[k][0];
                int y = knights[k][1];

                for (int xi = 0; xi < knights[k][2]; ++xi) {
                    for (int yi = 0; yi < knights[k][3]; ++yi) {
                        int preX = x + xi;
                        int preY = y + yi;
                        knightsPosition[preX][preY] = 0;
                    }
                }

                for (int xi = 0; xi < knights[k][2]; ++xi) {
                    for (int yi = 0; yi < knights[k][3]; ++yi) {
                        int preX = x + xi;
                        int preY = y + yi;

                        int goX = 0; int goY = 0;
                        if (dir == 0) {
                            // 상
                            goX = preX - 1;
                            goY = preY;
                        } else if (dir == 1) {
                            // 우
                            goX = preX;
                            goY = preY + 1;
                        } else if (dir == 2) {
                            // 하
                            goX = preX + 1;
                            goY = preY;
                        } else if (dir == 3) {
                            // 좌
                            goX = preX;
                            goY = preY - 1;
                        }

                        if (isFirst == false) {
                            knights[k][0] = goX;
                            knights[k][1] = goY;
                            isFirst = true;
                        }

                        knightsPosition[goX][goY] = k;
                    }
                }

                if (knight != k) {
                    knights[k][4] -= GetTrapCount(knights[k][0], knights[k][1], knights[k][2], knights[k][3]);
                }
            }
        }
        
        
    }

    int result = 0;
    for (int k = 1; k <= N; ++k) {
        if (knights[k][4] > 0) {
            result += knights[k][5] - knights[k][4];
        }
    }

    cout << result;

    return 0;
}
