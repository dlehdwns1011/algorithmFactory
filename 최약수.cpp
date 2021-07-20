
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
		int oneN[3] = { 1,2,5 };
		int twoN[4] = { 10, 20, 25, 50 };
		int three[5] = { 100,125,200,250,500 };

		string x;
		cin >> x;
		int result = 0;

		int xNum = atoi(x.c_str());
		if (x.size() == 1) {
			for (int e : oneN) {
				if (xNum >= e) ++result;
				else break;
			}
		} else if (x.size() == 2) {
			result = 3;
			for (int e : twoN) {
				if (xNum >= e) ++result;
				else break;
			}
		} else if (x.size() > 2) {
			result = 7;
			while (xNum >= 100) {
				for (int e : three) {
					if (xNum >= e) ++result;
					else break;
				}
				xNum /= 10;
			}
		}
		
		cout << "#" << testnum << " " << result << "\n";
	}

	return 0;
}
