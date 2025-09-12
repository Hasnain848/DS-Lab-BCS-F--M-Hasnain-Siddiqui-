#include<iostream>
using namespace std;
void linearSearch(int *array,int target,int size){
    for(int i=0;i<size;i++){
        if(array[i]==target){
            cout<<"Target element index: "<<i+1<<endl;
            return;
        }
    }
    cout<<"Soorry element is not here"<<endl;
    
}
int main(){
    int size,target;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    int *array;
    array = new int[size];
    cout<<"Enter Data"<<endl;
    for(int i=0;i<size;i++){
        cout<<"Element "<<i+1<<" : ";
        cin>>array[i];
    }
    cout<<"\nEnter target element: ";
    cin>>target;
    linearSearch(array,target,size);
    delete [] array;

}
