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

    LL Merge(LL list){
    LL finallist;
    Node *list1 = Head;
    Node *list2 = list.Head;
    Node* list3;
    Node *last;
    if(list1==NULL){ 
        finallist.Head = list2;
        return finallist;
    }
    if(list2==NULL){
        finallist.Head = list1;
        return finallist;
    }
    if(list1->data<list2->data){
        list3 = list1;
        last = list1;
        list1=list1->next;
        last->next=NULL;
    }
    else{
       list3 = list2;
       last = list2;
        list2=list2->next;
        last->next=NULL;
    }
    while (list1!=NULL && list2!=NULL){
        if(list1->data<list2->data){
            last->next=list1;
            last = list1;
            list1=list1->next;
            last->next=NULL;
        }
        else{
            last->next=list2;
            last = list2;
            list2=list2->next;
            last->next=NULL;
        }
    }
    if(list1!=NULL){
        last->next=list1;
    }
    else{
        last->next=list2;
    }
    finallist.Head=list3;
    return finallist;
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
    LL list3=list2.Merge(list1);
    list3.Display();

}