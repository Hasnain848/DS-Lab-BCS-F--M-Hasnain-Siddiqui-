/*Task #5:
Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation.*/
#include<iostream>
using namespace std;
void creatematrix(int **&matrix,int row,int colom)
{  
    matrix = new int*[row];
    for(int i=0;i<row;i++)
    {
        matrix[i] = new int[colom];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<colom;j++)
        {
            cout<<"Elmement row "<<i+1<<" and coloum "<<j+1<<" :";
            cin>>matrix[i][j];
        }
    }
}
void DeallocateMatrix(int **&matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];  
    }
    delete[] matrix;  
    matrix = nullptr; 
}

void Addition(int **A,int **B,int row ,int colom)
{
    int **result = new int*[row];
    for(int i=0;i<row;i++)result[i]=new int[colom];
    for(int i=0;i<row;i++){
        for(int j=0;j<colom;j++){
            result[i][j]=A[i][j]+B[i][j];
        }
    }
    cout<<"\n========= After Addition ========="<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<colom;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
     DeallocateMatrix(result,row);
}
void Subtraction(int **matrix1,int **matrix2,int row ,int colom){
    int **result = new int*[row];
    for(int i=0;i<row;i++)result[i]=new int[colom];
    for(int i=0;i<row;i++){
        for(int j=0;j<colom;j++){
            result[i][j]=matrix1[i][j]-matrix2[i][j];
        }
    }
    cout<<"\n========= After Subtraction ========="<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<colom;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    DeallocateMatrix(result,row);
}
int main()
{
    cout<<"======== Program for Two Matrix Addition & Subtraction ========"<<endl;
    int row, colom,choice;
    cout<<"Enter the row for each matrix : ";
    cin>>row;
    cout<<"Enter the colom for each matrix : ";
    cin>>colom;
    
    system("cls");
    cout<<"========= Enter the Matrix A Data ========="<<endl;
    int **A;
    creatematrix(A,row,colom);
    cout<<"========= Enter the Matrix B Data ========="<<endl;
    int **B;
    creatematrix(B,row,colom);
    system("cls");
    cout<<"======== What you want to perform ========"<<endl;
    cout<<"1. Addition (A+B)"<<endl;
    cout<<"2. Subtraction (A-B)"<<endl;
    cout<<"3. Subtraction (B-A)"<<endl;
    cout<<"4. Exit "<<endl;
    cout<<"Enter the choice: ";
    cin>>choice;
    switch(choice){
        case 1: Addition(A,B,row,colom); break;
        case 2: Subtraction(A,B,row,colom); break;
        case 3: Subtraction(B,A,row,colom); break;
        case 4: break;
        default: {
            cout<<"Invalid input"<<endl;
            break;
        }
    }
    DeallocateMatrix(A,row);       
    DeallocateMatrix(B,row);
}