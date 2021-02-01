#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 내적 구하기
int solution(vector<int> a, vector<int> b) {
	int answer = 0;
	for (int i = 0; i < a.size(); ++i)
		answer += a[i] * b[i];
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> a;
	vector<int> b;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		a.push_back(input);
	}
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		b.push_back(input);
	}
		

	auto result = solution(a,b);

	cout << result;

	return 0;
}
