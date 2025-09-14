/*5. Convert Between Linked List Types
Implement functions for conversion:
1. Convert a singly linked list into a doubly linked list.
2. Convert a singly linked list into a circular linked list.
• Demonstrate both conversions with sample input lists.*/
#include<iostream>
using namespace std;
class Node{
       public:
        int data;
        Node *next;
        Node *prev;

    Node(int value){
        data=value;
        next=NULL;
        prev=NULL;
    }
};
class LL{
    Node *Head;
    Node *Tail;
    public:
    LL(){Head =Tail= NULL;}
    void Insert(int value)
    {
        Node *newnode=new Node(value);
        if(Head==NULL)
        {
          Head =Tail=newnode;
           return;
        }
       else
       {    Tail->next=newnode;
            Tail = newnode;
       }
    }
    void SinglytoDoubly(){
        Node *p = Head;
        Node *q = NULL;
        while(p){
            p->prev=q;
            q=p;
            p=p->next;
           
        }
        p = Head;
        cout<<"\n========== Converted to Doubly Linked List ==========\n";
        while(p){
            cout<<p->data<<"<=> ";
            p=p->next;
        }
        cout<<"NULL"<<endl;

    }
    void SinglytoCircular(){
        if(Head==NULL || Tail==NULL)return;
          Node *p = Head;
    while(p){ //to convert it from doubly to singly then convert it into circular
        p->prev = NULL;      
        if(p->next == NULL)  
            break;
        p = p->next;
    }
    Tail->next=Head;
    cout<<"\n========== Converted to Circular Linked List ==========\n";
    Node *q= Head;
    do {
        cout<<q->data<<"-> ";
        q = q->next;
    } while(q != Head);
    cout << "Head\n";
    }
    void Display(){
        Node *p = Head;
        cout<<"============ Original List ============="<<endl;
        while(p){
            cout<<p->data<<"-> ";
            p=p->next;
        }
        cout<<"NULL"<<endl;
    }
   void DisplayReverse(){ // to check is doubly linkelist made or not
        Node *p=Tail;
        while(p){
            cout<<p->data<<"<=> ";
            p=p->prev;
        }
    }
    ~LL()
    {
        Node *p = Head;
        while(p){
            Node *temp=p;
            p=p->next;
            delete temp;
        }
        Head =nullptr;
        
    }
};
int main(){
     LL list;
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(5);
    list.Insert(6);
    list.Insert(7);
    list.Insert(8);
    
    list.Display();
    list.DisplayReverse();// check list is singly
    list.SinglytoDoubly();
    list.DisplayReverse();// check Is list become doubly
    list.SinglytoCircular();
    list.DisplayReverse();// check Is list become Circular

}