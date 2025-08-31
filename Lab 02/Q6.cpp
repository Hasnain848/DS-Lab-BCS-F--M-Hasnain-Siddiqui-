/*Task #6:
Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=>
Demonstrate the class by storing marks of 5 students and printing them safely without
direct pointer manipulation.*/
#include<iostream>
using namespace std;
class safepointer
{
    int *value;
    public:
    safepointer(){
        value = nullptr;
    }
    safepointer(int value){
        this ->value=new int(value);
    }
    void setvalue(int val){
        if(value==nullptr){
            value = new int;
        }
        *value=val;
    }
    int getvalue(){
        if(value==nullptr){
            cout<<"variable pointer in null"<<endl;
            return 0;
        }
        return *value;
    }
    void release(){
        if(value != nullptr){
            delete value;
            value = nullptr;
        }
    }
    ~safepointer(){
        release();
    }
};
int main(){
    safepointer marks[5];
    for(int i=0;i<5;i++){
        int m;
        cout<<"Enter marks of Student "<<i+1<<" :";
        cin>>m;
        marks[i].setvalue(m);
    }
    cout<<"\n======= Display Students Marks ======="<<endl;
    for(int i=0;i<5;i++){
        cout<<"Student "<<i+1<<" marks: "<<marks[i].getvalue()<<endl;
    }
    return 0;
}