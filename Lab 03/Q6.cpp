/*6. Flatten a Multilevel Linked List
Each node has:
• next pointer (normal linked list connection).

Lab Manual 03
• child pointer (points to another linked list).
Write a function to flatten the structure so that all nodes appear in a single-level list.
• Example:
• 1 → 2 → 3
• |
• 4 → 5
Output: 1 → 2 → 4 → 5 → 3*/
#include<iostream>
using namespace std;
class Node{
       public:
    int data;
    Node *child;
    Node *next;

    Node(int value){
        data=value;
        child =NULL;
        next=NULL;
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
    void Display(){
        Node *p = Head;
        while(p){
            cout<<p->data<<"-> ";
            p=p->next;
        }
        cout<<"NULL"<<endl;
    }
    void flatten(Node *p){
    if (Head == NULL) {
        return;
    }
    while(p != NULL){
        if(p->child!=NULL){
            Node* next=p->next;
            p->next=p->child;
            Node* tail=p->child;
             flatten(tail);   // agar child ka child ho to us kai lie recursive ho jaye ga
            while(tail->next!=NULL){
                tail=tail->next;
            }
            tail->next =next;
            p->child =NULL;
        }
        p=p->next; 
    }
}

Node* getHead() { return Head; }
  
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
    Node* head = list.getHead();
    Node* second = head->next;  

    Node* child1 = new Node(4);
    Node* child2 = new Node(5);
    child1->next = child2;
    second->child = child1;

    cout << "Before flattening (main list only):\n";
    list.Display();
    list.flatten(list.getHead());

    cout << "\nAfter flattening:\n";
    list.Display();

    return 0;

}