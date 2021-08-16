#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;

	for (auto num : numbers) {
		if (num % 2 == 0) {
			answer.emplace_back(num + 1);
		} else {
			int count = 0;
			auto t = num;
			while ((num % 2) != 0) {
				num = num / 2;
				++count;
			}

			long long dif = (t >> count - 1) << count - 1;
			answer.emplace_back(t + 1 + (t - dif));
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// x < f(x) // x 와 비트가 1~2개 다른 수 중 가장 작은 수
	auto result = solution({2, 7});

	for (auto re : result) {
		cout << re << " ";
	}
	

	return 0;
}

