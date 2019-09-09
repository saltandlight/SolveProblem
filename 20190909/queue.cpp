#include <stdio.h>

const int MAX = 1000;
struct Queue{
  //        0 1 2 3 4 5 6 7
  // data   0 0 0 0 0 0 0 0 
  //        f
  //            r
  
  int data[MAX];
  int f, r;
  int capacity;
  
  void create(int y){
    capacity=y;
    f=0;
    r=0;
  }
  
  void push(int y){
    if(r-f >= capacity){
      printf("Overflow\n");
    }else if(r == capacity){
      printf("Overflow\n");
    }
    else{
      data[r++]=y;
    }
  }
  
  void pop(){
    if(r-f <= 0 ){
      printf("Underflow\n");
    }
    else if(f == capacity) printf("Underflow\n");
    else{
      data[f]=0;    
      f++;
    }
  }
  
  int front(){
    //큐의 맨 앞에 있는 원소 반환
    //단, 반환할 것이 없다면 -1을 반반환할
    if(r-f <= 0){
      printf("NULL\n");
      return -1;
    }else{
      return data[f];  
    }
  }
  
  int size(){
    return r-f;
  }
};


int main(){
  int n, m;
  int opt, opr;
  int x;
  Queue q1;
  
  scanf("%d %d", &n, &m);
  
  q1.create(n);
  
  for(int i=0;i<m;i++){
    scanf("%d", &opt);
    switch(opt){
      case 1: //push x
        scanf("%d", &opr);
        q1.push(opr);
        break;
      case 2: //pop
        q1.pop();
        break;
      case 3: //front
        x=q1.front();
        if(x==-1){ 
          break;
        }else{
          printf("%d\n", x);
        }
        break;
    }
  }
  return 0;
}