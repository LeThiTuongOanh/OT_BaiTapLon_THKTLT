#include <stdio.h>
#include <ctype.h>
#include<string.h>

void xuatKyTu(char* st) {
    while (*st) {
        printf("%c ", *st);
        st++;
    }
    printf("\n");
}


void chuyenChuHoa(char* st) {
    while (*st) {
        *st = toupper((unsigned char)*st);
        st++;
    }
}


void chuyenKyTuDauChuHoa(char* st) {
    int newWord = 1;
    while (*st) {
        if (isspace((unsigned char)*st)) {
            newWord = 1;
        }
        else if (newWord && !isspace((unsigned char)*st)) {
            *st = toupper((unsigned char)*st);
            newWord = 0;
        }
        else {
            *st = tolower((unsigned char)*st);
        }
        st++;
    }
}

int main() {
    char st[100];

    printf("Nhap vao chuoi: ");
    fgets(st, sizeof(st), stdin);
    st[strcspn(st, "\n")] = '\0';  

    printf("Cac ky tu cua chuoi: ");
    xuatKyTu(st);

    chuyenChuHoa(st);
    printf("Chuoi sau khi chuyen sang chu hoa: %s\n", st);

    chuyenKyTuDauChuHoa(st);
    printf("Chuoi sau khi chuyen ky tu dau moi tu ve chu hoa: %s\n", st);

    return 0;
}
