/*Task#3: Suppose you have an AVL tree with the following nodes: 10, 5, 15, 3, and 7 (in this
order). Perform the following steps:
1. Insert the value 12 into the tree.
2. Calculate the balance factor for each node.
3. Check the height of the tree.
4. If the tree becomes unbalanced during insertion, implement the rotations required to
5. maintain balance.
6. Provide the final balanced AVL tree.*/
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
        else if(BF(node)==-2 && BF(node->right)==-1){
            return RRRotation(node);
        }
        else if(BF(node)==-2 && BF(node->right)==1){
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
    void displayWithBF(Node *node){
        if(node == nullptr) return;
        displayWithBF(node->left);
        cout << "Node: " << node->data 
             << " | Height: " << node->height 
             << " | BF: " << BF(node) << endl;
        displayWithBF(node->right);
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
     void showBalanceFactors(){
        displayWithBF(root);
    }
    
    int getTreeHeight(){
        return getheight(root);
    }
   
};
int main(){
    AVL tree;
    cout << "============== Building Initial AVL TREE ==============" << endl;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(3);
    tree.Insert(7);
    
    cout << "Inorder Traversal: ";
    tree.display();
    cout << "\nBalance Factors:" << endl;
    tree.showBalanceFactors();
    cout << "Tree Height: " << tree.getTreeHeight() << endl;
    cout << "=======================================================" << endl;
    
    cout << "\n>> Inserting 12 into tree..." << endl << endl;
    tree.Insert(12);
    
    cout << "============== Final AVL TREE ========================" << endl;
    cout << "Inorder Traversal: ";
    tree.display();
    cout << "\nBalance Factors:" << endl;
    tree.showBalanceFactors();
    cout << "Tree Height: " << tree.getTreeHeight() << endl;
    cout << "=======================================================" << endl;
    
    return 0;
}
