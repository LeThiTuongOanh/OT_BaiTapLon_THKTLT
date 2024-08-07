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

int main() {
	int *a, n = 0;
	nhapM1C_SoNguyen(&a, &n);
	xuatM1C_SoNguyen(a, n);

	printf("\nCac so cuc tieu trong mang:\n");
	xuatCucTieu(a, n);
	free(a);
	getchar();
	getchar();
	return 0;
}
