#include <stdio.h>
#include <queue>

using namespace std;

const int MAX=100000;
queue <int> Queue;
int check[MAX]={0,};
int n;

void BFS(int x){
  
  Queue.push(x);
  check[x]++;
  
  while(!Queue.empty()){
    int cur=Queue.front();
    Queue.pop();
 
    if(cur==n){
      printf("%d", check[cur]-1);
      break;
    }
    
    if(cur*2 < MAX){
      if(check[cur*2]==0){
        Queue.push(cur*2);
        check[cur*2]=check[cur]+1;
      }
    }
    if(cur/3!=0 && check[cur/3]==0){
      Queue.push(cur/3);
      check[cur/3]=check[cur]+1;
    }
  }//end-while
  
}
int main() {
  scanf("%d", &n);
  
  BFS(1);
  return 0;
}