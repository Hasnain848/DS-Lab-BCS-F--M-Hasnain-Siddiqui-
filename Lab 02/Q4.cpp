/*Task #4:
Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses.*/
#include<iostream>
using namespace std;
void ResizeArray(int *&Array,int &oldsize)
{
    int newsize;
    cout<<"\nEnter the number of new months: ";
    cin>>newsize;
    if(newsize==oldsize)
    {
        return;
    }
    if(newsize<oldsize)
    {
        if (newsize < oldsize) {
        char confirm;
        cout << "\nWarning: You are deleting some expances, Continue? (y/n): ";
        cin >> confirm;
        if (confirm != 'y') return;
}
    }
    int *newArray = new int[newsize];
    int limit= (oldsize<newsize)?oldsize:newsize;
    for(int i=0;i<limit;i++)
    {
        newArray[i]=Array[i];
    }
    for (int i = limit; i < newsize; i++)
    {
        newArray[i] = 0;
    }

    delete[]Array;
    Array=newArray;
    oldsize=newsize;
}
int main()
{
    int n;
    char choice;
    int *expances;
    cout<<"Enter the number of months you want to track: ";
    cin>>n;
    expances = new int[n];
    cout<<"\n======= Enter the Expances ========"<<endl;
  //  while(1)
 //   {
        for(int i=0;i<n;i++)
        {
            cout<<"Month "<<i+1<<" :";
            cin>>expances[i];
        }
        cout<<"Do you want to Track for more months (y/n): ";
        cin>>choice;
        if(choice=='y')
        {
            ResizeArray(expances,n);
            for (int i=0;i<n;i++)
        {
            if (expances[i]==0) 
            {
                cout<<"Month "<<i+1<<" : ";
                cin>>expances[i];
            }
        }

        }
        int sum=0;
        for (int i=0;i<n;i++)
        {
            sum+=expances[i];
        }
        cout<<"\n==========================================="<<endl;
        cout<<"Total Expances   : "<<sum<<endl;
        cout<<"Average Expances : "<<(double)sum/n<<endl;
        delete [] expances;
   // }
}