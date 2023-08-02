#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

typedef struct {
    char MSSV[10], hoten[30];
    int gioitinh; //1: nữ, 0: nam
    char diachi[50];
    float dtb;
} SINHVIEN;

void Nhap1SV(SINHVIEN &sv); //Nhập thông tin 1 sinh viên
void NhapDSSV(SINHVIEN dssv[], int &n); //Nhập danh sách sinh viên
void Xuat1SV(SINHVIEN sv); //Xuất thông tin 1 sinh viên
void XuatDSSV(SINHVIEN dssv[], int n); //Xuất danh sách sinh viên
int TimSV(SINHVIEN dssv[], int n, char maso[]); //Tìm sinh viên
void XoaSV(SINHVIEN dssv[], int &n, char maso[]); //Hàm xóa
void SapTheoDTB(SINHVIEN dssv[], int n); //Sắp xếp theo điểm tb
void SapTheoHoTen(SINHVIEN dssv[], int n); //Sắp xếp theo họ tên
void Hoanvi(SINHVIEN &a, SINHVIEN &b); // Hoán vị 2 sinh viên

int main() {
    // Nhap va xuat danh sach sinh vien
    int n;
    SINHVIEN dssv[50];
    NhapDSSV(dssv, n);
    XuatDSSV(dssv, n);

    // Xóa sinh vien
    char maso[30];
    cout << "Nhap ma so sinh vien can xoa: ";
    cin >> maso;
    XoaSV(dssv, n, maso);
    // Xem kết quả sau khi xóa
    cout << "Danh sach sinh vien sau khi xoa: " << endl;
    XuatDSSV(dssv, n);

    SapTheoDTB(dssv, n);
    cout << "Danh sach sinh vien theo thu tu tang dan cua diem trung binh: " << endl;
    XuatDSSV(dssv, n);

    SapTheoHoTen(dssv, n);
    cout << "Danh sach sinh vien duoc sap xep theo bang chu cai: " << endl;
    XuatDSSV(dssv, n);
}

void Nhap1SV(SINHVIEN &sv) {
    cout << "Nhap thong tin sinh vien: " << endl;
    cout << "\tMa so sinh vien: "; fflush(stdin); cin >> sv.MSSV;
    cout << "\tHo va ten: "; fflush(stdin); gets(sv.hoten);
    cout << "\tGioi tinh: "; fflush(stdin); cin >> sv.gioitinh;
    cout << "\tDia chi: "; fflush(stdin);; gets(sv.diachi);
    cout << "\tDiem trung binh: "; fflush(stdin); cin >> sv.dtb;
}

void NhapDSSV(SINHVIEN dssv[], int &n) {
    // cout << "Nhap so sinh vien (toi da 50 sinh vien): ";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    //     Nhap1SV(dssv[i]);

    ifstream inputFile;
    inputFile.open("filename.txt");

    if (!inputFile.is_open()) {
        std::cout << "Error: Unable to open the file." << std::endl;
        return;
    }

    string nString;
    getline(inputFile, nString);
    n = stoi(nString);

    for (int i = 0; i < n; i++) {
        string MSSVString;
        getline(inputFile, MSSVString);
        strcpy(dssv[i].MSSV,MSSVString.c_str());

        string hotenString;
        getline(inputFile, hotenString);
        strcpy(dssv[i].hoten, hotenString.c_str());

        string gioitinhString;
        getline(inputFile, gioitinhString);
        dssv[i].gioitinh = stoi(gioitinhString);

        string diachiString;
        getline(inputFile, diachiString);
        strcpy(dssv[i].diachi, diachiString.c_str());

        string dtbString;
        getline(inputFile, dtbString);
        dssv[i].dtb = stof(dtbString);
    }
    inputFile.close();
}

void Xuat1SV(SINHVIEN sv) {
    printf("%30s%30s%30d%50s%30.2f\n", sv.MSSV, sv.hoten, sv.gioitinh, sv.diachi, sv.dtb);
}

void XuatDSSV(SINHVIEN dssv[], int n) {
    for (int i = 0; i < 170; i++) printf("-"); cout << endl;
    printf("%30s%30s%30s%50s%30s\n", "MSSV", "Ho va ten", "Gioi tinh", "Dia chi", "Diem trung binh");
    for (int i = 0; i < n; i++)
        Xuat1SV(dssv[i]);
    for (int i = 0; i < 170;i++) printf("-"); cout << endl;
}

int TimSV(SINHVIEN dssv[], int n, char maso[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(dssv[i].MSSV, maso) == 0)
            return i;
    }
    return -1;
}
void XoaSV(SINHVIEN dssv[], int &n, char maso[]) {
    int sttSv = TimSV(dssv, n, maso);
    if (sttSv == -1)
        cout << "Sinh vien khong co trong danh sach" << endl;
    else {
        for (int i = sttSv; i < n-1; i++)
            dssv[i] = dssv[i+1];
        n--;
    }
}

void SapTheoDTB(SINHVIEN dssv[], int n) {
    for (int i = 0; i < n; i++) {
        int minGPAIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (dssv[j].dtb < dssv[minGPAIndex].dtb)
                minGPAIndex = j;
        }
        if (minGPAIndex != i)
            Hoanvi(dssv[i], dssv[minGPAIndex]);
    }
}

void SapTheoHoTen(SINHVIEN dssv[], int n) {
    for (int i = 0; i < n; i++) {
        int minNameIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(dssv[j].hoten, dssv[minNameIndex].hoten) < 0)
                minNameIndex = j;
        }
        if (minNameIndex != i)
            Hoanvi(dssv[i], dssv[minNameIndex]);
    }
}

void Hoanvi(SINHVIEN &a, SINHVIEN &b) {
    SINHVIEN temp = a;
    a = b;
    b = temp;
}


