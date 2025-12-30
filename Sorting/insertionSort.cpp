// timecomplexity:
//  best case: O(n)
//  worst case: O(n^2)
// use case- when the size of the array is small try to implement insertion sort
// space complexity = O(1)

#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i=1;
        for(;j>=0; j--){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}