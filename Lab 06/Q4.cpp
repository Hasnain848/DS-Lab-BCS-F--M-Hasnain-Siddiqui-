/*Task 4 – Circular Queue
Implement a circular queue using arrays. Handle the following conditions correctly:
1. Enqueue when rear wraps around
2. Dequeue when front moves ahead
3. Prevent overflow when queue is full*/
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
    return (top == -1 && rear == -1);
}
    bool isFull(){
        return ((rear+1)%size== top);
    }
    void Enqueue(int val){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return;
        }
        else if(isEmpty()){
            top=rear =0;
        }
        else
         rear=(rear+1)%size;
        q[rear]=val;
    }
    int dequeue(){
        int x=0;
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        else if(top==rear)
        {
            x=q[top];
            top=rear=-1;
        }
        else{
            x = q[top];
            top=(top+1)%size;
        }
        return x;
    }
    void Display(){
         if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout<<"=========Displaying Queue========"<<endl;
        int i=top;
        do{
            cout<<q[i]<<endl;
            i=(i+1)%size;
        }while(i!=(rear+1)%size);
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