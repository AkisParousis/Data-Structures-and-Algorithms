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

        void BFS() {
		    queue<Node*> q;
		    Node* currentNode = root;
		    
		    if (currentNode != nullptr) q.push(root);
		    
		    while (currentNode != nullptr) {
		        if (currentNode->left != nullptr) {
		            q.push(currentNode->left);
		        }
		        if (currentNode->right != nullptr) {
		            q.push(currentNode->right);
		        }
		        cout << q.front()->value << " ";
		        q.pop();
		        if (!q.empty()) {
		            currentNode = q.front();
		        } else {
		            currentNode = nullptr;
		        }
		    }
		}

        void DFSPreOrder(Node* currentNode) {
            if (currentNode->left != nullptr) {
                DFSPreOrder(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                DFSPreOrder(currentNode->right);
            }
            cout << currentNode->value << " ";
        }

        void DFSPostOrder(Node* currentNode) {
            if (currentNode->left != nullptr) {
                DFSPostOrder(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                DFSPostOrder(currentNode->right);
            }
            cout << currentNode->value << " ";
        }

        void DFSInOrder(Node* currentNode) {
            if (currentNode->left != nullptr) {
                DFSInOrder(currentNode->left);
            }
            cout << currentNode->value << " ";
            if (currentNode->right != nullptr) {
                DFSInOrder(currentNode->right);
            }
        }
};


int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
}
