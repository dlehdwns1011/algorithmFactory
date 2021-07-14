#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

//|r1 - r2| + |c1 - c2| 
int getManDis(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int i = 0; i < 5; ++i) {
		// 하나의 시험실
		vector<string> place = places[i];
		vector<pair<int, int> > player;
		
		for (int j = 0; j < 5; ++j) {
			// 하나의 row
			string block = place[j];
			for (int k = 0; k < 5; ++k) {
				if (block[k] == 'P') {
					player.emplace_back(j, k);
				}
			}
		}

		bool finish = false;
		if (player.size() < 2) {
			answer.emplace_back(1);
			continue;
		}

		for (int j = 0; j < player.size() - 1; ++j) {
			for (int k = j + 1; k < player.size() ; ++k) {
				int dis = getManDis(player[j], player[k]);
				if (dis < 2) {
					finish = true;
					break;
				} else if (dis == 2) {
					if (player[j].first == player[k].first) {
						// 일직선
						if (place[player[j].first][(player[j].second + player[k].second) / 2] != 'X') {
							finish = true;
							break;
						}
					}
					else if (player[j].second == player[k].second) {
						// 일직선
						if (place[(player[j].first + player[k].first) / 2][player[j].second] != 'X') {
							finish = true;
							break;
						}
					}
					else {
						// 대각선
						if (place[player[j].first][player[k].second] != 'X' || place[player[k].first][player[j].second] != 'X') {
							finish = true;
							break;
						}
					}
				}
			}
			if (finish) break;
		}
		answer.emplace_back((finish == false)? 1:0);
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// p 사람 o 빈자리 x 파티션
	auto result = solution({{"PPOOP", "PXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}} );

	for (auto seg : result) {
		cout << seg << " ";
	}

	return 0;
}
