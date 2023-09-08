// 우선순위 큐 구현하기

// myPQ.push(x)
// myPQ.pop()
// myPQ.top()

#include <stdio.h>

const int MAX=100;

struct priorityQueue{
  int data[MAX];
  int len=0;
  
  void push(int x){
    data[len++]=x;
  }
  
  void pop(){
    int pMax=-999999, index_max=-888;
  
    for(int i=0;i<=len;i++){
      if(pMax < data[i]){
        pMax=data[i];
        index_max=i;
      }
    }  
    
    data[index_max]=0;
    
    for(int i=index_max;i<len;i++){
      data[i]=data[i+1];
    }
    
    len--;
  }
  
  int top(){
    int pMax=-99999;
    
    for(int i=0;i<len;i++){
      if(pMax < data[i]){
        pMax=data[i];
      }
    }
    
    return pMax;
  }
};
int main(){
  priorityQueue myPQ;
  
  myPQ.push(1);
  myPQ.push(8);
  myPQ.push(7);
  myPQ.push(5);
  
  printf("%d\n", myPQ.top());  //8
  
  myPQ.pop();
  
  printf("%d\n", myPQ.top());  //7
  
  myPQ.pop();
  
  printf("%d\n", myPQ.top());  // 5
  
  myPQ.pop();
  
  printf("%d\n", myPQ.top());  // 1

  
  
  return 0;
}