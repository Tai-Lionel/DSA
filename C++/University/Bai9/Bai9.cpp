#include <iostream>
#include <cstring>

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
void Them1SinhVien(LinkedList &l, SinhVien sv);
void deleteStudentById(LinkedList &l, char id[]);
void sort(LinkedList &l);
void listGPA5(LinkedList l);
int numMale(LinkedList l);
void updateGPAById(LinkedList l, char id[]);

int main() {
    int n; cout << "Nhap so luong sinh vien: "; cin >> n;
    LinkedList dssv;
    input(dssv, n);
    output(dssv);
    SinhVien sv; input1Student(sv); Them1SinhVien(dssv, sv); cout << "Danh sach sinh vien moi: " << endl; output(dssv); 
    char id[10]; cout << "\nNhap mssv can xoa: " ; cin >> id ;deleteStudentById(dssv, id); cout << "Danh sach sinh vien moi: " << endl; output(dssv);
    sort(dssv); cout << "Danh sach sinh vien sau khi sap xep theo thu tu tang dan cua diem trung binh: " << endl; output(dssv);
    cout << "Danh sach sinh vien co diem trung binh lon hon hoac bang 5: " << endl; listGPA5(dssv);
    cout << "So luong sinh vien nam: " << numMale(dssv) << endl;
    cout << "Nhap mssv can thay doi diem trung binh: "; cin >> id; updateGPAById(dssv, id); output(dssv);
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
    if (l.head == nullptr) {
        l.head = newNode;
        l.tail = newNode;
    } else {
        l.tail->next = newNode;
        l.tail = newNode;
    }
}

void input1Student(SinhVien &sv) {
    cout << "Nhap thong tin sinh vien: " << endl;
    cout << "Ma so sinh vien: "; fflush(stdin); gets(sv.mssv);
    cout << "Ho ten: "; fflush(stdin);; gets(sv.hoten);
    cout << "Gioi tinh: "; fflush(stdin);; cin >> sv.gioitinh;
    cout << "Dia chi: "; fflush(stdin); gets(sv.diachi);
    cout << "Diem trung binh: "; fflush(stdin); cin >> sv.dtb;
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
    printf("%30s%30s%30d%50s%30.2f\n", sv.mssv, sv.hoten, sv.gioitinh, sv.diachi, sv.dtb);
}

void output(LinkedList l) {
    printf("%30s%30s%30s%50s%30s\n", "MSSV", "Ho va ten", "Gioi tinh", "Dia chi", "Diem trung binh");
    Node* temp = l.head;
    while (temp) {
        output1Student(temp->sv);
        temp = temp->next;
    }
}

void Them1SinhVien(LinkedList &l, SinhVien sv) {
    Node* newNode = constructNode(sv);
    append(l, newNode);
}

Node* findStudentById(LinkedList l, char id[]) {
    Node* temp = l.head;
    while (temp) {
        if (strcmp(temp->sv.mssv, id) == 0)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void deleteFirst(LinkedList &l) {
    if (l.head == nullptr) return;
    if (l.head == l.tail) {
        l.head = nullptr;
        l.tail = nullptr;
    } else {
        Node* temp = l.head;
        l.head = l.head->next;
        delete temp;
    }
}

void deleteLast(LinkedList &l) {
    if (l.head == nullptr) return;
    if (l.head == l.tail) {
        l.head = nullptr;
        l.tail = nullptr;
    } else {
        Node* temp = l.head;
        while (temp->next->next)
            temp = temp->next;
        l.tail = temp;
        delete l.tail->next;
        l.tail->next = nullptr;
    }
}

void deleteStudent(LinkedList &l, Node* target) {
    if (target == l.head) deleteFirst(l);
    else if (target == l.tail) deleteLast(l);
    else {
        Node* pre = nullptr;
        Node* temp = l.head;
        while (temp != target) {
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;
        delete(temp);
    }
}

void deleteStudentById(LinkedList &l, char id[]) {
    Node* sv = findStudentById(l, id);
    if (sv) deleteStudent(l, sv);
}

void sort(LinkedList &l) {
    Node* sortedNode = nullptr;
    while (sortedNode != l.head) {
        Node* temp = l.head;
        while (temp->next != sortedNode) {
            if (temp->sv.dtb > temp->next->sv.dtb) {
                SinhVien swapVariable = temp->sv;
                temp->sv = temp->next->sv;
                temp->next->sv = swapVariable;
            }
            temp = temp->next;
        }
        sortedNode = temp;
    }
}

void listGPA5(LinkedList l) {
    printf("%30s%30s%30s%50s%30s\n", "MSSV", "Ho va ten", "Gioi tinh", "Dia chi", "Diem trung binh");
    Node* temp = l.head;
    while (temp) {
        if (temp->sv.dtb >= 5)
            output1Student(temp->sv);
        temp = temp->next;
    }
    cout << endl;
}

int numMale(LinkedList l) {
    Node* temp = l.head;
    int num = 0;
    while (temp) {
        if (temp->sv.gioitinh == 0)
            num++;
        temp = temp->next;
    }
    return num;
}

void updateGPAById(LinkedList l, char id[]) {
    Node* sv = findStudentById(l, id);
    int dtb; cout << "Nhap diem trung binh moi: "; cin >> dtb;
    if (sv) sv->sv.dtb = dtb;
}
