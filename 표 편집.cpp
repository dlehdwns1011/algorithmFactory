//"U X": 현재 선택된 행에서 X칸 위에 있는 행을 선택합니다.
//"D X" : 현재 선택된 행에서 X칸 아래에 있는 행을 선택합니다.
//"C" : 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택합니다.단, 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택합니다.
//"Z" : 가장 최근에 삭제된 행을 원래대로 복구합니다.단, 현재 선택된 행은 바뀌지 않습니다.

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
	set<int> cell;
	vector<int> zLise;
	string oriCell(n, 'X');
	for (int i = 0; i < n; ++i) {
		cell.insert(i);
	}

	auto nowRow = cell.find(k);
	for (auto command : cmd) {
		if (command[0] == 'C') {
			zLise.push_back(*nowRow);
			nowRow = cell.erase(nowRow);
			if (nowRow == cell.end()) {
				--nowRow;
			}
		} else if (command[0] == 'Z') {
			cell.insert(zLise[zLise.size() - 1]);
			zLise.pop_back();
		} else {
			int count = atoi(command.substr(2, command.size() - 2).c_str());
			while (count != 0) {
				if (command[0] == 'U') {
					--nowRow;
				} else {
					++nowRow;
				}
				--count;
			}
		}
	}

	for (auto index : cell) {
		oriCell[index] = 'O';
	}

	return oriCell;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// x < f(x) // x 와 비트가 1~2개 다른 수 중 가장 작은 수
	auto result = solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" });
	cout << result;

	return 0;
}

