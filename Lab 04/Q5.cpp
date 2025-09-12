/*5. Implement the Interpolation Search algorithm. The program should take a sorted array
with uniformly distributed values and a target value from the user. The algorithm should
estimate the position of the target and check if the estimated position holds the correct
value. If the element is found, print its index; otherwise, indicate that it's not present.*/
#include<iostream>
using namespace std;

void interpolationSearch(int arr[],int size,int key) {
    int low=0,high=size-1;

    while(low<=high&&key>=arr[low]&& key<=arr[high]){
        
        int pos=low+((key-arr[low])*(high-low))/(arr[high]-arr[low]);
        if(arr[pos]==key){
            cout<<"Target element index: "<<pos<<endl;
            return;

        }

        if(arr[pos]<key){

            low =pos+1; 
        }
        else{

            high =pos-1; 
        }
    }

    cout<<"ERROR: Target element is not in the list"<<endl;
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
   
   interpolationSearch(array,size,target);
   
    delete [] array;

}