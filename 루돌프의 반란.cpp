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

pair<int, int> dolf;
int santa[31][5]; // x,y,점수,기절,탈락
int arr[51][51];
int santaCount = 0;
int liveSanta = 0;
int N, M, C, D;

int compareSanta(int a, int b) {
    if (santa[a][0] > santa[b][0]) {
        return a;
    } else if (santa[a][0] < santa[b][0]) {
        return b;
    }

    if (santa[a][1] > santa[b][1]) {
        return a;
    } else if (santa[a][1] < santa[b][1]) {
        return b;
    }
}

int GetDistance(int x, int y, int x1, int y1) {
    return ((x1 - x) * (x1 - x)) + ((y1 - y) * (y1 - y));
}

int FindSanta() {
    //가장 가까운 산타를 찾음
    int x = dolf.first; int y = dolf.second;

    int minDistance = 10000;
    int result = 0;
    for (int count = 1; count <= santaCount; ++count) {
        if (santa[count][4] != 1) { // 탈락하지 않음
            int distance = GetDistance(x, y, santa[count][0], santa[count][1]);
            if (distance <= minDistance) {
                if (distance == minDistance) {
                    result = compareSanta(result, count);
                } else {
                    result = count;
                    minDistance = distance;
                }
            }

        }
    }

    return result;
}

void GoToSanta(int santaNum, int dir, int count) {
    int x = santa[santaNum][0];
    int y = santa[santaNum][1];

    int dx = 0; int dy = 0;
    if (dir == 1) {
        dx = -1;
        dy = -1;
    } else if (dir == 2) {
        dx = -1;
    } else if (dir == 3) {
        dx = -1;
        dy = 1;
    } else if (dir == 4) {
        dy = -1;
    } else if (dir == 5) {
        dy = 1;
    } else if (dir == 6) {
        dx = 1;
        dy = -1;
    } else if (dir == 7) {
        dx = 1;
    } else if (dir == 8) {
        dx = 1;
        dy = 1;
    }

    for (int c = 0; c < count; ++c) {
        x += dx;
        y += dy;
    }

    if (x < 1 || x > N || y < 1 || y > N) {
        // 산타가 탈락
        --liveSanta;
        santa[santaNum][4] = 1;
        arr[santa[santaNum][0]][santa[santaNum][1]] = 0;
        return;
    }

    // 산타 있는지 확인
    if (arr[x][y] != 0) {
        GoToSanta(arr[x][y], dir, 1);
    }

    arr[santa[santaNum][0]][santa[santaNum][1]] = 0;
    santa[santaNum][0] = x;
    santa[santaNum][1] = y;
    arr[x][y] = santaNum;
}

