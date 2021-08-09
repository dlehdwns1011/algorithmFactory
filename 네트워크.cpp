#include <iostream>
#include <vector>
#include <set>

using namespace std;

void decideRoot(vector<vector<int>> computers, vector<int>& root, int nowIndex, int rootNum)
{
	if (rootNum == -1) {
		rootNum = nowIndex;
	}

	if (root[nowIndex] == rootNum) {
		return;
	}

	root[nowIndex] = rootNum;
	vector<int> network = computers[nowIndex];
	for (int i = 0; i < network.size(); ++i) {
		if (nowIndex != i && network[i] == 1) {
			decideRoot(computers, root, i, rootNum);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int comNum = computers.size();
	vector<int> root;
	for (int i = 0; i < comNum; ++i) {
		root.emplace_back(-1);
	}

	int now = 0;
	while (now != comNum) {
		decideRoot(computers, root, now, root[now]);
		++now;
	}

	set<int> resultSet(root.begin(), root.end());
	return resultSet.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> mu;
	string m;
	string s;

	int n = 3;
	auto result = solution(n, { {1, 1, 0},{1, 1, 1}, {0, 1, 1} });

	cout << result;

	return 0;
}
