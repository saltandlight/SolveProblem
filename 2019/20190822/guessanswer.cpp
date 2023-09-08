#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const long long int MAX=10000000;
long long int n;
long long int y;


long long int gety(long long int x){
  return x*(x+1);
}

bool check(long long int x){
  y=gety(x);
  if(y>=n){
    return true;
  }
  else{ 
    return false;
    
  }
}


int main(){
  scanf("%lld", &n);
  
 
  
  long long int start=1;
  long long int end=(long long int)sqrt(n)+1;
  
  // if(start+1==end){
  //   printf("0");
  //   return 0;
  // }
  
  if(check(start)){
    if(n==start){
      printf("0");
      return 0;
    }
    printf("1\n"); 
    return 0;
  }
  if(!check(end)){
    printf("%d\n",end); return 0;
  }
  
  while(start+1<end){
    int mid=(start+end)/2;
  //  printf("start:%d end:%d\n", start, end);
    if(check(mid)){
      end=mid;
    }else start=mid;
     
  }
  
  // if(n==arr[start]) printf("%d", start);
  // else if(n==arr[end]) printf("%d", end);
  // else printf("%d", start);
  if(n==gety(start)) printf("%d", start);
  else if(n==gety(end)) printf("%d", end);
  else printf("%d", start);  
  return 0;
}