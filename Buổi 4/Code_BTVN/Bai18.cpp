#include <stdio.h>


int tinh_xn(int n) {
    
    if (n == 0) return 1;
    if (n == 1) return 2;
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += tinh_xn(i);
    }
    return sum;
}

int main() {

    int n;

    printf("Nhap n: ");
    scanf_s("%d", &n);

    int result = tinh_xn(n);
    printf("Gia tri cua x%d la: %d\n", n, result);

    return 0;
}
