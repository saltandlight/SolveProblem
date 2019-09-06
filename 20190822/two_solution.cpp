#include <stdio.h>
#include <stdlib.h>

const int MAX = 100005;
int left, right, sum, prev;
int s_inx=0;
int min=1000000;
 int x, y;
void merging(int arr[], int s1, int e1, int s2, int e2){
 int p=s1, q=s2;
 int temp[MAX];
 int inx=0;

 while(p<=e1 && q<=e2){
   //1 2 4 6     3 5 6 9
   //      p       q
   //temp
   //1 2 3 4 
   if(arr[p] <= arr[q]){
     temp[inx++]=arr[p++];
   }
   else{
     temp[inx++]=arr[q++];
   }
   
 }
 
 if(p > e1){
   while(q<=e2){
     temp[inx++]=arr[q++];
   }
 }
 if(q > e2){
   while(p<=e1){
     temp[inx++]=arr[p++];
   }
 }
 
 for(int i=s1;i<=e2;i++){
   arr[i]=temp[i-s1];
 }
}

void mergeSort(int arr[], int start, int end){
  if(start>=end) return;
  else{
    int mid=(start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merging(arr, start, mid, mid+1, end); //이 함수 내에서 x,y 바꿔주기
  }
}

int binarySearch(int arr[], int s, int e, int num){
  if(s>e){
    return -1;
  }
  else if(s==e) { 
    if(sum<0) sum=sum*(-1);
    if(min > sum){
      x=left;
      y=right;
      min=sum;
    }
    
    if(x>y){
      int temp=y;
      y=x;
      x=temp;
    }

    return sum;
  }
  else{
    prev=sum;
    //if(prev==0) prev=num;
    int mid=(s+e)/2;
    left=num;
    right=arr[mid];
    
    sum=left+right;
    // printf("prev: %d  sum: %d\n", prev, sum);
    // printf("s:%d, m:%d, e:%d\n",s,mid, e);
    // printf("left: %d right: %d\n", left, right);
    // printf("\n");
    if(left==right){
      sum=prev;
    }
    else if(prev != sum){
   // if(abs(prev) > abs(sum)){
      if(sum>0){
         if(abs(min) > abs(sum)){
          x=left;
          y=right;
          min=sum;
         }
    
         if(x>y){
           int temp=y;
           y=x;
           x=temp;
        }
       return binarySearch(arr, s, mid-1,  num);
      }
      else{
         if(abs(min) > abs(sum)){
           x=left;
           y=right;
           min=sum;
          }
    
          if(x>y){
            int temp=y;
            y=x;
           x=temp;
          }
        return binarySearch(arr, mid, e,  num);
        //return binarySearch(arr, mid+1, e,  num);
      } 
    }
  }
}

int main() {

  int n;
  int arr[MAX];
  
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);
    
  
  mergeSort(arr, 0, n-1); 
  // for(int i=0;i<n;i++){
  //   printf("%d ",arr[i]);
  // }printf("\n");
  for(int i=0;i<n;i++){
    int num=arr[i];
    binarySearch(arr, 0, n, num);
  }
  
  printf("%d %d", x, y);
 
  return 0;
}