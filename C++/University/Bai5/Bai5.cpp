#include <iostream>
#include <ctime>

using namespace std;

// Ham phat sinh mang
void phatSinhMang(int a[], int N) {
    int chon;
    cout << "Nhap lua chon: " << endl;
    cout << "1. Mang tang" << endl;
    cout << "2. Mang giam" << endl;
    cout << "3. Mang ngau nhien" << endl;
    cin >> chon;
    if (chon == 1) {
        int previousValue = rand() % 1000 + 1; 
        a[0] = previousValue;

        for (int i = 1; i < N; i++) {
            int increment = rand() % 20 + 1; // between 1 and 20
            int nextValue = previousValue + increment;
            a[i] = nextValue;
            previousValue = nextValue;
        }
    } else if (chon == 2) {
        int previousValue = rand() % 1000 + 100; 
        a[0] = previousValue;

        for (int i = 1; i < N; i++) {
            int decrement = rand() % 20 + 1; // between 1 and 20
            int nextValue = previousValue - decrement;
            a[i] = nextValue;
            previousValue = nextValue;
        }
    } else {
        for (int i = 0; i < N; i++) {
            a[i] = rand() % 100000 + 1;
        }
    }
}

// Ham xuat mang
void xuatMang(int a[], int N) {
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Ham sap xep mang theo kieu chon truc tiep - Selection Sort
void SapXepChonTrucTiep(int a[], int N, int &ss, int &g) {
    ss = 0;
    g = 0;
    for (int i = 0; i < N; i++) {
        int minIndex = i;
        for (int j = i + 1; j < N; j++) {
            ss++;
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (i != minIndex) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
            g+=3;
        }
        // cout << "Buoc " << i + 1 << ": ";
        // xuatMang(a, N);
    }
}

// Ham sap xep mang theo kieu chen truc tiep - Insertion Sort
void SapXepChenTrucTiep(int a[], int N, int &ss, int &g) {
    ss = 0;
    g = 0;
    for (int i = 1; i < N; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            ss++;
            g++;
        }
        a[j + 1] = key;
        g++;
        // cout << "Buoc " << i << ": ";
        // xuatMang(a, N);
    }
}

// Ham sap xep mang theo kieu noi bot - Bubble Sort
void SapXepNoiBot(int a[], int N, int &ss, int &g) {
    ss = 0;
    g = 0;
    for (int i = N-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            ss++;
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                g+=3;
            }
        }
        // cout << "Buoc " << N - i << ": ";
        // xuatMang(a, N);
    }
}

// Ham sap xep mang theo kieu doi cho truc tiep - Interchange Sort
void SapXepDoiChoTrucTiep(int a[], int N, int &ss, int &g) {
    ss = 0;
    g = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            ss++;
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j]= temp;
                g+=3;
            }
        }
        // cout << "Buoc " << i+1 << ": ";
        // xuatMang(a, N);
    }
}

// Ham sap xep mang theo kieu pivot - Quick Sort

int pivot(int a[], int pivotIndex, int endIndex, int &ss, int &g, int N) {
    int swapIndex = pivotIndex;
    for (int i = pivotIndex+1; i <= endIndex; i++) {
        ss++;
        if (a[i] < a[pivotIndex]) {
            swapIndex++;
            int temp = a[swapIndex];
            a[swapIndex] = a[i];
            a[i]= temp;
            g+=3;
        }
        
    }
    int temp = a[pivotIndex];
    a[pivotIndex] = a[swapIndex];
    a[swapIndex] = temp;
    g+=3;
    // xuatMang(a, N);
    return swapIndex;

}

void QuickSort(int a[], int leftIndex, int rightIndex, int &ss, int &g, int N) {
    if (leftIndex >= rightIndex) return;
    int pivotIndex = pivot(a, leftIndex, rightIndex, ss, g, N);
    QuickSort(a, leftIndex, pivotIndex-1, ss, g, N);
    QuickSort(a, pivotIndex+1, rightIndex, ss, g, N);
}

void QuickSort(int a[], int N, int &ss, int &g) {
    ss = 0;
    g = 0;
    QuickSort(a, 0, N-1, ss, g, N);
}

int main() {
    /* Khai bao va khoi tao mang*/
    int N;
    cout << "Nhap so phan tu cua mang: ";
    cin >> N;
    int a[N];
    phatSinhMang(a, N);
    cout << "Mang phat sinh: " << endl;
    xuatMang(a, N);

    /* Sap xep mang*/
    int ss, g;
    QuickSort(a, N, ss, g);

    /* In ket qua*/
    cout << "Mang sau khi sap xep: " << endl;
    xuatMang(a, N);
    cout << "So lan so sanh: " << ss << endl;
    cout << "So lan gan: " << g << endl;
}