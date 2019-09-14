#include <stdio.h>

const long long int MAX=500010;

struct Stack{
long long int data[MAX];
long long int len=0;
long long int capacity;

//create
 void create(long long int size){
   capacity=size;
   len=0;
 }
//push
 void push(long long int x){
   if(len >= capacity) printf("Overflow\n");
   else data[len++]=x;
 }
//pop
 void pop(){
   if(len <= 0) printf("Underflow\n");
   else{
     data[len-1]=0;
     len--;
   }
 }
//top
 long long int top(){
   if(len <= 0){
     printf("Underflow\n");
     return -1;
   }else{
     return data[len-1];
   }
 }
//size
 long long int size(){
   return len;
 }
  
};

int main(){
  long long int n;
  long long int arr[MAX];
  
  scanf("%d", &n);
  
  //size : n 인 스택 만듬
  Stack s1;
  s1.create(n);
  
  for(int i=1;i<=n;i++){
    scanf("%d", &arr[i]);
    s1.push(arr[i]);  
    printf("push %d\n", arr[i]);
  }
  
  //a: arr에서 하나씩 앞으로 오는 애
  //b: 스택 팝하면서 비교하는 애 
  
  long long int a,b;
  long long int inx=n;
  long long int res_len=n;
  long long int res[MAX];
  
  a=s1.top();
  s1.pop();
  inx--;
  printf("a: %lld ", a);
  while(b!=-1){
    b=s1.top();
    printf("b: %lld\n", b);

    if(a<b){
      printf("a<b\n");
      res[res_len--]=inx;
      printf("1111111111111\n");
      for(long long int i=inx;i<res_len;i++){
        s1.push(arr[i]);
        printf("push %lld\n", arr[i]);
      }
      a=s1.top();
      printf("a: %lld ", a);
      s1.pop(); inx--;
    }else{
      printf("a >= b\n");
      s1.pop();
      inx--;
    }
    
   if(b==-1) break;
  }
  
  
  
  
  
  return 0;
}