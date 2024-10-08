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

class Queue {
    private:
        Node* first;
        Node* last;
        int length;

    public:
        Queue(int value) {
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

        ~Queue() {
            Node* temp = first;
            while (first) {
                first = first->next;
                delete temp;
                temp = first;
            }
        }

        void printQueue() {
            if (length == 0) {
                cout << "Queue: empty" << endl;
                return;
            }
            Node* temp = first;
            cout << "Queue: ";
            while (temp) {
                cout << temp->value;
                temp = temp->next;
                if (temp) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }


        Node* getFirst() {
            return first;
        }

        Node* getLast() {
            return last;
        }

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp;
            while (first) {
                temp = first;
                first = first->next;
                delete temp;
            }
            first = nullptr;
            last = nullptr;
            length = 0;
        }

        bool isEmpty() {
            if (length == 0) return true;
            return false;
        }

        void enqueue(int value) {
            Node* newNode = new Node(value);
            newNode->next = nullptr;
            last->next = newNode;
            last = newNode;
            length++;
        }

        int dequeue() {
            if (length == 0) return INT_MIN;
            Node* temp = first;
            first = first->next;
            int value = temp->value;
            delete temp;
            length--;
            return value;
        }
        
};


int main() {
    Queue* queue = new Queue(5);
    queue->enqueue(10);
    queue->enqueue(15);
    queue->enqueue(20);
    queue->printQueue();
    queue->makeEmpty();
    queue->printQueue();
    delete queue;
    return 0;
}
