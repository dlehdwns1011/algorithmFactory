#include <iostream>
#include <string>
#include <vector>

using namespace std;

int boardsize = 0;
int arr[25][25];
bool visit[25][25];
int minC = 987654321;

void dfs(int i, int j, int cost, int dir)
{
	if (cost >= minC) return;

	visit[i][j] = true;

	if (i == boardsize - 1 && j == boardsize - 1)
	{
		if (minC > cost)
		{
			minC = cost;
			return;
		}
	}

	// 주변 탐색
	bool result = false;
	//하
	if (i != boardsize - 1)
	{
		if (visit[i + 1][j] == false && arr[i + 1][j] != 1)
		{
			if (dir == 1 || dir == -1)
				dfs(i + 1, j, cost + 100, 1);
			else
				dfs(i + 1, j, cost + 600, 1);
			visit[i + 1][j] = false;
		}
	}
	//우
	if (j != boardsize - 1)
	{
		if (visit[i][j + 1] == false && arr[i][j + 1] != 1)
		{
			if (dir == 3 || dir == -1)
				dfs(i, j + 1, cost + 100, 3);
			else
				dfs(i, j + 1, cost + 600, 3);
			visit[i][j + 1] = false;
		}
	}
	//상
	if (i != 0)
	{
		if (visit[i - 1][j] == false && arr[i - 1][j] != 1)
		{
			if (dir == 0)
				dfs(i - 1, j, cost + 100, 0);
			else
				dfs(i - 1, j, cost + 600, 0);
			visit[i - 1][j] = false;
		}
	}
	//좌
	if (j != 0)
	{
		if (visit[i][j - 1] == false && arr[i][j - 1] != 1)
		{
			if (dir == 2)
				dfs(i, j - 1, cost + 100, 2);
			else
				dfs(i, j - 1, cost + 600, 2);
			visit[i][j - 1] = false;
		}
	}
}

int solution(vector<vector<int>> board) {
	boardsize = board.size();
	for (int i = 0; i < boardsize; ++i)
	{// i -> 행
		for (int j = 0; j < board[i].size(); ++j)
		{// j -> 열
			arr[i][j] = board[i][j];
			visit[i][j] = false;
		}
	}

	dfs(0, 0, 0, -1);

	return minC;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<vector<int>> board;
	for (int i = 0; i < n; ++i)
	{
		vector<int> temp;
		for (int j = 0; j < n; ++j)
		{
			int a;
			cin >> a;
			temp.emplace_back(a);
		}
		board.emplace_back(temp);
	}
	
	auto result = solution(board);

	//for (int i = 0; i < result.size(); i++)
	{
		cout << result << " ";
	}

	return 0;
}
