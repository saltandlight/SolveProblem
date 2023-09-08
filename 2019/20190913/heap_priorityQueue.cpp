// 우선순위 큐 구현하기(힙)

#include <stdio.h>

const int MAX=100;

//         1
//     2       7
//   3   8    9  10
// 4

struct PriorityQueue{
  
  int data[MAX];
  //원소의 맨 끝을 가리킴
  int len=1;
  
  //       0 1 2 3 4 5 6 7
  //  data
  
  void push(int x){
    data[len++]=x;
    int inx=len-1;//방금 막 넣은 아이
    
    while(index>1){
      if(data[inx] < data[inx/2]){
        int temp=data[inx];
        data[inx]=data[inx/2];
        data[inx/2]=temp;
      }else{
        break;
        
      }
      
      inx=inx/2;
    }
    
  }
  void pop(){
    data[1]=data[len-1];
    data[len-1]=0;
    len--;
    
    int inx=1;
    
    while(1){
      //1. 자식들 중에서 우선순위가 높은 친구 알아내야 함.
      //2. 나와 그 우선순위가 높은 친구를 비교해서 자리를 바꾸어야 함.
      
      int pInx=-1; //우선순위가 높은 친구의 노드번호
      
      // (A) 자식이 모두 없는 경우
      // (B) 왼쪽 자식만 존재하는 경우
      // (C) 왼쪽 오른쪽 자식이 모두 존재하는 경우
      if(inx*2 >= len){ //(A)
        break;
      }
      
      else if((1 <= inx*2 && inx*2 < len) && len <= inx*2+1){
        //(B)
        pInx=inx*2;
      }
      else{
        if(data[inx*2] < data[inx*2+1]){
          pInx=inx*2;
        }else{
          pInx=inx*2+1;
        }
      }
      
      
      if(data[inx] > data[pInx]){
        int temp=data[inx];
        data[inx]=data[pInx];
        data[pInx]=temp;
        
        inx=pInx;
      }else{
        break;
      }
    }
  }
  int top(){
    return data[1];
  }
  
  
};
int main() {
  PriorityQueue myPQ;
  
  myPQ.push(1);
  myPQ.push(2);
  myPQ.push(3);


  
  printf("%d\n", myPQ.top());
  myPQ.pop();

  printf("%d\n", myPQ.top());
  myPQ.pop();
  
  printf("%d\n", myPQ.top());
  myPQ.pop();
  return 0;
}