#include <stdio.h>

const int MAX = 10010;

int main() {

	int n;
	long long int m;
	long long int res[MAX];

	scanf_s("%d%lld", &n, &m);
	int ans = 1;
	res[0] = ans;

	for (int i = 1; i < 10007; i++) {
		ans = (n * ans) % 10007;
		res[i] = ans;
	}


	m = m % 10006;
	printf("%lld", res[m]);

	return 0;
}