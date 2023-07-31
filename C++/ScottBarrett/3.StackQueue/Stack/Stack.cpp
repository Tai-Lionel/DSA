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

class Stack {
    private: 
        Node* top;
        int height;
    public:
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }
        ~Stack() {
            while(top) {
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }
        void printStack() {
            Node* temp = top;
            while (temp) {
                cout << temp->value <<endl;
                temp = temp->next;
            }
        }
        Node* getTop() {
            return top;
        }
        int getHeight() {
            return height;
        }
        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }
        int pop() {
            if (height == 0) return INT_MIN;
            int poppedValue = top->value; 
            Node* temp = top;
            top = top->next;
            delete temp;
            height--;
            return poppedValue;
        }
};

int main() {
    Stack* myStack = new Stack(1);

    cout << "Popped value: " << myStack->pop() << endl;
    cout << "Popped value: " << myStack->pop() << endl;
}