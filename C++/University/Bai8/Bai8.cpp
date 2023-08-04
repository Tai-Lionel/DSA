#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

Node* constructNode(int value);
void constructLinkedList(LinkedList &l);
void destroy(LinkedList &l);
void append(LinkedList &l, Node* newNode);
void input(LinkedList &l);
void output(LinkedList l);
void sort(LinkedList &l);
void link(LinkedList l1, LinkedList l2, LinkedList &l3);

int main() {
    LinkedList l1, l2;
    cout << "Nhap danh sach lien ket thu nhat: " << endl; input(l1); 
    cout << "Nhap danh sach lien ket thu hai: " << endl; input(l2);
    cout << "Danh sach lien ket thu nhat: "; output(l1);
    cout << "\nDanh sach lien ket thu hai: "; output(l2);
    sort(l1); sort(l2);
    cout << "\nSau khi sap xep: ";
    cout << "\nDanh sach lien ket thu nhat: "; output(l1);
    cout << "\nDanh sach lien ket thu hai: "; output(l2);
    LinkedList l3; link(l1, l2, l3); cout << "\nDanh sach lien ket noi danh sach thu nhat va danh sach thu hai: "; output(l3);
    destroy(l1); destroy(l2); destroy(l3);
}

Node* constructNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

void constructLinkedList(LinkedList &l) {
    l.head = l.tail = nullptr;
}

void destroy(LinkedList &l) {
    while (l.head) {
        Node* temp = l.head;
        l.head = l.head->next;
        delete temp;
    }
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

void input(LinkedList &l) {
    constructLinkedList(l);
    int value;
    do {
        cout << "Nhap gia tri vao danh sach (Nhap 0 de ket thuc): ";
        cin >> value;
        if (value == 0) break;
        Node* newNode = constructNode(value);
        append(l, newNode);
    } while (true);
}

void output(LinkedList l) {
    Node* temp = l.head;
    while (temp) {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

void sort(LinkedList &l) {
    Node* sortedNode = nullptr;
    while (sortedNode != l.head) {
        Node* before = nullptr;
        Node* temp = l.head;
        Node* after = temp->next;
        while (after != sortedNode) {
            if (temp->value > after->value) {
                if (temp == l.head) {
                    temp->next = after->next;
                    after->next = temp;
                    l.head = after;
                } else {
                    temp->next = after->next;
                    after->next = temp;
                    before->next = after;
                    if (after == l.tail) l.tail = temp;
                }
                Node* swapVariable = temp;
                temp = after;
                after = swapVariable;
            }
            before = temp;
            temp = after;
            after = temp->next;
        }
        sortedNode = temp;
    }
}

void link(LinkedList l1, LinkedList l2, LinkedList &l3) {
    Node* temp1 = l1.head;
    Node* temp2 = l2.head;
    constructLinkedList(l3);
    while (temp1 && temp2) {
        if (temp1->value < temp2->value) {
            Node* newNode = constructNode(temp1->value);
            append(l3, newNode);
            temp1 = temp1->next;
        } else {
            Node* newNode = constructNode(temp2->value);
            append(l3, newNode);
            temp2 = temp2->next;
        }
    }
    while (temp1) {
        Node* newNode = constructNode(temp1->value);
        append(l3, newNode);
        temp1 = temp1->next;
    }
    while (temp2) {
        Node* newNode = constructNode(temp2->value);
        append(l3, newNode);
        temp2 = temp2->next;
    }
}