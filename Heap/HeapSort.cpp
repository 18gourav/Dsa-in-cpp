#include<iostream>
using namespace std;
void heapify(int arr[],int n,int index){
    int largest = index;
    int left = largest * 2;
    int right = largest * 2 + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,n,largest);
    }

}

void heapSort(int arr[],int n){
    int size = n;

    while(size > 1){
        //step 1 -> swap first and last element
        swap(arr[1],arr[size]);

        //step2 --> decrease size cuz the first element we swapped is in correct position
        size--;

        //step 3--> the element which comes at first position, we have to heapify it cuz it is not in his correct pos
        heapify(arr,n,1);
    }
}

//TC of heapsort -> O(nlogn)

int main() {

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    heapSort(arr,n);

    for(int i=1; i<=n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}