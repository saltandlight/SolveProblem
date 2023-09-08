#include <stdio.h>

const long long int MAX = 100000;

long long int arr[MAX];
long long int cnt[MAX];
long long int quest[MAX];

void merging(long long int arr[], int s1, int e1, int s2, int e2) {
	long long int temp[MAX];
	int idx = 0;
	int p = s1, q = s2;
	//1 3 4  5   6 7 9 10
	//s1    e1   s2    e2
	//p		     q
	while (p <= e1 && q <= e2) {
		if (arr[p] <= arr[q]) temp[idx++] = arr[p++];
		else temp[idx++] = arr[q++];
	}

	//q만 범위 밖으로 나갈 경우
	for (int i = p; i <= e1; i++) temp[idx++] = arr[i];

	//p만 범위 밖으로 나갈 경우
	for (int i = q; i <= e2; i++) temp[idx++] = arr[i];


	//temp -> arr
	for (int i = s1; i <= e2; i++)
		arr[i] = temp[i - s1];
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


int binarySearch(long long int arr[], int s, int e, int value) {
	int count = 0;
	if (s > e) return -1;
	else if (s == e) { 
		if (arr[s] == value) return s;
		else return -1;
	}
	else {
		int mid = (s + e) / 2;
		if (arr[mid] == value){ 
		  
		  
		  return mid;
		} //찾았을 때 양쪽 끝으로 가면서 자신의 값과 다를때까지 카운트해주기 
		else if (arr[mid] > value) return binarySearch(arr, s, mid - 1, value);
		else return binarySearch(arr, mid + 1, e, value);
	}
}



int main() {

	long long int n, q;
	scanf("%lld", &n);

	scanf("%lld", &q);

	for (long long int i = 0; i < n; i++) {
		arr[i] = 0;
		cnt[i] = 0;
	}

	for (long long int i = 0; i < q; i++)
		quest[i] = 0;


	for (long long int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);


	for (long long int i = 0; i < q; i++)
		scanf("%lld", &quest[i]);

	//mergeSort
	mergeSort(arr, 0, n - 1);

	int z = 0;
	int idx = 0;

	//call count_bin function 
	for (long long int i = 0; i < q; i++) {
		z = binarySearch(arr, 0, n - 1, quest[i]);
		if (z == -1) { //없을 때 
			cnt[idx++] = 0;
		}
		else {
			cnt[idx]++;
			for(int j=z-1;j>=0;j--){ //왼쪽으로 가기 
		     if(arr[j]==quest[i]){
		       cnt[idx]++;
		     }else break;
		  }
		  for(int j=z+1;j<n;j++){ //왼쪽으로 가기 
		     if(arr[j]==quest[i]){
		       cnt[idx]++;
		     }else break;
		  }
			//여기서 어떻게 했드라 
		// 	z = binarySearch(arr, z + 1, n - 1, quest[i]);
		// 	printf("z: %d\n", z);
			idx++;
		}
	}

	for (int i = 0; i < idx; i++)
		printf("%d\n", cnt[i]);
	
	return 0;
}