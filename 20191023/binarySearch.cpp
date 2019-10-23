#include <stdio.h>

const int MAX = 100010;

long long int n, q;
long long int arr[MAX];
long long int quest[MAX];

void binarySearch(long long int arr[], long long int start, long long int end, long long int x) {
	if (start > end) {
		return;
	}
	else {

		if (start == end) {
			if (arr[start] == x) {
				printf("YES\n");
				return;
			}
			else {
				printf("NO\n");
				return;
			}
		}
		else {

			int mid = (start + end) / 2;
			// printf("%lld %lld %lld\n",start,mid,end);
			if (arr[mid] == x) {
				printf("YES\n"); return;
			}
			else {
				if (arr[mid] > x) return binarySearch(arr, start, mid-1, x);
				else return binarySearch(arr, mid + 1, end, x);
			}
		}
	}
}

int main() {
	scanf_s("%lld %lld", &n, &q);

	for (long long int i = 0; i < n; i++) {
		scanf_s("%lld", &arr[i]);
	}

	for (long long int i = 0; i < q; i++) {
		scanf_s("%lld", &quest[i]);
	}

	for (long long int i = 0; i < q; i++) {
		binarySearch(arr, 0, n - 1, quest[i]);
	}

	return 0;
}