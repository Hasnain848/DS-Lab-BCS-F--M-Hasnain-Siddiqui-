/*Implement the class Hash class having the functionality of insert, delete, search and display using list (built
in library for linked list in C++).*/
#include<iostream>
#include<list>
using namespace std;
# define table_size 7
class Hashtable{
private:
list<pair<string,string>>table[table_size];
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
// Hashtable(){
//     for(int i=0;i<table_size;i++){
//         table[i;
//     }
// }
void insert(string key,string value){
    
    int index = hashfunction(key);
    for(auto&x :table[index]){
        if(x.first==key){
            x.second=value;
            return;
        }
    }
    table[index].push_front({key,value});
            
}
bool search(string key) {
    int index = hashfunction(key);

    for(auto&x :table[index]){
        if(x.first==key){
             cout << "Found: " << x.second << endl;
                return true;
        }
    }
    cout<<"Record not found"<<endl;
    return false;     
}
void Delete(string key){
    int index = hashfunction(key);
    for (auto i = table[index].begin(); i != table[index].end(); i++) {
            if (i->first == key) {
                table[index].erase(i);
                cout << "Deleted\n";
                return;
            }
        }

        cout << "Key not found\n";
}
void display() {
    for (int i = 0; i < table_size; i++) {
        if(!table[i].empty()){
            cout << "Bucket " << i << ": ";
            for(auto& p:table[i]){
                cout<<"()"<<p.first<< " : " <<p.second<< ") -> ";
            }
             cout << "NULL\n";
            }
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

    myhash.insert("A", "zzzzz");  // update value

    cout << "\n--- After update Hash Table ---\n";
    myhash.display();

    cout << "\nSearching for key A...\n";
    bool found = myhash.search("A");

    return 0;
}