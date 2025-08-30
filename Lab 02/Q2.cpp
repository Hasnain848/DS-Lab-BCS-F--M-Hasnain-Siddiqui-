/*Task #2:
Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
=> Rows represent benches, columns represent seats on each bench.
=> Initialize the array with 0 (empty).
=> Let the user fill seats (1 for occupied).
=> Print the final seating chart in matrix form*/
#include<iostream>
using namespace std;
int main(){
    int **seatchart;
    int row ,colom,choice;
    cout<<"Enter the row in class: ";
    cin>>row;
    cout<<"Enter the seats on each bench: ";
    cin>>colom;
    seatchart = new int*[row];
    for(int i=0;i<row;i++){
        seatchart[i] =new int [colom]; 
    }
    seatchart[0][0]=0;
    // cout<<"Enetr the seats which are Occupied (1 for occupied and 0 for not-occupied)"<<endl;
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<colom;j++){
    //         cout<<"Bench "<<i+1<<" Seat "<<j+1<<" : ";//<<endl;;
    //         cin>>seatchart[i][j];
    //     }
    // }
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<colom;j++){
    //         cout<<"Bench "<<i+1<<" Seat "<<j+1<<" : "<<(seatchart[i][j]==1)?"Occupied":"Not Occupied";
    //     }
    // }
    cout << "Enter seat occupancy (1 for occupied, 0 for not occupied):\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colom; j++) {
            cout << "Bench " << i + 1 << " Seat " << j + 1 << ": ";
            cin >>choice;//seatchart[i][j];
            if(choice != 0 && choice != 1) {
            cout << "Invalid entry, setting seat as not occupied (0)." << endl;
            choice = 0; 
        }
            seatchart[i][j]=choice;
        }
    }

    cout << "\nFinal Seating Chart (0 = empty, 1 = occupied):\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colom; j++) {
            cout << seatchart[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i=0;i<row;i++){
        delete [] seatchart[i];
    }
    delete[] seatchart;

}