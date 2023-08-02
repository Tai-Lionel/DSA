#include <iostream>
using namespace std;

// Ham nhap mang tinh
void nhapMangTinh(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i+1 << ": ";
        cin >> arr[i];
    }
}

// Ham tim gia tri nho nhat
int timGiaTriNhoNhatTinh(int arr[], int n) {
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
    int mangTinh[n];
    nhapMangTinh(mangTinh, n);
    int minValue = timGiaTriNhoNhatTinh(mangTinh, n);
    cout << "Phan tu co gia tri nho nhat trong mang tinh la: " << minValue;
    return 0;
}