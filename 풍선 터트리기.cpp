#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> a) {
	int answer = 2;
	if (a.size() == 3)
		return 3;
	
	int leftMin = a[0];
	vector<int> rightMin = a;
	int nowMin = a[a.size()-1];
	for (int i = rightMin.size() - 1 ; i >= 0 ; --i)
	{
		if (nowMin > rightMin[i])
			nowMin = rightMin[i];
		rightMin[i] = nowMin;
	}

	for (int i = 1; i < a.size() - 1; ++i)
	{
		if (leftMin > a[i] || rightMin[i+1] > a[i])
			++answer;

		if (leftMin > a[i])
			leftMin = a[i];
	}

	return answer;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arrsize = 10;
	int arr[100] = { -16,27,65,-2,58,-92,-71,-68,-61,-33};
	vector<int> a;
	for (int i = 0; i < arrsize; ++i)
		a.emplace_back(arr[i]);

	auto result = solution(a);

	cout << result;

	return 0;
}
