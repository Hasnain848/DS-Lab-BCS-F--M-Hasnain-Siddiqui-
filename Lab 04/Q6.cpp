/*6. Implement the Comb Sort algorithm to sort an array of integers. This algorithm improves
upon bubble sort by reducing the number of comparisons and swaps using a "gap" that
decreases over time. After sorting, perform a complexity analysis: count and display the
total number of swaps and comparisons performed during the sorting process.*/
#include<iostream>
using namespace std;
int swaps=0;
int comparisons=0;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void CombSort(int *arr,int size){
    comparisons = 0;
    swaps =0;

    float shrink =1.3;
    int gap = size;
    bool swapped =true;

    while(gap>1 || swapped){
        gap=(int)(gap/shrink);
        if(gap<1)gap=1;
        swapped = false;
        for(int i=0;i+gap<size;i++){
            comparisons++;
            if(arr[i]>arr[i+gap]){
                swap(arr[i],arr[i+gap]);
                swaps++;
                swapped=true;
            }
        }
        
    }

}
int main(){
    int size;
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
    CombSort(array,size);
   cout<<"\n========= Sorted Array ========="<<endl;
   for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
   }
   cout<<"\n<- Complexity Analysis ->"<<endl;
   cout<<"Comparisons: "<<comparisons<<endl;
   cout<<"Swaps: "<<swaps<<endl;
    delete [] array;

}
