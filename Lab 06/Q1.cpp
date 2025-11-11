/*Task 1 – Basic Stack Implementation
Implement a stack using arrays. Support the following operations:
1. Push an element
2. Pop an element
3. Peek (top element)
4. Display stack contents*/
#include<iostream>
using namespace std;
class stack{
    int size;
    int top;
    int *s;
    public:
    stack(){
        size=0;
        top=-1;
        s=nullptr;
    }
    stack(int size){
        this->size=size;
        top=-1;
        s = new int[size];
    }
    void push(int value){
        if(top>=size-1){
            cout<<"Stack overflow or full"<<endl;
            return;
        }
        else{
            top++;
            s[top]=value;
        }
    }
    int pop(){
        if(top==-1)
            {cout<<"Stack is Underflow or empty"<<endl;
            return 0;}
        else{
            int x = s[top];
            top--;
            return x;
        }
    }
    int peek(){
        if(top==-1)
            {cout<<"Stack is Underflow or empty"<<endl;
            return 0;}
        else{
            int x = s[top];
            return x;
        }
    }
    void display(){
        if(top==-1)
            {cout<<"Stack is Underflow or empty"<<endl;
            return;}
        else{
            cout<<"==========================="<<endl;
        for(int i=0;i<=top;i++){
            cout<<s[i]<<endl;
        }}
        cout<<"==========================="<<endl;
    }
    ~stack(){
    delete[] s;
}

};
int main(){
    int n;
    cout<<"Enter size of stack: ";
    cin>>n;
    stack st(n);
    int choice,value;
    do{
        cout<<"===================================================="<<endl;
        cout<<"\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value to push: ";
                cin>>value;
                st.push(value);
                break;
            case 2:
                cout<<"Popped value: "<<st.pop()<<endl;
                break;
            case 3:
                cout<<"Top element: " << st.peek()<<endl;
                break;
            case 4:
                cout<<"Stack contents:\n";
                st.display();
                break;
        }
    }while(choice!=5);
}
