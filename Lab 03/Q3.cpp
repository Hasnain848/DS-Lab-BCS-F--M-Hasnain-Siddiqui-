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
    void reversing(int k){
       Node* p=Head;
        Node *dummy=new Node(0);
        dummy->next=p;
         Node* prevGroupEnd = dummy;
        while(1){
            Node *kgroup = prevGroupEnd;
            for(int i=0;i<k && kgroup!=NULL;i++){
              kgroup = kgroup->next;
            }
            if(kgroup==NULL){
                break;
            }
            Node *groupstart=prevGroupEnd->next;
            Node *nextgroup = kgroup->next;
             Node* q =NULL;
             Node* r =NULL;
             Node *curr = groupstart;
            while(curr!=nextgroup){
                r =q;
                q =curr;
                curr =curr->next;
                q->next=r;
            }
            prevGroupEnd->next=q;
            groupstart->next=nextgroup;

            prevGroupEnd =groupstart;
        }
     Head = dummy->next;
        delete dummy;
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
    int k;
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(5);
    list.Insert(6);
    list.Insert(7);
    list.Insert(8);
    cout<<"=========== Original List =========="<<endl;
    list.Display();
    cout<<"Enter the K: ";
    cin>>k;
    list.reversing(k);
    cout<<"\n=========== After Reversing in Group=========="<<endl;
    list.Display();
  

}