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

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }

    int getLength() {
        return length;
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

    void makeEmpty() {
        Node* current = head;
        while (current != nullptr) {
            Node* nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
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

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode; 
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            if (length == 1){
                tail=head->next;
            }
        }
        length++;
    }

    void deleteFirst() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
    }

    Node* get(int index) {
        if (index < 0 || index >= length || length==0) {
            return nullptr;
        }
        
        Node* temp = head;
        while (index > 0) {
            temp = temp->next;
            index--;
        }
        
        return temp;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;
            Node* newNode = new Node(value);
        if (index == 0) {
            this->prepend(value);
            return true;
        }
        if (index == length) {
            this->append(value);
            return true;
        } else {
            Node* temp = this->get(index);
            newNode->prev = temp->prev;
            temp->prev = newNode;
            newNode->next = temp;
            newNode->prev->next = newNode;
            length++;
            return true;
        }
    }

    void deleteNode(int index) {
        if (index < 0 || index > length) return;
        if (index == 0) {
            deleteFirst();
            return;
        } 
        if (index == length-1) {
            deleteLast();
        } else {
            Node* temp = get(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            length--;
        }
        return;
    }



};

int main() {
    DoubleLinkedList dll(5);
    dll.append(10);
    dll.append(15);

    dll.insert(1, 100);
    cout << endl;
}
