#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string makeString(char alpha, int n , int& nowCount) {
	string result = "";

	for (int i = 0; i < n; ++i) {
		++nowCount;
		result += alpha;
		if (nowCount % 10 == 0) {
			result += '\n';
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int test = 0; cin >> test;

	for (int testnum = 1; testnum <= test; ++testnum)
	{
		int n; cin >> n;
		string result = "";

		int count = 0; char alpha; int num = 0;
		for (int i = 0; i < n; ++i) {
			cin >> alpha >> num;
			result += makeString(alpha, num, count);
		}

		cout << "#" << testnum << "\n" << result << "\n";
	}

	return 0;
}

