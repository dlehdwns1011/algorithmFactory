#include <iostream>
#include <string>
#include <vector>

using namespace std;

int checkMerge(vector<vector<int>> arr)
{
	int value = arr[0][0];
	for (int i = 0; i < arr.size(); ++i)
		for (int j = 0; j < arr[i].size(); ++j)
			if (arr[i][j] != value)
				return 3;

	return value;
}

void Divide(vector<vector<int>> arr, int& one , int& zero)
{
	int arrSize = arr[0].size();
	if (arrSize == 1)
	{
		if (arr[0][0] == 1)	one++;
		else zero++;

		return;
	}

	//0~arrSize-1 까지이다.

	// 왼쪽 위
	// x, y : 0 ~ size/2 - 1
	vector<vector<int>> leftUp;
	for (int x = 0 ; x < arrSize / 2 ; ++x)
	{
		vector<int> col;
		for (int y = 0; y < arrSize / 2; ++y)
			col.emplace_back(arr[x][y]);
		leftUp.push_back(col);
	}

	int result = checkMerge(leftUp);
	if (result == 3) //아니야
		Divide(leftUp, one, zero);
	else //맞아 
		(result == 1) ? one++ : zero++;

	// 오른쪽 위
	// x : 0 ~ size/2 - 1
	// y : size/2 ~ size - 1
	vector<vector<int>> rightUp;
	for (int x = 0; x < arrSize / 2; ++x)
	{
		vector<int> col;
		for (int y = arrSize/2; y < arrSize; ++y)
			col.emplace_back(arr[x][y]);
		rightUp.push_back(col);
	}

	result = checkMerge(rightUp);
	if (result == 3) //아니야
		Divide(rightUp, one, zero);
	else //맞아 
		(result == 1) ? one++ : zero++;

	// 왼쪽 아래
	// x : size/2 ~ size - 1
	// y : 0 ~ size/2 - 1
	vector<vector<int>> leftDown;
	for (int x = arrSize/2; x < arrSize; ++x)
	{
		vector<int> col;
		for (int y = 0; y < arrSize / 2; ++y)
			col.emplace_back(arr[x][y]);
		leftDown.push_back(col);
	}

	result = checkMerge(leftDown);
	if (result == 3) //아니야
		Divide(leftDown, one, zero);
	else //맞아 
		(result == 1) ? one++ : zero++;

	// 오른쪽 아래
	// x : size/2 ~ size - 1
	// y : size/2 ~ size - 1
	vector<vector<int>> rightDown;
	for (int x = arrSize/2; x < arrSize; ++x)
	{
		vector<int> col;
		for (int y = arrSize/2; y < arrSize; ++y)
			col.emplace_back(arr[x][y]);
		rightDown.push_back(col);
	}

	result = checkMerge(rightDown);
	if (result == 3) //아니야
		Divide(rightDown, one, zero);
	else //맞아 
		(result == 1) ? one++ : zero++;
	
}

vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer;
	int one = 0;
	int zero = 0;

	int firstCheck = checkMerge(arr);
	if (firstCheck == 3)
		Divide(arr, one, zero);
	else (firstCheck == 1) ? (one)++ : (zero)++;

	answer.emplace_back(zero);
	answer.emplace_back(one);

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	auto result = solution({ {1,1,1,1,1,1,1,1} ,{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1} ,{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1} ,{0,0,0,0,1,1,1,1} });

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";

	cout << endl;
	auto result2 = solution({ {1,1},{1,1} });

	for (int i = 0; i < result2.size(); ++i)
		cout << result2[i] << " ";
	
	return 0;
}
