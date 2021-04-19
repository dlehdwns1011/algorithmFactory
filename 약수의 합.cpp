#include <iostream>

using namespace std;

int solution(int n) {
	if (n == 0) return 0;
	int answer = 0;

	for (int i = 1; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
			answer += (i == n / i) ? i : i + n / i;
	}

	return answer;
}
