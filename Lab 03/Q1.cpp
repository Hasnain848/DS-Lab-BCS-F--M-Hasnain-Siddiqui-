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
    bool palindrome(){
       Node *p=Head;
       Node*q =Head;
       while(q->next!=NULL && q->next->next!=NULL){
        p=p->next;
        q=q->next->next;
       }
       bool flag=true;
       Node *half1=Head;
       Node *temphalf2=p;
       Node* half2=reversing(temphalf2);
       while(half2){
        if(half1->data!=half2->data){
            flag=false;
            break;
        }
        half1=half1->next;
        half2=half2->next;
       }
       return flag;
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
    int i=1,value,size;
    LL list;
    cout<<"Enter the size of List You want to enter: ";
    cin>>size;
    cout<<"\n=========== Enter the Data in List ============"<<endl;
    for(int i=0;i<size;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>value;
        list.Insert(value);
    }
    cout<<"\n===========  List  ============"<<endl;
    list.Display();
    cout<<"Palindrome: ";
    (list.palindrome()==true)?cout<<"True"<<endl : cout<<"False"<<endl;

    //  cout<<"\n\nDeleted Last Element: "<<list.DeleteLast()<<endl;
    //  list.Display();
}