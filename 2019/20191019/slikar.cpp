#include <stdio.h>
#include <queue>

using namespace std;

const int MAX=55;
char arr[MAX][MAX];
int gan_x[4]={-1,1,0,0};
int gan_y[4]={0,0,1,-1};
int check_water[MAX][MAX]={0,};
int check_go[MAX][MAX]={0,};
int r, c;

void waterBFS(){
  bool flag=false; 
  queue <int> Queue_x;
  queue <int> Queue_y;
  
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(arr[i][j]=='*'){ //현재 좌표 
        Queue_x.push(i); Queue_y.push(j);
        check_water[i][j]++;
      }  
      
     
        while(!Queue_x.empty() && !Queue_y.empty()){
          int cur_x=Queue_x.front();
          int cur_y=Queue_y.front();
          
          Queue_x.pop(); Queue_y.pop();
        
          for(int m=0;m<4;m++){
            int new_x=cur_x+gan_x[m]; int new_y=cur_y+gan_y[m];
            if(new_x >-1 && new_y > -1 && new_x < r && new_y < c && arr[new_x][new_y]!='D' && arr[new_x][new_y] != 'X' && check_water[new_x][new_y]==0){
                // printf("%d %d\n", new_x, new_y);
                Queue_x.push(new_x); Queue_y.push(new_y);
                check_water[new_x][new_y]=check_water[cur_x][cur_y]+1;
                    
                
            }//end-if
          }//end-for
      
          
        }  
         //확인하는 애 
  
      }//end-if
    }
  }//end-for
  
void slikarBFS(){
  
  queue <int> Go_x;
  queue <int> Go_y;
  
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(arr[i][j]=='S'){
        Go_x.push(i); Go_y.push(j);
        check_go[i][j]++;
      }
      
   
      while(!Go_x.empty() && !Go_y.empty()){
         
          int cgo_x=Go_x.front(); 
          int cgo_y=Go_y.front();
          Go_x.pop(); 
          Go_y.pop();
          
          for(int n=0;n<4;n++){
            int ngo_x=cgo_x+gan_x[n];
            int ngo_y=cgo_y+gan_y[n];
            if(ngo_x > -1 && ngo_y >-1 && ngo_x < r && ngo_y < c && check_go[ngo_x][ngo_y]==0 && arr[ngo_x][ngo_y]=='.'){
                   Go_x.push(ngo_x); Go_y.push(ngo_y);
                   check_go[ngo_x][ngo_y]=check_go[cgo_x][cgo_y]+1;
            }
          }
      }
      
      
    } //end-for 
  }//end-for'
  
  
}
 
  
  




int main() {
  int goal_x, goal_y;
  
  scanf("%d %d", &r, &c);
  
  for(int i=0;i<r;i++){
    scanf("%s", &arr[i]);
  }
  
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(arr[i][j]=='D'){
        goal_x=i;
        goal_y=j;
      }
    }
  }
  
  
  waterBFS();
  slikarBFS();
  
  
  int min = 99999;
  
  bool flag=false;
  for(int i=0;i<4;i++){
    int n_goalx=goal_x+gan_x[i]; int n_goaly=goal_y+gan_y[i];
    if(n_goalx > -1 && n_goaly > -1 && n_goalx < r && n_goaly < c && arr[n_goalx][n_goaly]!='X' ){
       //check_Water는 0인데 check_go가 0이 아닐 떄 도 잡아줘야 됨
       if(check_go[n_goalx][n_goaly] < check_water[n_goalx][n_goaly] || (check_water[n_goalx][n_goaly]==0 && check_go[n_goalx][n_goaly]!=0)){
        
         if(min > check_go[n_goalx][n_goaly] && check_go[n_goalx][n_goaly]!=0){
            min=check_go[n_goalx][n_goaly];
            flag=true;
         }
          
           // break;
       }
    }//end-if
  }
  
  
  if(flag==false) printf("KAKTUS");
  else printf("%d", min);
  return 0;
}