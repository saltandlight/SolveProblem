#include <stdio.h>

const int MAX=100010;

void merging(int arr[], int s1, int e1, int s2, int e2){
    int p=s1,q=s2;
    int temp[MAX];
    int inx=0;
    
    //1 2 4 6    4 6 9 10
    //         p     q
    while(p<=e1 && q<=e2){
      if(arr[p] <= arr[q])
        temp[inx++]=arr[p++];
      else 
        temp[inx++]=arr[q++];
    }
    
    if(p > e1){
      for(int i=q;i<=e2;i++){
         temp[inx++]=arr[i];
      }
    }
    if(q > e2){
      for(int i=p;i<=e1;i++){
         temp[inx++]=arr[i];
      }
    }
    
    for(int i=s1;i<=e2;i++){
      arr[i] = temp[i-s1];
      
      // printf("%d ", arr[i]);
    }
    //printf("\n");
}


//1. 기저조건
//2. 
void mergeSort(int arr[], int start, int end){
  if(start>=end) return;
  else{
     int mid=(start+end)/2;
     mergeSort(arr, start, mid);
     mergeSort(arr, mid+1, end);
     
     merging(arr, start, mid, mid+1,end);
  }
}



int main(){
  int n;
  int arr[MAX];
  
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }
  
  mergeSort(arr,0,n-1);
  
  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
  return 0;
}