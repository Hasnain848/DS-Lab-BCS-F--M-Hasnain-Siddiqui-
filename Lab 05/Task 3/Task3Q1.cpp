/*1. Implement a C++ function sumTail(int n, int total) that calculates the sum
of numbers from 1 to n using tail recursion. The recursive call should be the last
operation in the function.*/
#include<iostream>
using namespace std;
int sumTail(int n,int total){
    if(n==0){
        return total;
    }
    else{
        total = total+n;
        return sumTail(n-1,total);
    }
}
int main(){
    int n;
    cout<<"Enter the number; ";
    cin>>n;
    int total =0;
   cout<<"Total: "<<sumTail( n,total)<<endl ;
}