#include <stdio.h>
#include <string.h>
const int MAX = 210;


int main() {
	char temp1[MAX];
	char temp2[MAX];

	int num1[MAX];
	int num2[MAX];

	int arith[MAX][MAX];//나중에 합산할 배열 

	scanf("%s", &temp1);
	scanf("%s", &temp2);

	for (int i = 0; i < strlen(temp1); i++) {
		num1[i] = temp1[i] - '0';
	}
	for (int i = 0; i < strlen(temp2); i++) {
		num2[i] = temp2[i] - '0';
	}
	int k=MAX-1; //열
 	int m=0; //행
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			arith[i][j] = 0;
		}
	}

	int start_k = 0;
	for (int j = strlen(temp2)-1;j>=0;j--) {
		for (int i = strlen(temp1)-1; i >= 0;i--) {
				arith[m][k] += num1[i] * num2[j] % 10;
				arith[m][k - 1] += (num1[i] * num2[j]) / 10;
				if (arith[m][k] > 9) {
					arith[m][k - 1] += arith[m][k] / 10;
					arith[m][k] = arith[m][k] % 10;
				}
			k--;
		}
		m++;
		start_k = k;
		k = MAX -1- m;
	}

	int sum[MAX];

	for (int i = 0; i < MAX; i++) sum[i] = 0;

	for (int j = MAX-1; j >=0; j--) {
		for (int i = 0; i < m; i++) {
			sum[j] += arith[i][j];
			if (sum[j] > 9) {
				sum[j-1] += sum[j]/10;
				sum[j] = sum[j] % 10;
			}
		}
	}
	bool flag = false;

  for (int j = 0; j < MAX; j++) {
		if (sum[j] != 0) {
			flag = true;
		}if (flag == true) printf("%d", sum[j]);
	}
	
	if (flag == false) printf("0");
	return 0;
}