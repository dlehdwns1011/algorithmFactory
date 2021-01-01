#include <iostream>
#include <vector>
#include <algorithm>

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
		int n;
		cin >> n;
		string tstring;
		cin >> tstring;

		if(tstring.size() < n)
			cout << "#" << testnum << " none\n";

		vector<string> v;
		for (int j = 0; j < tstring.size(); ++j)
			v.emplace_back(tstring.substr(j, tstring.size() - j));
		
		sort(v.begin(), v.end());

		cout << "#" << testnum << " " << v[n - 1] << "\n";
		v.clear();
	}

	return 0;
}
