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

        bool isPalindrome() {
            Node* firsty = head;
            Node* lasty = tail;
            for (int i = 0; i < length/2; i++) {
                if (firsty->value != lasty->value)
                    return false;
                firsty = firsty->next;
                lasty = lasty->prev;
            }
            return true;
        }

};

int main() {
    DoublyLinkedList* dll = new DoublyLinkedList(1);
    dll->append(2);
    dll->append(2);
    dll->append(1);

    if (dll->isPalindrome()) {
        cout << "is a palindrome";
    } else {
        cout << "is not a palindrome";
    }
}