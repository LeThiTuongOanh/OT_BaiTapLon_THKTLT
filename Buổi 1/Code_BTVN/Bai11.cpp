#include <stdio.h>
#include <stdlib.h>


void nhapM1C_SoNguyen(int **a, int *n) {
	*n = 10; 
	*a = (int *)malloc(*n * sizeof(int)); 
	if (*a == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}
	for (int i = 0; i < *n; i++) {
		(*a)[i] = rand() % 100;
	}
}


void xuatM1C_SoNguyen(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, a[i], (void*)(a + i));
	}
}

void xuatCucTieu(int *a, int n) {
	if (n < 1) return;

	for (int i = 0; i < n; i++) {
		if ((i == 0 && a[i] < a[i + 1]) || // First element
			(i == n - 1 && a[i] < a[i - 1]) || // Last element
			(i > 0 && i < n - 1 && a[i] < a[i - 1] && a[i] < a[i + 1])) { // Middle elements
			printf("So cuc tieu tai vi tri %d: %d\n", i, a[i]);
		}
	}
}

void xoaPhanTuTaiViTri(int *a, int *n, int k) {
	if (k < 0 || k >= *n) {
		printf("Vi tri khong hop le.\n");
		return;
	}
	for (int i = k; i < *n - 1; i++) {
		a[i] = a[i + 1];
	}
	(*n)--;
}

void themPhanTuTaiViTri(int **a, int *n, int x, int k) {
	if (k < 0 || k > *n) {
		printf("Vi tri khong hop le.\n");
		return;
	}
	*a = (int *)realloc(*a, (*n + 1) * sizeof(int));
	if (*a == NULL) {
		printf("Memory reallocation failed.\n");
		exit(1);
	}
	for (int i = *n; i > k; i--) {
		(*a)[i] = (*a)[i - 1];
	}
	(*a)[k] = x;
	(*n)++;
}

void chuyenChanLenDauLeXuongCuoi(int *a, int n) {
	int chan[50], le[50];
	int chanCount = 0, leCount = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			chan[chanCount++] = a[i];
		}
		else {
			le[leCount++] = a[i];
		}
	}
	for (int i = 0; i < chanCount; i++) {
		a[i] = chan[i];
	}
	for (int i = 0; i < leCount; i++) {
		a[chanCount + i] = le[i];
	}
}

int kiemTraChanLeXenKe(int *a, int n) {
	for (int i = 0; i < n - 1; i++) {
		if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int *a, n = 0;	
	nhapM1C_SoNguyen(&a, &n);
	xuatM1C_SoNguyen(a, n);

	printf("\nCac so cuc tieu trong mang:\n");
	xuatCucTieu(a, n);


	int k = 3;
	printf("\nXoa phan tu tai vi tri %d:\n", k);
	xoaPhanTuTaiViTri(a, &n, k);
	xuatM1C_SoNguyen(a, n);


	int x = 99;
	k = 2;
	printf("\nThem phan tu %d tai vi tri %d:\n", x, k);
	themPhanTuTaiViTri(&a, &n, x, k);
	xuatM1C_SoNguyen(a, n);


	printf("\nChuyen so chan len dau, le xuong cuoi:\n");
	chuyenChanLenDauLeXuongCuoi(a, n);
	xuatM1C_SoNguyen(a, n);

	if (kiemTraChanLeXenKe(a, n)) {
		printf("\nMang co chua chan le xen ke.\n");
	}
	else {
		printf("\nMang khong chua chan le xen ke.\n");
	}



	free(a);
	getchar();
	getchar();
	return 0;
}
