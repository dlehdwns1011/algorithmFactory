#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	int total = 0;
	for (int i = 1; i < n + 1; ++i)
		total += i;

	vector<int> floor(total);
	int floorindex = 1;
	int c = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = i; j != 0; --j)
		{
			floor[c] = i;
			++c;
		}
	}

	vector<int> answer(total);
	int count = 1;
	int mode = 1;
	int index = 0;

	while(1)
	{
		
		answer[index] = count;
		if (count == n)
			break;
		index += floor[index];
		++count;
		
	}
	++count;
	mode = 2;
	for(int i = n - 1 ; i != 0 ; --i)
	{
		for (int j = i; j > 0; --j)
		{
			switch (mode)
			{
			case 1:
				index += floor[index];
				break;
			case 2:
				++index;
				break;
			case 3:
				index -= floor[index];
				break;
			}
			answer[index] = count;
			++count;
		}
		
		if (mode == 1) mode = 2;
		else if (mode == 2) mode =3;
		else if (mode == 3) mode = 1;
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

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}
