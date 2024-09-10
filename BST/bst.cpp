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

    public:
        BinarySearchTree() { root = nullptr; }


        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }

        Node* getRoot() {
            return root;
        } 

        bool insert(int value) {
            Node* temp = root;
            while (temp != nullptr) {
                if (value > temp->value) {
                    if (temp->right == nullptr){
                        temp->right = new Node(value);
                        return true;
                    } else {
                        temp = temp->right;
                    }
                } else if (value < temp->value) {
                    if (temp->left == nullptr){
                        temp->left = new Node(value);
                        return true;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    return false;
                }
            }
            root = new Node(value);
            return true;
        }

        bool contains(int value) {
            Node* temp = root;
            while (temp != nullptr) {
                if (value > temp->value) {
                    temp = temp->right;
                } else if (value < temp->value) {
                    temp = temp->left;
                } else {
                    return true;
                }
            }
            return false;
        }
};


int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
}
