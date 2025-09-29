#include<iostream>
using namespace std;
#define N 5
bool mazesolver(int maze[N][N],int x, int y,int sol[N][N]){
    if(x==N-1 && y==N-1){
        return true;
    }

    if(x>=0 && x<N&&y>=0 && y<N&& maze[x][y]==1 && sol[x][y]==0){
        sol[x][y]=1;
        if (mazesolver(maze,x,y+1,sol))return true;//right
        if (mazesolver(maze,x,y-1,sol))return true;//left
        if (mazesolver(maze,x+1,y,sol))return true;//down
        if (mazesolver(maze,x-1,y,sol))return true;//up
        sol[x][y]=0;
        return false;

    }
    return false;

}
void print(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
int main(){
    int maze[N][N] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 0, 1, 1}
    };
    int sol[N][N]={0};
    if(!mazesolver(maze,0,0,sol)){
        cout<<"Soory no solution"<<endl;
    }
    cout<<"Solution "<<endl;
    print(sol);
}