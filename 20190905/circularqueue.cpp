//큐 구현하기 (Queue)

// Q.create(y)
// Q.push(y)
// Q.pop()
// Q.front()
// Q.size()

#include <stdio.h>

const int MAX = 10;

struct Queue{
  //        0 1 2 3 4 5 6 7
  // data   0 0 0 0 0 0 0 0 
  //        f
  //            r
  
  int data[MAX];
  int f, r;
  int capacity;
  int numElement;

  
  void create(int y){
    capacity=y;
    f=0;
    r=0;
    numElement=0;
  }
  
  void push(int y){
    if(numElement >= capacity){
      printf("Queue overflow\n");
    }else{
      data[r] = y;
      
      r=(r+1) % MAX;
      
      numElement++;
    }
  }
  
  void pop(){
    if(numElement <= 0){
      printf("Queue underflow\n");
    }
    else{
      data[f]=0;    
      f=(f+1) % MAX;
      
      numElement--;
    }
  }
  
  int front(){
    //큐의 맨 앞에 있는 원소 반환
    //단, 반환할 것이 없다면 -1을 반반환할
    if(numElement <= 0){
      return -1;
    }else{
      return data[f];  
    }
  }
  
  int size(){
    return numElement;
  }
};

int main() {
  Queue q1;
  
  q1.create(4);
  
  for(int i=0;i<10000;i++){
    q1.push(i);
    q1.push(i+1);
    q1.push(i+2);
    q1.push(i+3);
    
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();

  }
  
  q1.push(1);
  q1.push(2);
  
  printf("%d\n", q1.front()); //1

  q1.pop();

  printf("%d\n", q1.front()); //2

  return 0;
}