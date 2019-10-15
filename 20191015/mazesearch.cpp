#include <stdio.h>
#include <queue>

using namespace std;

const int MAX=1010;

int n, m;
int arr[MAX][MAX];
int gan_x[4]={0,1,0,-1};
int gan_y[4]={1,0,-1,0};


void BFS(int x, int y){
  int goal_x=0;
  int goal_y=m-1;
  
  int check[MAX][MAX]={0,};
  queue <int> Queue_x;
  queue <int> Queue_y;
  
  Queue_x.push(x);
  Queue_y.push(y);
  check[x][y]=true;
  
  while(!Queue_x.empty() && !Queue_y.empty()){
    int cur_x=Queue_x.front();
    int cur_y=Queue_y.front();
    if(cur_x==goal_x && cur_y==goal_y){
        break;
    }
    
    Queue_x.pop();
    Queue_y.pop();
    
    for(int i=0;i<4;i++){
      int new_x=cur_x+gan_x[i];
      int new_y=cur_y+gan_y[i];
      
     
      if(new_x>-1 && new_y>-1 && new_x<n && new_y <m && check[new_x][new_y]==0 && arr[new_x][new_y]==0){
        check[new_x][new_y]=check[cur_x][cur_y]+1; //여기에 거리를 
        Queue_x.push(new_x);
        Queue_y.push(new_y);
      }
    }
    
  }
  printf("%d", check[goal_x][goal_y]-1);
}


int main() {

  scanf("%d %d", &n, &m);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d", &arr[i][j]);
    }
  }

  BFS(n-1,0);
  
  return 0;
}