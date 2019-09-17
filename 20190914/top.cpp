<<<<<<< HEAD
#include <stdio.h>

const int MAX = 500010;
bool flag = false;

struct Stack {
	long long int data[MAX];
	long long int len;
	long long int capacity;
	//create
	void create(long long int size) {
		capacity = size;
		len = 0;
	}
	//push
	void push(long long int x) {
		if (len >= capacity) {
			printf("Overflow\n");
		}
		else {
			data[len] = x;
			len++;
		}
	}
	//pop
	void pop() {
		if (len <= 0) {
			flag = true;
		}
		else {
			data[len - 1] = 0;
			len--;
		}
	}
	//front
	long long int top() {
		if (len <= 0) {
			flag = true;
		}
		else {
			return data[len - 1];
		}
	}
	//size
	long long int size() {
		return len;
	}
};

int main() {
	long long int n, a, b;
	long long int arr[MAX];
	long long int res[MAX];

	scanf_s("%lld", &n);

	Stack s1;
	s1.create(n);

	for (long long int i = 1; i <= n; i++) {
		scanf_s("%lld", &arr[i]);
		s1.push(arr[i]);
		res[i] = 0;
	}


	long long int res_inx = n;
	long long int inx = 0;

	a = s1.top();
	// printf("a:%lld ", a);
	s1.pop();

	while (res_inx > 0) {
		b = s1.top();
		// printf(", b:%lld\n", b);

		if (a < b) {
			res[res_inx--] = s1.len;
			s1.pop();
			inx = s1.len;
			for (long long int i = inx + 1; i <= res_inx; i++) {
				s1.push(arr[i]);
			}
			a = s1.top();
			// 	printf("a:%lld", a);
			s1.pop();
		}
		else {
			s1.pop();
			if (s1.len == 0) {
				res[res_inx--] = 0;
				for (long long int i = s1.len + 1; i <= res_inx; i++) {
					s1.push(arr[i]);
				}
				a = s1.top();
				// printf("a:%lld ", a);
				s1.pop();
			}
		}
	}
	// 	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("%lld ", res[i]);
	}

	return 0;
=======
#include <stdio.h>

const int MAX = 500010;
bool flag = false;

struct Stack {
	long long int data[MAX];
	long long int len;
	long long int capacity;
	//create
	void create(long long int size) {
		capacity = size;
		len = 0;
	}
	//push
	void push(long long int x) {
		if (len >= capacity) {
			printf("Overflow\n");
		}
		else {
			data[len] = x;
			len++;
		}
	}
	//pop
	void pop() {
		if (len <= 0) {
			flag = true;
		}
		else {
			data[len - 1] = 0;
			len--;
		}
	}
	//front
	long long int top() {
		if (len <= 0) {
			flag = true;
		}
		else {
			return data[len - 1];
		}
	}
	//size
	long long int size() {
		return len;
	}
};

int main() {
	long long int n, a, b;
	long long int arr[MAX];
	long long int res[MAX];

	scanf_s("%lld", &n);

	Stack s1;
	s1.create(n);

	for (long long int i = 1; i <= n; i++) {
		scanf_s("%lld", &arr[i]);
		s1.push(arr[i]);
		res[i] = 0;
	}


	long long int res_inx = n;
	long long int inx = 0;

	a = s1.top();
	// printf("a:%lld ", a);
	s1.pop();

	while (res_inx > 0) {
		b = s1.top();
		// printf(", b:%lld\n", b);

		if (a < b) {
			res[res_inx--] = s1.len;
			s1.pop();
			inx = s1.len;
			for (long long int i = inx + 1; i <= res_inx; i++) {
				s1.push(arr[i]);
			}
			a = s1.top();
			// 	printf("a:%lld", a);
			s1.pop();
		}
		else {
			s1.pop();
			if (s1.len == 0) {
				res[res_inx--] = 0;
				for (long long int i = s1.len + 1; i <= res_inx; i++) {
					s1.push(arr[i]);
				}
				a = s1.top();
				// printf("a:%lld ", a);
				s1.pop();
			}
		}
	}
	// 	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("%lld ", res[i]);
	}

	return 0;
>>>>>>> bdd33d3b60bdecf774749733005d2809d23e7b1b
}