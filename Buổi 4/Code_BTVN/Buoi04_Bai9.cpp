#include <stdio.h>

double TinhS1_DeQuy(int n) {
	if (n == 1) {
		return 1.0 / (1 * 2 * 3);
	}
	return 1.0 / (n * (n + 1) * (n + 2)) + TinhS1_DeQuy(n - 1);
}

double TinhS1_KhongDeQuy(int n) {
	double tong = 0;
	for (int i = 1; i <= n; i++) {
		tong += 1.0 / (i * (i + 1) * (i + 2));
	}
	return tong;
}


int TinhS2_DeQuy(int n) {
	if (n == 1) {
		return 1;
	}
	return n * n + TinhS2_DeQuy(n - 1);
}


int main() {
	int n;
	printf("Nhap so nguyen duong n: ");
	scanf_s("%d", &n);

	// Tính S1(n)
	double S1_dequy = TinhS1_DeQuy(n);
	double S1_khongdequy = TinhS1_KhongDeQuy(n);
	printf("S1(n) de quy: %.10lf\n", S1_dequy);
	printf("S1(n) khong de quy: %.10lf\n", S1_khongdequy);

	int S2_dequy = TinhS2_DeQuy(n);
	printf("S2(n) de quy: %d\n", S2_dequy);
	getchar();
	getchar();
	return 0;
}
