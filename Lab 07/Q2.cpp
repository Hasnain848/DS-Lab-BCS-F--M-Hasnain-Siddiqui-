#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int val) : data(val), next(NULL) {}
};


void insert(node*&head,int val){
    node* temp=new node(val);
    if(head==NULL){
        head = temp;
        return;
    }
    node* curr = head;
    while(curr->next){
        curr= curr->next;
    }
    curr->next =temp;
}

void freeingspace(node*head){
    while(head){
        node* temp =head;
        head =head->next;
        delete temp;
    }
}

int findmax(int arr[],int n){
    int max =arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max) {
            max = arr[i];
        }
    }
    return max;
}

void radixsort(int arr[],int n,bool ascending=true){
    int max=findmax(arr,n);
    int exp=1;

    while((max/exp)>0){
        node* buckets[10]={NULL};  

        for(int i=0;i<n;i++){
            int digit=(arr[i]/exp)%10; 
            insert(buckets[digit],arr[i]);
        }
        
        int idx = 0;
        if(ascending) {
            for(int i=0; i<10;i++){
                node* temp=buckets[i];
                while(temp){
                    arr[idx++]=temp->data;
                    temp=temp->next;
                }
                freeingspace(buckets[i]);
            }
        }
        else{
            for(int i=9;i>=0;i--) {
                node* temp=buckets[i];
                while(temp){
                    arr[idx++]=temp->data;
                    temp=temp->next;
                }
                freeingspace(buckets[i]);
            }
        }
        
        exp*=10;
    }
}

void printArray(int arr[],int n) {
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout <<endl;
}

int main() {
    int arr[]={36,987,654,2,20,99,456,957,555,420,66,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"==============================================================="<<endl;
    cout << "Original array: ";
    printArray(arr, n);

    int *arr_asc=new int[n];
    for(int i=0;i<n;i++)
        arr_asc[i]=arr[i];
    radixsort(arr_asc,n,true);
    cout<<"==============================================================="<<endl;
    cout<<"Ascending order: ";
    printArray(arr_asc,n);
    
    int *arr_desc=new int[n];
    for(int i=0;i<n;i++)
        arr_desc[i]=arr[i];
    radixsort(arr_desc,n,false);
    cout<<"Descending order: ";
    printArray(arr_desc,n);
    cout<<"==============================================================="<<endl;
    delete[]arr_asc;
    delete[]arr_desc;
    return 0;
}