/*4. Use Insertion Sort to sort an array of integers provided by the user. Then, implement the
Binary Search algorithm to find a target value within the newly sorted array. The program
should display the sorted array and the index of the found element or a message if it's not
present.*/
#include<iostream>
using namespace std;
void InsertionSort(int *arr,int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){            
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

}
void BinarySearch(int *arr,int size,int key){
    int left=0;
    int right= size - 1;
    bool found = false;

    while (left<=right){
        int mid=left+(right-left)/2;
        
        if (arr[mid]==key){
            cout<<"\nElement found at index "<<mid+1<<endl;
            found=true;
            break;
        }
        else if(arr[mid]<key){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }

    if(!found){
        cout<<"\nERROR: Target element is not in the list"<<endl;
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
    cout<<"\nEnter target element: ";
    cin>>target;
   InsertionSort(array,size);
   cout<<"\n========= Sorted Array ========="<<endl;
   for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
   }
   BinarySearch(array,size,target);
   
    delete [] array;

}