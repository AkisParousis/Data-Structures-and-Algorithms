#include <iostream>
#include <cmath> // Include cmath for pow function

using namespace std;

class Node {
    public:
        int value;
        Node* prev;
        Node* next;
        Node(int value) {
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
};

class DoubleLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        int value;
        DoubleLinkedList* next;
        DoubleLinkedList* prev;
        DoubleLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if (head == nullptr) {
            return;
        } 
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
            delete tail->next;
        }
        length--;
    }

    void printList() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "empty";
        } else {
            while (temp != nullptr) {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr) {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }


};

int main() {
    DoubleLinkedList dll(10);
    dll.append(20);
    dll.append(30);
    dll.append(40);
    dll.deleteLast();
    dll.printList();
}
