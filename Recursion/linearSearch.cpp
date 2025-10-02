#include<iostream>
using namespace std;


bool isPresent(int arr[], int n,int key){
    if(n == 0){
        return 0;
    }

    if(arr[0] == key){
        return true;
    }
    else{
        int part = isPresent(arr+1,n-1,key);
        return part;
    }
    

}

int main(){

    int arr[5] = {1,2,3,4,5};
    int size = 5;

    int ans = isPresent(arr,size,5);
    if(ans){
        cout<<"the elem is present";
    }
    else {
        cout<<"the elem is not present";
    }
    
    return 0;
}