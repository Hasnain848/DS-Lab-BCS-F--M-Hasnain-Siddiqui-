#include<iostream>
using namespace std;

void printboard(int **board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int **board,int row ,int colom ,int N){
    for(int j=0;j<N;j++){ // horizontal
        if(board[row][j]==1)return false;
    }
    for(int i=0;i<N;i++){ // vertical
        if(board[i][colom]==1)return false;
    }
    for(int i=row,j=colom;j>=0&&i>=0;i--,j--){ // left diagonal
        if(board[i][j]==1)return false;
    }
    for(int i=row,j=colom;j<N&&i>=0;i--,j++){ // left diagonal
        if(board[i][j]==1)return false;
    }
    return true;
}
void NQueens(int **board,int row,int N){
    static int sol_count=0;
    if(row==N){
        sol_count++;
        cout<<"======== Solution "<<sol_count<<" ========"<<endl;
        printboard(board,N);
        cout<<endl;
        return;
    }

    for(int j=0;j<N;j++){
        if(isSafe(board,row,j,N)){
            board[row][j]=1;
            NQueens(board,row+1,N);
            board[row][j]=0;
        }
    }
    return ;
}
int main(){
    int n;
    cout<<"Enter the number of queens you want to placed: ";
    cin>>n;
    int **board;
    board = new int*[n];
    for(int i=0;i<n;i++){
        board[i]=new int[n]();
    }
    NQueens(board,0,n);
    for(int i=0;i<n;i++){
        delete[]board[i];
    }
    delete[]board;
    return 0;
}

