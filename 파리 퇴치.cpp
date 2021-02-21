#include <iostream>

using namespace std;
int arr[16][16];

int cal(int x, int y, int m)
{
	int result = 0;
	for (int i = x; i < x + m; ++i)
		for (int j = y; j < y + m; ++j)
			result += arr[i][j];
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test = 0;
	cin >> test;
	for (int testnum = 1; testnum <= test; ++testnum)
	{
		int n, m;
		int result = 0;
		cin >> n >> m;

		for (int i = 0; i < n; ++i)
			for(int j = 0 ; j < n ; ++j)
				cin >> arr[i][j];

		for (int i = 0; i + m - 1 <= n; ++i)
			for (int j = 0; j + m - 1 <= n; ++j)
			{
				int tempResult = cal(i, j, m);
				if (tempResult > result)
					result = tempResult;
			}

		cout << "#" << testnum << " " << result << "\n";
	}

	return 0;
}
