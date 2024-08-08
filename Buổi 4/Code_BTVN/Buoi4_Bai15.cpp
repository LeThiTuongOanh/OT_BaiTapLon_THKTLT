#include <stdio.h>

// Hàm đệ quy tính tổng các giá trị của dãy từ A_1 đến A_n-1
int tinhTongAn(int n);

// Hàm đệ quy tính giá trị A_n
int tinhAn_DeQuy(int n) {
	if (n == 1) {
		return 1; // Điều kiện cơ sở
	}
	else {
		return n * tinhTongAn(n - 1);
	}
}

// Hàm đệ quy tính tổng các giá trị của dãy từ A_1 đến A_n-1
int tinhTongAn(int n) {
	if (n == 1) {
		return 1; // Điều kiện cơ sở
	}
	else {
		return tinhAn_DeQuy(n) + tinhTongAn(n - 1);
	}
}

int main() {
	int n;
	printf("Nhap gia tri cua n: ");
	scanf_s("%d", &n);

	int result = tinhAn_DeQuy(n);
	printf("Gia tri A_%d la: %d\n", n, result);

	getchar();
	getchar();

	return 0;
}
