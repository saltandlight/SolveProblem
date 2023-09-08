#include <stdio.h>
#include <queue>

using namespace std;

const int MAX=1010;

int arr[MAX][MAX];
int check[MAX][MAX]={0,};
int save[MAX][MAX]={0,};
int gan_x[4]={0,1,0,-1};
int gan_y[4]={1,0,-1,0};
int n, m;


/*        	    x-1,y

       x,y-1    x, y      x, y+1

	    x+1,y
*/
void BFS(int x, int y){
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       check[i][j]=0;
    }
  }
  
  
  queue <int> Queue_x;
  queue <int> Queue_y;
  
  check[x][y]=true;
  Queue_x.push(x);
  Queue_y.push(y);
  
  while(!Queue_x.empty() && !Queue_y.empty()){
    int cur_x=Queue_x.front();
    int cur_y=Queue_y.front();
    
    Queue_x.pop(); Queue_y.pop();
    
    for(int i=0;i<4;i++){
      int next_x=cur_x+gan_x[i];
      int next_y=cur_y+gan_y[i];
      
      if(next_x > -1 && next_y > -1 && next_x < n && next_y < m && check[next_x][next_y]==0){
          check[next_x][next_y]=check[cur_x][cur_y]+1;
          if( arr[next_x][next_y] == 0 ){
               Queue_x.push(next_x);
               Queue_y.push(next_y);
          }
      }//end-if
    }//end-for
    
  }//end-while
  
}

int main(){
  scanf("%d %d", &n, &m);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  BFS(n-1,0);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==1){
        save[i][j]=check[i][j];
      }
    }
  }
    
  BFS(0, m-1);
  
  int min=9999;
  int x=0;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==1 && save[i][j]!=0 && check[i][j]!=0){
        x=save[i][j]+check[i][j];
        if(min > x){
          min=x;
        }
      }
    }
  }
  
  printf("%d", min-2);
  return 0;
}