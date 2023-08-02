#include <iostream>
using namespace std;

// Ham nhap mang dong
void nhapMangDong(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i+1 << ": ";
        cin >> arr[i];
    }
}

// Ham tim gia tri nho nhat
int timGiaTriNhoNhat(int* arr, int n) {
    int minValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minValue)
            minValue = arr[i];
    }
    return minValue;
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int* mangDong = new int[n];
    nhapMangDong(mangDong, n);
    cout << "Phan tu co gia tri nho nhat trong mang la: " << timGiaTriNhoNhat(mangDong, n) << endl;
}