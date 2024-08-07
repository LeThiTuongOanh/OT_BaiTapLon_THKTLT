#include <stdio.h>

int main() {
	// Bài 3: Khai báo và nhập giá trị cho a và b
	float a, b;
	float *pa, *pb;

	printf("Nhap so thuc a: ");
	scanf_s("%f", &a);
	printf("Nhap so thuc b: ");
	scanf_s("%f", &b);

	// Khởi tạo con trỏ
	pa = &a;
	pb = &b;

	// Xuất giá trị và địa chỉ của các con trỏ pa, pb
	printf("\nGia tri cua a: %f", *pa);
	printf("\nDia chi cua a: %p", (void*)pa);
	printf("\nGia tri cua b: %f", *pb);
	printf("\nDia chi cua b: %p", (void*)pb);

	// Bài 9: Tính toán tổng, hiệu, tích, thương
	float tong = *pa + *pb;
	float hieu = *pa - *pb;
	float tich = *pa * *pb;
	float thuong = *pa / *pb;

	// Xuất kết quả tính toán và địa chỉ ô nhớ chứa kết quả
	printf("\n\nTong: %f", tong);
	printf("\nDia chi cua tong: %p", (void*)&tong);
	printf("\nHieu: %f", hieu);
	printf("\nDia chi cua hieu: %p", (void*)&hieu);
	printf("\nTich: %f", tich);
	printf("\nDia chi cua tich: %p", (void*)&tich);
	printf("\nThuong: %f", thuong);
	printf("\nDia chi cua thuong: %p", (void*)&thuong);

	return 0;
}
