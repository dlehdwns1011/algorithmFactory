using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	int before = -1;

	for (int i : arr)
	{
		if (i != before)
			answer.push_back(i);
		before = i;
	}

	return answer;
}
