class Solution {
    private:
    bool isSafe(int row,int col,vector<vector<char>>& board,int val){
        for(int i=0; i<board.size(); i++){
            //row check
            if(board[row][i] == val){
                return false;
            }

            //col check
            if(board[i][col] == val){
                return false;
            }

            //3*3 matrix check
            if(board[3*(row/3) + (i/3)][3*(col/3) + i%3] == val){
                return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board[0].size();
        //Process all matrix values
        for(int row=0; row<n; row++){
            for(int col =0; col<n; col++){
                //now check if a place is filled and check fitting no bw 1 and 9
                if(board[row][col] == '.'){
                    for(char val = '1'; val<='9'; val++){
                        if(isSafe(row,col,board,val)){
                            board[row][col] = val;
                            bool isPossibleSol = solve(board);                           if(isPossibleSol){
                                return true;
                            }
                            else{
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

//TC : 9^m
//SC : O(1)
//m -> no of empty cell