/*Task # 2:
Some ABC university students want to develop an ASCII code-based dictionary app for their Final Year
Project. This app should allow the users to perform the following operations:
a) Add_Record () This function will take a string input from user and add into the dictionary. For adding
the string user will use a unique hash function k MOD 100 (table size must be 100, for k user will calculate
the SUM of ASCII character of that word).
b) Word_Search () User will only pass a single string. If string is not available then generate an error
message.
c) Print_Dictionary () Users can also display the complete dictionary.*/
#include<iostream>
using namespace std;
#define table_size 100
struct node{
string key;
string value;
node* next;
node(string k,const string& v):key(k),value(v){next=nullptr;}
};
class Dictionary{
private:
node *table[table_size];
int hashfunction(string key){
    int key2=asci_code(key);
    return key2 % table_size;
}
public:
int asci_code(string key){
    int sum=0;
    for(int i=0;key[i]!='\0';i++){
        sum+=key[i];
    }
    return sum;
}
Dictionary(){
    for(int i=0;i<table_size;i++){
        table[i]=nullptr;
    }
}
void Addrecord(string key,string value){
    
    int index = hashfunction(key);
    node*newnode=new node(key,value);
    if (table[index]==nullptr){
        table[index]=newnode;
        return;
    }
    else{
         node* found = search(key);

        if (found != nullptr) {
        found->value = value;
        return;
    }
            newnode->next=table[index]; //insertion at head
            table[index]=newnode;
    }
            
}
node* search(string key) {
    int index = hashfunction(key);

    node* curr = table[index];
    while (curr != nullptr) {
        if (curr->key == key) {
            return curr;  
        }
        curr = curr->next;
    }
    
    return nullptr;       
}
void Delete(string key){
    int index = hashfunction(key);
    node* temp =table[index];
    node* prev =nullptr;
    while(temp &&temp->key!=key){
        prev = temp;
        temp = temp->next;
    }
    if(temp==nullptr){
        cout<<" Key: "<<key<<"Not found"<<endl;
        return;
    }
    if(prev==nullptr)
    table[index]=temp->next;
    else prev ->next=temp->next;
    delete temp;
    cout<<"key "<<key<<" deleted successfully !"<<endl;
}
void display() {
    for (int i = 0; i < table_size; i++) {
        node* curr = table[i];
        if (curr == nullptr) {
            continue;
        }
         cout << "index " << i << ": ";
        while (curr != nullptr) {
            cout << "(" << curr->key << "," << curr->value << ") -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
}

};

int main() {
    Dictionary records;

    records.Addrecord("AB", "FASTNU");
    records.Addrecord("CD", "CSS");
    records.Addrecord("EF", "Electric");
    //     cout << "\n--- Before update Hash Table ---\n";
    // records.display();
    // records.Addrecord("A", "zzzzz");   

    // cout << "\n--- After update Hash Table ---\n";
    // records.display();

   
    node* result = records.search("AB");

    if (result != nullptr){
        cout << "\nSearch key AB: ";
      cout <<  result->value << endl;
    }
    else{
        cout<<"ERROR: Record is not present"<<endl;
    }
    records.Delete("EF");
    records.display();
    return 0;
}



