/*Question#1: You are developing a text editor. Implement a function that searches for
all occurrences of a user-provided keyword in a large document. Use the Brute
Force algorithm to find and return the starting indices of the keyword in the
document. Example:
Input: Text = &quot;the quick brown fox jumps over the lazy dog&quot;
Pattern = &quot;the&quot;
Output: [0, 31]
Extra Challenge: Count and return the total number of comparisons your algorithm
makes.*/
#include<iostream>
using namespace std;
int comparision=0;
void bruteforceSearch(string text,string pattern){
    int n=text.length();
    int m=pattern.length();
    bool first = true;

    for(int i=0;i<=n-m;i++){
         int j = 0;

        while (j < m) {
            comparision++;  

            if (text[i + j] != pattern[j])
                break;

            j++;
        }
        if(j==m){
            if (!first) cout << ", ";
            cout << i;
            first = false;
           // cout<<i<<",";

        }
    }
}
int main(){
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    cout<<"[";
    bruteforceSearch(text, pattern);
    cout<<"]"<<endl;
    cout<<"Toatal no of Comparisions: "<<comparision<<endl;
    return 0;
}