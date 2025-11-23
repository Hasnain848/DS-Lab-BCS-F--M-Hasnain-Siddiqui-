/*Task # 5:
Implement a C++ class StudentHashTable to manage student records in a hash table with a size of 15. Use
quadratic probing for collision resolution with the formula (index + attempt^2) % table size.Implement the
function InsertRecord that takes a student&#39;s roll number and name, inserting the record into the hash table
using quadratic probing.Implement the function SearchRecord that takes a roll number, searches for the
corresponding record using quadratic probing, and prints the student&#39;s name if found; otherwise, print a
&quot;Record not found&quot; message.*/
#include <iostream>
using namespace std;
#define table_size 15
struct records
{
    int roll;
    string name;
    records(int r = 0, string v = " ") : roll(r), name(v) {}
};
class StudentHashTable
{
    records studTable[table_size];
    bool isoccupied[table_size] = {false};
    int hashfunction(int key)
    {
        return key % table_size;
    }

public:
    StudentHashTable() {}
    void InserRecord(string value, int key)
    {
        int index = hashfunction(key);
        int startindex = index;
        int i = 1;
        while (isoccupied[index])
        {
            if (studTable[index].roll == key)
            {
                studTable[index].name = value;
                return;
            }
            index = (index + i * i) % table_size;
            i++;
            if (index == startindex)
            {
                cout << "Table are full !" << endl;
                return;
            }
        }
        studTable[index].name = value;
        studTable[index].roll = key;
        isoccupied[index] = true;
    }
    void SearchRecord(int key)
    {
        int index = hashfunction(key);
        int startindex = index;
        int i = 1;

        while (isoccupied[index] == true)
        {
            if (studTable[index].roll == key)
            {
                cout << "Student name: " << studTable[index].name << " ,Roll no: " << studTable[index].roll << endl;
                return;
            }
            index = (index + i * i) % table_size;
            i++;

            if (index == startindex)
            {
                cout << "Record Not found" << endl;
                return;
            }
        }
    }
    void Display()
    {
        for (int i = 0; i < table_size; i++)
        {
            if (isoccupied[i])
                cout << "Student name: " << studTable[i].name << " ,Roll no: " << studTable[i].roll << endl;
        }
    }
};
int main()
{
    StudentHashTable hashTable;
    cout << "===== Inserting Student Records =====" << endl;
    hashTable.InserRecord("Ali Khan", 101);
    hashTable.InserRecord("Bilal Ahmed", 116);
    hashTable.InserRecord("Cemal Raza", 102);
    hashTable.InserRecord("Dua Fatima", 117);
    hashTable.InserRecord("Emaan Shah", 103);
    hashTable.InserRecord("Fahad Mustafa", 131);
    hashTable.InserRecord("Gulzar Hussain", 89);
    hashTable.InserRecord("Hamza Ali", 45);

    cout << "\n===== Displaying All Records =====" << endl;
    hashTable.Display();
    cout << "\n===== Searching for Records =====" << endl;
    cout << "Searching for Roll No 101:" << endl;
    hashTable.SearchRecord(101);

    cout << "\nSearching for Roll No 117:" << endl;
    hashTable.SearchRecord(117);

    cout << "\nSearching for Roll No 89:" << endl;
    hashTable.SearchRecord(89);

    cout << "\nSearching for Roll No 999 (should not be found):" << endl;
    hashTable.SearchRecord(999);

    cout << "\n===== Updating Record =====" << endl;
    cout << "Updating Roll No 101 with new name:" << endl;
    hashTable.InserRecord("Ali Nawaz", 101);
    hashTable.SearchRecord(101);

    cout << "\n===== Final Display =====" << endl;
    hashTable.Display();

    return 0;
}
