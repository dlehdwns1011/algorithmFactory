#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void Random(int *arr,int * m,int p)
{
   int rand_num;
   int num;
   printf("input the length of the list : "); //�� ������ ���
   scanf("%d",&num); //������ �Է��� ���� n�� ������
   *m=num;
   printf("Generated random list : "); //�� ������ ���
   for(p=0;p<*m;p++)//p��0���� �ʱ�ȭ�ϰ� p�� n���� ������ ����, �� �� p�� +1
   {
      rand_num=rand()%100;//0~99������ ���� ����
      *(arr+p)=rand_num;//������ ������ (arr+p)�� ������ 
      printf(" %d ",*(arr+p));//������ ������ ���
   }
   printf("\n");//�� �� ������
}
void Ascending(int *arr,int a)//�����Լ����� �����������ڸ� ���� *arr�� a�� ����
{//�������� ���� �Լ�
   int i,j; //i�� j�� ����
   int temp=0; //temp�� 0���� ����

   for(j=0;j<a-1;j++)//j=0���� 1�� �����ؼ� a-2���� �ݺ�
      {
         for(i=0;i<a-1;i++)//i=0 ���� 1�� �����ؼ� a-2���� �ݺ�
         {
            if(*(arr+i)>*(arr+i+1))//*(arr+i)�� *(arr+i+1)���� Ŭ��
               {
                  temp=*(arr+i);//temp�� *(arr+i)���� �Է�
                  *(arr+i)=*(arr+i+1);//*(arr+i)�� *(arr+i+1)���� �Է�
                  *(arr+i+1)=temp;//*(arr+i+1)���� temp���� �Է�
            }
         }   
         printf("Step %d : ",j+1);//Step �� for������ 1���� a-1���� �ݺ�
                  
            for(i=0;i<a;i++)//i=0���� a-1���� 1�� ����//ũ�Ⱑa�� arr ���
                  printf("%d ",*(arr+i));//*(arr+i)�� ��� 
               printf("\n");
         }
}
void Descending(int *arr,int a)//�����Լ����� ���� �������ڸ� ���� *arr�� a�� ����
{//�������� ���� �Լ�
   int i,j,temp=0; //i�� j�� ���� temp�� 0���� ����
      for(j=0;j<a-1;j++)//j=0���� 1�� �����ؼ� a-2���� �ݺ�
      {
         for(i=0;i<a-1;i++)//i=0 ���� 1�� �����ؼ� a-2���� �ݺ�
         {
            if(*(arr+i)<*(arr+i+1))//*(arr+i)�� *(arr+i+1)���� Ŭ��
            {
                  temp=*(arr+i);//temp�� *(arr+i)���� �Է�
                  *(arr+i)=*(arr+i+1);//*(arr+i)�� *(arr+i+1)���� �Է�
                  *(arr+i+1)=temp;//(arr+i+1)���� temp���� �Է�
            }//end if
         }//end for
         printf("Step %d : ",j+1);//Step �� for������ 1���� a-1���� �ݺ�
                  
            for(i=0;i<a;i++)//i=0���� a-1���� +1�� ����//ũ�Ⱑa�� arr ���
                  printf("%d ",arr[i]);//*(arr+i)�� ��� 
               printf("\n");//�� �� ����
      }//end for

}
int main(void)
{//�����Լ�
   int ary[100]; //���� 100�� �迭
   int n=0; 
   int i=0;
   int choice = 0;
   int count = 0;  //n=0,i,rand_num,choice=0,count=0�� ���� ����
   srand((unsigned int)time(NULL));//���� �߻�
   while(1)//���ѹݺ�
   { 
      printf("\n-- MENU --\n");
      printf("1. Random List Generation\n2. Bubble Sort in Ascending Order\n3. Bubble Sort in Descending Order\n4. Exit\n");
      printf("Choose the item : "); //�� ������� ���
      scanf("%d",&choice); //������ �Է��� ���� choice�� ������
      if(count==0 &&choice==2||count==0&&choice==3) //count�� 0�̰ų� 2�̸� �� count�� 0�̰ų� 3�̸� ����
         printf("Error : list is not found \n"); // �� ������ ���
      else //���� ���ǰ� ���� ������
      {
      
         switch(choice)//choice�� ���� ���� ������ �޶���
         {
         case 1 : //choice�� 1�̸� ����
            Random(ary,&n,i);
            break;//����
         case 2 : //choice�� 2�̸� ����
            Ascending(ary,n); // Ascending�Լ� ����
            break;//����
         case 3 : //choice�� 3�̸� ����
            Descending(ary,n); //Descending�Լ� ����
            break;//����
         case 4 : //choice�� 4�̸� ����
            printf("Exit\n");//Exit�� ��°� �� �� ����
            return 0;

         }//end switch
      }//end else
      count++;//count�� +1
   }//end while
}//end main