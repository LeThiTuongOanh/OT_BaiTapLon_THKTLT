#include <stdio.h>
#include <stdlib.h>


int tinh_U(int n) {
   
    if (n < 6) {
        return n;
    }

    int* U = (int*)malloc((n + 1) * sizeof(int));
    if (U == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        exit(1);
    }

    for (int i = 0; i < 6; i++) {
        U[i] = i;
    }

    for (int i = 6; i <= n; i++) {
        U[i] = U[i - 5] + U[i - 4] + U[i - 3] + U[i - 2] + U[i - 1];
    }

    int result = U[n];

    free(U);

    return result;
}

int main() {
    int n;
    printf("Nhap gia tri cua n: ");
    scanf_s("%d", &n);

    int U_n = tinh_U(n);

    printf("U(%d) = %d\n", n, U_n);

    return 0;
}
