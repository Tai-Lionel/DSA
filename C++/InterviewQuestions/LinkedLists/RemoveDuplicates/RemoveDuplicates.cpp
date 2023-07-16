#include <iostream>
#include <unordered_set>

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

        void removeDuplicates() {
            Node* current = head;
            while (current != nullptr) {
                Node* pre = current;
                Node* after = current->next;
                while (after != nullptr) {
                    if (after->value == current->value) {
                        Node* aboutDeleted = after;
                        pre->next = after->next;
                        delete aboutDeleted;
                        length--;
                        after = pre;
                    }
                    pre = after;
                    after = after->next;
                }
                current = current->next;
            }
        }

};

int main() {
    LinkedList* ll = new LinkedList(1);
    ll->append(2);
    ll->append(3);
    ll->append(2);
    ll->append(4);
    ll->append(5);
    ll->append(3);
    ll->append(3);
    ll->append(3);
    ll->append(3);

    ll->removeDuplicates();
    ll->printList();
}