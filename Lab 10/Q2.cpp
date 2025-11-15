#include<iostream>
#include<algorithm>
using namespace std;
class maxheap{
    private:
    int heap[100];
    int size;
    public:
    maxheap(){
        size =0;
    }
    int parent(int ind){
        return (ind-1)/2;
    }
    int left(int ind){
        return (2*ind)+1;
    }
    int right(int ind){
        return (2*ind)+2;
    }
    void insert(int val){
        if(size>100)return;
        heap[size]=val;
        heapify_up(size);
        size++;
    }
    void Delete(){
        if(size==0){
            cout<<"Hepunderflow"<<endl;
            return;
        }
        cout<<"Deleed element: "<<heap[0]<<endl;
        heap[0]=heap[size-1];
        size--;
        heapifydown(0);
    }
    void heapify_up(int index){
        while(index!=0 && heap[index]>heap[parent(index)]){
            swap(heap[index],heap[parent(index)]);
            index=parent(index);
        }
    }
     
    void updatekey(int i,int newval){
       heap[i]=newval;
       if(newval>heap[parent(i)]){
           heapify_up(i);
       }
       else { 
           heapifydown(i);
        }
    }
    void heapifydown(int index){
        int largest = index;
        int l=left(index);
        int r= right(index);

        if (l<size && heap[l]>heap[largest]){
            largest=l;
        }
        if(r<size && heap[r]>heap[largest]){
            largest=r;
        }
        if(largest!=index){
            swap(heap[index],heap[largest]);
            heapifydown(largest);
        }
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    maxheap heap;
    heap.insert(8);
    heap.insert(7);
    heap.insert(5);
    heap.insert(4);
    heap.display();
    heap.updatekey(1,0);
    heap.display();

}