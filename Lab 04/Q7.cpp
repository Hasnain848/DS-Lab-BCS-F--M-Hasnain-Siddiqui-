/*7. Implement the Shell Sort algorithm to sort an array of integers. The algorithm should start
with a large gap, then perform a gapped insertion sort, and gradually reduce the gap until
it's 1. After sorting, compare its performance against the Bubble Sort and Insertion Sort
algorithms for the same input array size (e.g., 1000 elements). Record and display the time
taken and the number of comparisons/swaps for all three algorithms to demonstrate why
Shell Sort is an improvement over Insertion Sort.*/
#include<iostream>
using namespace std;
long long comparisons = 0;
long long swaps =0 ;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void ShellSort(int arr[],int n){
    comparisons =swaps = 0;
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int j=i;
            while(j>=gap){
                comparisons++;
                if(arr[j-gap]>temp){
                    arr[j]=arr[j-gap];
                    swaps++;
                    j-=gap;
                }
                else break;
            }
            arr[j]=temp;
        }
    }
}
void InsertionSort(int *arr,int size){
    comparisons =swaps= 0;
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0){
            comparisons++;  
            if(arr[j]>key){
                arr[j+1]=arr[j];
                j--;
                swaps++;
            }
            else break;        
        }
        arr[j+1]=key;
    }

}
void BubbleSort(int *arr,int size){
    comparisons =swaps= 0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            comparisons++;
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaps++;
            }
        }
    }

}
void arrayCopyfunction(int *source, int *dest,int size){
    for(int i=0;i<size;i++){
        dest[i]=source[i];
    }
}
int main(){
int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int *array,*temp;
    array = new int[size];
    temp = new int[size];
    cout<<"Enter Data"<<endl;
    for(int i=0;i<size;i++){
        cout<<"Element "<<i+1<<" : ";
        cin>>array[i];
    }
    cout<<"\n========= Original Array ========="<<endl;
    for(int i=0;i<size;i++){
     cout<<array[i]<<" ";
    }
    cout<<"\n=================================="<<endl;
    arrayCopyfunction(array,temp,size);
    BubbleSort(temp,size);
    cout<<"\n<- Bubble Sort Complexity Analysis ->"<<endl;
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Swaps: "<<swaps<<endl;

    arrayCopyfunction(array,temp,size);
    InsertionSort(temp,size);
    cout<<"\n<- Insertion Sort Complexity Analysis ->"<<endl;
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Swaps: "<<swaps<<endl;

    arrayCopyfunction(array,temp,size);
    ShellSort(temp,size);
    cout<<"\n<- Shell Sort Complexity Analysis ->"<<endl;
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Swaps: "<<swaps<<endl;

    delete [] temp;
    delete [] array;
}
