#include <stdio.h>

const int MAX=1000;

struct Tree{
  int child[MAX];
  int inx=0;
  int root;
  
  void push(int x){
    child[inx++]=x;
  }
  
};
int main() {
  int n,x,y;
  int a,b;
  int v;
  int len1=0;
  int len2=0;
  int result1[MAX];
  int result2[MAX];
  
  Tree tree[MAX];
  
  scanf("%d %d %d", &n,&x,&y);
  
  for(int i=1;i<n;i++){
    scanf("%d %d", &a,&b);
    
    tree[a].push(b);
  }

  if(x==0 || y==0){
    printf("0");
    return 0;
  }
  v=x;
  bool flag1=false;
  
 int cnt=3;
 
   while(v!=0){
    for(int i=0;i<n;i++){
      for(int j=0;j<tree[i].inx;j++){
        if(tree[i].child[j] == v){
          // printf("v: %d\n", v);
          result1[len1++]=i;
          v=i;
          flag1=true;
          break;
        }
       }
    }  
  }//endwhile
  
  
  
  v=y;
  while(v!=0){
    for(int i=0;i<n;i++){
      for(int j=0;j<tree[i].inx;j++){
        if(tree[i].child[j] == v){
          // printf("v: %d\n", v);
          result2[len2++]=i;
          v=i;
          flag1=true;
          break;
        }
       }
    }  
  }//endwhile
  
    
  for(int i=0;i<len1;i++){
    for(int j=0;j<len2;j++){
      if(result1[i]==result2[j]){
        printf("%d", result1[i]);
        return 0;
      }
    }
  }  
    
  return 0;
}
