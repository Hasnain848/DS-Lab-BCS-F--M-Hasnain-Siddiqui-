#include<iostream>
using namespace std;
class runner{
    string name;
    int sec;
    public:
    runner(){
        name="";
        sec=0;
    }
    runner(string n,int score):name(n),sec(score){}
    
        runner(const runner& obj){
        name = obj.name;
        sec = obj.sec;
    }
    void setname(string n){name=n;}
    void setsecond(int s){sec=s;}
    int getsecond(){return sec;}
    void display(){
        cout<<name<<" - "<<sec<<" seconds"<<endl;
    }
    runner& operator=(const runner&obj){
        if (this!=&obj){     
            name =obj.name;
            sec =obj.sec;
        }
        return *this;
    }
};
void merge(runner r[],int left , int mid,int right){
    int nl=mid-left+1;
    int nr=right-mid;
    runner *l1=new runner[nl];
    runner *l2=new runner[nr];
    for (int i=0;i<nl;i++)    
        l1[i]= r[left+i];    
    for (int j=0;j<nr;j++)    
        l2[j]= r[mid+1+j];    
    int i=0,j=0,k=left;
    while(i<nl && j<nr){
        if(l1[i].getsecond()<=l2[j].getsecond()){
            r[k]=l1[i];
            i++;
        }
        else{
            r[k]=l2[j];
            j++;
        }
        k++;
    }
    while(i<nl)    
    {    
        r[k++] = l1[i++];      
    }    
      
    while(j<nr)    
    {    
        r[k++] = l2[j++];       
    } 
    delete[] l1;
    delete[] l2;
}

void mergeSort(runner r[], int left, int right)  
{  
    if (left<right)   
    {  
        int mid =(left+right)/2;  
        mergeSort(r,left,mid);  
        mergeSort(r, mid+1,right);  
        merge(r,left,mid,right);  
    }  
}   
  
int main()  
{  
    string name;
    int sec;
    runner r[10];
    for(int i=0;i<10;i++){
        cout<<"Enter name and finish time for runner "<<i+1<<": ";
        cin>>name;
        cin>>sec;
        r[i].setname(name);
        r[i].setsecond(sec);
    }
    mergeSort(r,0,9);
    cout<<endl;
    cout<<"Top 5 fastest Runners: "<<endl;
    for(int i=0;i<5;i++){
        cout<<i+1<<". ";
        r[i].display();
    }

} 