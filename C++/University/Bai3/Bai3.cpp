#include <iostream>
#include <ctime>

using namespace std;

void PhatSinhMangTang(int a[], int N) {
    srand(time(0));

    int previousValue = rand() % 100 + 1; 
    a[0] = previousValue;

    for (int i = 1; i < N; i++) {
        int increment = rand() % 20 + 1; // between 1 and 20
        int nextValue = previousValue + increment;
        a[i] = nextValue;
        previousValue = nextValue;
    }
}

void XuatMang(int a[], int N) {
    cout << "Mang phat sinh: ";
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int TimTuyenTinh(int a[], int N, int X, int &ss) {
    for (int i = 0; i < N; i++) {
        ss++;
        if (a[i] == X) {
            return i;
        }
    }
    return -1;
}

int TimNhiPhan(int a[], int N, int X, int &ss) {
    int start = 0;
    int end = N-1;
    
    while (start <= end) {
        int mid = start + (end-start)/2;
        ss++;
        if (a[mid] == X)
            return mid;
        else if (a[mid] > X) {
            end = mid-1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int N;
    cout << "Nhap do dai cua mang: ";
    cin >> N;
    int a[N];
    PhatSinhMangTang(a, N);
    XuatMang(a, N);
    
    int X;
    cout << "Nhap so can tim: ";
    cin >> X;

    cout << "\nKet qua tim tuyen tinh: \n";
    int ssTT = 0;
    int ketQuaTimTuyenTinh = TimTuyenTinh(a, N, X, ssTT);
    if (ketQuaTimTuyenTinh == -1)
        cout << "Khong tim thay" << endl;
    else
        cout << "So can tim nam o vi tri: " << ketQuaTimTuyenTinh << endl;
    cout << "So lan so sanh " << ssTT << endl;

    cout << "\nKet qua tim nhi phan: \n";
    int ssNP;
    int ketQuaTimNhiPhan = TimNhiPhan(a, N, X, ssNP);
    if (ketQuaTimNhiPhan == -1)
        cout << "Khong tim thay" << endl;
    else
        cout << "So can tim nam o vi tri: " << ketQuaTimNhiPhan << endl;
    cout << "So lan so sanh: " << ssNP << endl;
    return 0;
}