#include <stdio.h>

const int MAX=10;

int n, r;
char result[MAX];
bool check[MAX];


void getResult(int k){
  if(k>=r){
    printf("%s\n", result);
  }
  else{
    for(int i=0;i<n;i++){
      if(check[i]==false){
        char x='a'+i;
        result[k]=x;
        check[i]=true;
        getResult(k+1);
        check[i]=false;
        result[k]='\0';
      }
    }
  }
}


int main() {
  scanf("%d %d", &n, &r);
  
  getResult(0);
  


  return 0;
}
