#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testnum;
	cin >> testnum;

	
	for (int test = 0; test < testnum; ++test)
	{
		string a = "";
		string b = "";
		cin >> a;
		cin >> b;
		int result = 0;

		while (1)
		{
			int findindex = a.find(b);
			if (findindex == -1)
				break;

			++result;
			a.erase(a.begin() + findindex, a.begin() + findindex + b.size());
		}
		cout << "#" << test + 1 << " " << result + a.size() << "\n";
	}

	return 0;
}
