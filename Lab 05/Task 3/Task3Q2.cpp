#include<iostream>
using namespace std;
int sumNotTail(int n){
    if(n==1){
        return 1;
    }
    else{
        return n+sumNotTail(n-1);
       
    }
}
int main(){
    int n;
    cout<<"Enter the number; ";
    cin>>n;
    int total =0;
   cout<<"Total: "<<sumNotTail( n)<<endl ;
}