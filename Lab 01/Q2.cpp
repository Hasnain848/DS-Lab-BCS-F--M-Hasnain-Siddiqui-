/*Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
complete with a shallow copy implementation? Define attributes such as student name, exam
date, and score within the class, and include methods to set these attributes and display exam
details. As part of this exercise, intentionally omit the implementation of the copy constructor
and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
shallow copy, and observe any resulting issues?*/
#include<iostream>
#include<cstring>
using namespace std;
class Exam
{
    char *studname;
    char *examdate;
    int score;

    public:
    Exam(const char* name, const char* date, double sc)
    {
        studname = new char[strlen(name)+1];
        strcpy(studname,name);
        examdate = new char[strlen(date)+1];
        strcpy(examdate,date);
        score = sc;
    }
    void setAttributes(const char* name, const char* date, double sc)
    {
       strcpy(studname,name);// studname = name;
       strcpy(examdate,date);
       score = sc;

    }
    void Display()
    {
        cout<<"-------- Information --------"<<endl;
        cout<<"Student Name: "<<studname<<endl;
        cout<<"Exam date: "<<examdate<<endl;
        cout<<"Score: "<<score<<endl;
    }
    ~Exam()
    {
        delete [] studname;
        delete [] examdate;
    }
};
int main() 
{
    Exam exam1("Hasnain", "2025-08-23", 95.5);
    cout << "Exam1 details:" << endl;
    exam1.Display();
    cout << "Creating shallow copy ->exam2 = exam1.." << endl;
    Exam exam2 = exam1;  // shallow copy (yahan default copy constructor call hoga jo shallow copy kare ga)
    cout << "Exam2 details :" << endl;
    exam2.Display();
    cout<<"=========================================================================================="<<endl;
    cout<<" Problem: both exam1 and exam2 will try to delete the same memory (studentName & examDate)\n -> This causes double free / memory corruption"<<endl;
    cout<<"=========================================================================================="<<endl;
    return 0;
}