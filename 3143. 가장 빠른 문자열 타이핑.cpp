//3143. ���� ���� ���ڿ� Ÿ����
//� ���ڿ� A�� Ÿ�����Ϸ��� �Ѵ�.
//
//�׳� �� ���ھ� Ÿ���� �Ѵٸ� A�� ���̸�ŭ Ű�� ������ �� ���̴�.
//
//���⿡ �ӵ��� ���� �� ���̱� ���� � ���ڿ� B�� ����Ǿ� �־ Ű�� �ѹ� ���� ������ B��ü�� Ÿ���� �� �� �ִ�.
//
//�̹� Ÿ���� �� ���ڸ� ����� ���� �Ұ����ϴ�.
//
//���� ��� A = ��asakusa��, B = ��sa���� ��, ���� �׸��� ���� B�� �� �� ����ϸ� 5�� ���� A�� Ÿ���� �� �� �ִ�.
//
//
//
//A�� B�� �־��� �� A ��ü�� Ÿ���� �ϱ� ���� Ű�� ������ �ϴ� Ƚ���� �ּڰ��� ���Ͽ���.
//
//
//[�Է�]
//
//ù ��° �ٿ� �׽�Ʈ ���̽��� �� T�� �־�����.
//
//�� �׽�Ʈ ���̽����� ù ��° �ٿ� �� ���ڿ� A, B�� �־�����.A�� ���̴� 1�̻� 10, 000����, B�� ���̴� 1�̻� 100�����̴�.
//
//
//[���]
//
//�� �׽�Ʈ ���̽����� A ��ü�� Ÿ���� �ϱ� ���� Ű�� ������ �ϴ� Ƚ���� �ּڰ��� ����Ѵ�.
//

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testnum = 0;
	cin >> testnum;

	
	for (int test = 0; test < testnum; ++test)
	{
		string a = "";
		string b = "";
		cin >> a;
		cin >> b;
		int result = 0;

		while (1)
		{
			int findindex = a.find(b);
			if (findindex == -1)
				break;

			++result;
			a.erase(a.begin() + findindex, a.begin() + findindex + b.size());
		}
		cout << "#" << test + 1 << " " << result + a.size() << "\n";
	}

	return 0;
}
