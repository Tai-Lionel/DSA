#include <iostream>
#include <ctime>

using namespace std;

void PhatSinhMang(int a[], int N) {
    srand(time(0));

    int c = rand() % 3 + 1;

    if (c == 1) {
        int previousValue = rand() % 100 + 1; 
        a[0] = previousValue;

        for (int i = 1; i < N; i++) {
            int increment = rand() % 20 + 1; // between 1 and 20
            int nextValue = previousValue + increment;
            a[i] = nextValue;
            previousValue = nextValue;
        }
    } else if (c == 2) {
        int previousValue = rand() % 100 + 1; 
        a[0] = previousValue;

        for (int i = 1; i < N; i++) {
            int decrement = rand() % 20 + 1; // between 1 and 20
            int nextValue = previousValue - decrement;
            a[i] = nextValue;
            previousValue = nextValue;
        }
    } else {
        for (int i = 0; i < N; i++) {
            a[i] = rand() % 100 + 1;
        }
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
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int TimNhiPhan2(int a[], int N, int X, int &ss) {
    int start = 0;
    int end = N-1;

    while (start <= end) {
        int mid = start + (end-start)/2;
        ss++;
        if (a[mid] == X) 
            return mid;
        else if (a[mid] > X)
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return -1;
}

bool KiemTraTang(int a[], int N) {
    for (int i = 1; i < N; i++) {
        if (a[i] <= a[i-1])
            return false;
    }
    return true;
}

bool KiemTraGiam(int a[], int N) {
    for (int i = 1; i < N; i++) {
        if (a[i] >= a[i-1])
            return false;
    }
    return true;
}


int main() {
    int N;
    cout << "Nhap do dai cua mang: ";
    cin >> N;
    int a[N];
    PhatSinhMang(a, N);
    XuatMang(a, N);
    
    int X;
    cout << "Nhap so can tim: ";
    cin >> X;

    cout << "\nKet qua tim kiem: \n";
    int ss = 0;
    int ketQuaTimKiem;
    if (KiemTraTang(a, N))
        ketQuaTimKiem = TimNhiPhan(a, N, X, ss);
    else if (KiemTraGiam(a, N))
        ketQuaTimKiem = TimNhiPhan2(a, N, X, ss);
    else
        ketQuaTimKiem = TimTuyenTinh(a, N, X, ss);
    if (ketQuaTimKiem == -1)
        cout << "Khong tim thay" << endl;
    else
        cout << "So can tim nam o vi tri: " << ketQuaTimKiem << endl;
    cout << "So lan so sanh " << ss << endl;
}