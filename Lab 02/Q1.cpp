/*Task #1:
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly.*/
#include<iostream>
using namespace std;
int main(){
    int *arr;
    int size,choice;
    cout<<"Enter the initial size of array: ";
    cin>>size;
    arr = new int[size];
    arr[0]=0;
    cout<<"Enter 0 if you dont want to update "<<endl;
    for(int i=0;i<size;i++){
        
        cout<<"Array["<<i+1<<"]:  ";
        cin>>choice;
        if(choice==0){
            continue;
        }
        arr[i]=choice;
    }
    cout<<"\nPrinting Array"<<endl;
    for(int i=0;i<size ;i++)
        cout<<arr[i]<<" ";
    delete []arr;
    return 0;
}