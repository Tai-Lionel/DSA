#include <iostream>

using namespace std;


class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
        }

        ~LinkedList() {
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

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    
        Node* findKthFromEnd(int k) {
            Node* slow = head;
            Node* fast = head;
            while (fast) {
                slow = slow->next;
                for (int i = 0; i < k; i++) {
                    if (fast != nullptr) fast = fast->next;
                }
            } 
            return slow;
        }
};

int main() {
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(6);
    myLinkedList->append(7);

    cout << myLinkedList->findKthFromEnd(4)->value << endl;
}