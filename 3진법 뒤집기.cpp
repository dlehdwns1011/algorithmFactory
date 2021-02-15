#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> vec;
	while (n / 3 != 0)
	{
		vec.emplace_back(n % 3);
		n /= 3;
	}
	vec.emplace_back(n);
	
	int mul = 1;
	for (int i = vec.size() - 1; i >= 0; --i)
	{
		answer += vec[i] * mul;
		mul *= 3;
	}
		
	return answer;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;


	auto result = solution(n);

	cout << result;

	return 0;
}
