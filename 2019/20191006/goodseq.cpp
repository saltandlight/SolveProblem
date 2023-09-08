#include <stdio.h>

const int MAX=90;
int arr[MAX];
int n;
int idx=0;
bool flag=false;

bool isGoodseq(int arr2[], int len){
  if(len==1) return true;
  else{
    for(int i=1;i<=len/2;i++){
      int count=0;
      for(int j=0;j<i;j++){
        if(arr2[len-1-i-j]==arr2[len-1-j]){
          count++;
        }
      }if(count==i) return false;
    }
    
    return true; 
  }
}


void getArr(int x){
 if(x>=n){
  //print arr
  for(int i=0;i<n;i++){
    printf("%d", arr[i]);
  }
  printf("\n");
  flag=true;
  return;
 }
 else{
  for(int i=1;i<=3;i++){
     arr[x]=i;
     if(isGoodseq(arr, x+1)==true && flag==false){
       getArr(x+1);  //check 해주는 함수결과가 true라면
     }
     idx=i;
   }if(idx==3) return;//3까지 했는데 안 될 때 다시 돌아가게끔 
 }
}

int main(){
  scanf("%d", &n);
  
  getArr(0);
  return 0;
}