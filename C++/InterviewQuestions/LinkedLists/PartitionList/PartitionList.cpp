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

        void partitionList(int x) {
            if (head->next == nullptr) return;
            Node* preSwapNode = nullptr;
            Node* swapNode = nullptr;

            Node* dummy = new Node(x-1);
            dummy->next = head;
            head = dummy;            

            Node* temp = head;
            Node* pre = nullptr;
            for (int i = 0; i < length; i++) {
                if (temp->value >= x) {
                    preSwapNode = pre;
                    swapNode = temp;
                    break;
                }
                pre = temp;
                temp = temp->next;
            }

            Node* preCurrentNode = head->next;
            Node* currentNode = head->next->next;
            while (currentNode) {
                if (currentNode->value < x) {
                    Node* newNode = new Node(currentNode->value);
                    preSwapNode->next = newNode;
                    newNode->next = swapNode;
                    preSwapNode = newNode;
                    preCurrentNode->next = currentNode->next;
                    delete currentNode;
                    currentNode = preCurrentNode->next;
                } else {
                    preCurrentNode = currentNode;
                    currentNode = currentNode->next;
                }
            }
            head = head->next;
        }

};

int main() {
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(4);
    myLinkedList->append(3);
    myLinkedList->append(2);
    myLinkedList->append(5);
    myLinkedList->append(2);
    myLinkedList->partitionList(5);
    myLinkedList->printList();
}