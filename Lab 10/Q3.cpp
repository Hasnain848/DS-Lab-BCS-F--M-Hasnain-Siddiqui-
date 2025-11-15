#include<iostream>
using namespace std;
class maxheap{
    int heap[100];
    int size;
    public:
    maxheap(){size=0;}
    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    void heapify_up(int index){
        while(index !=0 && heap[index]>heap[parent(index)]){
            swap(heap[index],heap[parent(index)]);
            index = parent(index);
        }


    }
    void heapify_down(int index){
        int largest = index;
        int l = left(index);
        int r = right(index);

        if(l<size && heap[l]>heap[largest])
            largest = l;
        if(r<size && heap[r]>heap[largest])
            largest = r;
        if(largest!=index){
            swap(heap[index],heap[largest]);
            heapify_down(largest);
        }
    }
    void insert(int val){
        if(size>100){
            cout<<"Heap is Full"<<endl;
            return;
        }
        heap[size]=val;
        heapify_up(size);
        size++;
    }
    int Delete(){
        if(size==0){
            cout<<"Heap is Empty"<<endl;
            return -1;
        }
        int x = heap[0];
        heap[0]=heap[size-1];
        size--;
        heapify_down(0);
        return x;
    }
      void display(){
        for(int i=0;i<size;i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
};
void creatheap(maxheap &h,int arr[],int n){
    for(int i=0;i<n;i++){
        h.insert(arr[i]);
    }

}
int main(){
    maxheap h;
    int n,K;
    cout<<"Enter the size of array: ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the Data in Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Element "<<i+1<<" : ";
        cin>>arr[i];
    }
    cout<<"Enter the Kth value: ";
    cin>>K;
    creatheap(h,arr,n);
    //h.display();
    int x;
    for(int i=0;i<K;i++){
        x= h.Delete();
    }
    cout<<"Output: "<<x<<endl;

    delete []arr;
}