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
        int length;

    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
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

        int getLength() {
            return length;
        }

		void append(int value) {
			Node* newNode = new Node(value);
			if (length == 0) {
				head = newNode;
			} else {
				Node* currentNode = head;
				while (currentNode->next != nullptr) {
					currentNode = currentNode->next;
				}
				currentNode->next = newNode;
				newNode->prev = currentNode;
			}
			length++;
		}

        void swapPairs() {
            Node* current = head;
            while (current && current->next) {
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                current = current->next->next;
            }
        }
        
};

int main() {
    DoublyLinkedList* dll = new DoublyLinkedList(1);
    dll->append(2);
    dll->append(3);
    dll->append(4);

    dll->swapPairs();
    dll->printList();
}