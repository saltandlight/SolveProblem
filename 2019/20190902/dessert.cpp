#include <stdio.h>
#include <math.h>

const int MAX=20;
int n;
int arr[MAX];
int opr[MAX];
char opt[3]={'+','-','.'};
char result[MAX];
int count=0;
//arr과 연산자 순열 합쳐서 계산해주는 함수
//계산한 결과가 0이라면 여기서 출력해주자..!
//뒤에서 앞으로 계산해주기


bool calc(char res[], int arr2[]){
  int cnt=1;
  int sum=0;
  for(int i=0;i<n;i++)
    opr[i]=arr2[i];
    
  for(int i=n-1;i>=0;i--){
    
    if(opr[i+1]!=0 && res[i]=='.'){
      if(arr2[i+1]>9 ){
         cnt*=100;
        // printf("opr_i:%d opr_i+1:%d cnt:%d ", opr[i], opr[i+1], cnt);
         opr[i]=cnt*opr[i]+opr[i+1];
        // opr[i]=(int)pow(100, cnt)*opr[i]+opr[i+1];
        // printf("res:%d\n", opr[i]);
      }
      else {
        cnt*=10;
        // printf("opr_i:%d opr_i+1:%d cnt:%d ", opr[i], opr[i+1], cnt);
        opr[i]=cnt*opr[i]+opr[i+1];
        // printf("res:%d\n", opr[i]);
       
      }
      opr[i+1]=opr[i+2];
      opr[i+1]=0;
    }
    if(res[i]=='.' && res[i-1]!='.') cnt=1;
    if(opr[i]==0) opr[i]=opr[i+1];
  }
  
  for(int i=0;i<n;i++){
    if(res[i]=='+'){
      opr[i+1]=opr[i]+opr[i+1];
      opr[i]=0;
    }else if(res[i]=='-'){
      opr[i+1]=opr[i]-opr[i+1];
      opr[i]=0;
    }
  }
  
  
  for(int i=0;i<n;i++){
    sum+=opr[i];
  }
  if(sum==0) return true;
  else return false;
 
}


//연산자 순열 찍어주는 함수
void getResult(int cur){
  //n-1만큼이면 탈출
  if(cur >= n-1){
    //result 출력
    //여기서 계산하는 함수 호출
   
    if(calc(result, arr)==true){
      count++;
      if(count <= 20){
       for(int i=0;i<n;i++){ 
         printf("%d ",arr[i]);
         if(i!=n-1)printf("%c ", result[i]);
       } printf("\n");
      }
    }
  }
  
  //아니면 계속 돌아감.
  else{
    for(int i=0;i<3;i++){
      result[cur]=opt[i];
      getResult(cur+1);
    }
  }
  
}


int main() {
  scanf("%d", &n);
  
  for(int i=0;i<n;i++) 
    arr[i]=i+1;
   
  getResult(0);
  printf("%d\n", count);
  return 0;
}