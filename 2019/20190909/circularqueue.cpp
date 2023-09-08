# include <stdio.h>

const int MAX=1010;

struct Queue{
  int data[MAX];
  int capacity=0;
  int r, f;
  
  //create
  void create(int s){
    capacity=s;
    r=0;
    f=0;
  }
  //push
  void push(int x){
    if(r-f >= capacity){
      //꽉 차있다면
      printf("Overflow\n");
    }
    // else if(r >= capacity){
    //   printf("Overflow\n");
    // }
    
    else{
      data[r]=x;
      r=(r+1) % MAX;
    }
  }
  //pop
  void pop(){
    if(r-f <= 0){
      printf("Underflow\n");
    }
    // else if(f>= capacity){
    //   printf("Underflow\n");
    // }
    else{
      data[f]=0;
      f=(f+1) % MAX;
    }
  }
  //front
  int front(){
    if(r-f<=0){
      printf("NULL\n");
      return -1;
    }else{
      return data[f];
    }
  }
  //size
  int size(){
    return r-f;
  }
};



int main(){
  int n, m, opt, opr, x;
  
  scanf("%d %d", &n, &m);
  
  
  Queue q1;
  q1.create(n);
  
  for(int i=0;i < m;i++){
    scanf("%d", &opt);
    switch(opt){
      case 1: scanf("%d", &opr);
              q1.push(opr);    
              break;
      case 2: q1.pop();
              break;
      case 3: x=q1.front();
            if(x!=-1){
               printf("%d\n", x);
             }
            break;
      }
  }
  return 0;
}