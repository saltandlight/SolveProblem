#include <stdio.h>

const int MAX = 105;
int n, r;
char result[MAX];
bool check[MAX];

void getResult(int x){
  if(x>=r){
    //print result 
      printf("%s\n", result);
  }else{
    for(int i=0;i<n;i++){
      char alpha=i+'a';
      if(check[i]==false){
        result[x]=alpha;
        check[i]=true;
        getResult(x+1);
        check[i]=false;
        result[x]=0;
      }
    }//end-for
  }//end else
}

int main() {
 //n개의 원소, r개만 뽑기(for)
 scanf("%d %d", &n, &r);
 getResult(0);
 
 
  
  return 0;
}