#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAX=100;

int input[6]={1,2,3, 1, 2, 3};
bool check[MAX]={false,};
int n=0;
int arr[MAX];

//�Լ��� �����ؼ� �ƿ� ���� �����鼭 Ȯ���ϰ� �ؾ� �� 
//�ƴϸ� isGoodseq �Լ��� ȣ���ϴ� �Լ��� ����̸� �ǰ���...!!

//���̰� Ȧ���� �� ����! 
bool isGoodseq(int arr[], int len, int sec){
 
  if(len==1) return true;
  else if(sec == len/2 && len%2==0){
     int count=0;
    for(int i=0;i<=sec;i++){
      if(arr[i]==arr[i+sec]){
          count++;        
      }
    }
    
    if(count==len/2){
      return false;
    }
    else return true;
  }else if(sec==len/2 && len%2!=0){
     int count=0;
    for(int i=1;i<=sec;i++){
      if(arr[i]==arr[i+sec]){
        count++;
      }
    }
    
    if(count==len/2){
      return false;
    }else return true;
  }
  else{
    int count=0;
    
    for(int i=len-2*sec;i<=len-sec;i++){
      if(arr[i]==arr[i+sec]){
        count++;
      }
    }


    if(count==sec){
      return false;
    }else return isGoodseq(arr,len,sec+1);
  }
}


//1. arr�� ��¥ ���̰� n�� �ǵ��� ��� ���� �־��ִ� �Լ�
//2. Ż�� ����: n�� �� ��������.
void getArr(int x){
  int point=0;
  if(x>=n){
    
    for(int i=0;i<x;i++){
      printf("%d", arr[i]);
    }
    printf("\n11111111111111111111111\n");
  } 
  else{
    int count=0;
    for(int i=0;i<3;i++){
       arr[x]=input[i];
        count++;
        
        
       if(isGoodseq(arr,x+1,1)==true){ 
          
        printf("x:%d\n",x);
        for(int i=0;i<x;i++){
              printf("%d", arr[i]);
        }
        printf("\n");
            getArr(x+1);
            arr[x]=0;
       }else{
         printf("x:%d\n",x);
        for(int i=0;i<x;i++){
              printf("%d", arr[i]);
        }
        printf("\n");
       }
    }
    
    
  }
  
  
}


int main() {
  int s=0;
  int min=9879879;
  scanf("%d", &n);
  
  for(int i=0;i<MAX;i++) arr[i]=0;
   
   getArr(0);
 
  // for(int i=0;i<n;i++){
  //     printf("%d", arr[i]);
  // }
  
  return 0;
}