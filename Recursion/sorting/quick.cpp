#include<iostream>
using namespace std;

int partition(int *arr,int s,int e){
    int Pivot = arr[s];
    int count = 0;

    for(int i=s+1; i<=e; i++){
        if(Pivot>=arr[i]){
             count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex],arr[s]);

    while(s<pivotIndex && e>pivotIndex){
        while(Pivot>=arr[s]){
            s++;
        }
        while(Pivot<arr[e]){
            e--;
        }

        if(s<pivotIndex && e>pivotIndex){
            swap(arr[s++],arr[e--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e){
    if(s>=e){
        return ;
    }

    int p = partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);

}

int main() {

    int arr[5] = {3,8,5,2,4};

    quickSort(arr,0,4);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}