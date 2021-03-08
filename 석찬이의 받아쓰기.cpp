#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test = 0; cin >> test;

	for (int testnum = 1; testnum <= test; ++testnum)
	{
		int n; cin >> n;
		char string1[100001], string2[100001];
		cin >> string1 >> string2;

		int result = 0;
		for (int i = 0; i < n; ++i)
			if (string1[i] == string2[i])
				++result;

		cout << "#" << testnum << " " << result << "\n";
	}

	return 0;
}
