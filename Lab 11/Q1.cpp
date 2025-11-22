/*Task # 1
Suppose you are working on a program that needs to store a large number of strings, with the possibility of
duplicate strings. You decide to use chain hashing to efficiently store and retrieve the strings, but you want
to ensure that collisions are avoided as much as possible. Your hash function simply takes the sum of the
ASCII values of the characters in the string and returns the remainder after dividing by the number of
buckets. You decide to implement the hash table using a linked list for each bucket.
Input and output:
HashTable myhash;
[hine: key is A]
myhash.insert(&quot;A&quot;,&quot;aaaaa&quot;);
myhash.insert(&quot;B&quot;,&quot;bbbbb&quot;);
myhash.insert(&quot;C&quot;,&quot;ccccc&quot;);
myhash.insert(&quot;A&quot;,&quot;zzzzz&quot;);*/
#include<iostream>
using namespace std;
# define table_size 7
struct node{
    string key;
    string value;
    node*next;
    node(string k,const string& v):key(k),value(v){next = nullptr;}
};
class Hashtable{
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
Hashtable(){
    for(int i=0;i<table_size;i++){
        table[i]=nullptr;
    }
}
void insert(string key,string value){
    
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

void display() {
    for (int i = 0; i < table_size; i++) {
        node* curr = table[i];
        if (curr == nullptr) {
            continue;
        }
         cout << "Bucket " << i << ": ";
        while (curr != nullptr) {
            cout << "[" << curr->key << " : " << curr->value << "] -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
}

};

int main() {
    Hashtable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
        cout << "\n--- Before update Hash Table ---\n";
    myhash.display();
    myhash.insert("A", "zzzzz");   

    cout << "\n--- After update Hash Table ---\n";
    myhash.display();

    cout << "\nSearching for key A...\n";
    node* result = myhash.search("A");

    if (result != nullptr)
        cout << "Found " << result->key << " : " << result->value << endl;
    else
        cout << "Key not found\n";

    return 0;
}
