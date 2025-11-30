/*Question#2: You are building a plagiarism detection tool. Implement the Rabin-Karp
algorithm to find whether a small snippet of text appears anywhere in a larger
document. Return all positions where the snippet occurs. Assume you are using a
simple hash function with a prime modulus of your choice. Example:
Input: Text = &quot;Data structures and algorithms are fun. Algorithms make tasks easier.&quot;
Pattern = &quot;Algorithms&quot; Output:
[27, 41]
Extra Challenge: Demonstrate the effect of hash collisions by printing any false-
positive hash matches that are discarded.*/
#include<iostream>
using namespace std;
#define d 256  
void rabinKarp(string text, string pattern, int q) {
    int n = text.length();    
    int m = pattern.length(); 
    bool first = true;
    if (m == 0 || m > n) {
        cout << "No valid pattern to search.\n";
        return;
    }
    int p = 0;  
    int t = 0;  
    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    cout << " ,False positive hash at index: " << i;
                    break;
                }
            }
            if (match) {
                if (!first) cout << ", ";
                cout << i;
                first = false;
            }
        }
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}

int main() {
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    cout << "[";
    rabinKarp(text, pattern, 101);
    cout << "]" << endl;

    return 0;
}
