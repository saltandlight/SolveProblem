#include <stdio.h>
#include <queue>

using namespace std;

const int MAX=30;

int arr[MAX][MAX];
int check[MAX][MAX]={0,};
int gan_x[4]={0,1,0,-1};
int gan_y[4]={1,0,-1,0};
int danji[MAX]={0,};
int idx=0;
int n;

void BFS(int x, int y){
  

  queue <int> Queue_x;
  queue <int> Queue_y;
  
  int length=0;
  check[x][y]++;
  Queue_x.push(x);
  Queue_y.push(y);
  
  while(!Queue_x.empty() && !Queue_y.empty()){
    int cur_x=Queue_x.front();
    int cur_y=Queue_y.front();
    length++;
    Queue_x.pop();
    Queue_y.pop();
    
    for(int i=0;i<4;i++){
      int next_x=cur_x+gan_x[i];
      int next_y=cur_y+gan_y[i];
      
      if(next_x>-1 && next_y >-1 && next_x<n && next_y<n && check[next_x][next_y]==0 && arr[next_x][next_y]==1){
        check[next_x][next_y]=check[cur_x][cur_y]+1;
        Queue_x.push(next_x);
        Queue_y.push(next_y);
      }
    }
    
   
  }//end while
   danji[idx++]=length;
}

int main() {
  int cnt=0;
  
  scanf("%d", &n);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%1d", &arr[i][j]);
      // printf("%d %d %d   ", i,j,arr[i][j]);
    }
  }
 
 
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(arr[i][j]==1 && check[i][j]==0){
        BFS(i, j);
        cnt++;
      }
    }
  }
  
  for(int i=0;i<idx;i++){
    for(int j=0;j<idx;j++){
      if(danji[i]<danji[j]){
        int temp=danji[i];
        danji[i]=danji[j];
        danji[j]=temp;
      }
    }
  }
  
  printf("%d\n", cnt);
  
  for(int i=0;i<idx;i++){
    printf("%d\n", danji[i]);
  }
  
  
  return 0;
}