#include <stdio.h>
#include <string.h>

typedef struct {
    int nam;
    int tuoiNghiHuu;
    int thangNghiHuu;
    int thangBatDau;
    int thangKetThuc;
    int namBatDau;
    int namKetThuc;
} QuyDinhNghiHuu;

QuyDinhNghiHuu quyDinhNam[] = {
    {2021, 60, 3, 1, 9, 1961, 1961},
    {2022, 60, 6, 10, 6, 1961, 1962},
    {2023, 60, 9, 7, 3, 1962, 1963},
    {2024, 61, 0, 4, 12, 1963, 1964},
    {2025, 61, 3, 1, 9, 1964, 1964},
    {2026, 61, 6, 10, 6, 1964, 1965},
    {2027, 61, 9, 7, 3, 1965, 1966},
    {2028, 62, 0, 4, 12, 1966, 9999}
};

QuyDinhNghiHuu quyDinhNu[] = {
    {2021, 55, 4, 1, 8, 1966, 1966},
    {2022, 55, 8, 9, 4, 1966, 1967},
    {2023, 56, 0, 5, 12, 1967, 1967},
    {2024, 56, 4, 1, 8, 1968, 1968},
    {2025, 56, 8, 9, 4, 1968, 1969},
    {2026, 57, 0, 5, 12, 1969, 1969},
    {2027, 57, 4, 1, 8, 1970, 1970},
    {2028, 57, 8, 9, 4, 1970, 1971},
    {2029, 58, 0, 5, 12, 1971, 1971},
    {2030, 58, 4, 1, 8, 1972, 1972},
    {2031, 58, 8, 9, 4, 1972, 1973},
    {2032, 59, 0, 5, 12, 1973, 1973},
    {2033, 59, 4, 1, 8, 1974, 1974},
    {2034, 59, 8, 9, 4, 1974, 1975},
    {2035, 60, 0, 5, 12, 1975, 9999}
};

QuyDinhNghiHuu* timQuyDinhNghiHuu(QuyDinhNghiHuu* quyDinh, int kichThuoc, int thang, int nam) {
    for (int i = 0; i < kichThuoc; i++) {
        if (nam > quyDinh[i].namBatDau && nam < quyDinh[i].namKetThuc) {
            return &quyDinh[i];
        }
        else if (nam == quyDinh[i].namBatDau && thang >= quyDinh[i].thangBatDau) {
            return &quyDinh[i];
        }
        else if (nam == quyDinh[i].namKetThuc && thang <= quyDinh[i].thangKetThuc) {
            return &quyDinh[i];
        }
    }
    return NULL;
}

int main() {
    char hoTen[100];
    int ngay, thang, nam;
    char gioiTinh[10];
    int namHienTai = 2024;
    QuyDinhNghiHuu* quyDinh = NULL;

    printf("Nhap ho ten : ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strcspn(hoTen, "\n")] = 0;

    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf_s("%d %d %d", &ngay, &thang, &nam);

    printf("Nhap gioi tinh (nam/nu): ");
    scanf_s("%9s", gioiTinh, sizeof(gioiTinh));

    if (strcmp(gioiTinh, "nam") == 0) {
        quyDinh = timQuyDinhNghiHuu(quyDinhNam, sizeof(quyDinhNam) / sizeof(QuyDinhNghiHuu), thang, nam);
    }
    else if (strcmp(gioiTinh, "nu") == 0) {
        quyDinh = timQuyDinhNghiHuu(quyDinhNu, sizeof(quyDinhNu) / sizeof(QuyDinhNghiHuu), thang, nam);
    }
    else {
        printf("Loi: Gioi tinh khong hop le. Ma loi: errcode\n");
        return -1;
    }

    if (quyDinh != NULL) {
        int tuoi = namHienTai - nam;
        if (tuoi < 18 || (strcmp(gioiTinh, "nu") == 0 && tuoi > quyDinhNu[sizeof(quyDinhNu) / sizeof(QuyDinhNghiHuu) - 1].tuoiNghiHuu) || (strcmp(gioiTinh, "nam") == 0 && tuoi > quyDinhNam[sizeof(quyDinhNam) / sizeof(QuyDinhNghiHuu) - 1].tuoiNghiHuu)) {
            printf("Loi: Tuoi khong thuoc trong tuoi lao dong. Ma loi: 101\n");
            return 101;
        }

        int namNghiHuu = nam + quyDinh->tuoiNghiHuu;
        int thangNghiHuu = thang + quyDinh->thangNghiHuu;

        if (thangNghiHuu > 12) {
            thangNghiHuu -= 12;
            namNghiHuu++;
        }

        printf("%s, gioi tinh %s, sinh ngay %02d/%02d/%d. Hien tai (nam %d) da %d tuoi. Thoi gian duoc nghi huu la: %02d/%d.\n",
            hoTen, gioiTinh, ngay, thang, nam, namHienTai, tuoi, thangNghiHuu, namNghiHuu);
    }
    else {
        printf("Khong tim thay quy dinh nghi huu phu hop cho ngay thang nam sinh nay.\n");
    }

    return 0;
}
