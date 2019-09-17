#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAX = 100;

char input[3] = { '1','2','3' };

bool isGoodseq(char arr[], int len, int sec) {
	string str(arr);
	if (len == 1) return true;
	else if (sec == len / 2 && len % 2 == 0) {
		string a = str.substr(0, sec);
		string b = str.substr(sec, sec);
		// cout << "a: "<<a<<", b:"<<b<<endl;
		if (a.compare(b) == 0) {
			// printf("false\n");
			return false;
		}
		else return true;
	}
	else if (sec == len / 2 && len % 2 != 0) {
		string a = str.substr(1, sec);
		string b = str.substr(sec + 1, sec);
		// cout << "a: "<<a<<", b:"<<b<<endl;
		if (a.compare(b) == 0) {
			// printf("false\n");
			return false;
		}
		else return true;
	}
	else {
		// cout<<"sec:"<<sec<<", len:"<<len<<endl;
		string a = str.substr(len - sec, sec);
		string b = str.substr(len - 2 * sec, sec);
		// cout << "a: "<<a<<", b:"<<b<<endl;
		if (a.compare(b) == 0) {
			// printf("false\n");
			return false;
		}
		else return isGoodseq(arr, len, sec + 1);
	}
}

int main() {
	int s = 0;
	int n;
	char arr[MAX];
	int min = 9879879;
	scanf_s("%d", &n);

	for (int i = 0; i < MAX; i++) arr[i] = '\0';
	while (s < n) {
		for (int i = 0; i < 3; i++) {
			arr[s] = input[i];
			// printf("%s\n", arr);
			if (isGoodseq(arr, s + 1, 1) == true) {
				break;
			}
			else if (i == 2) {
				s--;
				i = 0;
			}
		}
		s++;
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] != '\0') {
			printf("%c", arr[i]);
		}
	}

	return 0;
}