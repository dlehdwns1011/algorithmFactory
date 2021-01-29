#include <iostream>

using namespace std;

int find369(int i)
{
	int result = 0;

	while ((i / 10) != 0)
	{
		if (i % 10 == 3 || i % 10 == 6 || i % 10 == 9)
			++result;
		i /= 10;
	}

	if (i % 10 == 3 || i % 10 == 6 || i % 10 == 9)
		++result;

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int num = find369(i);
		if (num == 0) cout << i;
		else
		{
			for (int j = 0; j < num; ++j)
				cout << "-";
		}
		cout << " ";
	}

	return 0;
}
