/*Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.*/
#include<iostream>
using namespace std;
class Box
{
    public:
    int *size;
    Box(int s) 
    {
         size = new int(s); 
    }
    Box(const Box& other) 
    {
        size = new int(*other.size); 
    }
    Box& operator=(const Box&other){
		if(this!=&other){
			delete size;                  
            size = new int(*other.size);
           
		}
	
			return *this;
		
	}
    void display(){
        cout<<"Box Size: "<<*size<<endl;
    }
    ~Box() 
    {
        delete size; 
    }


};
int main(){
     cout << "--- Creating box1 ---" << endl;
    Box box1(10);
    box1.display();

    cout << "\n--- Creating box2 as a deep copy of box1 (Copy Constructor) ---" << endl;
    Box box2 = box1;  
    box2.display();

    cout << "\n--- Modifying box2 size ---" << endl;
    *box2.size = 20;
    box1.display(); 
    box2.display(); 

    cout << "\n--- Using Copy Assignment Operator (box3 = box2) ---" << endl;
    Box box3(5);
    box3 = box2;  
    box3.display();

    cout << "\n--- Modifying box3 size ---" << endl;
    *box3.size = 30;
    box2.display(); 
    box3.display(); 
    return 0;
}