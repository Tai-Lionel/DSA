#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree {
    public:
        Node* root;
        
        BinarySearchTree() {
            root = nullptr;
        }

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while (true) {
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else if (newNode->value > temp->value) {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                } else {
                    return false;
                }
            }
        }

        bool contains(int value) {
            Node* temp = root;
            while (temp != nullptr) {
                if (value < temp->value) temp = temp->left;
                else if (value > temp->value) temp = temp->right;
                else return true;
            }
            return false;
        }

        // destroy
        void destroy(Node* currentNode) {
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }
};

int main() {
    BinarySearchTree* bst = new BinarySearchTree();

    bst->insert(47);
    bst->insert(26);
    bst->insert(84);
    bst->insert(16);
    bst->insert(32);
    bst->insert(64);
    bst->insert(92);

    bst->insert(20);

    cout << bst->root->left->left->right->value << endl;
    cout << bst->contains(28);
}