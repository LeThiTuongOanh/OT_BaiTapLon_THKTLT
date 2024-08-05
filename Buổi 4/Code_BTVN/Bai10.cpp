#include <stdio.h>


int fibonacci(int n) {
    if (n <= 2) return 1;
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


void fibonacci_in_range(int m, int n) {
    int i = 1;
    int fib;

    printf("Cac so Fibonacci trong doan [%d, %d] la: ", m, n);

    while (1) {
        fib = fibonacci(i);
        if (fib > n) break;  
        if (fib >= m) {
            printf("%d ", fib);  
        }
        i++;
    }

    printf("\n");
}

int main() {
    int n, m;
    printf("Moi nhap m:");
    scanf_s("%d", &m);
    printf("Moi nhap n:");
    scanf_s("%d", &n);
    fibonacci_in_range(m, n);

    return 0;
}
