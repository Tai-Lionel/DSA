/* Khai bao thu vien */
#include <iostream>
#include <stdlib.h>
#include <cmath>
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
NODE* TimMax(LIST L);
bool LaSNT(int x);
int DemSNT(LIST L);
NODE* TimChanDau(LIST L);
void ThemNewNodeTruocp(LIST &L, NODE* newNode, NODE* p);
void ThemXTruocChanDau(LIST &L, int X);
NODE* TimLeCuoi(LIST L);
void ThemXSauLeCuoi(LIST &L, int X);
NODE* TimMin(LIST L);
void XoaDau(LIST &L);
void XoaCuoi(LIST &L);
void XoaMin(LIST &L);
NODE* findNodeByValue(LIST &L, int X);
void removeNodeBeforeTarget(LIST &L, NODE* target);
void removeNodeAfterTarget(LIST &L, NODE* target);
void XoaTruocSau(LIST &L, int X);
void Tach(LIST L, LIST &L1, LIST &L2);

/* Ham main */
int main() {
    LIST L;
    Nhap(L);
    cout << "\nDanh sach vua nhap: "; Xuat(L);
    cout << "\nDanh sach chan: "; XuatChan(L);
    cout << "\nTong chan: " << TongChan(L);
    if(TimMax(L)) cout << "\nGia tri lon nhat: " << TimMax(L)->Data; else cout << "\nGia tri lon nhat: ";
    cout << "\nSo luong so nguyen to: " << DemSNT(L);
    int X; cout << "\nNhap gia tri muon them vao chan dau: "; cin >> X; ThemXTruocChanDau(L, X); cout << "Danh sach them gia tri vua nhap vao chan dau: "; Xuat(L);
    cout << "\nNhap gia tri muon them vao le cuoi: "; cin >> X; ThemXSauLeCuoi(L, X); cout << "Danh sach sau khi them gia tri vua nhap vao le cuoi: "; Xuat(L);
    XoaMin(L); cout << "\nDanh sach sau khi xoa gia tri nho nhat: "; Xuat(L);
    cout << "\nNhap gia tri muon xoa truoc va sau: "; cin >> X; XoaTruocSau(L, X); cout << "Danh sach sau khi xoa truoc sau: "; Xuat(L);
    LIST L1, L2; Tach(L, L1, L2); cout << "\nL1: "; Xuat(L1); cout << "\nL2: "; Xuat(L2);
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

// Tong chan
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

// Tim gia tri long nhat trong danh sach
NODE* TimMax(LIST L) {
    NODE* p = L.pHead;
    NODE* maxNode = L.pHead;
    while (p) {
        if (p->Data > maxNode->Data)
            maxNode = p;
        p = p->pNext;
    }
    return maxNode;
}

// La so nguyen to hay khong
bool LaSNT(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    for (int i = 2; i <= (int)sqrt(x); i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

// Dem so nguyen to
int DemSNT(LIST L) {
    int primeNum = 0;
    NODE* p = L.pHead;
    while (p) {
        if (LaSNT(p->Data))
            primeNum++;
        p = p->pNext;
    }
    return primeNum;
}

// Tim Node co gia tri chan dau tien
NODE* TimChanDau(LIST L) {
    NODE* p = L.pHead;
    while (p) {
        if (p->Data % 2 == 0)
            return p;
        p = p->pNext;
    }
    return p;
}

void ThemNewNodeTruocp(LIST &L, NODE* newNode, NODE* p) {
    if (L.pHead == L.pTail) ThemDau(L, newNode);
    if (L.pHead == p) ThemDau(L, newNode);
    if (L.pTail == p) ThemCuoi(L, newNode);
    NODE* pre = NULL;
    NODE* temp = L.pHead;
    while (temp != p) {
        pre = temp;
        temp = temp->pNext;
    }
    pre->pNext = newNode;
    newNode->pNext = temp;
}

void ThemXTruocChanDau(LIST &L, int X) {
    NODE* p = TimChanDau(L);
    NODE* newNode = TaoNode(X);
    if (p == NULL) {
        ThemDau(L, newNode);
        cout << "p is null\n";
    }
    else 
        ThemNewNodeTruocp(L, newNode, p);
}

NODE* TimLeCuoi(LIST L) {
    NODE* leCuoi = NULL;
    NODE* temp = L.pHead;
    while (temp) {
        if (temp->Data % 2 == 1)
            leCuoi = temp;
        temp = temp->pNext; 
    }
    return leCuoi;
}

void ThemXSauLeCuoi(LIST &L, int X) {
    NODE* newNode = TaoNode(X);
    NODE* p = TimLeCuoi(L);
    if (p == NULL)
        ThemCuoi(L, newNode);
    else {
        if (p == L.pTail) {
            ThemCuoi(L, newNode);
            return;
        }
        newNode->pNext = p->pNext;
        p->pNext = newNode;
    }
}

NODE* TimMin(LIST L) {
    if (L.pHead == L.pTail)
        return L.pHead;
    NODE* minNode = L.pHead;
    NODE* temp = L.pHead;
    while (temp) {
        if (temp->Data < minNode->Data)
            minNode = temp;
        temp = temp->pNext;
    }
    return minNode;
}

void XoaDau(LIST &L) {
    if (L.pHead == L.pTail)
        L.pHead = L.pTail = NULL;
    else { 
        NODE* temp = L.pHead;
        L.pHead = L.pHead->pNext;
        delete temp;
    }
}

void XoaCuoi(LIST &L) {
    if (L.pHead == L.pTail)
        L.pHead = L.pTail = NULL;
    else {
        NODE* temp = L.pHead;
        while (temp->pNext->pNext)
            temp = temp->pNext;
        L.pTail = temp;
        delete L.pTail->pNext;
        L.pTail->pNext = NULL;
    }
}

void XoaMin(LIST &L) {
    NODE* minNode = TimMin(L);
    if (minNode == L.pHead) XoaDau(L);
    else if (minNode == L.pTail) XoaCuoi(L);
    else {
        NODE* pre = NULL;
        NODE* p = L.pHead;
        while (p != minNode) {
            pre = p;
            p = p->pNext;
        }
        pre->pNext = p->pNext;
        delete p;
    }
}

NODE* findNodeByValue(LIST &L, int X) {
    NODE* temp = L.pHead;
    while (temp) {
        if (temp->Data == X)
            return temp;
        temp = temp->pNext;
    }
    return temp;
}

void removeNodeBeforeTarget(LIST &L, NODE* target) {
    if (L.pHead == nullptr || target == L.pHead) return;
    NODE* prepre = nullptr;
    NODE* pre = nullptr;
    NODE* temp = L.pHead;
    while (temp != target) {
        prepre = pre;
        pre = temp;
        temp = temp->pNext;
    }
    if (pre == L.pHead)
        XoaDau(L);
    else {
        prepre->pNext = target;
        delete pre;
    }
}

void removeNodeAfterTarget(LIST &L, NODE* target) {
    if (L.pHead == nullptr || target == L.pTail) return;
    if (target->pNext->pNext == nullptr) {
        XoaCuoi(L);
        return;
    }
    NODE* temp = L.pHead;
    while (temp != target)
        temp = temp->pNext;
    NODE* aboutRemoved = temp->pNext;
    temp->pNext = temp->pNext->pNext;
    delete aboutRemoved;
}

void XoaTruocSau(LIST &L, int X) {
    NODE* target = findNodeByValue(L, X);
    if (target) {
        removeNodeBeforeTarget(L, target);
        removeNodeAfterTarget(L, target);
    }
}

void Tach(LIST L, LIST &L1, LIST &L2) {
    KhoiTao(L1); KhoiTao(L2);
    NODE* temp = L.pHead;
    while (temp) {
        NODE* newNode = TaoNode(temp->Data);
        if (LaSNT(temp->Data)) ThemCuoi(L1, newNode);
        else ThemCuoi(L2, newNode);
        temp = temp->pNext;
    }
}