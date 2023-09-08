//연속부분 최대합 O(n log n)



#include <stdio.h>


using namespace std;


const int MAX=100;


int n;

int data[MAX];


//재귀함수를 작성하기 위한 과정
//1. 함수를 말로 정의한다.

//2. 기저조건(Base Condition)일 때 제대로 동작하게 한다

//3. 함수가 제대로 동작한다고 가정하고 완성한다.


int getSubMax(int start, int end){
 
 //data의 start~end 구간 중 연속부분 최대합을 변환하는 함수
  
 
 if(start>=end) return data[start];
  
  
int mid=(start+end)/2;
  
  
int left=getSubMax(start,mid);
  
int right=getSubMax(mid+1,end);
  

  //중간부분을 포함하는 연속부분 중 최대합을 구하자
  
  
// 1 8 -5 3 | 2 5 -10 2
  
//       mid
 
//    6          7
  
 
int leftSum = 0, leftMax=-987987987;
  
for(int i=mid;i>=0;i--){
   
   leftSum+=data[i];
    
    
  if(leftMax < leftSum)
      leftMax=leftSum;
 
 }
  
  
int rightSum=0, rightMax=-987987987;
  
for(int i=mid+1;i<=end;i++){
    
rightSum=rightSum+data[i];
    
  
  if(rightMax < rightSum)
      
rightMax=rightSum;
  }
  
 
 int myMax=leftMax+rightMax;
  
  
 
 if(left >= right && left >= myMax) return left;
  
else if(right >= left && right >= myMax) return right;
 
 else return myMax;
  
}

int main() {
  scanf("%d", &n);
  
 
 for(int i=0;i<n;i++)
    
    scanf("%d", &data[i]);
    
  
printf("%d\n", getSubMax(0, n-1));
  
  
return 0;
 }