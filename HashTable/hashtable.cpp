#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

        int hash(string key) {
            int hash = 0;
            for (int i = 0; i < key.length(); i++) {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue *  23) % SIZE;
            }
            return hash;
        }

    public:
        HashTable() {
            for(int i = 0; i < SIZE; i++) {
                dataMap[i] = nullptr;
            }
        }
        
        // ---------------------------------------------------
        //  Destructor code is similar to keys() function
        //  Watch that video to help understand how this works
        // ---------------------------------------------------
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }

        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << "Index " << i << ": ";
                if(dataMap[i]) {
                    cout << "Contains => ";
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "{" << temp->key << ", " << temp->value << "}";
                        temp = temp->next;
                        if (temp) cout << ", ";
                    }
                    cout << endl;
                } else {
                    cout << "Empty" << endl;
                }
            }
            return; // Add a return statement at the end of the function.
        }
        
        void set(string key, int value) {
            int index = hash(key);
            Node* newNode = new Node(key, value);
            if (dataMap[index] == nullptr) {
                dataMap[index] = newNode;
            } else {
                Node* temp = dataMap[index];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    
        int get(string key) {
            int index = hash(key);
            Node* temp = dataMap[index];
            while (temp != nullptr) {
                if (temp->key == key) return temp->value;
                temp = temp->next;
            }
            return 0;
        }

        vector<string> keys() {
            vector<string> allKeys;
            for (int i=0; i<SIZE; i++) {
                Node* temp = dataMap[i];
                while (temp != nullptr) {
                    allKeys.insert(allKeys.begin(), temp->key);
                    temp = temp->next;
                }
            }
            return allKeys;
        }

        bool itemInCommon(vector<int> vect1, vector<int> vect2) {
            unordered_map<int, bool> myMap;
 
            for (auto i : vect1) {
                myMap.insert({i, true});
            }
        
            for (auto j : vect2) {
                if (myMap[j]) return true;
            }
            
            return false;
        }

        vector<int> findDuplicates(const vector<int>& nums) {
            vector<int> duplicates = {};
            unordered_map<int, int> myMap;

            for (auto i : nums) {
                auto result = myMap.insert({ i, 1 });
                if (!result.second) {
                    // Element was already present; increment the value at the key K.
                    ++(result.first->second);
                    duplicates.push_back(i);
                }
            }

            return duplicates;
        }

        char firstNonRepeatingChar(const string& input_string) {
            vector<char> v;
            for(char c : input_string) {
                v.push_back(c);
            }

            if (v.empty()) return '\0';
	        unordered_map<char, int> myMap;
            
            for (vector<char>::iterator t=v.begin(); t!=v.end(); ++t)  {
                auto result = myMap.insert({ *t, 1 });
                if (!result.second) {
                    // Element was already present; increment the value at the key K.
                    ++(result.first->second);
                }
            }

            for(char& c : v) {
                if (myMap[c] == 1) return c;
            }
            return '\0';
        }

        vector<vector<string>> groupAnagrams(const vector<string>& strings) {
            string str;
	        unordered_map<string, vector<string>> myMap;
            for(string str : strings) {
                string non_sorted = str;
                sort(str.begin(), str.end());
                auto result = myMap.insert({ str, {non_sorted} });
                if (!result.second) {
                    // Element was already present; increment the value at the key K.
                    result.first->second.insert(result.first->second.end(), non_sorted);
                }
            }
            vector<vector<string>> anagramGroups;
            for (auto& it: myMap) {
                // Do stuff
                anagramGroups.insert(anagramGroups.begin(), it.second);
            }
            return anagramGroups;

        }

        vector<int> twoSum(const vector<int>& nums, int target) {
            unordered_map<int, int> myMap;
            for (long long unsigned int i = 0; i < nums.size(); i++) {
                int num = nums[i];
                int complement = target - num;
                if (myMap.find(complement) != myMap.end()) {
                    return {myMap[complement], int(i)};
                }
                myMap[num] = i;
            }
            return {};
        }

        vector<int> subarraySum(const vector<int>& nums, int target) {
            unordered_map<int, int> sumIndex;
            sumIndex[0] = -1;
            int currentSum = 0;
        
            for (int i = 0; i < nums.size(); i++) {
                currentSum += nums[i];
                if (sumIndex.find(currentSum - target) != sumIndex.end()) {
                    return {sumIndex[currentSum - target] + 1, i};
                }
                sumIndex[currentSum] = i;
            }
        
            return {};
        }

        vector<int> removeDuplicates(const vector<int>& myList) {
            vector<int> outputList;
            unordered_set<int> mySet;
            for (int i = 0; i < myList.size(); i++) {
                mySet.insert(myList[i]);
            }
            for (auto it : mySet) {
                outputList.insert(outputList.begin(), it);
            }
            return outputList;
        }

        bool hasUniqueChars(const string& str) {
            unordered_set<char> mySet = {};
            for (char ch : str) {
                auto it = mySet.insert(ch).second;
                if (!it) return false;
            }
            return true;   
        }

        vector<vector<int>> findPairs(const vector<int>& arr1, const vector<int>& arr2, int target) {
            vector<vector<int>> vec;
            unordered_set<int> mySet = {};
            
            for (auto i : arr1) {
                mySet.insert(i);
            }
            
            for (auto i : arr2) {
                for (auto j : mySet){
                    if ((j + i) == target) {
                        vec.push_back({i, j});
                        break;
                    }
                }
            }
            return vec;
        }

        int longestConsecutiveSequence(const vector<int>& nums) {
            int length = 1;
            int val;
            unordered_set<int> lengths;
            for (auto it : nums) {
                while (true) {
                    val = ++it;
                    if(find(nums.begin(), nums.end(), val) != nums.end()) {
                        length++;
                    } else {
                        lengths.insert(length);
                        length = 1;
                        break;
                    }
                }
            }
            if (lengths.empty()) {
                return 0;
            }
            return *max_element(lengths.begin(), lengths.end());
        }
};



int main() {
    HashTable ht;
    vector<int> arr1 = {};
    vector<int> arr2 = {4, 5, 6};
    int target = 8;

    int result = ht.longestConsecutiveSequence(arr1);
}
