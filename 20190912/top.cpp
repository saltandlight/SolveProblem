#include <stdio.h>

const int MAX=500000;

struct Stack{
  long long int data[MAX];
  long long int len;
  long long int capacity;
  long long int inx;
  
  //create
  void create(long long int size){
    capacity=size;
    len=0;
  }
  //push
  void push(long long int x){
    if(len >= capacity){
      printf("Overflow\n");
    }else{
      data[len]=x;
      inx=len+1;
      len++;
    }
  }
  //pop
  void pop(){
    if(len <= 0){
      printf("Underflow\n");
    }else{
      data[len--]=0;
    }
  }
  //front
  long long int front(){
    if(len <= 0){
      printf("Underflow\n");
    }else{
      return data[len];
    }
  }
  //size
  long long int size(){
    return len;
  }
};

int main() {
  long long int n,a,b;
  long long int arr[MAX];
  long long int rec[MAX];
  
  scanf("%d", &n);

  Stack s1;
  
  s1.create(n);
  
  for(long long int i=1;i<=n;i++){
    scanf("%d", &arr[i]);
    s1.push(arr[i]);
  }
  
  long long int len2=n;
  long long int inx=n;//pop할 때마다 빼주기
  
  a=s1.front();
  s1.pop();
  inx--;
  
  // 수정하기
  while(len2!=0){
    b=s1.front();
    if(a<b){
      rec[len2--]=inx;
      s1.pop();
      a=b;
    }
    else{
      
      
    }
    
  }




  
  
  return 0;
}