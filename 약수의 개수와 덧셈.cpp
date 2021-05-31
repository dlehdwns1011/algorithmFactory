#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int checkOdd(int n)
{
	int result = 0;
	for (int i = 1; i <= sqrt(n); ++i)
	{
		if (n % i == 0) result += 2;
		if (i * i == n) --result;
	}
		
	return result;
}

int solution(int left, int right) {
	int answer = 0;

	for (int i = left; i <= right; ++i)
	{
		int result = checkOdd(i);
		answer += (result % 2 == 0) ? i : i * (-1);
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<solution(13, 17);

	return 0;
}
