#include <iostream>

using namespace std;
//���� ������ �������� ���ϴ� ���α׷�
int main()
{
	int sum=0,a=0,f; //declare
	int arr[100];
	
	cout<<"1���� 10000������ ������ : "<<endl;
	for(int i=1;i<=10000;i++) //0���� 10000������ ����
	{
		sum=0;
		a=0;
		for(int j=1;j<i;j++)
		{
			if(i%j==0){ //����� ã�� ����.
				arr[a]=j;
				a++;
				sum+= j;}  //�Է��� ���� ����� ã���� �� ������ ����.
		}
		f=a;
		if(sum==i){ //�Էµȼ��� �Ҽ�(�ڱ⸦����)�հ� �Էµȼ��� ���ٸ�
			for(a=0;a<f;a++)
			{
				if(a!=f-1){
					cout<<arr[a]<<"+";}
				if(a==f-1){
					cout<<arr[a];}
			}
			cout<<" = "<<i<<endl; //�� ���� ������.
				
		}
	}

}

