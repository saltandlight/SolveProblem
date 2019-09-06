#include <stdio.h>

const int MAX = 1000000;
int n;
long long int m, H;
long long int tree[MAX];
long long int result[MAX];


bool check(long long int height){
  //tree배열에서 height를 다 각각 빼주고 그의 합...!
  long long int sum=0;
  for(int i=0;i<n;i++){
    if(tree[i] > height){
      result[i]=tree[i]-height;
      sum += result[i];
    }else{
      result[i]=0;
    }
  }
  
  //for(int i=0;i<n;i++) printf("%d ", result[i]);
  //printf("sum: %d\n", sum);
  if(sum < m){ 
      return true;
  }
  
  return false;
}

int main() {

  //1. N, M, tree입력받기
  scanf("%d %lld", &n, &m);
  for(int i=0;i<n;i++) scanf("%lld", &tree[i]);
  
  //start와 end를 min, max로 고정
  long long int min=10000000000;
  long long int max=tree[0];
  
  for(int i=0;i<n;i++){
    if(min > tree[i]) min=tree[i];
    if(max < tree[i]) max=tree[i];
  }
  
  long long int start=min;
  long long int end=max;
  
  if(check(start)){
    //printf("%d\n", start);
    return 0;
  } 
  if(!check(end)){
   // printf("%d\n", end);
    return 0;
  }
  // 5 6 7 8 9 10 11
  // s     m       e
  // x x o o o o o o
  // s     e  
  // x x x x x x o o
  // s     m       e
  //       s       e
  while(start+1 < end){
    int mid=(start+end)/2;
    //printf("start:%d mid:%d end:%d\n", start, mid, end);

    if(check(mid)==true){
      end=mid;
    }else{
      start=mid;
    }
  }
  
  printf("%d",start);
  return 0;
}