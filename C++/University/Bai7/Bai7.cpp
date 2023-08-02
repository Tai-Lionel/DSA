/* Khai bao thu vien */
#include <iostream>
#include <stdlib.h>
using namespace std;

/* Khai bao cau truc */
struct ttNODE {
    int Data;
    struct ttNODE *pNext;
};
typedef struct ttNODE NODE;
struct ttList {
    NODE *pHead, *pTail;
};
typedef struct ttList LIST;

/* Khai bao cac nguyen ham */
void KhoiTao(LIST &L);
void Huy(LIST &L);
NODE *TaoNode(int x);
void ThemDau(LIST &L, NODE *p);
void Nhap(LIST &L);
void Xuat(LIST L);
void XuatChan(LIST L);
int TongChan(LIST L);

/* Ham main */
int main() {
    LIST L;
    Nhap(L);
    cout << "\nDanh sach vua nhap: "; Xuat(L);
    cout << "\nDanh sach chan: "; XuatChan(L);
    cout << "\nTong chan: " << TongChan(L);
    Huy(L);
    
}

/* Cai dat cac ham con */

// Khoi tao danh sach lien ket - Linked List Constructor
void KhoiTao(LIST &L) {
    L.pHead=L.pTail=NULL;
}

// Huy danh sach lien ket - Linked List Destructor
void Huy(LIST &L) { 
    NODE* p = new NODE;
    while(L.pHead!=NULL) {
        p=L.pHead;
        L.pHead=L.pHead->pNext;
        delete p;
    }
}

// Tao mot node moi - Node Constructor
NODE *TaoNode(int x) {
    NODE *p;
    p=new NODE;
    if(p==NULL) {
        cout << "Khong cap phat duoc vung nho, ket thuc";
        exit(0);
    }
    p->Data=x;
    p->pNext=NULL;
    return p;
}

// Them dau - Prepend
void ThemDau(LIST &L, NODE *p) {
    if (L.pHead == NULL) {
        L.pHead = L.pTail = p;
    } else {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

// Them cuoi - Append
void ThemCuoi(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = L.pTail = p;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

// Nhap danh sach lien ket - multiple append
void Nhap(LIST &L) {
    int x;
    NODE *p;
    KhoiTao(L);
    do {
        cout << "Nhap gia tri vao danh sach (Nhap 0 ket thuc): ";
        cin >> x;
        if (x == 0) break;
        p = TaoNode(x);
        ThemCuoi(L, p);
    } while(true);
}

// Xuat danh sach lien ket - Print List
void Xuat(LIST L) {
    NODE *p=L.pHead;
    while (p != NULL) {
        cout<<p->Data<<" ";
        p=p->pNext;
    }
}

// Xuat chan
void XuatChan(LIST L) {
    NODE* p = L.pHead;
    while (p) {
        if (p->Data % 2 == 0)
            cout << p->Data << " ";
        p = p->pNext;
    }
}

int TongChan(LIST L) {
    int s = 0;
    NODE* p = L.pHead;
    while (p) {
        if (p->Data % 2 == 0)
            s += p->Data;
        p = p->pNext;
    }
    return s;
}

