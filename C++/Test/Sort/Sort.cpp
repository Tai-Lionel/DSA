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
        ~LinkedList() {
            Node* temp = head;
            while (head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
        int getHead() {
            if (length == 0) return -1;
            return this->head->value;
        }
        int getTail() {
            if (length == 0) return -1;
            return this->tail->value;
        }
        int getLength() {
            return this->length;
        }
        void printList() {
            Node* temp = this->head;
            while (temp != nullptr) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
        void append(int value) {
            /* have the last node points to the new node
            then have the tail points to the new node */
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            this->length++;
        }
        void deleteLast() {
            /* have the tail points to the second last node
            have that second last node points to nowhere*/
            if (length == 0) return;
            if (length == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Node* temp = head;
                Node* pre = head;
                // temp points to the last node, stop
                while (temp->next != nullptr) {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
                delete temp;
            }
            length--;
        }
        void prepend(int value) {
            /* have the new node points to the first node
            have the head points to the new node */
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }
        void deleteFirst() {
            /* have the head points to the second node */
            if (length == 0) return;
            if (length == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            length--;
        }
        Node* get(int index) {
            if (index < 0 || index >= length) 
                return nullptr;
            Node* temp = head;
            for (int i = 0; i < index; i++)
                temp = temp->next;
            return temp;
        }
        bool set(int index, int value) {
            Node* temp = get(index);
            if (!temp)
                return false;
            temp->value = value;
            return true;
        }
        bool insert(int index, int value) {
            /* have the new node points to the result node
            have the preNode poinst to the new node */
            if (index < 0 || index > length)
                return false;
            if (index == 0) {
                prepend(value);
                return true;
            }
            if (index == length) {
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* temp = get(index-1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }
        void deleteNode(int index) {
            /* have the pre points to the result node */
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst();
            if (index == length - 1) return deleteLast();
            Node* pre = get(index-1);
            Node* temp = temp->next;
            pre->next = temp->next;
            delete temp;
            length--;
        }
        void reverse() {
            if (length == 0) return;
            tail = head;
            Node* pre = nullptr;
            Node* temp = head;
            Node* sub = head->next;
            while (temp != nullptr) {
                temp->next = pre;
                pre = temp;
                temp = sub;
                if (sub != nullptr)
                    sub = sub->next;
            }
            head = pre;
        }
        void bubbleSort() {
            if (length == 0) return;
            Node* dummy = new Node(0);
            dummy->next = head;
            head = dummy;
            
            Node* pre = head;
            Node* temp = head->next;
            Node* sub = temp->next;
            Node* last = tail;

            int tempLength = length;
            while (last != head) {
                pre = head;
                temp = pre->next;
                sub = temp->next;
                for (int i = 0; i < tempLength; i++) {
                    if (temp->value > sub->value) {
                        temp->next = sub->next;
                        pre->next = sub;
                        sub->next = temp;
                        temp = pre->next;
                        sub = temp->next;
                    }
                    pre = temp;
                    temp = sub;
                    sub = sub->next;
                }
                tempLength--;
                printList();
                last = pre;
            }
            head = head->next;
        }

};

int main() {
    LinkedList* myLinkedList = new LinkedList(3);
    myLinkedList->append(6);
    myLinkedList->append(2);
    myLinkedList->append(12);
    myLinkedList->append(5);

    myLinkedList->bubbleSort();
    
    cout << "List: "; myLinkedList->printList();
    
}