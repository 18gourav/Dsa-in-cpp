#include<iostream>
#include<array>
using namespace std;

int main() {

    //we often do not use it bcoz it is static in nature
    array<int,4> arr = {1,2,3,4};
    int size = arr.size();
    cout<<size<<endl;

    for(int i=0; i<size; i++){
        cout << arr[i];
    }
    cout<<endl;

    // for accesing a element at a index
    cout<<"element at index 2 is "<< arr.at(2)<<endl;
    // to know whether a array is empty or not
    cout<<"the array is empty or not "<<arr.empty()<<endl;
    // to get array first elem
    cout<<"first element "<<arr.front()<<endl;
    // to get array last elem
    cout<<"the last elem is "<<arr.back();

    return 0;
}