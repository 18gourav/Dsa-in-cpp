#include<iostream>
using namespace std;

bool findElem(int arr[], int n,int key) {
    for(int i=0; i<n;i++){
        if(arr[i] == key ){
            return 1;
        }
    }
    return 0;
}

int main() {
    
    int arr[5] = {2,9,6,4,0};

    int key;
    cin>>key;

    bool found = findElem(arr,5,key);

    if(found) {
        cout<<"key element is founded";
    }
    else {
        cout<<"element not exist";
    }


    return 0;
}