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
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
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

        int getLength() {
            return length;
        }

		void append(int value) {
			Node* newNode = new Node(value);
			if (head == nullptr) {
				head = newNode;
			} else {
				Node* currentNode = head;
				while (currentNode->next != nullptr) {
					currentNode = currentNode->next;
				}
				currentNode->next = newNode;
			}
			length++;
		}
        void reverseBetween(int m, int n, bool author) {
            Node* before = head;
            for (int i = 0; i < m-1; i++) {
                before = before->next;
            }
            Node* first = before->next;

            Node* last = head;
            for (int i = 0; i < n; i++) {
                last = last->next;
            }
            Node* after = last->next;
            
            Node* pre = nullptr;
            Node* temp = first;
            Node* sub = temp->next;

            while (temp != after) {
                temp->next = pre;
                pre = temp;
                temp = sub;
                if (temp != nullptr)
                    sub = temp->next;
            }

            first->next = after;
            before->next = pre;
        }

        void reverseBetween(int m, int n) {
            if (head == nullptr) return;

            Node* dummy = new Node(0);
            dummy->next = head;
            
            //first
            Node* prev = dummy;
            for (int i = 0; i < m; i++) {
                prev = prev->next;
            }

            //second
            Node* current = prev->next;

            for (int i = 0; i < n - m; i++) {
                Node* temp = current->next;
                current->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }
            head = dummy->next;
            delete dummy;
        }
};

int main() {
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->append(6);
    myLinkedList->append(7);
    myLinkedList->append(8);
    myLinkedList->append(9);
    myLinkedList->append(10);

    myLinkedList->reverseBetween(1, 3, true);
    myLinkedList->printList();
}