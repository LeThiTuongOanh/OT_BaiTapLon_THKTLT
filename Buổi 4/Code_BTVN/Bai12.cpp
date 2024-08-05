#include <stdio.h>


void tinh_danh_sach(int n, int* x_n, int* y_n) {

    int x = 1, y = 0;
    int x_truoc, y_truoc;

    for (int i = 1; i <= n; i++) {
        x_truoc = x;
        y_truoc = y;
        x = x_truoc + y_truoc;
        y = 3 * x_truoc + 2 * y_truoc;
    }

    *x_n = x;
    *y_n = y;
}

int main() {
    int n;
    printf("Nhap gia tri cua n: ");
    scanf_s("%d", &n);

    int x_n, y_n;
    tinh_danh_sach(n, &x_n, &y_n);

    printf("x_%d = %d\n", n, x_n);
    printf("y_%d = %d\n", n, y_n);

    return 0;
}
