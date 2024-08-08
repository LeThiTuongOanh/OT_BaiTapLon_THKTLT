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

int main() {
	int n;
	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	int fibonacciMax_DeQuy = timFibonacciMaxNhoHonN_DeQuy(n);
	printf("So Fibonacci lon nhat nho hon %d theo de quy la: %d\n", n, fibonacciMax_DeQuy);
	getchar();
	getchar();
	return 0;
}
