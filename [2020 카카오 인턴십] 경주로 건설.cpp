#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int visit[25][25] = { 0, };
int dis[25][25][4] = { 0, };
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };

struct Sdata
{
	Sdata(int a, int b, int c)
	{
		x = a; y = b; dir = c;
	}
	int x;
	int y;
	int dir;
	//0 우
	//1 하
	//2 상
	//3 좌
};

int solution(vector<vector<int>> board) {
	int boardsize = board.size();

	queue<Sdata> queue;
	if (board[1][0] == 0)
	{
		queue.push(Sdata(1, 0, 1));
		dis[1][0][1] = 1;
		visit[1][0] = 1;
	}
	if (board[0][1] == 0)
	{
		queue.push(Sdata(0, 1, 0));
		dis[0][1][0] = 1;
		visit[0][1] = 1;
	}
	visit[0][0] = 1;


	while (!queue.empty())
	{
		int px = queue.front().x;
		int py = queue.front().y;
		int pdir = queue.front().dir;
		queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (0 <= nx && nx < boardsize && 0 <= ny && ny < boardsize)
			{
				if (board[nx][ny] == 0)
				{
					int plus = 1;
					if (pdir != i) plus = 6;

					if (visit[nx][ny] == 0)
					{
						queue.push(Sdata(nx, ny, i));
						dis[nx][ny][i] = dis[px][py][i] + plus;
						visit[nx][ny] = 1;
					}
					else 
					{
						if (dis[nx][ny][i] >= dis[px][py][i] + plus)
						{
							queue.push(Sdata(nx, ny, i));
							dis[nx][ny][i] = dis[px][py][i] + plus;
						}
					}
				}
			}
		}

	}

	return min(dis[boardsize - 1][boardsize - 1]) * 100;
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
