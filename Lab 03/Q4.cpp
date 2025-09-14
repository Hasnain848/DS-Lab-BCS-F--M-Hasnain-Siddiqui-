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
          Tail->next=Head;
           return;
        }
       else
       {    Tail->next=newnode;
            Tail = newnode;
            Tail->next=Head;
       }
    }
    void Display(){
        Node *p = Head;
        do{
            cout<<p->data<<"-> ";
            p=p->next;
        }while(p->next!=Head);
        cout<<"Head"<<endl;
    }
   int survivor(int k,int size){
        Node *p=Head;
        Node *q =Tail;
        int count =1;
        for(int i=size;i>1;i--){
            for(int j=1;j<k;j++){
                q=p;
                p=p->next;
            }
            int val =p->data;
            p=p->next;
            q->next=p;
            if(Head->data==val)Head = p;
            if(Tail->data==val)Tail = q;
            deleteNode(val);

        }
       return Head->data;
   }
    void deleteNode(int value){
    if(Head==NULL)  
      {  return;}
    Node *p=Head;
    Node *q=Tail; 
    if(Head->data==value){
        if(Head==Tail){
            delete Head;
            Head=Tail=NULL;
            return;
        }
        Head=Head->next;
        Tail->next=Head;
        delete p;
        return;
    }
    p=Head->next;
    while(p!=Head){
        if(p->data==value){
            q->next=p->next;
            if(p==Tail){
                Tail=q;
            }
            delete p;
            return;
        }
        q =p;
        p =p->next;
    }
}

   ~LL(){
        if(Head==NULL) return;
        Node *p=Head;
        Tail->next=NULL; 
        while(p){
            Node *temp=p;
            p=p->next;
            delete temp;
        }
    }
};
int main() {
    int size,k,value;
    LL list;
    cout<<"Enter the size of List (N): ";
    cin>>size;
    cout<<"=========== Enter the Data in List ============"<<endl;
    for(int i=0;i<size;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>value;             
        list.Insert(value);
    }
    cout<<"Enter k (the k-th person to eliminate): ";
    cin>>k;
    int survivorPos=list.survivor(k,size);
    cout<<"\nSurvivor person: "<<survivorPos<<endl;
 
}
