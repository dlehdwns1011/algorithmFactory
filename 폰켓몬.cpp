#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
	set<int> s(nums.begin(), nums.end());
	return (nums.size() / 2 < s.size()) ? nums.size() / 2 : s.size();
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> nums;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		nums.emplace_back(a);
	}

	auto result = solution(nums);
	cout << result;

	return 0;
}
