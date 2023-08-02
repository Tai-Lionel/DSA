#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef struct {
    char MSSV[10], hoten[30];
    int gioitinh; //1: nữ, 0: nam
    char diachi[50];
    float dtb;
} SINHVIEN;

int main() {
    ifstream inputFile;
    inputFile.open("filename.txt");

    if (!inputFile.is_open()) {
        std::cout << "Error: Unable to open the file." << std::endl;
        return 1;
    }

    string nString;
    getline(inputFile, nString);
    int n = stoi(nString);
    cout << n << endl;

    SINHVIEN dssv[n];
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

    printf("%30s%30s%30s%50s%30s\n", "MSSV", "Ho va ten", "Gioi tinh", "Dia chi", "Diem trung binh");
    for (int i = 0; i < n; i++)
        printf("%30s%30s%30d%50s%30.2f\n", dssv[i].MSSV, dssv[i].hoten, dssv[i].gioitinh, dssv[i].diachi, dssv[i].dtb);

    inputFile.close();

}