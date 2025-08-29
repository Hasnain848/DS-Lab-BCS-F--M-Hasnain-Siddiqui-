#include<iostream>
using namespace std;
int main(){
    int student;
    int *noOfcourses;
    int **jagged;
    cout<<"Enter the no of student: ";
    cin>>student;
    noOfcourses = new int[student];
    jagged = new int*[student];
    cout<<"\nEnter the no of courses enrolled of  each student"<<endl;
    for(int i=0;i<student;i++){
        cout<<"Student "<<i+1<<" : ";
        cin>>noOfcourses[i];
        jagged[i] = new int[noOfcourses[i]];
    }
    for(int i=0;i<student;i++){
        int sum=0;
        cout<<"========Student "<<i+1<<" ========"<<endl;
        for(int j=0;j<noOfcourses[i];j++){
            cout<<"Course "<<j+1<<" marks: ";
            cin>>jagged[i][j];
           // sum+=jagged[i][j];
        }
       // double average = (double)sum/noOfstudent[i];
       // cout<<"Averge marks: "<<average<<endl;
    }
    for(int i=0;i<student;i++){
        int sum=0;
        cout<<"\n========Student "<<i+1<<" ========"<<endl;
        for(int j=0;j<noOfcourses[i];j++){
            sum+=jagged[i][j];
        }
        double average = (double)sum/noOfcourses[i];
        cout<<"Average marks: "<<average<<endl;
    }
    //  for(int i=0;i<courses;i++){
    //     cout<<"\n========Course "<<i+1<<" ========"<<endl;
    //     for(int j=0;j<noOfstudent[i];j++){
    //         cout<<"Student "<<j+1<<" marks: "<<jagged[i][j]<<endl;
           

    //     }
    // }
for(int i=0;i<student;i++){
    delete[]jagged[i];
}
delete[] jagged;


}
