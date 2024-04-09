#include <cstring>
#include <memory.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <list>

using namespace std;

int fishDir[5][5][9];
int copyDir[5][5][9];
int nextDir[5][5][9];
int smell[5][5];
pair<int, int> shark;

bool isEnableSharkMove(pair<int, int> sharkPosition, int dir) {
    if (dir == 1) {
        return (sharkPosition.first - 1 == 0) ? false : true;
    } else if (dir == 2) {
        return (sharkPosition.second - 1 == 0) ? false : true;
    } else if (dir == 3) {
        return (sharkPosition.first + 1 == 5) ? false : true;
    } else if (dir == 4) {
        return (sharkPosition.second + 1 == 5) ? false : true;
    }
}

pair<int, int> GetSharkMove(pair<int, int> sharkPosition, int dir) {
    if (dir == 1) {
        if (sharkPosition.first - 1 != 0) {
            sharkPosition.first -= 1;
        }
    } else if (dir == 2) {
        if (sharkPosition.second - 1 != 0) {
            sharkPosition.second -= 1;
        }
    } else if (dir == 3) {
        if (sharkPosition.first + 1 != 5) {
            sharkPosition.first += 1;
        }
    } else if (dir == 4) {
        if (sharkPosition.second + 1 != 5) {
            sharkPosition.second += 1;
        }
    }

    return sharkPosition;
}

bool isSafe(int x, int y) {
    if (x == shark.first && y == shark.second) {
        return false;
    }

    return true;
}

int GetEnableDir(int x, int y, int dir) {
    int firstDir = dir;
    if (dir == 1) {
        if (y - 1 != 0 && smell[x][y - 1] == 0 && isSafe(x,y - 1)) {
            return dir;
        }
    } else if (dir == 2) {
        if (x - 1 != 0 && y - 1 != 0 && smell[x - 1][y - 1] == 0 && isSafe(x- 1, y- 1)) {
            return dir;
        }
    } else if (dir == 3) {
        if (x - 1 != 0 && smell[x - 1][y] == 0 && isSafe(x - 1, y)) {
            return dir;
        }
    } else if (dir == 4) {
        if (x - 1 != 0 && y + 1 != 5 && smell[x - 1][y + 1] == 0 && isSafe(x - 1, y + 1)) {
            return dir;
        }
    } else if (dir == 5) {
        if (y + 1 != 5 && smell[x][y + 1] == 0 && isSafe(x, y + 1)) {
            return dir;
        }
    } else if (dir == 6) {
        if (x + 1 != 5 && y + 1 != 5 && smell[x + 1][y + 1] == 0 && isSafe(x+ 1, y+ 1)) {
            return dir;
        }
    } else if (dir == 7) {
        if (x + 1 != 5 && smell[x + 1][y] == 0 && isSafe(x+ 1, y)) {
            return dir;
        }
    } else if (dir == 8) {
        if (x + 1 != 5 && y - 1 != 0 && smell[x + 1][y - 1] == 0 && isSafe(x+ 1, y- 1)) {
            return dir;
        }
    }

    --dir;
    if (dir == 0) {
        dir = 8;
    }

    while (dir != firstDir) {
        if (dir == 1) {
            if (y - 1 != 0 && smell[x][y - 1] == 0 && isSafe(x, y- 1)) {
                return dir;
            }
        } else if (dir == 2) {
            if (x - 1 != 0 && y - 1 != 0 && smell[x - 1][y - 1] == 0 && isSafe(x- 1, y- 1)) {
                return dir;
            }
        } else if (dir == 3) {
            if (x - 1 != 0 && smell[x - 1][y] == 0 && isSafe(x - 1, y)) {
                return dir;
            }
        } else if (dir == 4) {
            if (x - 1 != 0 && y + 1 != 5 && smell[x - 1][y + 1] == 0 && isSafe(x- 1, y+ 1)) {
                return dir;
            }
        } else if (dir == 5) {
            if (y + 1 != 5 && smell[x][y + 1] == 0 && isSafe(x, y+ 1)) {
                return dir;
            }
        } else if (dir == 6) {
            if (x + 1 != 5 && y + 1 != 5 && smell[x + 1][y + 1] == 0 && isSafe(x+ 1, y+ 1)) {
                return dir;
            }
        } else if (dir == 7) {
            if (x + 1 != 5 && smell[x + 1][y] == 0 && isSafe(x+ 1, y)) {
                return dir;
            }
        } else if (dir == 8) {
            if (x + 1 != 5 && y - 1 != 0 && smell[x + 1][y - 1] == 0 && isSafe(x+ 1, y- 1)) {
                return dir;
            }
        }

        --dir;
        if (dir == 0) {
            dir = 8;
        }
    }

    return 0;
}





int GetFishCount(int x, int y) {
    int result = 0;
    for (int i = 1; i < 9; ++i) {
        result += nextDir[x][y][i];
    }

    return result;
}

