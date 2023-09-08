#include <stdio.h>

const int MAX = 100010;

long long int n, q;
long long int num[MAX];
long long int quest[MAX];

void binarySearch(long long int arr[], long long int start, long long int end, long long int x) {
	int count = 0;
	if (start > end) {
		return;
	}
	else {
		if (start == end) {
			if (arr[start] == x) { printf("1\n"); return; }
			else { printf("0\n"); return; }
		}
		else {
			long long int mid = (start + end) / 2;
			if (arr[mid] == x) {
				//여기서 좌우로 뻗어나가며 카운트를 증가시키기
				//left
				long long int left = mid;
				while (left >= 0 && arr[left] == x) {
					count++;
					left--;
				}
				long long int right = mid + 1;
				while (right <= n - 1 && arr[right] == x) {
					count++;
					right++;
				}
				printf("%lld\n", count);
			}
			else if (arr[mid] > x) {
				return binarySearch(arr, 0, mid, x);
			}
			else {
				return binarySearch(arr, mid + 1, end, x);
			}

		}//end-else
	}//end-else
}


void merging(long long int arr[], long long int s1, long long int e1, long long int s2, long long int e2) {
	long long int p, q;
	long long int temp[MAX];
	long long int idx = 0;
	p = s1; q = s2;

	while (p <= e1 && q <= e2) {
		if (arr[p] >= arr[q]) {
			temp[idx++] = arr[q++];
		}
		else {
			temp[idx++] = arr[p++];
		}
	}//end-while

	//p가 e1를 탈출, q만 남음
	for (long long int i = q; i <= e2; i++) {
		temp[idx++] = arr[i];
	}

	//q가 e2를 탈출, p만 남음
	for (long long int i = p; i <= e1; i++) {
		temp[idx++] = arr[i];
	}

	for (long long int i = s1; i <= e2; i++) {
		arr[i] = temp[i - s1];
	}
}

void mergeSort(long long int arr[], long long int start, long long int end) {
	if (start >= end) return;
	else {
		long long int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merging(arr, start, mid, mid + 1, end);
	}
}

int main() {
	scanf_s("%lld %lld", &n, &q);

	for (long long int i = 0; i < n; i++) {
		scanf_s("%lld", &num[i]);
	}

	for (long long int i = 0; i < q; i++) {
		scanf_s("%lld", &quest[i]);
	}

	mergeSort(num, 0, n - 1);


	for (long long int i = 0; i < q; i++) {
		binarySearch(num, 0, n - 1, quest[i]);
	}


	return 0;
}