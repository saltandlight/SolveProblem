#include <stdio.h>
#include <string.h>

const int MAX = 150;

using namespace std;

int main() {
	bool flag = false;

	char num1[MAX];
	char num2[MAX];

	int temp1[MAX];
	int temp2[MAX];
	int result[MAX];

	scanf("%s", &num1);
	scanf("%s", &num2);

	int len_num1 = strlen(num1);
	int len_num2 = strlen(num2);

	//char arr-> int arr
	for (int i = 0; i < len_num1; i++) {
		temp1[i] = num1[i] - '0';
	}
	for (int i = 0; i < len_num2; i++) {
		temp2[i] = num2[i] - '0';
	}
	int gan = 0;
	//arith(minus)
	//len_num1>len_num2
	if (len_num1 > len_num2) {
		gan = len_num1 - len_num2;
		for (int i = 0; i < len_num1; i++) {
			result[i] = 0;
		}
		for (int i = len_num2 - 1; i >= 0; i--) {
			if (temp1[i + gan] < temp2[i]) {
				temp1[i + gan - 1]--;
				temp1[i + gan] += 10;
			}
			result[i + gan] = temp1[i + gan] - temp2[i];
		}
		
		for (int i = gan-1; i >= 0;i--) {
		    if(temp1[i]<0 && i>=1){
			  temp1[i-1]--;
			  temp1[i]+=10;
			}
			result[i] = temp1[i];
		}

		for (int i = 0; i < len_num1; i++) {
			if (result[i] != 0) flag = true;
			if(flag==true) printf("%d", result[i]);
		}
	}
	else if (len_num1 < len_num2) {
		//len_num1<len_num2
		gan = len_num2 - len_num1;
		for (int i = 0; i < len_num2; i++) {
			result[i] = 0;
		}
		for (int i = len_num1 - 1; i >= 0; i--) {
			if (temp2[i + gan] < temp1[i]) {
				temp2[i + gan - 1]--;
				temp2[i + gan] += 10;
			}
			result[i + gan] = temp2[i + gan] - temp1[i];
		}

		for (int i = gan - 1; i >= 0; i--) {
			if (temp2[i] < 0 && i >= 1) {
				temp2[i - 1]--;
				temp2[i] += 10;
			}
			result[i] = temp2[i];
		}
		printf("-");
		for (int i = 0; i < len_num2; i++) {
			if (result[i] != 0) flag = true;
			if (flag == true) printf("%d", result[i]);
		}
	}
	//len_num1=len_num2
	else {
		if (strcmp(num1, num2) == 0) {
			printf("0");
		}
		else if (strcmp(num1, num2) > 0) {
			for (int i = len_num1; i >= 0; i--) {
				if (temp1[i] < temp2[i]) {
					temp1[i - 1]--;
					result[i] = temp1[i] + 10 - temp2[i];
				}
				else {
					result[i] = temp1[i] - temp2[i];
				}
			}
			for (int i = 0; i < len_num2; i++) {
				if (result[i] != 0) flag = true;
				if (flag == true)  printf("%d", result[i]);
			}
		}
		else {
			for (int i = len_num1; i >= 0; i--) {
				if (temp2[i] < temp1[i]) {
					temp2[i - 1]--;
					result[i] = temp2[i] + 10 - temp1[i];
				}
				else {
					result[i] = temp2[i] - temp1[i];
				}
			}printf("-");
			for (int i = 0; i < len_num2; i++) {
				if (result[i] != 0) flag = true;
				if (flag == true)  printf("%d", result[i]);
			}
		}
	}


	return 0;
}
