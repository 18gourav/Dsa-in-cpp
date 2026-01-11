#include<iostream>
using namespace std;


int getSum(int arr[], int n){
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return arr[0];
    }

    
    int part = getSum(arr+1,n-1);
    int sum = arr[0] + part;

    return sum;

}

int main(){

    int arr[5] = {1,2,3,4,5};
    int size = 5;

    cout << getSum(arr,size);
    
    return 0;
}