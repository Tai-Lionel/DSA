#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
    int value;
    Node* left;
    Node* right;
} Node;

typedef struct BinarySearchTree {
    Node* root;
} BinarySearchTree;

Node* constructNode(int value);
void constructBinarySearchTree(BinarySearchTree &bst);
void add(BinarySearchTree &bst, Node* newNode);
void input(BinarySearchTree &bst);
void outputInOrder(BinarySearchTree bst);
void outputInOrder(BinarySearchTree bst, Node* currentNode);
void outputPreOrder(BinarySearchTree bst);
void outputPreOrder(BinarySearchTree bst, Node* currentNode);
void outputPostOrder(BinarySearchTree bst);
void outputPostOrder(BinarySearchTree bst, Node* currentNode);
Node* findNode(BinarySearchTree bst, int X);
Node* findNode(BinarySearchTree bst, Node* currentNode, int X);
Node* findMinNode(BinarySearchTree bst);
Node* findMaxNode(BinarySearchTree bst);
int height(BinarySearchTree bst);
int numLeaf(BinarySearchTree bst);
int numTwoChildren(BinarySearchTree bst);
int numOneChildren(BinarySearchTree bst);
void deleteNode(BinarySearchTree &bst, int X);
Node* deleteNode(BinarySearchTree &bst, Node* currentNode, int X);

int main() {
    BinarySearchTree bst;
    input(bst);
    cout << "Duyet cay theo thu tu truoc: "; outputPreOrder(bst); cout << endl;
    cout << "Duyet cay theo thu tu giua: "; outputInOrder(bst); cout <<  endl;
    cout << "Duyet cay theo thu tu sau: "; outputPostOrder(bst); cout << endl;
    int X; cout << "Nhap gia tri can tim kiem: "; cin >> X; Node* res = findNode(bst, X);
    cout << "Node tim duoc co gia tri: "; if (res) cout << res->value << endl;
    Node* minNode = findMinNode(bst); cout << "Node nho nhat tim duoc co gia tri: "; if (minNode) cout << minNode->value << endl; 
    Node* maxNode = findMaxNode(bst); cout << "Node lon nhat tim duoc co gia tri: "; if (maxNode) cout << maxNode->value << endl; 
    cout << "Do cao cua cay nhi phan: " << height(bst) << endl;
    cout << "So nut la: " << numLeaf(bst) << endl;
    cout << "So nut co hai con: " << numTwoChildren(bst) << endl;
    cout << "So nut mot con: " << numOneChildren(bst) << endl;
    cout << "Nhap gia tri muon xoa: "; cin >> X; deleteNode(bst, X); cout << "Cay nhi phan moi: "; outputInOrder(bst); cout << endl;
}

Node* constructNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void constructBinarySearchTree(BinarySearchTree &bst) {
    bst.root = nullptr;
}

void add(BinarySearchTree &bst, Node* newNode) {
    if (bst.root == nullptr)
        bst.root = newNode;
    else {
        Node* temp = bst.root;
        while (true) {
            if (newNode->value < temp->value) {
                if (temp->left)
                    temp = temp->left;
                else {
                    temp->left = newNode;
                    return;
                }
            } else {
                if (temp->right)
                    temp = temp->right;
                else {
                    temp->right = newNode;
                    return;
                }
            }
        }
    }
}

void input(BinarySearchTree &bst) {
    constructBinarySearchTree(bst);
    int value;
    do {
        cout << "Nhap gia tri vao cay (Nhap 0 de ket thuc): ";
        cin >> value;
        if (value == 0) break;
        Node* newNode = constructNode(value);
        add(bst, newNode);
    } while (true);
}

void outputInOrder(BinarySearchTree bst) {
    outputInOrder(bst, bst.root);
}

void outputInOrder(BinarySearchTree bst, Node* currentNode) {
    if (currentNode->left)
        outputInOrder(bst, currentNode->left);
    cout << currentNode->value << " ";
    if (currentNode->right)
        outputInOrder(bst, currentNode->right);
}

void outputPreOrder(BinarySearchTree bst) {
    outputPreOrder(bst, bst.root);
}

