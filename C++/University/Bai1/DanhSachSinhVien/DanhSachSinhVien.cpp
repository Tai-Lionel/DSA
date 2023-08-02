#include <iostream>
#include <cstring>

using namespace std;

typedef struct {
    int maSo;
    char hoTen[50];
    float diemTrungBinh;
    char gioiTinh[4];
} SinhVien;

void nhapSinhVien(SinhVien &s) {
        cout << "Nhap ma so: ";
        cin >> s.maSo;
        cout << "Nhap ho ten: ";
        fflush(stdin);
        fgets(s.hoTen, 50, stdin);
        cout << "Nhap diem trung binh: ";
        cin >> s.diemTrungBinh;
        cout << "Nhap gioi tinh: ";
        cin >> s.gioiTinh;
}

void nhapDanhSachSinhVien(SinhVien s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i+1 << ": " << endl;
        nhapSinhVien(s[i]);
    }
}

void xuatSinhVien(SinhVien s) {
    cout << "\nThong tin sinh vien:\n";
    cout << "\tMa so: " << s.maSo << endl;
    cout << "\tHo ten: " << s.hoTen;
    cout << "\tDiem trung binh: " << s.diemTrungBinh << endl;
    cout << "\tGioi tinh: " << s.gioiTinh << endl;

}

void xuatDanhSachSinhVien(SinhVien s[], int n) {
    cout << "\nDanh sach sinh vien\n";
    for (int i = 0; i < n; i++) {
        xuatSinhVien(s[i]);
    }
}

void xuatLonHon5(SinhVien s[], int n) {
    cout << "\nDanh Sach sinh vien co diem trung binh lon hon hoac bang 5: \n"; 
    for (int i = 0; i < n; i++) {
        if (s[i].diemTrungBinh >= 5) {
            xuatSinhVien(s[i]);
        }
    }
}

int soLuongSinhVienNam(SinhVien s[], int n) {
    int count = 0;
    char nam[4] = "nam";
    char Nam[4] = "Nam";
    for (int i = 0; i < n; i++) {
        if (strcmp(s[i].gioiTinh, nam) == 0 || strcmp(s[i].gioiTinh, Nam) == 0)
            count++;
    }
    return count;
}


int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    SinhVien danhSachSinhVien[n];
    nhapDanhSachSinhVien(danhSachSinhVien, n);
    xuatDanhSachSinhVien(danhSachSinhVien, n);
    xuatLonHon5(danhSachSinhVien, n);
    cout << "So luong sinh vien nam: " << soLuongSinhVienNam(danhSachSinhVien, n) << endl;
}