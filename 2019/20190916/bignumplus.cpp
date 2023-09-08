#include <stdio.h>
#include <string.h>

const int MAX = 110;

int main() {
	char str1[MAX], str2[MAX];
	int temp1[MAX], temp2[MAX];
	int res[MAX];
	

	scanf_s("%s", &str1, MAX);
	scanf_s("%s", &str2, MAX);

	int str1_len = strlen(str1);
	int str2_len = strlen(str2);
	int diff = 0;

	for (int i = 0; i < MAX; i++) {
		res[i] = 0;
	}
		
	for (int i = 0; i < str1_len; i++) {
		temp1[i] = str1[i] - '0';
	}

	for (int i = 0; i < str2_len; i++) {
		temp2[i] = str2[i] - '0';
	}

	
	if (str1_len > str2_len) {
		diff = str1_len - str2_len;
		for (int i = str1_len - 1; i >= diff; i--) {
			res[i] += temp1[i] + temp2[i - diff];
			if (res[i] > 9) {
				res[i] -= 10;
				res[i - 1]++;
			}

		}
		bool flag = false;
		for (int i = diff - 1; i >= 0; i--) {
			res[i] += temp1[i];
			if (i != 0 && res[i] > 9) {
				res[i] -= 10;
				res[i - 1]++;
			}

		}
		for (int i = 0; i < str1_len; i++) {
			printf("%d", res[i]);
		}
	}
	else if (str1_len == str2_len) {
		for (int i = 0; i < str1_len; i++) {
			res[i + 1] += temp2[i] + temp1[i];
			if (res[i + 1] > 9) {
				res[i + 1] -= 10;
				res[i]++;
			}
		}

		if (res[0] != 0) {
			for (int i = 0; i <= str1_len; i++) {
				printf("%d", res[i]);
			}
		}
		else {
			for (int i = 1; i <= str1_len; i++) {
				printf("%d", res[i]);
			}
		}
	}
	else {
		diff = str2_len - str1_len;
		for (int i = str2_len - 1; i >= diff; i--) {
			res[i] += temp2[i] + temp1[i - diff];
			if (res[i] > 9) {
				res[i] -= 10;
				res[i - 1]++;
			}
		}
		bool flag1 = false;

		for (int i = diff - 1; i >= 0; i--) {
			res[i] += temp2[i];
			if (i != 0 && res[i] > 9) {
				res[i] -= 10;
				res[i - 1]++;
			}
		}

		for (int i = 0; i < str2_len; i++) {
			printf("%d", res[i]);
		}
	}
	return 0;
}