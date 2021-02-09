#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPalin(string str)
{
	int i = 0; int j = str.size() - 1;

	while (i < j)
	{
		if (str[i] == str[j])
		{
			++i; --j;
		}
		else
			return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test = 0;
	cin >> test;

	for (int testnum = 1; testnum <= test; ++testnum)
	{
		int result = 0;

		int a, b;
		cin >> a >> b;

		for (int i = a; i <= b; ++i)
		{
			if (isPalin(to_string(i)))
			{
				double temp = sqrt(i);
				double itemp = (int)temp;
				if (temp == itemp)
				{
					if (isPalin(to_string((int)temp)))
					{
						cout << i <<" ";
						++result;
					}
				}
			}
		}
		
		cout << "#" << testnum << " " << result << "\n";
	}

	return 0;
}

