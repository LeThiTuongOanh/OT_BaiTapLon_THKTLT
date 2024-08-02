#include <stdio.h>
#include <stdlib.h>

// Cấu trúc hỗn số
typedef struct {
	int phan_nguyen;
	int tu_so;
	int mau_so;
} HonSo;

// Hàm tạo mảng hỗn số ngẫu nhiên
void taoMangHonSo(HonSo *arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i].phan_nguyen = rand() % 10; // phần nguyên ngẫu nhiên từ 0 đến 9
		arr[i].tu_so = rand() % 10; // tử số ngẫu nhiên từ 0 đến 9
		arr[i].mau_so = rand() % 9 + 1; // mẫu số ngẫu nhiên từ 1 đến 9 (mẫu khác 0)
	}
}

// Hàm xuất danh sách hỗn số
void xuatMangHonSo(HonSo *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %d/%d\n", arr[i].phan_nguyen, arr[i].tu_so, arr[i].mau_so);
	}
}

int soSanhHonSo(HonSo a, HonSo b) {
	float giaTriA = a.phan_nguyen + (float)a.tu_so / a.mau_so;
	float giaTriB = b.phan_nguyen + (float)b.tu_so / b.mau_so;
	if (giaTriA < giaTriB) return -1;
	if (giaTriA > giaTriB) return 1;
	return 0;
}

// 1. Tìm hỗn số x trong mảng b theo giải thuật Linear Search
int linearSearch(HonSo *arr, int n, HonSo x) {
	for (int i = 0; i < n; i++) {
		if (soSanhHonSo(arr[i], x) == 0) {
			return i;
		}
	}
	return -1;
}
void menu() {
	printf("\n------Menu-------\n");
	printf("0. Thoat khoi chuong trinh\n");
	printf("1. Tao ngau nhien hon so\n");
	printf("2. Xuat danh sach hon so\n");
	printf("3. Tim hon so x theo Linear Search\n");
	printf("4. Sap xep phan tu co phan nguyen chan len dau\n");
	printf("5. Tim hon so x theo Binary Search\n");
	printf("6. Chia mang b thanh s1 va s2\n");
	printf("7. Xoa phan tu thu k trong mang\n");
	printf("8. Them hon so x vao mang tai vi tri k\n");
	printf("9. Tao mang phan so tu mang hon so\n");
	printf("10. Tinh tong cac phan tu cua mang\n");
	printf("11. Tim phan tu lon nhat/nho nhat cua mang\n");
	printf("12. Xuat vi tri phan tu co phan nguyen chan\n");
	printf("13. Xuat vi tri phan tu lon nhat/nho nhat\n");
}

int main() {
	int n;
	printf("Nhap so luong hon so: ");
	scanf_s("%d", &n);
	HonSo *arr = (HonSo *)malloc(n * sizeof(HonSo));
	int chon;

	do {
		menu();
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &chon);
		switch (chon) {
		case 0:
			break;
		case 1:
			taoMangHonSo(arr, n);
			break;
		case 2:
			printf("Danh sach hon so:\n");
			xuatMangHonSo(arr, n);
			break;
		case 3:
		{
				  HonSo x;
				  printf("Nhap hon so can tim (phan nguyen, tu so, mau so): ");
				  scanf_s("%d %d %d", &x.phan_nguyen, &x.tu_so, &x.mau_so);
				  int index = linearSearch(arr, n, x);
				  if (index != -1) {
					  printf("Tim thay hon so tai vi tri %d\n", index);
				  }
				  else {
					  printf("Khong tim thay hon so\n");
				  }
		}
			break;
	
		default:
			printf("Lua chon khong hop le\n");
			break;
		}
	} while (chon != 0);

	free(arr);
	return 0;
}
