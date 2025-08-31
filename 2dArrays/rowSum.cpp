#include<iostream>
#include<climits>
using namespace std;

int main(){

    int arr[3][4];
    int rowSum[3];
   
    for(int row =0; row<3; row++){
        for(int col = 0; col<4;col++){
            cin>>arr[row][col];
        }
    }

    for(int row = 0; row<3; row++){
        for(int col=0; col<4; col++){
            cout<<arr[row][col]<<' ';
        }
        cout<<endl;
    }

    int sum = 0;

    for(int row = 0; row<3; row++){
        for(int col=0; col<4; col++){
            sum += arr[row][col];
        }
        rowSum[row] = sum;
        sum = 0;
    }
    

    int maxi = INT_MIN;
    int rowIndex = -1;

    for(int j=0;j<3;j++) {
        if(rowSum[j] > maxi) {
            maxi = rowSum[j];
            rowIndex = j;
        }
       
    }
     cout<<rowIndex;


    return 0;
}