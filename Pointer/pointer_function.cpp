#include<iostream>
using namespace std;

void print(int *p){
    cout<<*p;
}

void update(int *p){
    p = p + 1;
}

int getSum(int arr[], int n){


    // in this size of arr is 8 --> why? --> because in function(int arr[]) we are passing pointer not entire array
    //so it has only address which has 8 byte size
    cout<<"size of the array is : "<<sizeof(arr)<<endl;

    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += i[arr];
    }

    return sum;
}

int main() {

    int a = 5;
    int *b = &a;
    // print(b);

    //these 2 cout statements will print 2 same address --> because the value of p is updated in update func
    //intead of p = p + 1 --> *p = *p + 1(if we do this then it will update p value in main func)
    // cout<<"before : "<<b<<endl;
    // update(b);
    // cout<<"after : "<<b<<endl;

    int brr[5] = {1,2,3,4,5};
    cout<<"sum of the array is "<<getSum(brr,5);



    return 0;
}