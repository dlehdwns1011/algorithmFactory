#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test;
	cin >> test;
	for (int testnum = 0; testnum < test; ++testnum)
	{
		string teststring;
		cin >> teststring;

		bool now = false;
		int result = 0;
		for (int i = 0; i < teststring.size(); ++i)
		{
			if (!now && teststring[i] == '1')
			{
				now = true;
				++result;
			}
			else if (now && teststring[i] == '0')
			{
				now = false;
				++result;
			}
		}
		cout << "#" << testnum + 1 << " " << result << "\n";
	}
	return 0;
}
