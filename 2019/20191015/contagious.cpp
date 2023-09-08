#include <stdio.h>
#include <queue>

using namespace std;

const int MAX=100001;

int n, k;
int check[MAX]={0,};
int cnt=0;

void BFS(int x){
  queue <int> Queue;
  
  Queue.push(x);
  check[x]++;
  cnt++;
  
  while(!Queue.empty()){
    int cur=Queue.front();
    Queue.pop();
    
    if(cur*2 <= n){
      if(check[cur*2]==0){
        check[cur*2]=check[cur]+1;
        Queue.push(cur*2);
        cnt++;
      }
    }
    
    if(cur/3 > 0){
      if(check[cur/3]==0){
        check[cur/3]=check[cur]+1;
        Queue.push(cur/3);
        cnt++;
      }
    }
    
    
  }
  
}

int main() {
  scanf("%d %d", &n, &k);

  BFS(k);
  
  printf("%d", n-cnt);
  return 0;
}