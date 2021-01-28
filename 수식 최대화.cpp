#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long cal(string expression, string order)
{
	long long result = 0;
	long long leftnum, rightnum;
	int pos = 0;
	int index = -1;
	while (expression.find(order[0], pos) != -1)
	{
		index = expression.find(order[0], pos);
		pos = index + 1;
	}
	char preorder;
	if (index != -1)
	{
		preorder = order[0];
		string left = expression;
		left.erase(left.begin() + index, left.end());
		leftnum = cal(left,order);
		string right = expression;
		right.erase(right.begin(), right.begin() + index + 1);
		rightnum = cal(right, order);
	}
	else
	{
		pos = 0;
		index = -1;
		while (expression.find(order[1], pos) != -1)
		{
			index = expression.find(order[1], pos);
			pos = index + 1;
		}
		if (index != -1)
		{
			preorder = order[1];
			string left = expression;
			left.erase(left.begin() + index, left.end());
			leftnum = cal(left, order);
			string right = expression;
			right.erase(right.begin(), right.begin() + index + 1);
			rightnum = cal(right, order);
		}
		else
		{
			pos = 0;
			index = -1;
			while (expression.find(order[2], pos) != -1)
			{
				index = expression.find(order[2], pos);
				pos = index + 1;
			}
			if (index != -1)
			{
				preorder = order[2];
				string left = expression;
				left.erase(left.begin() + index, left.end());
				leftnum = cal(left, order);
				string right = expression;
				right.erase(right.begin(), right.begin() + index + 1);
				rightnum = cal(right, order);
			}
			else		return stoll(expression);
		}
	}
	if (preorder == '+')		return leftnum + rightnum;
	else if (preorder == '-')		return leftnum - rightnum;
	else if (preorder == '*')		return leftnum * rightnum;
}

long long solution(string expression) {
	long long max = 0;
	string cases[6];
	cases[0] = "*+-";
	cases[1] = "*-+";
	cases[2] = "+*-";
	cases[3] = "+-*";
	cases[4] = "-*+";
	cases[5] = "-+*";

	for(int i = 0; i < 6; ++i)
	{
		long long temp = cal(expression, cases[i]);
		if (temp < 0)			temp *= -1;
		if (temp > max)			max = temp;
	}
	return max;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string expression;
	cin >> expression;

	auto result = solution(expression);

	cout << result;
	return 0;
}
