#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test = 0;
	cin >> test;
	for (int testnum = 1; testnum <= test; ++testnum)
	{
		string tstring;	cin >> tstring;
		int result = 1;

		int sizeofString = tstring.size();
		for (int i = 0; i < sizeofString / 2; ++i)
		{
			if (tstring[i] != tstring[sizeofString - 1 - i])
			{
				result = 0;
				break;
			}
		}

		cout << "#" << testnum << " " << result << "\n";
	}

	return 0;
}
