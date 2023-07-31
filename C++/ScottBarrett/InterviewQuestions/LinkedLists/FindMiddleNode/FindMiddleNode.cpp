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

        int getHead() {
            if (head == nullptr) {
                return -1;
            } else {
                return head->value;
            }
        }

        int getTail() {
            if (tail == nullptr) {
                return -1;
            } else { 
                return tail->value;
            }  
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
        
        Node* findMiddleNode(bool author) {
            // find the length of the linked list
            Node* temp = head;
            int length;
            if (head == nullptr)
                return head;
            length = 0;
            while (temp) {
                length++;
                temp = temp->next;
            }
            // go to the middle one
            temp = head;
            for (int i = 0; i < length/2; i++) {
                temp = temp->next;
            }
            return temp;
        }

        // "tortoise and hare" algorithm
        Node* findMiddleNode() {
            Node* slow = head;
            Node* fast = head;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
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

    cout << myLinkedList->findMiddleNode()->value << endl;
}

