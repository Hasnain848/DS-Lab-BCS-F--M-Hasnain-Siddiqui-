/*Task#2: Suppose you have an AVL tree with the following elements: 50, 30, 70, 20, 40, 60, 80.
You need to insert a new node with value 55 into the tree and then display the tree after
performing a left rotation on the root. Write a C++ code to accomplish this task using the
AVLTree class and its methods.*/
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    int height;
    Node *left;
    Node *right;
    Node(int val):data(val),height(0){left=nullptr;right=nullptr;}
};
class AVL
{
    Node *root;
    Node* Insert(Node* node,int data){
        if(node==nullptr)
            return new Node(data);
        if(data < node->data){
            node->left=Insert(node->left,data);
        }
        else{
            node->right=Insert(node->right,data);
        }
        node->height=getheight(node);
        if(BF(node)==2 && BF(node->left)==1){
            return LLRotation(node);
        }
        else if(BF(node)==2 && BF(node->left)==-1){
            return LRRotation(node);
        }
        else if(BF(node)==-2 && BF(node->left)==-1){
            return RRRotation(node);
        }
        else if(BF(node)==-2 && BF(node->left)==1){
            return RLRotation(node);
        }
        return node;
    }
    int getheight(Node *node){
        if(node==nullptr){
            return 0;
        }
        int hl = getheight(node->left);
        int hr = getheight(node->right);
        return hl>hr?hl+1:hr+1;
    }
    int BF(Node* node){
        if(node==nullptr){
            return 0;
        }
        int hl = getheight(node->left);
        int hr = getheight(node->right);
        return hl-hr;
    }
    Node* LLRotation(Node* node){
        Node *pl=node->left;
        Node *plr=pl->right;

        pl->right=node;
        node->left=plr;

        pl->height=getheight(pl);
        node->height=getheight(node);
        return pl;
    }
    Node* LRRotation(Node* node){
        Node *pl=node->left;
        Node *plr=pl->right;

        pl->right=plr->left;
        node->left=plr->right;
        plr->left=pl;
        plr->right=node;

        pl->height=getheight(pl);
        plr->height=getheight(plr);
        node->height=getheight(node);
        return plr;
    }
    Node* RRRotation(Node* node){
        Node *pl=node->right;
        Node *plr=pl->left;

        pl->left=node;
        node->right=plr;

        pl->height=getheight(pl);
        node->height=getheight(node);
        return pl;
    }
    Node* RLRotation(Node* node){
        Node *pl=node->right;
        Node *plr=pl->left;

        pl->left=plr->right;
        node->right=plr->left;
        plr->left=node;
        plr->right=pl;

        pl->height=getheight(pl);
        plr->height=getheight(plr);
        node->height=getheight(node);
        return plr;
    }
    void inorder(Node *node){
        if(node ==nullptr)return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
    public:
    AVL(){root=nullptr;}
    void Insert(int data){
        root=Insert(root,data);
    }
    void display(){
        inorder(root);
        cout<<endl;
    }
};
int main(){
    AVL tree;
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);
    cout<<"============== AVL TREE ==============="<<endl;
    tree.display();
    cout<<"======================================="<<endl;
    cout<<"Inserting 55 in tree"<<endl;
    tree.Insert(55);
    cout<<"============== AVL TREE ==============="<<endl;
    tree.display();
    cout<<"======================================="<<endl;
}