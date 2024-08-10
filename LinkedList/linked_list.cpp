#include <iostream>
#include <cmath> // Include cmath for pow function


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
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
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

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }

        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
            } else {
                head = head->next;
            }
            // delete temp;
            length--;
        }

        void partitionList(int x) {
            LinkedList* big = new LinkedList(0);
            big->makeEmpty();
            LinkedList* small = new LinkedList(0);
            small->makeEmpty();
            Node* temp = this->head;
            while (temp!= nullptr) {
                if (temp->value >= x) {
                    big->append(temp->value);
                } else {
                    small->append(temp->value);
                }
                temp = temp->next;
            }
            temp = big->head;
            while (temp!= nullptr) {
                small->append(temp->value);
                temp = temp->next;
            }
            this->head = small->head;
        }

        void removeDuplicates() {
            Node* temp = head;
            Node* part = head;
            bool flag = false;
            while(temp!=nullptr){
                while (part!=temp) {
                    if (part->value == temp->value){
                        flag = true;
                    }
                    part = part->next;
                }
                if (flag==true){
                    part->next=temp->next;
                    --length;
                }
                flag=false;
                part=head;
                temp=temp->next;
            }
        }

        int binaryToDecimal() {
            Node* temp = head;
            int decimal = 0;
            int power = length-1;
            while (temp != nullptr) {
                decimal += temp->value * pow(2, power);
                power--;
                temp = temp->next;
            }
            return decimal;
        }

        void reverseBetween(int m, int n){
            
            if (m == n || length == 0 || length == 1) return;
            
            LinkedList* start = new LinkedList(0);
            start->makeEmpty();
            // start->printList();
            LinkedList* between = new LinkedList(0);
            between->makeEmpty();
            
            for (int i=0; i<m; i++) {
                start->append(head->value);
                this->deleteFirst();
            }
            Node* first = head;
            this->deleteFirst();

            for (int i=m; i<n-1; i++) {
                between->append(head->value);
                this->deleteFirst();
            }

            Node *curr = between->head, *prev = nullptr, *next;

            while (curr != nullptr) {
                // Store next
                next = curr->next;
                // Reverse current node's next pointer
                curr->next = prev;
            
                // Move pointers one position ahead
                prev = curr;
                curr = next;
            }
            between->head = prev;

            Node* second = head;
            this->deleteFirst();
            
            start->append(second->value);
            Node* temp = between->head;
            while (temp !=nullptr) {
                start->append(temp->value);
                temp = temp->next;
            }
            
            start->append(first->value);
            temp = this->head;
            while (temp !=nullptr) {
                start->append(temp->value);
                temp = temp->next;
            }
            
            this->head = start->head;
        }

};


int main() {
    LinkedList list(1);

    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);

    // list.printList();
    list.reverseBetween(1, 4);

    // cout << "AFTER:     ";
    // list.printList();

    return 0;
}
