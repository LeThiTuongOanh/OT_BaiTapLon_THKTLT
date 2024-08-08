#include <stdio.h>

// Hàm đệ quy tính số Fibonacci thứ i
int fibonacciDeQuy(int i) {
	if (i <= 1) return i;
	return fibonacciDeQuy(i - 1) + fibonacciDeQuy(i - 2);
}

// Hàm tìm số Fibonacci lớn nhất nhưng nhỏ hơn n bằng cách đệ quy
int timFibonacciMaxNhoHonN_DeQuy(int n) {
	int i = 0;
	int fib = fibonacciDeQuy(i);
	int previousFib = 0;

	while (fib < n) {
		previousFib = fib;
		i++;
		fib = fibonacciDeQuy(i);
	}
	return previousFib;
}

// Hàm khử đệ quy tìm số Fibonacci lớn nhất nhưng nhỏ hơn n
int timFibonacciMaxNhoHonN_KhuDeQuy(int n) {
	int fib1 = 0, fib2 = 1;
	int nextFib = fib1 + fib2;

	while (nextFib < n) {
		fib1 = fib2;
		fib2 = nextFib;
		nextFib = fib1 + fib2;
	}
	return fib2;
}
int main() {
	int n;
	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	int fibonacciMax_DeQuy = timFibonacciMaxNhoHonN_DeQuy(n);
	printf("So Fibonacci lon nhat nho hon %d theo de quy la: %d\n", n, fibonacciMax_DeQuy);

	int fibonacciMax_KhuDeQuy = timFibonacciMaxNhoHonN_KhuDeQuy(n);
	printf("So Fibonacci lon nhat nho hon %d theo khu de quy la: %d\n", n, fibonacciMax_KhuDeQuy);


	getchar();
	getchar();
	return 0;
}
