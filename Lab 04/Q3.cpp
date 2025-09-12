/*3. Implement the Selection Sort algorithm. The program should take an array of integers from
the user, find the smallest element, and exchange it with the element at the first position.
This process should continue until the array is completely sorted. Display the sorted array
to the user.*/
#include<iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void SelectionSort(int *arr,int size){
    for(int i=0;i<size-1;i++){
        int minindex=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minindex]){
                minindex = j;
            }
        }
        swap(arr[i],arr[minindex]);
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
    SelectionSort(array,size);
   cout<<"\n========= Sorted Array ========="<<endl;
   for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
   }
   
    delete [] array;

}