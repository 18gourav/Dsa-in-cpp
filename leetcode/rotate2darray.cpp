// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix
// and do the rotation.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        // temp matrix (NOT const, and properly sized)
        vector<vector<int>> ans(row, vector<int>(col));

        int k = 0;
        int m = 0;

        for (int i = 0; i < col; i++) {
            for (int j = row - 1; j >= 0; j--) {
                ans[k][m] = matrix[j][i];
                m++;
            }
            k++;
            m = 0;
        }

        // copy back to original matrix
        matrix = ans;
    }
};
