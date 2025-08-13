// You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all
// pairs of elements such that each sum of elements of each pair equals 'S'.
//Each pair should be sorted i.e the first value should be less than or equals to the second value. 

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr,int S) {
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == S) {
                int first = min(arr[i], arr[j]);
                int second = max(arr[i], arr[j]);
                ans.push_back({first, second});
            }
        }
    }

    // Sort pairs first by first value, then second value
    sort(ans.begin(), ans.end());

    return ans;
}