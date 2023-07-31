#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        ~DoublyLinkedList() {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
        void printList() {
            Node* temp = head;
            if (temp == nullptr) 
                cout << "Empty List" << endl;
            while (temp != nullptr) {
                cout << temp->value <<endl;
                temp = temp->next;
            }
        }
        Node* getHead() {
            return head;
        }
        Node* getTail() {
            return tail;
        }
        int getLength() {
            return length;
        }
        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
        void deleteLast() {
            if (length == 0) return;
            Node* temp = tail;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp; 
            length--;
        }
        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length--;
        }
        Node* get(int index) {
            if (index < 0 || index >= length) 
                return nullptr;
            Node* temp = head;
            if (index < length/2) {
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
            } else {
                temp = tail;
                for (int i = length-1; i > index; i--) {
                    temp = temp->prev;
                }
            }
            return temp;
        }
        bool set(int index, int value) {
            Node* temp = get(index);
            if (temp == nullptr) 
                return false;
            temp->value = value;
            return true;
        }
        bool insert(int index, int value) {
            if (index < 0 || index > length) 
                return false;
            if (index == 0) {
                prepend(value);
                length++;
                return true;
            }
            if (index == length) {
                append(value);
                length++;
                return true;
            }
            Node* newNode = new Node(value);
            Node* temp = get(index);
            temp->prev->next = newNode;
            newNode->next = temp->prev;
            temp->prev = newNode;
            newNode->next = temp;
            length++;
            return true;
        }
        void deleteNode(int index) {
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst();
            if (index == length - 1) return deleteLast();
            if (length == 0) return;
            Node* temp = get(index);
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            length--;
        }
};

int main() {
    DoublyLinkedList* dll = new DoublyLinkedList(4);
    dll->append(3);
    dll->append(6);
    dll->append(8);

    dll->deleteNode(0);

    dll->printList();
}