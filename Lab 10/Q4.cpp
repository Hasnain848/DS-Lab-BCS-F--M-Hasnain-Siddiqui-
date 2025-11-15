#include<iostream>
#include<algorithm>
using namespace std;
 void heapifydown(int arr[],int size,int index){
        int largest = index;
        int l=2*index +1;
        int r=2*index +2;

        if (l<size && arr[l]>arr[largest]){
            largest=l;
        }
        if(r<size && arr[r]>arr[largest]){
            largest=r;
        }
        if(largest!=index){
            swap(arr[index],arr[largest]);
            heapifydown(arr,size,largest);
        }
    }
void convertMinToMaxHeap(int *arr,int n) {
    for(int i=n/2-1;i>=0;i--){
        heapifydown(arr,n,i);
    }
}
int main(){

    int n,K;
    cout<<"Enter the size of min array: ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the Data of min Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Element "<<i+1<<" : ";
        cin>>arr[i];
    }
    cout<<"=============================================="<<endl;
    cout<<"Input: arr[] = {";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"}"<<endl;
    convertMinToMaxHeap(arr,n);
    cout<<"Output: arr[] = {";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"}"<<endl;
 

    delete []arr;
}
