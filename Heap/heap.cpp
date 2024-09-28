#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

class Heap {
    private:
        vector<int> heap;

        int leftChild(int index) {
            return 2 * index + 1;
        }

        int rightChild(int index) {
            return 2 * index + 2;
        }

        int parent(int index) {
            return (index - 1) / 2;
        }

        void swap(int index1, int index2) {
            int temp = heap[index1];
            heap[index1] = heap[index2];
            heap[index2] = temp;
        }



    public:
        void printHeap() {
            cout << "\n[";
            for (size_t i = 0; i < heap.size(); i++) {
                cout << heap[i];
                if (i < heap.size() - 1) { 
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
        
        const vector<int>& getHeap() const {
            return heap;
        }

        void insert(int value) {
            heap.push_back(value);
            int current = heap.size() - 1;

            while (current > 0 && heap[current] > heap[parent(current)]) {
                swap(current, parent(current));
                current = parent(current);
            }
        }

        void sinkDown(int index) {
            int current = index;
            
            while(true) {
                int maxIndex = max(leftChild(current), rightChild(current));
            
                if (heap[current] < heap[maxIndex] && maxIndex<heap.size()) {
                    swap(current, maxIndex);
                    current = maxIndex;
                } else {
                    break;
                }
            }
        }

        int remove() {
            if (heap.empty()) {
                return INT_MIN;
            } else {
                int temp = *heap.begin();
                heap[0] = heap[heap.size() - 1];
                heap.pop_back();
                sinkDown(0);
                return temp;
            }
        }

};



int main() {
    Heap myHeap;
    vector<int> values = {25, 15, 25, 5, 10};
    for (int value : values) {
        myHeap.insert(value);
    }

    myHeap.remove();

    return 0;
}
