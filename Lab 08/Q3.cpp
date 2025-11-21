/*Create the BST which stores the students object in BST and student object has the
property like name, roll and score. Create tree based on name of student AND Perform
following operations in BST:
 Insert the student record,
 Search the students based on name
 Delete the students whose score is less than 10
 And get the students whose score is max in tree.
In main function create the object array of students with 10 students from those store 7
seven students randomly and perform all above objects.*/
#include<iostream>
#include <ctime>
using namespace std;
#include <iostream>
using namespace std;
class Student {
    string name;
    string roll;
    int score;
public:
    Student(){
        name ="";
        roll ="";
        score =0;
    }
    Student(string n,string r,int s){
        name =n;
        roll =r;
        score =s;
    }
    Student(const Student &obj){
        name =obj.name;
        roll =obj.roll;
        score =obj.score;
    }
    Student& operator=(const Student &obj){
        if(this!=&obj){ 
            name =obj.name;
            roll =obj.roll;
            score =obj.score;
        }
        return *this;
    }
    void Display(){
        cout<<"\n--------------------------------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Roll no : "<<roll<<endl;
        cout<<"Score: "<<score<<endl;
       // cout<<"--------------------------------"<<endl;
    }
    void setName(string n){name=n;}
    void setRoll(string r){roll=r;}
    void setScore(int s){score=s;}

    string getName()const{return name;}
    string getRoll()const{return roll;}
    int getScore()const{return score;}
};
class Node
{
    public:
    Student data;
    Node *left;
    Node *right;
    Node(Student s):data(s){right=left=NULL;}

};
class Tree
{
    int count;
    Node*root;
    Node* insert(Node *node,Student val)
    {
        if(node==NULL){
            return new Node(val);
        }
        if(val.getName()<node->data.getName()){
            node->left=insert(node->left,val);
        }
        else if(val.getName()>node->data.getName()){
            node->right=insert(node->right,val);
        }
        return node;
    }
    public:
    Tree(){root=NULL;count=0;}
    void insert(Student val)
    {
        root=insert(root,val);
    }
    void inorder(Node *node)
    {
        if(node!=NULL){
            inorder(node->left);
            node->data.Display();
            inorder(node->right);
        } 
    }
    void display()
    {
        cout<<"=========== Displaying BST Tree ============="<<endl;
        inorder(root);
        cout<<"\n============================================="<<endl;
    }
     void Search(string val){
        if(Search(root,val)){
            return ;
        }
        else{
            cout<<"\nNot Found"<<endl;
        }
    }
    bool Search(Node *node,string val)
    {
        if(node==NULL){
            return  false;
        }
        if(val==node->data.getName()){
            node->data.Display();
            return true;
        }
        else if(val<node->data.getName()){
            return Search(node->left,val);
        }
        else
            return Search(node->right,val);
    }
    
    Student findmax()
    {
        Node *node=root;
        while(node && node->right){
            node=node->right;
        }
        return node->data;
    }

    Node* Delete(Node *node,Student val)
    {
        if(node==NULL)return node;
         if(val.getName()<node->data.getName()){
            node->left=Delete(node->left,val);
        }
        else if(val.getName()>node->data.getName()){
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
    void  Delete(Student val)
    {
        root = Delete(root,val);
    }
      Node* findmin(Node *node)
    {
        while(node && node->left){
            node=node->left;
        }
        return node;
    }
   void Deletestudents(){
        deleteHelper(root);
    }

    void deleteHelper(Node* node){
        if(node == NULL) return;

        deleteHelper(node->left);
        deleteHelper(node->right);
        if(node->data.getScore() < 10){
            Delete(node->data);
        }
    }
    Student findMaxScore(Node* node) {
        if (node == NULL)
            return Student(); 
        Student left = findMaxScore(node->left);
        Student right = findMaxScore(node->right);
        Student maxStudent = node->data;

        if (left.getScore() > maxStudent.getScore())
            maxStudent = left;
        if (right.getScore() > maxStudent.getScore())
            maxStudent = right;
        return maxStudent;
    }
Student findMaxScore()
{
    return findMaxScore(root);
}

};
int main(){
    srand(time(0));
      Tree records;
    Student students[10] = {
        Student("Hasnain", "24K-0516", 95),
        Student("Ibtrahim", "24K-0517", 90),
        Student("Obaid", "24K-0518", 10),
        Student("Ahsan", "24K-0519", 76),
        Student("Umair", "24K-0520", 8),
        Student("Fahad", "24K-0521", 92),
        Student("Saad", "24K-0522", 81),
        Student("Ali", "24K-0523", 7),
        Student("Bilal", "24K-0524", 85),
        Student("Hamza", "24K-0525", 90)
    };
    bool used[10]={false};
    for(int i=0;i<7;i++){
        int index;
        do{
            index = rand() % 10;
        } while(used[index]);
        used[index] = true;
        records.insert(students[index]);
    }
    string na;
    //records.display();
  cout<<"Search the student by name:  ";
  cin>>na;
    records.Search(na);
    cout<<"\nDeleting Students whose Score is less than 10"<<endl;
    records.Deletestudents();
    //records.display();
    cout<<"The Student with Max score is"<<endl;
    Student max=records.findMaxScore();
    max.Display();
}
