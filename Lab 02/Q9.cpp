/*Task #9:
Implement a program to represent a sparse matrix using a dynamic 2D array.
=> Input matrix elements.
=> Display the matrix in normal form.
=> Display the matrix in compressed form (row, column, value).*/
#include<iostream>
using namespace std;
bool isSparceMatrix(int **matrix,int row, int col)
{
    int zeroCount = 0, nonZeroCount = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j] == 0)
                zeroCount++;
            else
                nonZeroCount++;
        }
    }
    return (zeroCount > nonZeroCount);
}
int main(){
    cout<<"========== Program is about Sparce Matrix =========="<<endl;
    int **SparceMatrix;
    int n,m;
    cout<<"Enter the row you want (n): ";
    cin>>n;
    cout<<"Enter the coloum you want (m): ";
    cin>>m;
    SparceMatrix = new int*[n];
    for(int i=0;i<n;i++){
        SparceMatrix[i]= new int [m];
    }
    cout<<"Enter the matrix data"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Row "<<i+1<<" Coloum "<<j+1<<" : ";
            cin>>SparceMatrix[i][j];
        }
    }
    if(isSparceMatrix(SparceMatrix,n,m))
    {
        cout<<"\n====== Normal Form ======="<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<SparceMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n====== Compressed Form ======="<<endl;
        cout<<"Row  Col  Value"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(SparceMatrix[i][j]!=0){
                    cout<<" "<<i<<"    "<<j<<"    "<<SparceMatrix[i][j]<<endl;
                }
            }
        }

    }
    else
    {
        cout<<"Sorry the matrix you Entered is NOT a sparce matrix"<<endl;    
    }
    for(int i=0;i<n;i++){
        delete [] SparceMatrix[i];
    }
    delete [] SparceMatrix;
    return 0;
}