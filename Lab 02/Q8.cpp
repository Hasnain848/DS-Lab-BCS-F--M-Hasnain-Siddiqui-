/*Task #8:
Create a dynamic program to store temperature readings of a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day.*/
#include<iostream>
using namespace std;
int main(){
    float **temperature;
    float *average;
    int n,m,hot,htime,cold,ctime;
    cout<<"Enter the number of days you want to store: ";
    cin>>n;
    cout<<"Enter, how many time to store in a day (1 or 3...times): ";
    cin>>m;
    temperature = new float*[n];
    average = new float[n];
    for(int i=0;i<n;i++){
        temperature[i] = new float[m];
    }
    float minVal = 99999.0;
    float maxVal = -99999.0;
    cout<<"\n====== Enter the Data ======="<<endl;
    for(int i=0;i<n;i++){
        float sum =0.0;
        for(int j=0;j<m;j++){
            cout<<"Day "<<i+1<<" Time "<<j+1<<" :";
            cin>>temperature[i][j];
            sum+=temperature[i][j];
            if(temperature[i][j]>maxVal){
                 maxVal = temperature[i][j];
                hot = i;
                htime=j;
            }
            if(temperature[i][j]<minVal){
                minVal = temperature[i][j]; 
                cold = i;
                ctime =j;
            }
        }
        average[i]=sum/m;
    }
    cout<<"\n======== Average Temperature ========="<<endl;
    for(int i=0;i<n;i++){
        cout<<"Day "<<i+1<<" : "<<average[i]<<endl;
    }
    cout<<"========================================="<<endl;
    cout<<"Hottest Day : "<<hot+1<<" which is "<<temperature[hot][htime]<<" ."<<endl;
     cout<<"Coldest Day : "<<cold+1<<" which is "<<temperature[cold][ctime]<<" ."<<endl;

     for(int i=0;i<n;i++){
    delete[] temperature[i];
}
delete[] temperature;
delete[] average;
}