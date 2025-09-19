#include<iostream>
using namespace std;
int calculateFactorial(int n){
    if(n==0)
        return 1;
    return n*calculateFactorial(n-1);
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Factorial: "<<calculateFactorial(n)<<endl;
}