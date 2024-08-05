#include <stdio.h>

int tinh_Yn_khu_dequy(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;

    int Yn_minus_1 = 3;
    int Yn_minus_2 = 2;
    int Yn_minus_3 = 1;
    int Yn = 0;

    for (int i = 4; i <= n; i++) {
        Yn = Yn_minus_1 + 2 * Yn_minus_2 + 3 * Yn_minus_3;
        Yn_minus_3 = Yn_minus_2;
        Yn_minus_2 = Yn_minus_1;
        Yn_minus_1 = Yn;
    }

    return Yn;
}

void menu() {
    int lua_chon, n;
    printf("Voi moi n >= 1, so Y_n duoc tinh nhu sau : Y1 = 1, Y2 = 2, Y3 = 3, Y_n = Y_(n - 1) + 2 * Y_(n - 2) + 3 * Y_(n - 3) neu n >= 4");
    printf("\n Menu \n");
    printf("1. Tinh gia tri Y_n bang khu de quy\n");
    printf("2. Tinh gia tri Y_n bang de quy long nhau\n");
    printf("3. Thoat\n");

    while (1) {
        printf("Nhap lua chon: ");
        scanf_s("%d", &lua_chon);

        switch (lua_chon) {
        case 1:
            printf("Nhap gia tri cua n (n >= 1): ");
            scanf_s("%d", &n);
            if (n < 1) {
                printf("n phai la so nguyen duong.\n");
            }
            else {
                int gia_tri = tinh_Yn_khu_dequy(n);
                printf("Gia tri phan tu thu %d cua day so Y la: %d \n", n, gia_tri);
            }
            break;
        case 3:
            printf("Thoat chuong trinh.\n");
            return;

        default:
            printf("Lua chon khong hop le. Vui long chon tu 1 den 3.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
