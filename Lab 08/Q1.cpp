#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val):data(val){right=left=NULL;}

};
class Tree
{
    int count;
    Node*root;
    Node* insert(Node *node,int val)
    {
        if(node==NULL){
            return new Node(val);
        }
        if(val<node->data){
            node->left=insert(node->left,val);
        }
        else if(val>node->data){
            node->right=insert(node->right,val);
        }
        return node;
    }
    public:
    Tree(){root=NULL;count=0;}
    void insert(int val)
    {
        root=insert(root,val);
    }
    void inorder(Node *node)
    {
        if(node!=NULL){
            inorder(node->left);
            cout<<node->data<<" ";
            inorder(node->right);
        } 
    }
    void display()
    {
        cout<<"=========== Displaying BST Tree ============="<<endl;
        inorder(root);
        cout<<"\n============================================="<<endl;
    }
    Node* findmin(Node *node)
    {
        while(node && node->left){
            node=node->left;
        }
        return node;
    }
    Node* Delete(Node *node,int val)
    {
        if(node==NULL)return node;
         if(val<node->data){
            node->left=Delete(node->left,val);
        }
        else if(val>node->data){
            node->right=Delete(node->right,val);
        }
        else{
            if(node->left==NULL&&node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left==NULL){
                Node *temp=node->right;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                Node *temp=node->left;
                delete node;
                return temp;
            }
            else{
                Node *temp=findmin(node->right);
                node->data=temp->data;
                node->right=Delete(node->right,temp->data);
            }
        }
        return node;
    }
    void  Delete(int val)
    {
        root = Delete(root,val);
    }
    bool Search(int val){
        return Search(root,val);
    }
    bool Search(Node *node,int val)
    {
        if(node==NULL){
            return  false;
        }
        if(val==node->data){
            return true;
        }
        else if(val<node->data){
            return Search(node->left,val);
        }
        else
            return Search(node->right,val);
    }
};
int main(){
    Tree t;
    t.insert(23);
    t.insert(12);
    t.insert(2);
    t.insert(54);
    t.insert(26);
    t.insert(43);
    t.display();
    t.Delete(2);
    t.display();
    cout<<t.Search(2);
}
