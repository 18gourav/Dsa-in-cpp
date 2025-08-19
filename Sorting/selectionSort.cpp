// timecomplexity:
//  best case: O(n^2)
//  worst case: O(n^2)
// use case- when the size of the array is small try to implement selection sort
// space complexity = O(1)

#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i = 0; i<n; i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
            minIndex = j;
        }
        swap(arr[minIndex],arr[i]);
    }
    
}