void deleteFish(int x, int y) {
    for (int i = 1; i < 9; ++i) {
        nextDir[x][y][i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M = 0;
    int S = 0;
    cin >> M >> S;

    for (int count = 0; count < M; ++count) {
        int x, y, dir;
        cin >> x >> y >> dir;

        fishDir[x][y][dir] += 1;
    }

    cin >> shark.first >> shark.second;
    for (int count = 0; count < S; ++count) {
        // 1. 복제
        for (int x = 1; x < 5; ++x) {
            for (int y = 1; y < 5; ++y) {
                for (int dir = 1; dir < 9; ++dir) {
                    copyDir[x][y][dir] = fishDir[x][y][dir];
                    nextDir[x][y][dir] = 0;
                }
            }
        }

        // 2. 이동
        for (int x = 1; x < 5; ++x) {
            for (int y = 1; y < 5; ++y) {
                for (int dir = 1; dir < 9; ++dir) {
                    if (fishDir[x][y][dir] != 0) {
                        int go = GetEnableDir(x, y, dir);
                        if (go == 1) {
                            nextDir[x][y - 1][go] += fishDir[x][y][dir];
                        } else if (go == 2) {
                            nextDir[x - 1][y - 1][go] += fishDir[x][y][dir];
                        } else if (go == 3) {
                            nextDir[x - 1][y][go] += fishDir[x][y][dir];
                        } else if (go == 4) {
                            nextDir[x - 1][y + 1][go] += fishDir[x][y][dir];
                        } else if (go == 5) {
                            nextDir[x][y + 1][go] += fishDir[x][y][dir];
                        } else if (go == 6) {
                            nextDir[x + 1][y + 1][go] += fishDir[x][y][dir];
                        } else if (go == 7) {
                            nextDir[x + 1][y][go] += fishDir[x][y][dir];
                        } else if (go == 8) {
                            nextDir[x + 1][y - 1][go] += fishDir[x][y][dir];
                        } else {
                            nextDir[x][y][dir] += fishDir[x][y][dir];
                        }
                    }
                }
            }
        }

        // 3. 상어 이동
        vector<int> sharkMove;
        int move = 111;
        while (move <= 444) {
            int move1 = move / 100;
            int move2 = (move % 100) / 10;
            int move3 = move % 10;

            pair<int, int> tempShark(shark);
            if (isEnableSharkMove(tempShark, move1)) {
                tempShark = GetSharkMove(tempShark, move1);
                if (isEnableSharkMove(tempShark, move2)) {
                    tempShark = GetSharkMove(tempShark, move2);
                    if (isEnableSharkMove(tempShark, move3)) {
                        sharkMove.push_back(move);
                    }
                    move += 1;
                } else {
                    move += 10;
                }
            } else {
                move += 100;
            }

            if (move % 10 >= 5) {
                move -= 4;
                move += 10;
            }

            if ((move % 100) / 10 >= 5) {
                move -= 40;
                move += 100;
            }
        }

        int maxFish = 0;
        int maxMove = 0;
        
        for (int move : sharkMove) {
            int move1 = move / 100;
            int move2 = (move % 100) / 10;
            int move3 = move % 10;

            int tempFish = 0;
            pair<int, int> tempShark1;
            tempShark1 = GetSharkMove(shark, move1);
            tempFish += GetFishCount(tempShark1.first, tempShark1.second);

            pair<int, int> tempShark2;
            tempShark2 = GetSharkMove(tempShark1, move2);
            tempFish += GetFishCount(tempShark2.first, tempShark2.second);

            pair<int, int> tempShark3;
            tempShark3 = GetSharkMove(tempShark2, move3);
            if (!(tempShark3.first == tempShark1.first && tempShark3.second == tempShark1.second)) {
                tempFish += GetFishCount(tempShark3.first, tempShark3.second);
            }
            

            if (maxFish < tempFish) {
                maxFish = tempFish;
                maxMove = move;
            }
        }

        // 4. 냄새 제거
        for (int x = 1; x < 5; ++x) {
            for (int y = 1; y < 5; ++y) {
                if (smell[x][y] != 0) {
                    smell[x][y] -= 1;
                }
            }
        }

        if (maxMove == 0) {
            maxMove = sharkMove[0];
        }

        if (maxMove != 0) {
            int move1 = maxMove / 100;
            int move2 = (maxMove % 100) / 10;
            int move3 = maxMove % 10;


            shark = GetSharkMove(shark, move1);
            if (GetFishCount(shark.first, shark.second) != 0) {
                smell[shark.first][shark.second] = 2;
            }
            deleteFish(shark.first, shark.second);

            shark = GetSharkMove(shark, move2);
            if (GetFishCount(shark.first, shark.second) != 0) {
                smell[shark.first][shark.second] = 2;
            }
            deleteFish(shark.first, shark.second);

            shark = GetSharkMove(shark, move3);
            if (GetFishCount(shark.first, shark.second) != 0) {
                smell[shark.first][shark.second] = 2;
            }
            deleteFish(shark.first, shark.second);
        }

        

        // 5. 복제 완료
        for (int x = 1; x < 5; ++x) {
            for (int y = 1; y < 5; ++y) {
                for (int dir = 1; dir < 9; ++dir) {
                    fishDir[x][y][dir] = nextDir[x][y][dir] + copyDir[x][y][dir];
                }
            }
        }

    }


    int result = 0;
    for (int x = 1; x < 5; ++x) {
        for (int y = 1; y < 5; ++y) {
            for (int dir = 1; dir < 9; ++dir) {
                result += fishDir[x][y][dir];
            }
        }
    }

    cout << result;

    return 0;
}
