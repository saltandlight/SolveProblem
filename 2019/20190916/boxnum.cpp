#include <stdio.h>

const long long int MAX = 30000;


void merging(long long int arr[], int s1,int e1,  int s2,  int e2) {
	int p, q, t_inx;
	long long int temp[MAX];
	p = s1, q = s2;
	t_inx = 0;

	while (p <= e1 && q<= e2) {
		if (arr[p] <=  arr[q]) {
			temp[t_inx++] = arr[p++];
		}
		else {
			temp[t_inx++] = arr[q++];
		}
	}
	for (int i = p; i <= e1; i++) {
		temp[t_inx++] = arr[i];
	}
	for (int i = q; i <= e2; i++) {
		temp[t_inx++] = arr[i];
	}


	
	for (int i = s1; i <= e2; i++) {
		arr[i] = temp[i-s1];
	}
}


void mergeSort(long long int arr[], int start, int end) {
	if (start >= end) return;
	else {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merging(arr, start, mid, mid + 1, end);
	}
}

int binarySearch(long long int arr[], int start, int end, int value) {
	if (start > end) return 0;
	else if (start == end) {
		if (arr[start] == value) return 1;
		else return 0;
	}
	else{
		int mid = (start + end) / 2;
		if (arr[mid] == value) return 1;
		else if (arr[mid] < value) return binarySearch(arr, mid + 1, end, value);
		else return binarySearch(arr, start, mid-1, value);
	}
}


int main() {
	long long int n;
	long long int box[MAX];

	long long int m;
	long long int num[MAX];
	
	scanf_s("%lld", &n);
	for ( int i = 0; i < n; i++) {
		scanf_s("%lld", &box[i]);
	}

	scanf_s("%lld", &m);
	for (int j = 0; j < m; j++) {
		scanf_s("%lld", &num[j]);
	}

	mergeSort(box,0,n-1);

	//for loop 내에서 num이 바뀔 때마다 호출
	for (int i = 0; i < m; i++) {
		int x=binarySearch(box, 0, n-1, num[i]);
		printf("%d\n", x);
	}
	


	/*
	for (long long int i = 0; i < n; i++) {
		printf("%lld ", box[i]);
	}
	printf("\n");

	for (long long int j = 0; j < m; j++) {
		printf("%lld ", num[j]);
	}*/
	return 0;
}