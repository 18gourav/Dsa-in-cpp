// Given an m x n matrix, return all elements of the matrix in spiral order

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

          vector<int> ans;
          int rows = matrix.size();          
          int cols = matrix[0].size();

          int count = 0;
          int total = rows * cols;

          int startingRow = 0;
          int startingCol = 0;
          int endingRow = rows - 1;
          int endingCol = cols - 1;

          while(count<total){
            //starting row
        for(int index = startingCol; count<total && index<=endingCol; index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;

            //ending col
        for(int index = startingRow;count<total && index<=endingRow; index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;

            //last row
        for(int index = endingCol;count<total && index>=startingCol; index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;

            //starting col
        for(int index = endingRow;count<total && index>=startingRow; index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;

          }

   return ans;
    }
};