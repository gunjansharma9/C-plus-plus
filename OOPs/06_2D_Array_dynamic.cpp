#include <iostream>
using namespace std;

int main(){
    int row = 5;
    int col = 3;
    int **arr = new int*[row ];

    for(int i=0;i<row;i++){
        arr[i] = new int[col];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<row;i++){
        delete []arr[col];
    }

    delete []arr;
    return 0;
}
