/*Question#4: You are developing a search feature for a large book database.
Implement the KMP algorithm to search for a query string in the book’s content.
Return all positions where the query occurs. Example:
Input: Text = &quot;ababababc&quot; Pattern = &quot;abab&quot;
Output: [0, 2, 4]

Extra Challenge: Show the LPS (Longest Prefix Suffix) array used for the search.*/
#include<iostream>
using namespace std;
void computeLPS(const string &pattern, int lps[]) {
    int m = pattern.size();
    int len = 0; 
    lps[0] = 0;  
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void DisplayLpstable(int lps[],int m,string pattern){
    cout<<"========= Displaying LPS TABLE ========="<<endl;
    for(int i=0;i<m;i++){
        cout<<pattern[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        cout<<lps[i]<<" ";
    }
    cout<<"\n========================================"<<endl;
}

void KMPSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    bool first = true;
    int *lps=new int[m];
    computeLPS(pattern, lps);
    DisplayLpstable(lps,m,pattern);
    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            if(first){
                cout<<"[";
            }
            if (!first) cout << ", ";
                cout << i-m;
                first = false;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
  delete []lps;
}

int main() {
    string text = "ababababc";
    string pattern = "abab";
    KMPSearch(text, pattern);
    cout<<"]";
    return 0;
}
