#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void Random(int *arr,int * m,int p)
{
   int rand_num;
   int num;
   printf("input the length of the list : "); //위 문장을 출력
   scanf("%d",&num); //유저가 입력한 값을 n의 값으로
   *m=num;
   printf("Generated random list : "); //위 문장을 출력
   for(p=0;p<*m;p++)//p를0으로 초기화하고 p가 n보다 작으면 실행, 그 후 p에 +1
   {
      rand_num=rand()%100;//0~99까지의 난수 생성
      *(arr+p)=rand_num;//생성된 난수를 (arr+p)의 값으로 
      printf(" %d ",*(arr+p));//생성된 난수를 출력
   }
   printf("\n");//한 줄 내리기
}
void Ascending(int *arr,int a)//메인함수에서 받은전달인자를 각각 *arr과 a로 받음
{//오름차순 정리 함수
   int i,j; //i와 j를 선언
   int temp=0; //temp를 0으로 선언

   for(j=0;j<a-1;j++)//j=0부터 1씩 증가해서 a-2까지 반복
      {
         for(i=0;i<a-1;i++)//i=0 부터 1씩 증가해서 a-2까지 반복
         {
            if(*(arr+i)>*(arr+i+1))//*(arr+i)가 *(arr+i+1)보다 클때
               {
                  temp=*(arr+i);//temp에 *(arr+i)값을 입력
                  *(arr+i)=*(arr+i+1);//*(arr+i)에 *(arr+i+1)값을 입력
                  *(arr+i+1)=temp;//*(arr+i+1)값에 temp값을 입력
            }
         }   
         printf("Step %d : ",j+1);//Step 을 for문으로 1부터 a-1까지 반복
                  
            for(i=0;i<a;i++)//i=0에서 a-1까지 1씩 증가//크기가a인 arr 출력
                  printf("%d ",*(arr+i));//*(arr+i)를 출력 
               printf("\n");
         }
}
void Descending(int *arr,int a)//메인함수에서 받은 전달인자를 각각 *arr과 a로 받음
{//내림차순 정리 함수
   int i,j,temp=0; //i와 j를 선언 temp를 0으로 선언
      for(j=0;j<a-1;j++)//j=0부터 1씩 증가해서 a-2까지 반복
      {
         for(i=0;i<a-1;i++)//i=0 부터 1씩 증가해서 a-2까지 반복
         {
            if(*(arr+i)<*(arr+i+1))//*(arr+i)가 *(arr+i+1)보다 클때
            {
                  temp=*(arr+i);//temp에 *(arr+i)값을 입력
                  *(arr+i)=*(arr+i+1);//*(arr+i)에 *(arr+i+1)값을 입력
                  *(arr+i+1)=temp;//(arr+i+1)값에 temp값을 입력
            }//end if
         }//end for
         printf("Step %d : ",j+1);//Step 을 for문으로 1부터 a-1까지 반복
                  
            for(i=0;i<a;i++)//i=0에서 a-1까지 +1씩 증가//크기가a인 arr 출력
                  printf("%d ",arr[i]);//*(arr+i)를 출력 
               printf("\n");//한 줄 내림
      }//end for

}
int main(void)
{//메인함수
   int ary[100]; //열이 100인 배열
   int n=0; 
   int i=0;
   int choice = 0;
   int count = 0;  //n=0,i,rand_num,choice=0,count=0를 각각 선언
   srand((unsigned int)time(NULL));//난수 발생
   while(1)//무한반복
   { 
      printf("\n-- MENU --\n");
      printf("1. Random List Generation\n2. Bubble Sort in Ascending Order\n3. Bubble Sort in Descending Order\n4. Exit\n");
      printf("Choose the item : "); //각 문장들을 출력
      scanf("%d",&choice); //유저가 입력한 값을 choice의 값으로
      if(count==0 &&choice==2||count==0&&choice==3) //count가 0이거나 2이면 또 count가 0이거나 3이면 실행
         printf("Error : list is not found \n"); // 위 문장을 출력
      else //위의 조건과 맞지 않으면
      {
      
         switch(choice)//choice의 값에 따라 실행이 달라짐
         {
         case 1 : //choice가 1이면 실행
            Random(ary,&n,i);
            break;//종료
         case 2 : //choice가 2이면 실행
            Ascending(ary,n); // Ascending함수 실행
            break;//종료
         case 3 : //choice가 3이면 실행
            Descending(ary,n); //Descending함수 실행
            break;//종료
         case 4 : //choice가 4이면 실행
            printf("Exit\n");//Exit을 출력과 한 줄 내림
            return 0;

         }//end switch
      }//end else
      count++;//count에 +1
   }//end while
}//end main