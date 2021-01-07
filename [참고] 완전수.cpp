#include <iostream>

using namespace std;
//범위 내에서 완전수를 구하는 프로그램
int main()
{
	int sum=0,a=0,f; //declare
	int arr[100];
	
	cout<<"1부터 10000까지의 완전수 : "<<endl;
	for(int i=1;i<=10000;i++) //0부터 10000까지의 진행
	{
		sum=0;
		a=0;
		for(int j=1;j<i;j++)
		{
			if(i%j==0){ //약수를 찾는 과정.
				arr[a]=j;
				a++;
				sum+= j;}  //입력한 수의 약수를 찾으면 그 값들을 더함.
		}
		f=a;
		if(sum==i){ //입력된수의 소수(자기를제외)합과 입력된수가 같다면
			for(a=0;a<f;a++)
			{
				if(a!=f-1){
					cout<<arr[a]<<"+";}
				if(a==f-1){
					cout<<arr[a];}
			}
			cout<<" = "<<i<<endl; //그 수는 완전수.
				
		}
	}

}

