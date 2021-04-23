#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N = 0;	cin >> N;
	vector<int> applier;
	for (int i = 0; i < N; ++i)
	{
		int temp; cin >> temp;
		applier.push_back(temp);
	}

	int B = 0, C = 0;	cin >> B >> C;

	long long result = 0;
	for (int i : applier)
	{
		i -= B;
		++result;
		if (i > 0)
		{
			result += (i / C);
			if (i % C != 0)
				++result;
		}
	}
	
	cout << result;

	return 0;
}
