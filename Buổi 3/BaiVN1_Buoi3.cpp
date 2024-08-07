#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void taoMaTran(int m, int n, int k, int maTran[][MAX]) {
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			maTran[i][j] = rand() % (k + 1);
		}
	}
}

void xuatMaTran(int m, int n, int maTran[][MAX]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", maTran[i][j]);
		}
		printf("\n");
	}
}

void xuatCacCotSoLe(int m, int n, int maTran[][MAX]) {
	printf("Cac cot chi chua so le:\n");
	for (int j = 0; j < n; j++) {
		int soLe = 1;
		for (int i = 0; i < m; i++) {
			if (maTran[i][j] % 2 == 0) {
				soLe = 0;
				break;
			}
		}
		if (soLe) {
			for (int i = 0; i < m; i++) {
				printf("%d ", maTran[i][j]);
			}
			printf("\n");
		}
	}
}

/*

int demChuSo2(int x) {
	int count = 0;
	while (x > 0) {
		if (x % 10 == 2) count++;
		x /= 10;
	}
	return count;
}


int demPhanTuCoChuSo2(int m, int n, int maTran[][MAX]) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (demChuSo2(maTran[i][j]) > 0) count++;
		}
	}
	return count;
}
*/

void sapXepDongTangLeGiamChan(int n, int dong[]) {
	int le[MAX], chan[MAX];
	int leCount = 0, chanCount = 0;
	for (int j = 0; j < n; j++) {
		if (dong[j] % 2 == 0) {
			chan[chanCount++] = dong[j];
		}
		else {
			le[leCount++] = dong[j];
		}
	}
	// Sắp xếp số lẻ tăng dần
	for (int i = 0; i < leCount - 1; i++) {
		for (int j = i + 1; j < leCount; j++) {
			if (le[i] > le[j]) {
				int temp = le[i];
				le[i] = le[j];
				le[j] = temp;
			}
		}
	}
	// Sắp xếp số chẵn giảm dần
	for (int i = 0; i < chanCount - 1; i++) {
		for (int j = i + 1; j < chanCount; j++) {
			if (chan[i] < chan[j]) {
				int temp = chan[i];
				chan[i] = chan[j];
				chan[j] = temp;
			}
		}
	}
	// Gộp lại mảng
	int index = 0;
	for (int i = 0; i < leCount; i++) {
		dong[index++] = le[i];
	}
	for (int i = 0; i < chanCount; i++) {
		dong[index++] = chan[i];
	}
}

void sapXepMaTranDongTangLeGiamChan(int m, int n, int maTran[][MAX]) {
	for (int i = 0; i < m; i++) {
		sapXepDongTangLeGiamChan(n, maTran[i]);
	}
}

int kiemTraGiamDanDongCot(int m, int n, int maTran[][MAX]) {
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (maTran[i][j] > maTran[i][j - 1]) return 0;
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < m; i++) {
			if (maTran[i][j] > maTran[i - 1][j]) return 0;
		}
	}
	return 1;
}


void lietKeDongGiamDan(int m, int n, int maTran[][MAX]) {
	printf("Cac dong co gia tri giam dan:\n");
	for (int i = 0; i < m; i++) {
		int giamDan = 1;
		for (int j = 1; j < n; j++) {
			if (maTran[i][j] > maTran[i][j - 1]) {
				giamDan = 0;
				break;
			}
		}
		if (giamDan) {
			printf("Dong %d: ", i + 1);
			for (int j = 0; j < n; j++) {
				printf("%d ", maTran[i][j]);
			}
			printf("\n");
		}
	}
}


int main() {
	int m, n, k = 100;
	int maTran[MAX][MAX];
	printf("Nhap so dong: ");
	scanf_s("%d", &m);
	printf("Nhap so cot: ");
	scanf_s("%d", &n);

	taoMaTran(m, n, k, maTran);
	printf("Ma tran ngau nhien:\n");
	xuatMaTran(m, n, maTran);

	int choice;

	do {
		printf("\nMenu:\n");
		printf("1. Xuat cac cot chi chua so le\n");
		printf("2. Tim phan tu lon nhat tren bien cua ma tran\n");
		printf("3. Dem so phan tu co chu so 2 trong cac chu so\n");
		printf("4. Xuat cac phan tu cuc tieu\n");
		printf("5. Sap xep dong tang le, giam chan\n");
		printf("6. Sap xep cot tang chan, giam le\n");
		printf("7. Kiem tra cac gia tri trong ma tran co giam dan theo cot va dong\n");
		printf("8. Liet ke chi so dong chua toan gia tri chan\n");
		printf("9. Liet ke cac dong chua gia tri giam dan\n");
		printf("10. Tim gia tri xuat hien nhieu nhat trong ma tran\n");
		printf("11. Tim cac chu so xuat hien nhieu nhat trong ma tran\n");
		printf("12. Liet ke cac cot co tong nho nhat trong ma tran\n");
		printf("13. Hoan vi hai cot trong ma tran\n");
		printf("14. Hoan vi hai dong trong ma tran\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			xuatCacCotSoLe(m, n, maTran);
			break;
		case 3:
			//printf("So phan tu co chu so 2: %d\n", demPhanTuCoChuSo2(m, n, maTran));
			break;
		case 5:
			sapXepMaTranDongTangLeGiamChan(m, n, maTran);
			printf("Ma tran sau khi sap xep dong tang le, giam chan:\n");
			xuatMaTran(m, n, maTran);
			break;
		case 7:
			if (kiemTraGiamDanDongCot(m, n, maTran)) {
				printf("Ma tran co gia tri giam dan theo dong va cot.\n");
			}
			else {
				printf("Ma tran khong co gia tri giam dan theo dong va cot.\n");
			}
			break;
		case 9:
			lietKeDongGiamDan(m, n, maTran);
			break;
		case 0:
			printf("Thoat.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	} while (choice != 0);

	return 0;
}
