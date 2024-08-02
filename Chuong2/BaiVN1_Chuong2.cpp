#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void taoMangNgauNhien(int *mang, int n, int tu, int den) {
	for (int i = 0; i < n; i++) {
		mang[i] = tu + rand() % (den - tu + 1);
	}
}


// Hàm in mảng
void inMang(int *mang, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", mang[i]);
	}
	printf("\n");
}

bool kiemTraSoNguyenTo(int num) {
	if (num < 2) {
		return false;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void Cau1(int *mang, int n, int x)
{
	printf("Phan tu so nguyen to: ");
	for (int i = 0; i < n; i++)
	{
		if (kiemTraSoNguyenTo(mang[i]))
		{
			if (mang[i]<x)
				printf("%d ", mang[i]);
		}

	}
}

int timSoLanXuatHien(int arr[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			count++;	
		}
	}
	return count;
}

void Cau3(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int x = timSoLanXuatHien(arr, n, arr[i]);
		printf("So lan xuat hien cua %d la %d\n", arr[i], x);
	}
}
int main()
{
	int n;
	int *mang = NULL;
	int tu = 0, den = 100;
	int luaChon, x, viTri;

	// Khởi tạo số ngẫu nhiên
	srand(time(NULL));

	// Tạo mảng ngẫu nhiên
	do {
		printf("Nhap so phan tu cua mang (>= 15): ");
		scanf_s("%d", &n);
	} while (n < 15);

	// Cấp phát bộ nhớ cho mảng
	mang = (int *)malloc(n * sizeof(int));
	if (mang == NULL) {
		printf("Khong the cap phat bo nho!\n");
		return 1; // Kết thúc chương trình nếu không thể cấp phát bộ nhớ
	}
	do {
		printf("\n======= MENU =======\n");
		printf("1. Tao mang ngau nhien\n");
		printf("2. Cau1: Liet ke so nguyen to nho hon n \n");
		printf("3. Cau2: Tinh tong cac phan tu co chu so dau la chu so le\n");
		printf("4. Cau3: Liet ke so nhan xuat hien cua phan tu trong mang \n");
		printf("5. Cau4: Sap xep mang co so chan tang dan , so le giam dan\n");
		printf("6. Cau5: Tim day con giam dai nhat trong mang \n");
		printf("7. Cau6: Tim so nho thu 2 trong mang \n");
		printf("8. Cau7: Tim trong day phan tu co chua x( x gom 2 chu so) \n");
		printf("9. Cau8: Sap xep ptu chan tang dan ptu le giu nguyen vi tri\n");
		printf("10. Cau9: Sap xep so le dau mang so chan cuoi mang \n");
		printf("0. Thoat\n");
		printf("Chon: ");
		scanf_s("%d", &luaChon);

		switch (luaChon) {
		case 1:
			taoMangNgauNhien(mang, n, tu, den);
			printf("Mang ngau nhien: ");
			inMang(mang, n);
			break;
		case 2:
			printf("Nhap vao so ngguyen x: ");
			scanf_s("%d", &x);
			Cau1(mang, n, x);
			break;
		case 4:
			Cau3(mang, n);
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le! Vui long chon lai.\n");
			break;
		}
	} while (luaChon != 0);

	// Giải phóng bộ nhớ
	free(mang);

	return 0;
}