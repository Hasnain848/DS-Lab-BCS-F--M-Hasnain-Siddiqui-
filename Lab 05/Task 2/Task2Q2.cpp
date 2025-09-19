/*2. Next, demonstrate indirect recursion by creating two functions, functionA(int n)
and functionB(int n). functionA should call functionB, and functionB
should call functionA, forming a cycle that prints numbers in a specific pattern.
Ensure both programs have a base condition to prevent infinite loops.*/
#include<iostream>
using namespace std;
void functionB(int n);
void functionA(int n){
if (n==0)
return;
cout<<n<<" ";
functionB(n-1);
}
void functionB(int n){
    if (n==0)
    return;
    cout<<n<<" ";
    functionA(n-1);
}
int main(){
    int n;
    cout<<"Enter the number; ";
    cin>>n;
   functionA(n) ;
}