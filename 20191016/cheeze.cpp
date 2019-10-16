#include <stdio.h>
#include <queue>

using namespace std;

const int MAX=100;
int check[MAX][MAX]={0,};
int arr[MAX][MAX]={0,};
int gan_x[4]={0,1,0,-1};
int gan_y[4]={1,0,-1,0};
int n, m;


void BFS(int x, int y){
  
  queue <int> Queue_x;
  queue <int> Queue_y;
  
  check[x][y]=true;
  Queue_x.push(x);
  Queue_y.push(y);
  
  while(!Queue_x.empty() && !Queue_y.empty()){
    int cur_x=Queue_x.front();
    int cur_y=Queue_y.front();
    
    Queue_x.pop();
    Queue_y.pop();
    
    for(int i=0;i<4;i++){
      int next_x=x+gan_x[i];
      int next_y=y+gan_y[i];
    
      if(next_x>-1 && next_y>=1 && next_x < n && next_y <m && check[next_x][next_y]==0){
         
      }
    }//end-for
    
  }//end-while
  
  
}



int main() {
  scanf("%d %d", &n, &m);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==1){
        BFS(i,j);
      }
    }
  }
  return 0;
}