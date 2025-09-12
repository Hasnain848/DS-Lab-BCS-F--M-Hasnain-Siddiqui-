/*2. Write a program to implement the Bubble Sort algorithm. The program should take
an array of integers as input from the user, sort the array using bubble sort, and then
display both the unsorted and sorted arrays.*/
#include<iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(int *arr,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

}
int main(){
    int size,target;
    cout<<"Enter the size of array: ";
    cin>>size;
    int *array;
    array = new int[size];
    cout<<"Enter Data"<<endl;
    for(int i=0;i<size;i++){
        cout<<"Element "<<i+1<<" : ";
        cin>>array[i];
    }
    cout<<"\n========= Unsorted Array ========="<<endl;
    for(int i=0;i<size;i++){
     cout<<array[i]<<" ";
    }
    BubbleSort(array,size);
   cout<<"\n========= Sorted Array ========="<<endl;
   for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
   }
   
    delete [] array;

}
