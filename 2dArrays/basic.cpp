#include<iostream>   
using namespace std;

int main() {

    // in this 2d array [3] --> rows [4] --> columns
    int arr[3][4];
    
    // this is for row wise input and output
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
            //  output -- 1 2 3 4 
            //            5 6 7 8
            //            9 10 11 12
    }

    // this is for col wise input and output
    for(int col =0; col<4; col++){
        for(int row = 0; row<3;row++){
            cin>>arr[row][col];
        }
    }

    for(int col = 0; col<4; col++){
        for(int row=0; row<3; row++){
            cout<<arr[row][col]<<' ';
        }
        cout<<endl;
        // output --> 1 2 3 
        //            4 5 6 
        //            7 8 9 
        //            10 11 12

        return 0;
    }

    