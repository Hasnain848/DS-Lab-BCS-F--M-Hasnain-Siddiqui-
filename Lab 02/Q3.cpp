#include<iostream>
using namespace std;
int main(){
    int courses;
    int *noOfstudent;
    int **jagged;
    cout<<"Enter the no of courses: ";
    cin>>courses;
    noOfstudent = new int[courses];
    jagged = new int*[courses];
    cout<<"\nEnter the no of students enrolled in each course"<<endl;
    for(int i=0;i<courses;i++){
        cout<<"Course "<<i+1<<" : ";
        cin>>noOfstudent[i];
        jagged[i] = new int[noOfstudent[i]];
    }
    for(int i=0;i<courses;i++){
        int sum=0;
        cout<<"========Course "<<i+1<<" ========"<<endl;
        for(int j=0;j<noOfstudent[i];j++){
            cout<<"Student "<<j+1<<" marks: ";
            cin>>jagged[i][j];
           // sum+=jagged[i][j];
        }
       // double average = (double)sum/noOfstudent[i];
       // cout<<"Averge marks: "<<average<<endl;
    }
    for(int i=0;i<courses;i++){
        int sum=0;
        cout<<"\n========Course "<<i+1<<" ========"<<endl;
        for(int j=0;j<noOfstudent[i];j++){
            sum+=jagged[i][j];
        }
        double average = (double)sum/noOfstudent[i];
        cout<<"Average marks: "<<average<<endl;
    }
    //  for(int i=0;i<courses;i++){
    //     cout<<"\n========Course "<<i+1<<" ========"<<endl;
    //     for(int j=0;j<noOfstudent[i];j++){
    //         cout<<"Student "<<j+1<<" marks: "<<jagged[i][j]<<endl;
           

    //     }
    // }
for(int i=0;i<courses;i++){
    delete[]jagged[i];
}
delete[] jagged;

}