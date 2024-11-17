#include <algorithm>
#include <iostream>
#include <vector>

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


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
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
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

       void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
        
		void bubbleSort() {
		    int temp;
		    for (int i=0; i<length-1; i++) {
		        Node* current = head;
                while (current->next != nullptr) {
		            if (current->next->value < current->value) {
		                temp = current->value;
		                current->value = current->next->value;
		                current->next->value = temp;
		            }
		            current = current->next;
		        }
            }
		}

        void selectionSort() {
            if (length < 2) return;
		    int min = head->value;
            Node* current = head->next;
            Node* flag = head;
            Node* temp = head;
		    for (int i=0; i<length-1; i++) {
                while (current != nullptr) {
		            if (current->value < min) {
		                min = current->value;
                        temp = current;
		            }
		            current = current->next;
		        }
                temp->value = flag->value;
                flag->value = min;
                flag = flag->next;
                min = flag->value;
                current = flag->next;
                temp = flag;
            }
		}

        void insertionSort() {
            if (length < 2) return;
            vector<int> values = {};
            Node* current = head;
            while (current != nullptr) {
                values.push_back(current->value);
                current = current->next;
            }
            current = head->next;
		    for (int i=1; i<length; i++) {
                int index = i;
                for (int j=i-1; j>=0; j--) {
                    if (current->value < values.at(j)) {
                        index = j;
                    }
                }
                if (i > index) {
                    rotate(values.rend() - i - 1, values.rend() - i, values.rend() - index);
                } else {        
                    rotate(values.begin() + i, values.begin() + i + 1, values.begin() + index + 1);
                }
                current = current->next;
            }
            current = head;
            for (int i=0; i<length; i++) {
                current->value = values[i];
                current = current->next;
            }
		}

        void merge(LinkedList& otherList) {
            Node* otherHead = otherList.getHead();
            Node* dummy = new Node(0);
            Node* current = dummy;
        
            while (head != nullptr && otherHead != nullptr) {
                if (head->value < otherHead->value) {
                    current->next = head;
                    head = head->next;
                } else {
                    current->next = otherHead;
                    otherHead = otherHead->next;
                }
                current = current->next;
            }
        
            if (head != nullptr) {
                current->next = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
            } else {
                current->next = otherHead;
                while (current->next != nullptr) {
                    current = current->next;
                }
            }
        
            tail = current;
            head = dummy->next;
            delete dummy;
            length += otherList.getLength();
        
            otherList.head = nullptr;
            otherList.tail = nullptr;
            otherList.length = 0;
        }

};

int main() {
    LinkedList list1(3);
    list1.append(4);
    LinkedList list2(1);
    list2.append(2);


    list1.merge(list2);
}
