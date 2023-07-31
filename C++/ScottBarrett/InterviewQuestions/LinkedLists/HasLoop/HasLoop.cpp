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
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
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
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        bool hasLoop(bool author) {
            Node* temp = head;
            while (temp->next) {
                if (tail->next == temp)
                    return true;
                temp = temp->next;
            }
            return false;
        }

        bool hasLoop() {
            Node* slow = head;
            Node* fast = head;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast)
                    return true;
            }
            return false;
        }
};

int main() {
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(6);
    myLinkedList->append(7);

    myLinkedList->getTail()->next = myLinkedList->getHead()->next->next;

    cout << myLinkedList->hasLoop() << endl;
}