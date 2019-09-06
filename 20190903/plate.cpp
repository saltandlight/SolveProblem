#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
const int MAX = 30;
bool flag=true;

struct Stack {
	int capacity=0;
	char data[MAX];
	int len = 0;

  void createStack(int s){
       capacity=s; 
  }
    
	void push(char x) {
		if (len >= capacity) {
			printf("impossible\n");
		}
		else {
			data[len++] = x;
		}
	}
	void pop() {
		if (len <= 0)
			printf("Stack Underflow\n");
		else {
			data[len - 1] = 0;
			len--;
		}
	}

	char top() {
		if (len <= 0) printf("Stack Underflow\n");
		else {
			return data[len - 1];
		}
	}

	int size() {
		return len;
	}
};

int main() {
	char arr[MAX];
	char input_arr[MAX]; //stack에 넣어줄 아이들(정렬된 애들)

	scanf("%s", arr); //입력값
  //arr의 길이만큼 스택의 크기 정해서 생성
  int arr_len = strlen(arr);
    
    
  //arr정렬시켜서 input_arr에 넣어주기
  for(int i=0;i<arr_len;i++){
   input_arr[i]=arr[i];
  }
  for(int i=0;i<arr_len;i++){
    for(int j=i+1;j<arr_len;j++){
      if(input_arr[i] > input_arr[j]){
          char temp=input_arr[i];
          input_arr[i]=input_arr[j];
          input_arr[j]=temp;
      }
    }
  }
    
    
	Stack s1;
  s1.createStack(arr_len);
    
	char y;
	int j = 0;
	int cnt = 0;
	string result="";

    //for loop 얼만큼 돌 지 다시 정하기 

	for (int i = 0; i < arr_len; i++) {
		s1.push(input_arr[i]);
		result.append("push\n");
		y = s1.top();
		
	 while(y== arr[j]) {
			s1.pop();
			result.append("pop\n");
			j++;	
			if(s1.size()==0) break;
			y = s1.top();
		}
	}
	
	if(s1.size()>0){
   	for(; j<arr_len; j++){
	    y=s1.top();
	    s1.pop();
	    result.append("pop\n");
	    if(y!=arr[j]) flag=false;
	  }
	}

	
  // printf("j:%d\n", j);
	if (flag==false) printf("impossible");
	else cout << result << endl;
	return 0;
}