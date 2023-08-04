#include <iostream>
#include <iomanip>
#include <stdio.h> // Include this header for printf and gets

using namespace std;

typedef struct SinhVien {
    char mssv[10];
    char hoten[30];
    int gioitinh;
    char diachi[50];
    float dtb;
} SinhVien;

typedef struct Node {
    SinhVien sv;
    Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

Node* constructNode(SinhVien sv);
void constructLinkedList(LinkedList &l);
void append(LinkedList &l, Node* newNode);
void input1Student(SinhVien &sv);
void input(LinkedList &l, int n);
void output1Student(SinhVien sv);
void output(LinkedList l);

int main() {
    int n; cout << "Nhap so luong sinh vien: "; cin >> n;
    LinkedList dssv;
    input(dssv, n);
    output(dssv);
}

Node* constructNode(SinhVien sv) {
    Node* newNode = new Node;
    newNode->sv = sv;
    newNode->next = nullptr;
    return newNode;
}

void constructLinkedList(LinkedList &l) {
    l.head = l.tail = nullptr;
}

void append(LinkedList &l, Node* newNode) {
    if (l.head == nullptr) { // Use comparison operator (==) here
        l.head = newNode;
        l.tail = newNode;
    } else {
        l.tail->next = newNode;
        l.tail = newNode;
    }
}

void input1Student(SinhVien &sv) {
    cout << "\nNhap thong tin sinh vien: ";
    cout << "\nMa so sinh vien: "; cin.ignore(); cin.getline(sv.mssv, 10);
    cout << "Ho ten: "; cin.getline(sv.hoten, 30);
    cout << "Gioi tinh: "; cin >> sv.gioitinh;
    cout << "Dia chi: "; cin.ignore(); cin.getline(sv.diachi, 50);
    cout << "Diem trung binh: "; cin >> sv.dtb;
}

void input(LinkedList &l, int n) {
    constructLinkedList(l);
    SinhVien sv;
    for (int i = 0; i < n; i++) {
        input1Student(sv);
        Node* newNode = constructNode(sv);
        append(l, newNode);
    }
}

void output1Student(SinhVien sv) {
    cout << setw(10) << sv.mssv << setw(30) << sv.hoten << setw(15) << sv.gioitinh << setw(30) << sv.diachi << setw(10) << sv.dtb << endl;
}

void output(LinkedList l) {
    cout << setw(10) << "MSSV" << setw(30) << "Ho va ten" << setw(15) << "Gioi tinh" << setw(30) << "Dia chi" << setw(10) << "Diem trung binh" << endl;
    Node* temp = l.head;
    while (temp) {
        output1Student(temp->sv);
        temp = temp->next;
    }
}
