#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX=100;

vector <int> myGraph[MAX];
int n, m;

void BFS(){
  queue <int> Queue;
  bool check[MAX]={0,};
  
  Queue.push(1);
  check[1]=true;

  
  while(!Queue.empty()){
    int current=Queue.front();
    Queue.pop();
    printf("%d ", current);
    
    for(int i=0;i<myGraph[current].size();i++){
      int x=myGraph[current][i];
      
      if(check[x]==false){
         Queue.push(x);
         check[x]=true;
      }
      
    }
  }
  
}

int main(){
  scanf("%d %d", &n,&m);
  
  for(int i=0;i<m;i++){
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  BFS();
  return 0;
}