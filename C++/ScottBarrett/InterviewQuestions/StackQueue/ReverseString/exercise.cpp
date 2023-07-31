#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(const string& str) {
    stack<char> myStack;
    for (int i = 0; i < str.length(); i++) {
        myStack.push(str[i]);
    }
    string reverseString;

    while (myStack.size()) {
        reverseString.push_back(myStack.top());
        myStack.pop();
    }

    return reverseString;
}

int main() {
    cout << reverseString("Udemy") ;
}