// /*Task 2 – Stack with Linked List
// Implement a stack using linked lists. Demonstrate its use with a real-life example (e.g., browser
// history navigation).*/
#include<iostream>
using namespace std;
class stacknode{
    public:
    string data;
    stacknode*next;
    stacknode(string val){
        data = val;
        next = NULL;
    }
};
class Stack{
    stacknode *top;
    public:
    Stack(){top=NULL;}
    void push(string val){
        stacknode *newnode=new stacknode(val);
        if(!newnode){
            cout<<"Memory allocation failed!"<<endl;
            return;
        }
        newnode->next=top;
        top = newnode;
    }
    string pop(){
        if(top==NULL)
            {cout<<"Stack is Underflow or empty"<<endl;
            return "NULL";}
        else{
            stacknode *temp = top;
            top=top->next;
            string x = temp->data;
            delete temp;
            return x;
        }
    }
    string peek(){
        if(top==NULL)
            {cout<<"Stack is Underflow or empty"<<endl;
            return "NULL";}
        else{
            string x = top->data;
            return x;
        }
    }
    bool isEmpty() {
        return top == NULL;
    }
    void display(){
        if(top==NULL)
            {cout<<"(Empty)"<<endl;
            return;}
        else{
            cout<<"=========Displaying Stack========"<<endl;
            stacknode *p=top;
            while(p){
                cout<<p->data<<endl;
                p=p->next;
            }
             cout<<"================================"<<endl;
        }
    }
    ~Stack()
    {
        stacknode *p = top;
        while(p){
            stacknode *temp=p;
            p=p->next;
            delete temp;
        }
        top =nullptr; 
    }
};
int main(){
    Stack backStack;
    Stack forwardStack;
    string currentPage = "Home";
    int choice;
    string page;
    do{
        cout<<"===================================================="<<endl;
        cout<<"\n========== Browser Navigation ==========\n";
        cout<<"Current Page: "<<currentPage<<endl;
        cout<<"1. Visit new page\n2. Back\n3. Forward\n4. Show history\n5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter page name: ";
                cin>>page;
                backStack.push(currentPage);
                while(!forwardStack.isEmpty())
                    forwardStack.pop(); 
                currentPage = page;
                cout<<"Visited: "<<currentPage<<endl;
                break;

            case 2:
                if(backStack.isEmpty()){
                    cout<<"No previous page!"<<endl;
                }
                else{
                    forwardStack.push(currentPage);
                    currentPage = backStack.pop();
                    cout<<"Moved back to: "<<currentPage<<endl;
                }
                break;

            case 3:
                if(forwardStack.isEmpty()){
                    cout<<"No forward page!"<<endl;
                }
                else{
                    backStack.push(currentPage);
                    currentPage = forwardStack.pop();
                    cout<<"Moved forward to: "<<currentPage<<endl;
                }
                break;

            case 4:
                cout<<"\n--- Back History ---\n";
                backStack.display();
                cout<<"--- Forward History ---\n";
                forwardStack.display();
                break;
        }
    }while(choice != 5);

    cout<<"Exiting Browser..."<<endl;
}

