/*Task 3 – Simple Queue Implementation
Implement a linear queue using arrays with the following operations:
1. Enqueue
2. Dequeue
3. Display queue contents
4. Check if queue is empty/full*/
#include<iostream>
using namespace std;
class Queue{
    int size;
    int top;
    int rear;
    int *q;
    public:
    Queue(){
        size=0;
        top=rear=-1;
        q=nullptr;
    }
    Queue(int size){
        this->size=size;
        top=rear=-1;
        q = new int[size];
    }
    bool isEmpty(){
        return (top==rear);
    }
    bool isFull(){
        return (rear== size-1);
    }
    void Enqueue(int val){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return;
        }
        rear++;
        q[rear]=val;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        top++;
        int x = q[top];
        return x;
    }
    void Display(){
        cout<<"=========Displaying Queue========"<<endl;
        for(int i=top+1;i<=rear;i++){
            cout<<q[i]<<endl;
        }
        cout<<"=================================="<<endl;
    }
    ~Queue(){ delete[] q; }
};
int main(){
    int n;
    cout<<"Enter size of Queue: ";
    cin>>n;
    Queue qu(n);
    int choice,value;
    do{
        cout<<"===================================================="<<endl;
        cout<<"\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                qu.Enqueue(value);
                break;
            case 2:
                cout<<"Dequeued value: "<<qu.dequeue()<<endl;
                break;
            case 3:
                cout<<"Queue contents:\n";
                qu.Display();
                break;
        }
    }while(choice!=4);
}