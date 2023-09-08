#include <stdio.h>

const int MAX=100010;
bool check[MAX]={false, };


struct Queue{
  int data[MAX];
  int f, r;
  int capacity;
  
  //create
  void create(int size){
    capacity=size;
    f=r=0;
  }
  //push
  void push(int x){
    //queue가 꽉 차면 overflow
    if(r-f >= capacity){ 
      printf("Overflow\n");
    }
    //아니면 그냥 넣기 
    else{
      data[r]=x;
      r++;
    }
  }
  //pop
  void pop(){
    //queue가 비면
    if(r-f <=0) printf("Underflow\n");
    //아니면
    else{
      data[f++]=0;
    }
  }
  //front
  int front(){
    if(r-f <= 0){
      printf("Underflow\n");
    }
    else{
      return data[f];
    }
  }
  //size
  int size(){
    return r-f;
  }
};

int main() {
  int n, k;
  int x;
  
  scanf("%d %d", &n, &k);
 
  Queue q1;
  //n 사이즈의 큐를 만들기
  q1.create(n);

  //1. 일단 k를 푸시함 
  q1.push(k);
  check[k]=true;
  // printf("push %d\n", k);
  
  // queue 빌 때까지 돈다. 
  while(q1.size() != 0){
    //2. 팝을 일단 함 
    x=q1.front();
    q1.pop();
    // printf("pop %d\n", x);
    //3. push할 아이들 하나씩 푸시 
    int doub_x=x*2;
    if(doub_x <= n && check[doub_x]==false){
      q1.push(doub_x);
      check[doub_x]=true;
      // printf("push %d\n", doub_x);
    }
    
    int div_x=x/3;
    if(div_x > 0 && check[div_x]==false){
      q1.push(div_x);
      check[div_x]=true;
      // printf("push %d\n", div_x);
    }
  }
  
  int cnt=0;
  
  for(int i=1;i<=n;i++){
    if(check[i]==false)
      cnt++;
  }
  
  printf("%d", cnt);
  return 0;
}