void outputPreOrder(BinarySearchTree bst, Node* currentNode) {
    cout << currentNode->value << " ";
    if (currentNode->left)
        outputPreOrder(bst, currentNode->left);
    if (currentNode->right)
        outputPreOrder(bst, currentNode->right);
}

void outputPostOrder(BinarySearchTree bst) {
    outputPostOrder(bst, bst.root);
}

void outputPostOrder(BinarySearchTree bst, Node* currentNode) {
    if (currentNode->left)
        outputPostOrder(bst, currentNode->left);
    if (currentNode->right)
        outputPostOrder(bst, currentNode->right);
    cout << currentNode->value << " ";
}

Node* findNode(BinarySearchTree bst, int X) {
    return findNode(bst, bst.root, X);
}

Node* findNode(BinarySearchTree bst, Node* currentNode, int X) {
    if (currentNode->value == X) return currentNode;
    if (X < currentNode->value) {
        if (currentNode->left)
            return findNode(bst, currentNode->left, X);
        else
            return nullptr;
    }
    else if (X > currentNode->value) {
        if (currentNode->right)
            return findNode(bst, currentNode->right, X);
        else
            return nullptr;
    }
    return nullptr;
}

Node* findMinNode(BinarySearchTree bst) {
    if (bst.root == nullptr) return nullptr;
    Node* temp = bst.root;
    while (temp->left)
        temp = temp->left;
    return temp;
}

Node* findMaxNode(BinarySearchTree bst) {
    if (bst.root == nullptr) return nullptr;
    Node* temp = bst.root;
    while (temp->right)
        temp = temp->right;
    return temp;
}

int height(BinarySearchTree bst) {
    queue<Node*> queue;
    queue.push(bst.root);
    int level = 0;
    while (queue.size()) {
        for (int i = 0; i < queue.size(); i++) {
            Node* temp = queue.front();
            queue.pop();
            if (temp->left) queue.push(temp->left);
            if (temp->right) queue.push(temp->right);
        }
        level++;
    }
    return level;
}

int numLeaf(BinarySearchTree bst) {
    queue<Node*> queue;
    queue.push(bst.root);
    int num = 0;

    while (queue.size()) {
        Node* temp = queue.front();
        queue.pop();
        if (temp->left == nullptr && temp->right == nullptr) num++;
        if (temp->left) queue.push(temp->left);
        if (temp->right) queue.push(temp->right);
    }
    return num;
}

int numTwoChildren(BinarySearchTree bst) {
    queue<Node*> queue;
    queue.push(bst.root);
    int num = 0;

    while (queue.size()) {
        Node* temp = queue.front();
        queue.pop();
        if (temp->left && temp->right) num++;
        if (temp->left) queue.push(temp->left);
        if (temp->right) queue.push(temp->right);
    }
    return num;
}

int numOneChildren(BinarySearchTree bst) {
    queue<Node*> queue;
    queue.push(bst.root);
    int num = 0;

    while (queue.size()) {
        Node* temp = queue.front();
        queue.pop();
        if ((temp->left && temp->right == nullptr) || (temp->left == nullptr && temp->right)) num++;
        if (temp->left) queue.push(temp->left);
        if (temp->right) queue.push(temp->right);
    }
    return num;
}

void deleteNode(BinarySearchTree &bst, int X) {
    bst.root = deleteNode(bst, bst.root, X);
}

Node* deleteNode(BinarySearchTree &bst, Node* currentNode, int X) {
    if (currentNode == nullptr) return currentNode;
    if (X < currentNode->value)
        currentNode->left = deleteNode(bst, currentNode->left, X);
    else if (X > currentNode->value)
        currentNode->right = deleteNode(bst, currentNode->right, X);
    else {
        if (currentNode->left == nullptr)
            return currentNode->right;
        if (currentNode->right == nullptr)
            return currentNode->left;
        Node* temp = currentNode->right;
        while (temp->left)
            temp = temp->left;
        currentNode->value = temp->value;
        deleteNode(bst, currentNode->right, temp->value);
    }
    return currentNode;
}

    

