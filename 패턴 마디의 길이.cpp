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
		string input;
		cin >> input;
		int result = 0;
		for (int i = 2; i < input.size() ; ++i)
		{
			string p = input.substr(i, input.size());
			if (p.find(input.substr(0, i)) == 0)
			{
				result = i;
				break;
			}
		}

		if (result == 0) result = 1;
		cout << "#" << itest + 1 << " " << result <<"\n";
	}

	return 0;
}