#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
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
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
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
        void swapFirstLast() {
            if (length == 0 || length == 1) return;
            int temp = head->value;
            head->value = tail->value;
            tail->value = temp;
        }
        void reverse() {
            if (length == 0) return;
            Node* before = nullptr;
            Node* temp = head;
            Node* after = temp->next;

            Node* swapVar = head;
            head = tail;
            tail = swapVar;

            while (temp) {
                temp->next = before;
                temp->prev = after;
                before = temp;
                temp = after;
                if (temp) after = temp->next;
            }
        }
};

int main() {
    DoublyLinkedList* dll = new DoublyLinkedList(1);
    dll->append(2);
    // dll->append(3);
    // dll->append(4);
    // dll->append(5);

    dll->reverse();

    dll->printList();
}