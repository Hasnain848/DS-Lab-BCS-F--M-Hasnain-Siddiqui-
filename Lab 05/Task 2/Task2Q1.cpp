/*1. Write a simple C++ program that demonstrates direct recursion. Create a function
printNumbers(int n) that prints numbers from n down to 1 by calling itself
directly.*/
#include<iostream>
using namespace std;
void printnumbers(int n){
    if(n==0)
    return;
    cout<<n<<" ";
    return printnumbers(n-1);
}
int main(){
    int n;
    cout<<"Enter the number; ";
    cin>>n;
    printnumbers(n);
}