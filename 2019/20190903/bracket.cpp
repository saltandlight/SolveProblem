#include <stdio.h>
#include <string.h>

const int MAX=60;
bool flag=false;

struct Stack{
  int capacity=0;
  int len=0;
  char data[MAX];
  
  //createStack
  void createStack(int size){
     capacity=size;
  }
  //push
  void push(char x){
    if(len >= capacity) flag=true;
    else{
      data[len++]=x;
    }
  }
  
  //pop
  void pop(){
    if(len <= 0){ 
      flag=true;
    }
    else{
      data[len--]='\0';
    }
  }
  
  //top
  char top(){
    if(len<=0){
      flag=true;
      return -1;
    }else{
      return data[len];
    }
  }
  
  //size
  int size(){
    return len;
  }
};



int main() {
  char arr[MAX];
  
  scanf("%s", arr);
  int arr_len=strlen(arr);
  
  
  Stack s1;
  s1.createStack(arr_len);
  
  for(int i=0;i<arr_len;i++){
    if(arr[i]=='('){
      s1.push('(');
      // printf("push (\n");
    }
    else{
      s1.pop();
      // printf("pop )\n");
    }
    
    if(flag==true){
      printf("NO"); return 0;
    }
  }
  
  
  //만약 다 for loop를 돌았어도 stack에 하나 이상 
  // 남아있으면 no
  if(s1.size()!=0) printf("NO");
  else printf("YES");
  
  
  
  return 0;
}