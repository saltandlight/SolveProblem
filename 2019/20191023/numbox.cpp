#include <stdio.h>

const int MAX = 1000010;

long long int n, m;
long long int box[MAX];
long long int num[MAX];

void binarySearch(long long int arr[], long long int start, long long int end, long long int x) {
	if (start > end) {
		printf("0\n");
		return;
	}
	else if (start == end) {
		if (arr[start] == x) {
			printf("1\n");
			return;
		}
		else {
			printf("0\n");
			return;
		}
	}
	else {
		long long int mid = (start + end) / 2;
		if (arr[mid] == x) {
			printf("1\n");
			return;
		}
		else if (arr[mid] > x) return binarySearch(arr, start, mid - 1, x);
		else return binarySearch(arr, mid + 1, end, x);
	}
}


void merging(long long int arr[], long long int s1, long long int e1, long long int s2, long long int e2) {
	long long int p, q;
	p = s1; q = s2;
	long long int temp[MAX];
	long long int idx = 0;

	while (p <= e1 && q <= e2) {
		if (arr[p] <= arr[q]) {
			temp[idx++] = arr[p++];
		}
		else {
			temp[idx++] = arr[q++];
		}
	}

	for (long long int i = q; i <= e2; i++) {
		temp[idx++] = arr[i];
	}

	for (long long int i = p; i <= e1; i++) {
		temp[idx++] = arr[i];
	}

	for (long long int i = s1; i <= e2; i++) {
		arr[i] = temp[i - s1];
	}
}
void mergeSort(long long int arr[], long long int s, long long int e) {
	if (s >= e) return;
	else {
		int mid = (s + e) / 2;
		mergeSort(arr, s, mid);
		mergeSort(arr, mid + 1, e);
		merging(arr, s, mid, mid + 1, e);
	}
}
int main() {
	scanf_s("%lld", &n);
	for (long long int i = 0; i < n; i++) {
		scanf_s("%lld", &box[i]);
	}

	scanf_s("%lld", &m);
	for (long long int i = 0; i < m; i++) {
		scanf_s("%lld", &num[i]);
	}


	mergeSort(box, 0, n - 1);

	for (long long int i = 0; i < m; i++) {
		binarySearch(box, 0, n - 1, num[i]);
	}

	return 0;
};