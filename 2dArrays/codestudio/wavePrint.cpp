// For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e.,
// print the first column top to bottom, next column bottom to top, and so on.
// For eg:-
// The sine wave for the matrix:-
// 1 2
// 3 4
// will be [1, 3, 4, 2].

#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int i = 0; i < mCols; i++) {
    if (i % 2 == 0) {
        //odd index -->  Top to bottom
        for (int j = 0; j < nRows; j++) {
            ans.push_back(arr[j][i]);
        }
    } else {
        //even index --> Bottom to top
        for (int j = nRows - 1; j >= 0; j--) {
            ans.push_back(arr[j][i]);
        }
        }
    }
    return ans;
}