void MoveSanta() {
    for (int goSanta = 1; goSanta <= santaCount; ++goSanta) {
        int dir = 0;
        int x = santa[goSanta][0];
        int y = santa[goSanta][1];
        int gox = x;
        int goy = y;

        
        if (santa[goSanta][3] == 0 && santa[goSanta][4] != 1) {
            bool isMove = false;
            int dir = 0;
            if (x == dolf.first) {
                // 같은 row
                if (y < dolf.second) {
                    // 산타가 왼쪽 // 산타가 오른쪽 이동
                    if (arr[x][y + 1] == 0) {
                        goy = y + 1;
                        isMove = true;
                        dir = 5;
                    }
                } else {
                    // 산타가 오른쪽 // 산타가 왼쪽 이동
                    if (arr[x][y - 1] == 0) {
                        goy = y - 1;
                        isMove = true;
                        dir = 4;
                    }
                }

            } else if (y == dolf.second) {
                // 같은 col
                if (x < dolf.first) {
                    // 산타가 윗쪽 // 산타가 아래로 이동
                    if (arr[x + 1][y] == 0) {
                        gox = x + 1;
                        isMove = true;
                        dir = 7;
                    }
                    
                } else {
                    // 산타가 아래쪽 // 산타가 위로 이동
                    if (arr[x - 1][y] == 0) {
                        gox = x - 1;
                        isMove = true;
                        dir = 2;
                    }
                }
            } else {
                // 대각선

                if (x < dolf.first && y < dolf.second) {
                    // 좌상 // 산타 우하이동
                    int t1 = GetDistance(x, y + 1, dolf.first, dolf.second);
                    int t2 = GetDistance(x + 1, y, dolf.first, dolf.second);
                    if (t1 <= t2 && arr[x][y + 1] == 0) {
                        // go t1
                        goy = y + 1;
                        dir = 5;
                        isMove = true;
                    } else if (arr[x + 1][y] == 0) {
                        // go t2
                        gox = x + 1;
                        dir = 7;
                        isMove = true;
                    } else if (arr[x][y + 1] == 0) {
                        // go t1
                        goy = y + 1;
                        dir = 5;
                        isMove = true;
                    }
                } else if (x > dolf.first && y < dolf.second) {
                    // 좌하 // 산타 상우이동
                    int t1 = GetDistance(x - 1, y, dolf.first, dolf.second);
                    int t2 = GetDistance(x, y + 1, dolf.first, dolf.second);
                    if (t1 <= t2 && arr[x - 1][y] == 0) {
                        // go t1
                        gox = x - 1;
                        dir = 2;
                        isMove = true;
                    } else if (arr[x][y + 1] == 0) {
                        // go t2
                        goy = y + 1;
                        dir = 5;
                        isMove = true;
                    } else if (arr[x - 1][y] == 0) {
                        // go t1
                        gox = x - 1;
                        dir = 2;
                        isMove = true;
                    }
                } else if (x > dolf.first && y > dolf.second) {
                    // 우하 // 산타 상좌이동
                    int t1 = GetDistance(x - 1, y, dolf.first, dolf.second);
                    int t2 = GetDistance(x, y - 1, dolf.first, dolf.second);
                    if (t1 <= t2 && arr[x - 1][y] == 0) {
                        // go t1
                        gox = x - 1;
                        dir = 2;
                        isMove = true;
                    } else if (arr[x][y - 1] == 0) {
                        // go t2
                        goy = y - 1;
                        dir = 4;
                        isMove = true;
                    } else if (arr[x - 1][y] == 0) {
                        // go t1
                        gox = x - 1;
                        dir = 2;
                        isMove = true;
                    }
                } else if (x < dolf.first && y > dolf.second) {
                    // 우상 // 산타 하좌이동
                    int t1 = GetDistance(x + 1, y, dolf.first, dolf.second);
                    int t2 = GetDistance(x, y - 1, dolf.first, dolf.second);
                    if (t1 <= t2 && arr[x + 1][y] == 0) {
                        // go t1
                        gox = x + 1;
                        dir = 7;
                        isMove = true;
                    } else if (arr[x][y - 1] == 0) {
                        // go t2
                        goy = y - 1;
                        dir = 4;
                        isMove = true;
                    } else if (arr[x + 1][y] == 0) {
                        // go t1
                        gox = x + 1;
                        dir = 7;
                        isMove = true;
                    }
                }
            }

            if (isMove) {
                arr[x][y] = 0;
                arr[gox][goy] = goSanta;

                santa[goSanta][0] = gox;
                santa[goSanta][1] = goy;

                if (gox == dolf.first && goy == dolf.second) {
                    // 돌프 만남
                    int go_dir = 9 - dir;
                    santa[goSanta][2] += D; // 점수
                    santa[goSanta][3] = 2; // 기절
                    GoToSanta(goSanta, go_dir, D);
                }
            }
        }



        if (santa[goSanta][3] > 0) {
            // 기절 카운트
            --santa[goSanta][3];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> N >> M >> santaCount >> C >> D;
    liveSanta = santaCount;
    cin >> dolf.first >> dolf.second;
    for (int count = 1; count <= santaCount; ++count) {
        int santaNum = 0; int x, y;
        cin >> santaNum >> x >> y;
        santa[santaNum][0] = x;
        santa[santaNum][1] = y;

        arr[x][y] = santaNum;
    }

    for (int count = 0; count < M; ++count) {
        // 1. 루돌프 움직임
        int goSanta = FindSanta();
        int dir = 0;
        if (santa[goSanta][0] == dolf.first) {
            // 같은 row
            if (santa[goSanta][1] < dolf.second) {
                // 산타가 왼쪽
                --dolf.second;
                dir = 4;
            } else {
                // 산타가 오른쪽
                ++dolf.second;
                dir = 5;
            }

        } else if (santa[goSanta][1] == dolf.second) {
            // 같은 col
            if (santa[goSanta][0] < dolf.first) {
                // 산타가 윗쪽
                --dolf.first;
                dir = 2;
            } else {
                // 산타가 아래쪽
                ++dolf.first;
                dir = 7;
            }
        } else {
            // 대각선

            if (santa[goSanta][0] < dolf.first && santa[goSanta][1] < dolf.second) {
                // 좌상
                --dolf.first;
                --dolf.second;
                dir = 1;
            } else if (santa[goSanta][0] > dolf.first && santa[goSanta][1] < dolf.second) {
                // 좌하
                ++dolf.first;
                --dolf.second;
                dir = 6;
            } else if (santa[goSanta][0] > dolf.first && santa[goSanta][1] > dolf.second) {
                // 우하
                ++dolf.first;
                ++dolf.second;
                dir = 8;
            } else if (santa[goSanta][0] < dolf.first && santa[goSanta][1] > dolf.second) {
                // 우상
                --dolf.first;
                ++dolf.second;
                dir = 3;
            }
        }

        if (santa[goSanta][0] == dolf.first && santa[goSanta][1] == dolf.second) {
            // 루돌프 움직임 후 산타 충돌
            santa[goSanta][2] += C; // 점수
            santa[goSanta][3] = 2; // 기절
            GoToSanta(goSanta, dir, C);
        }


        // 2. 산타 움직임
        MoveSanta();

        if (liveSanta == 0) {
            break;
        }

        for (int count = 1; count <= santaCount; ++count) {
            if (santa[count][4] != 1) {
                ++santa[count][2];
            }
        }
    }

    for (int count = 1; count <= santaCount; ++count) {
        cout<< santa[count][2] << " ";
    }

    return 0;
}
