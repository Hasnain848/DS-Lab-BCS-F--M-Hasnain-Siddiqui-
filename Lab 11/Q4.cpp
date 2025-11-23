/*Task # 4
Given an array of distinct integers, find using hashing if there are two pairs (a, b) and (c, d) such that
a+b = c+d, and a, b, c, and d are distinct elements. If there are multiple answers, then print any of
them.
Input: {3, 4, 7, 1, 2, 9, 8}
Output: (3, 8) and (4, 7)
Explanation: 3+8 = 4+7
Input: {3, 4, 7, 1, 12, 9};
Output: (4, 12) and (7, 9)
Explanation: 4+12 = 7+9
Input: {65, 30, 7, 90, 1, 9, 8};
Output: No pairs found*/
#include <iostream>
using namespace std;

#define TABLE_SIZE 211  
struct Pairs {
    int x;
    int y;
    int sum;  
    bool used;
    Pairs() : used(false), sum(0) {}
};

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    Pairs HashTable[TABLE_SIZE];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = arr[i];
            int y = arr[j];
            int sum = x + y;
            int index = hashFunction(sum);

            int originalIndex = index;
            while (HashTable[index].used && HashTable[index].sum != sum){
                index = (index + 1) % TABLE_SIZE;
                if (index == originalIndex) {
                    cout << "Hash table full!" << endl;
                    return 1;
                }
            }
            if (HashTable[index].used && HashTable[index].sum == sum){
                int c = HashTable[index].x;
                int d = HashTable[index].y;
                if (x!=c&&x!=d&&y!=c&&y!=d){
                    cout<<"("<<c<<","<<d<<") and ("<<x<<", "<<y<<")"<<endl;
                    return 0;
                }
            }
            HashTable[index].x = x;
            HashTable[index].y = y;
            HashTable[index].sum = sum;
            HashTable[index].used = true;
        }
    }
    
    cout << "No pairs found" << endl;
    return 0;
}