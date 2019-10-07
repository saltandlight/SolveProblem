#include <stdio.h>

const int MAX = 500010;
bool flag = false;
long long int n;

struct Stack {
	long long int data[MAX];
	long long int len;
	long long int capacity;
	long long int idx;
	
	//create
	void create(long long int size) {
		capacity = size;
		len = 0;
	}
	//push
	void push(long long int x) {
		if (len >= capacity) {
			printf("Overflow\n");
		}
		else {
			data[len] = x;
			len++;
		}
	}
	//pop
	void pop() {
		if (len <= 0) {
			flag = true;
		}
		else {
			data[len - 1] = 0;
			len--;
		}
	}
	//top
	long long int top() {
		if (len <= 0) {
			flag = true;
		}
		else {
			return data[len - 1];
		}
	}
	
	//size
	long long int size() {
		return len;
	}
};

int main(){
  long long int arr[MAX];
  long long int result[MAX];
  long long int res_idx=1;
  
  scanf("%lld", &n);
  Stack s;
  //사이즈가 n인 스택을 생성하기 
  s.create(n);
  
  for(int i=1;i<=n;i++){
    result[i]=0;
  }
  
  
  for(int i=0;i<n;i++){
    scanf("%lld", &arr[i]);
    if(i==0){ //가장 처음에 하는 작업
      s.push(i);
      result[res_idx++]=0;      
    }
    else{ //처음이 아닌 경우
      if(arr[s.top()] > arr[i]){
        result[res_idx++]=s.top()+1;
        s.push(i);
      }else{
        while(arr[s.top()] <= arr[i] && s.size() > 0){
          s.pop();
        }
        if(s.size()==0) result[res_idx++]=0;
        else result[res_idx++]=s.top()+1;
        s.push(i);

      }
      
    }
  }
    
  for(int i=1;i<=n;i++){
    printf("%lld ", result[i]);
  }  
    
    
  return 0;
}

