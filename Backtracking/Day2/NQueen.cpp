#include <bits/stdc++.h>
void addSolution(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
	vector<int> temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
} 

bool isSafe(int row,int col,vector<vector<int>> &board,int n){

	//now check for the row
	for(int i=col;i>=0; i--){
		if(board[row][i] == 1){
			return false;
		}
	}

	int x = row;
	int y = col;
	//now check for up left diagnal elem
	while(x >= 0 && y >= 0){
		if(board[x][y] == 1){
			return false;
		}
		x--;
		y--;
	}

	x = row;
	y = col;
	//now check for the down left diagnla elem
	while(x<n && y>=0){
		if(board[x][y] == 1){
			return false;
		}
		x++;
		y--;
	}

	return true;
}
void solve(int col,vector<vector<int>> &board,vector<vector<int>> &ans,int n){
	//base case
	if(col == n){
		addSolution(board,ans,n);
		return ;
	}

	//now solve 1 case and rest recursion will take care
	
	//now we have to try to place queen at every row of 1st col and get sol
	for(int row =0; row<n; row++){
		if(isSafe(row,col,board,n)){
			board[row][col] = 1;
			solve(col+1,board,ans,n);
			board[row][col]= 0;
		}
	}
}
vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n,vector<int>(n,0));
	vector<vector<int>> ans;

	solve(0,board,ans,n);
	
	return ans;
}

//TC : O(N!)
//SC : O(N^2)