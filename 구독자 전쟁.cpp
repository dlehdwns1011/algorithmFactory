#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testnum = 0;
	cin >> testnum;
	for (int itest = 0; itest < testnum; ++itest)
	{
		int n;
		cin >> n;
		int min, max;
		int a, b;
		cin >> a >> b;
		max = (a > b) ? b : a;

		if (a + b >= n)
			min = a + b - n;
		else if (a + b < n)
			min = 0;
		cout << "#" << itest + 1 << " " << max << " " << min << "\n";
	}

	return 0;
}
