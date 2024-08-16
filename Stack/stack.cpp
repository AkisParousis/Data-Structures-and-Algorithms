// #include <iostream>
// #include <climits>

// using namespace std;

// class Node {
//     public:
//         int value;
//         Node* next;
//         Node(int value) {
//             this->value = value;
//             next = nullptr;
//         }
// };

// class Stack {
//     private:
//         Node* top;
//         int height;
        
//     public:
//         Stack(int value) {
//             Node* newNode = new Node(value);
//             top = newNode;
//             height = 1;
//         }
    
//         ~Stack() {
//             Node* temp = top;
//             while (top) {
//                 top = top->next;
//                 delete temp;
//                 temp = top;
//             }
//         }
    
//         void printStack() {
//             Node* temp = top;
//             while (temp) {
//                 cout << temp->value << endl;
//                 temp = temp->next;
//             }
//         }
    
//         Node* getTop() {
//             return top;
//         }

//         int topValue() {
//             if (top) return top->value;
//             return INT_MIN;
//         }
    
//         int getHeight() {
//             return height;
//         }
        
//         void makeEmpty() {
//             Node* temp;
//             while (top) {
//                 temp = top;
//                 top = top->next;
//                 delete temp;
//             }
//             height = 0;
//         }
        
//         void push(int value) {
//             Node* newNode = new Node(value);
//             newNode->next = top;
//             top = newNode;
//             height++;
//         }

//         int pop() {
//             if (height == 0) {
//                 return INT_MIN;
//             }
//             Node* temp = top;
//             top = temp->next;
//             int poppedValue = temp->value;
//             delete temp;
//             height--;
//             return poppedValue;
//         }

// };

#include <iostream>
#include <vector>

using namespace std;

class Stack {
    private:
        vector<int> stackVector;
    
    public:
        vector<int>& getStackVector() {
            return stackVector;
        }
    
        void printStack() {
            for (int i = stackVector.size() - 1; i >= 0; i--) {
                cout << stackVector[i] << endl;
            }
        }
    
        bool isEmpty() {
            return stackVector.size() == 0;
        }
    
        int peek() {
            if (isEmpty()) {
                return int();
            } else {
                return stackVector[stackVector.size() - 1];
            }
        }
    
        int size() {
            return stackVector.size();
        }
    
        void push(int value) {
            stackVector.push_back(value);
        }
    
        void pop() {
            if (!stackVector.empty()) {
                stackVector.pop_back();
            }
        }
  
};

int main() {
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.printStack();
    cout << "Size: " << myStack.size() << endl;
    cout << "Peek: " << myStack.peek() << endl;
    return 0;
}
