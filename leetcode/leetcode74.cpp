// this is basically the binary search in 2d arrays

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();          
        int cols = matrix[0].size();

        int s = 0;
        int e = (rows * cols) - 1;
        int mid = s + (e-s)/2;

        while(s<=e){
           int element = matrix[mid/cols][mid%cols];
           if(element == target){
            return 1;
           }
           else if(target > element){
            s = mid + 1;
           }
           else if(target < element){
            e = mid - 1;
           }
           mid = s + (e-s)/2;
        }

        return 0;
        
    }
};