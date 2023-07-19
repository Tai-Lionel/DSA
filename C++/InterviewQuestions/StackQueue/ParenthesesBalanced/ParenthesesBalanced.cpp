#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalancedParentheses(const string& parentheses) {
    stack<char> myStack;
    for (int i = 0; i < parentheses.length(); i++) myStack.push(parentheses[i]);
    int closed_count = 0;
    int open_count = 0;
    while (myStack.size() != 0  && myStack.top() == ')') {
        closed_count++;
        myStack.pop();
    }
    while (myStack.size() != 0 && myStack.top() == '(') {
        open_count++;
        myStack.pop();
    }
    if (myStack.size() != 0 || closed_count != open_count) return false;
    else return true;
}

int main() {
    if (isBalancedParentheses("")) cout << "is balanced";
    else cout << "is not balanced";
}

