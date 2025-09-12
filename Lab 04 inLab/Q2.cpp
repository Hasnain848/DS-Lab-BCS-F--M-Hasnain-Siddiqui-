#include<iostream>
using namespace std;
void Addelement(int *&Array,int &oldsize,int pos,int key){
    int newsize =oldsize+1;
    int *newArray = new int[newsize];
    int index = 0;
    for(int i=0;i<newsize;i++){
        if(i==pos){
            newArray[i]=key;

        }
        else{
            newArray[i]=Array[index];
            index++;

        }
    }
 
    //delete[] Array;
    Array=newArray;
    oldsize=newsize;
}

void BinarySearch(int *arr,int size,int key){
    int left=0;
    int right= size - 1;
    bool found = false;

    while (left<=right){
        int mid=left+(right-left)/2;
        
        if (arr[mid]==key){
            cout<<"ID found at index "<<mid+1<<endl;
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
 
        Addelement(arr,size,left,key);
        cout<<"\nUpdated list after insertion:\n";
    }

   
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size,target;
    cout<<"Enter the size of array: ";
    cin>>size;
    int *array;
    array = new int[size];
    cout<<"Enter Employee ids"<<endl;
    for(int i=0;i<size;i++){
        cout<<"Employee "<<i+1<<" : ";
        cin>>array[i];
    }
    cout<<"\nEnter you id : ";
    cin>>target;
    BinarySearch(array,size,target);
    delete[] array;

}
