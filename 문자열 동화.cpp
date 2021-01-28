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
		int n = 0;
		cin >> n;
		string a, b, c;
		cin >> a >> b >> c;
		int result = 0;
		while ((a != b) && (b != c) && (a != c))
		{
			for (int i = 0; i < n; ++i)
			{
				if (a[i] == b[i] && b[i] == c[i] && a[i] == c[i])
					continue;
				if (a[i] == b[i])
					c[i] = a[i];
				else if (a[i] == c[i])
					b[i] = c[i];
				else if (c[i] == b[i])
					a[i] = b[i];
				else
				{
					b[i] = a[i];
					c[i] = a[i];
					++result;
				}
				++result;
			}
		}
		cout << "#" << itest + 1 << " " << result << "\n";
	}
	return 0;
}
