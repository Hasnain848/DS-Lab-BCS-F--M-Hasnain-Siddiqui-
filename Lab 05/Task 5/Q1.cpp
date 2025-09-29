#include<iostream>
using namespace std;
bool isSafe(int grid[9][9],int row,int colom,int digit){

    for(int j=0;j<9;j++){
        if(grid[row][j]==digit)
            return false;
    }
    for(int i=0;i<9;i++){
        if(grid[i][colom]==digit)
            return false;
    }
    int startgrid_row = (row/3)*3;
    int startgrid_colom = (colom/3)*3;
    for(int i=startgrid_row;i<=startgrid_row+2;i++){
        for(int j=startgrid_colom;j<= startgrid_colom+2;j++){
            if(grid[i][j]==digit)
            return false;
        }
    }
    return true;
}
bool sudokoSolver(int grid[9][9],int row,int colom){
    if(row==9)return true;
    int nextrow =row;
    int nextcolom=colom+1;
    if(nextcolom ==9){
        nextrow=row+1;
        nextcolom=0;
    }
    if(grid[row][colom]!=0){
        return sudokoSolver(grid,nextrow,nextcolom);
    }
    for(int dig=1;dig<=9;dig++){
        if(isSafe(grid,row,colom,dig)){
            grid[row][colom]=dig;
            if(sudokoSolver(grid,nextrow,nextcolom)){
                return true;
            }
            grid[row][colom]=0;
        }
    }
    return false;

}
void printGrid(int grid[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
int grid[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout<<"Original Sudoku:"<<endl;
    printGrid(grid);

    if(sudokoSolver(grid,0,0)){
        cout<<"\nSolved Sudoku:"<<endl;
        printGrid(grid);
    }
    else{
        cout<<"\nNo solution exists."<<endl;
    }
    return 0;
}
