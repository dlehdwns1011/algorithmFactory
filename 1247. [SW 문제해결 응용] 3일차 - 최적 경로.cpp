//DFS �⺻ Ʋ
#include <iostream>
#include <string.h>

using namespace std;

pair<int, int> gra[11];
pair<int, int> house;
bool visit[11];
int minV;
int n;
int visitcount;

int cal( pair<int, int> a ,  pair<int, int> b)
{
	int x = (a.first - b.first);
	if (x < 0)
		x *= -1;
	int y = (a.second - b.second);
	if (y < 0)
		y *= -1;
	return x + y;
}

void dfs(int root, int dist)
{
	if (minV < dist)
		return;

	visit[root] = true;

	if (visitcount == n)
	{
		int home = cal(house, gra[root]);
		if (dist + home < minV)
			minV = dist + home;
		return;
	}

	for (int i = 0; i <= n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			++visitcount;
			dfs(i, cal(gra[i] , gra[root]) + dist);
			visit[i] = false;
			--visitcount;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testnum = 0;
	cin >> testnum;
	for (int itest = 0; itest < testnum; ++itest)
	{		
		cin >> n;

		int x, y;
		cin >> x >> y;
		gra[0].first = x;
		gra[0].second = y;
		cin >> x >> y;
		house.first = x;
		house.second = y;
		memset(visit, false, 11);
		visit[0] = true;
		
		visitcount = 0;
		minV = 987654321;
		for (int i = 1; i <= n ; ++i)
		{
			cin >> x >> y;
			gra[i].first = x;
			gra[i].second = y;
		}

		dfs(0,0);

		cout << "#" << itest + 1 << " " << minV << "\n";
	}

	return 0;
}
