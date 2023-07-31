#include <iostream>
#include <queue>

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

    public:
        BinarySearchTree() { root = nullptr; }

        // ---------------------------------------------------
        //  Helper function used by destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode) {
                destroy(currentNode->left);
                destroy(currentNode->right);
                delete currentNode;
            }
        }

        ~BinarySearchTree() { destroy(root); }
 

        void insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return;
                    }
                    temp = temp->right;
                }
            }
        }

        bool contains(int value) {
            if (root == nullptr) return false;
            Node* temp = root;
            while(temp) {
                if (value < temp->value) {
                    temp = temp->left;
                } else if (value > temp->value) {
                    temp = temp->right;
                } else {
                    return true;
                }
            }
            return false;
        }

        void BFS() {
            queue<Node*> queue;
            queue.push(root);

            while (queue.size() > 0) {
                Node* currentNode = queue.front();
                queue.pop();
                cout << currentNode->value << " ";
                if (currentNode->left)
                    queue.push(currentNode->left);
                if (currentNode->right)
                    queue.push(currentNode->right);
            }
        }

        void DFSPreOrder(Node* currentNode) {
            cout << currentNode->value << " ";
            if (currentNode->left)
                DFSPreOrder(currentNode->left);
            if (currentNode->right)
                DFSPreOrder(currentNode->right);
        }

        void DFSPreOrder() { 
            DFSPreOrder(root); 
        }

        void DFSPostOrder(Node* currentNode) {
            if (currentNode->left)
                DFSPostOrder(currentNode->left);
            if (currentNode->right)
                DFSPostOrder(currentNode->right);
            cout << currentNode->value << " ";
        }

        void DFSPostOrder() { 
            DFSPostOrder(root); 
        }

        void DFSInOrder(Node* currentNode) {
            if (currentNode->left)
                DFSInOrder(currentNode->left);
            cout << currentNode->value << " ";
            if (currentNode->right)
                DFSInOrder(currentNode->right);
        }

        void DFSInOrder() { 
            DFSInOrder(root);
        }

};

int main() {
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(47);
    bst->insert(23);
    bst->insert(89);
    bst->insert(16);
    bst->insert(35);
    bst->insert(68);
    bst->insert(92);

    bst->DFSInOrder();
}