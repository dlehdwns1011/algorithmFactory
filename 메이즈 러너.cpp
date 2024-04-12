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

int N, M, K;
int miro[11][11];
int rotation_miro[11][11];
int player[11][3];
int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, 1, 0, -1 };
int visit[11] = { false, };

int totalMove;
int playerCount;
int exitX, exitY;

int GetDistance(int x1, int y1, int x2, int y2) {
    int x = (x1 - x2);
    int y = (y1 - y2);

    if (x < 0) x *= -1;
    if (y < 0) y *= -1;

    return x + y;
}

void RotationPlayer(int x, int y, int dx, int dy) {
    for (int count = 1; count <= M; ++count) {
        if (visit[count] == false && player[count][0] == x && player[count][1] == y) {
            player[count][0] = dx;
            player[count][1] = dy;
            visit[count] = true;
        }
    }
}

void RotationMiro(int n, int dx, int dy) {
    for (int p = 1; p <= M; ++p) {
        visit[p] = false;
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            RotationPlayer(x + dx + 1, y + dy + 1, y + dx + 1, n - x - 1 + dy + 1);
            rotation_miro[y + dx + 1][n - x - 1 + dy + 1] = miro[x + dx + 1][y + dy + 1];
        }
    }

    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            miro[x + dx][y + dy] = rotation_miro[x + dx][y + dy];
            if (miro[x + dx][y + dy] == -1) {
                exitX = x + dx;
                exitY = y + dy;
            } else if (miro[x + dx][y + dy] >= 1) {
                --miro[x + dx][y + dy];
            }
        }
    }
}

int GetAbs(int n) {
    return (n > 0) ? n : n * -1;
}

void FindRotationMiro() {
    int minSize = 11;
    int minX = 11;
    int minY = 11;
    for (int count = 1; count <= M; ++count) {
        if (player[count][2] == 1) {
            int x = player[count][0];
            int y = player[count][1];

            int goX = (x <= exitX) ? x : exitX;
            int goY = (y <= exitY) ? y : exitY;
            int dir = 0; int size = 0;
            if (GetAbs(x - exitX) >= GetAbs(y - exitY)) {
                size = GetAbs(x - exitX) + 1;
                dir = -1; // 왼쪽 (y)
            } else {
                size = GetAbs(y - exitY) + 1;
                dir = 1; // 위쪽 (x)
            }

            int count = 0;
            if (minSize >= size) {
                if (dir == 1) {
                    // x의 차이
                    if (goX != x) {
                        count = size - 1 - GetAbs(goX - x);
                    } else if (goX != exitX) {
                        count = size - 1 - GetAbs(goX - exitX);
                    } else if (x == exitX) {
                        count = size - 1;
                    }
                } else {
                    // y의 차이
                    if (goY != y) {
                        count = size - 1 - GetAbs(goY - y);
                    } else if (goY != exitY) {
                        count = size - 1 - GetAbs(goY - exitY);
                    } else if(exitY == y){
                        count = size - 1;
                    }
                }

                if (count > 0) {
                    // 이동가능 
                    if (dir == 1) {
                        for (int i = goX - 1; i > 0; --i) {
                            if (count == 0) {
                                break;
                            }
                            --count;
                            --goX;
                        }
                    } else {
                        for (int i = goY - 1; i > 0; --i) {
                            if (count == 0) {
                                break;
                            }
                            --count;
                            --goY;
                        }
                    }
                }
                

                if (minSize == size) {
                    if (goX < minX) {
                        minX = goX;
                        minY = goY;
                    } else if (goX == minX && goY < minY){
                        minX = goX;
                        minY = goY;
                    }
                } else {
                    minX = goX;
                    minY = goY;
                    minSize = size;
                }
                
            }

            
        }
    }

    RotationMiro(minSize, minX - 1, minY - 1);
}

void MovePlayer() {
    for (int count = 1; count <= M; ++count) {
        if (player[count][2] == 1) {
            int x = player[count][0];
            int y = player[count][1];

            int sub_dir = -1;
            int dir = -1;
            if (x != exitX) {
                dir = (x > exitX) ? 0 : 2;
            }
            
            if (y != exitY){
                sub_dir = (y > exitY) ? 3 : 1;
            }

            int goX = -1;
            int goY = -1;
            bool go = false;
            if (dir != -1) {
                // 이동
                goX = x + moveX[dir];
                goY = y + moveY[dir];
                if (goX > 0 && goX <= N && goY > 0 && goY <= N && miro[goX][goY] < 1) {
                    if (GetDistance(x, y, exitX, exitY) > GetDistance(goX, goY, exitX, exitY)) {
                        go = true;
                    }
                }
            }

            if (go == false && sub_dir != -1) {
                goX = x + moveX[sub_dir];
                goY = y + moveY[sub_dir];
                if (goX > 0 && goX <= N && goY > 0 && goY <= N && miro[goX][goY] < 1) {
                    if (GetDistance(x, y, exitX, exitY) > GetDistance(goX, goY, exitX, exitY)) {
                        go = true;
                    }
                }
            }

            if (go) {
                ++totalMove;
                player[count][0] = goX;
                player[count][1] = goY;

                if (goX == exitX && goY == exitY) {
                    player[count][2] = 0;
                    --playerCount;
                }
            }
        }
    }
}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    playerCount = M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> miro[i][j];
        }
    }

    for (int count = 1; count <= M; ++count) {
        cin >> player[count][0] >> player[count][1];
        player[count][2] = 1;
    }

    cin >> exitX >> exitY;
    miro[exitX][exitY] = -1;

    for (int count = 0; count < K; ++count) {
        if (playerCount == 0) {
            break;
        }

        // 1. 플레이어 이동
        MovePlayer();

        // 2. 회전
        FindRotationMiro();
    }

    cout << totalMove << "\n";
    cout << exitX << " " << exitY;

    return 0;
}
