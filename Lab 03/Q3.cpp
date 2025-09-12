/*3. Reverse in Groups of K
Reverse nodes of a singly linked list in groups of size k.
• Example:
o Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, with k = 3
o Output: 3 → 2 → 1 → 6 → 5 → 4 → 8 → 7*/
#include<iostream>
using namespace std;
class Node{
       public:
    int data;
    Node *next;

    Node(int value){
        data=value;
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
    Node* reversing(Node* p){
     Node* q =NULL;
     Node* r =NULL;

    while(p){
        r =q;
        q =p;
        p =p->next;
        q->next=r;
    }
    return q;
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
     int i=1,value,size1,size2;
    LL list1,list2;
    cout<<"Enter the size of List 1: ";
    cin>>size1;
    cout<<"Enter the size of List 2: ";
    cin>>size2;
    cout<<"\n=========== Enter the Data in List 1 ============"<<endl;
    for(int i=0;i<size1;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>value;
        list1.Insert(value);
    }
     cout<<"\n=========== Enter the Data in List 2 ============"<<endl;
    for(int i=0;i<size2;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>value;
        list2.Insert(value);
    }
  

}