#include <stdio.h>
#include <vector>

using namespace std;

const int MAX=1010;
vector <int> myGraph[MAX];
bool check[MAX]={0,};
int cnt=0;
int v, e;

void DFS(int x){
  if(check[x]==true) return;
  check[x]=true; 
  for(int i=0;i<myGraph[x].size();i++){
    int y=myGraph[x][i];
    
    if(check[y]==false){
      DFS(y);
    }
  }//end-for
  
}

int main() {
  v=e=0;
  scanf("%d %d", &v,&e);
  
  for(int i=0;i<e;i++){
    int a, b;
    
    scanf("%d %d", &a,&b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  for(int i=1;i<=v;i++){
    if(check[i]==false){
      DFS(i);
      cnt++;
    }
    
  }
  
  printf("%d", cnt);
  return 0;
}