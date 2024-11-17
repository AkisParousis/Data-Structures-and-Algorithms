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
#include <algorithm>
#include <iostream>
#include <stack>
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

        string reverseString(const string& str) {
            vector<char> temp = vector<char>();
            for (int i = 0; i < str.size(); i++) {
                temp.push_back(str[i]);
            }
            string reversed = "";
            while (!temp.empty()) {
                reversed += temp.back();
                temp.pop_back();
            }
            return reversed;
        }

        bool isBalancedParentheses(const string& parentheses) {
            for (auto it : parentheses) {
                this->push(it);
            }
            int amount = 0;
            while (!this->isEmpty()) {
                int top = this->peek();
                this->pop();
                if (top == 40) {
                    if (amount == 0) {
                        return false;
                    } else {
                        amount--;
                    }
                } else {
                    amount++;
                    continue;
                }
            }
            if (amount == 0) return true;
        }

        void sortStack(stack<int>& inputStack) {
            vector<int> vec;

            while (!inputStack.empty()) {
                int top = inputStack.top();
                vec.push_back(top);
                inputStack.pop();
            }

            sort(vec.rbegin(), vec.rend());

            for (int val : vec) {
                inputStack.push(val);
            }

        }
};

int main() {
    Stack myStack;
    stack<int> intStack;
    intStack.push(-3);
    intStack.push(1);
    intStack.push(5);
    intStack.push(-1);
    myStack.sortStack(intStack);
    return 0;
}
