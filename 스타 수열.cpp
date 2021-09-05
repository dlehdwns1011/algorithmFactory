#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
	if (a.size() < 2)    return 0;

	vector<int> aCount(a.size(), 0); // a[i]에 대해 집합이 몇개인지
	vector<int> aBefore(a.size(), -1);

	for (int i = 0; i < a.size(); ++i) {
		int now = a[i];
		if (i != 0 && a[i - 1] != now && aBefore[a[i]] != i - 1) {
			++aCount[a[i]];
			aBefore[a[i]] = i - 1;
		} else if (i + 1 != a.size() && a[i + 1] != now) {
			++aCount[a[i]];
			aBefore[a[i]] = i + 1;
		}
	}

	int result = 0;
	for (int i = 0; i < a.size(); ++i) {
		result = max(result, aCount[i]);
	}

	return result * 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 0 1 0 0 1 1 1 0
	auto result = solution({ 5, 2, 3, 3, 5, 3 });
	cout << result;

	return 0;
}

