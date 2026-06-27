#include <bits/stdc++.h> 

bool isSafe(int newX,int newY,vector<vector<bool>> &vis,vector < vector < int >> & arr,int n){
    if((newX >= 0 && newX < n) && (newY >=0 && newY<n) && (vis[newX][newY] == 0) 
    && (arr[newX][newY] == 1)){
        return true;
    }
    else{
        return false;
    }
}

void solve(int x,int y,vector < vector < int >> & arr,int n,vector<string> &ans,
string path,vector<vector<bool>> &vis){
    //base case
    if( x == n-1 && y == n-1){
        ans.push_back(path);
        return ;
    }

    //4 movements
    //D
    //L
    //R
    //U
    vis[x][y] = 1;

    //Down
    if(isSafe(x+1,y,vis,arr,n)){
        solve(x+1,y,arr,n,ans,path+"D",vis);
    }

    //Left
    if(isSafe(x,y-1,vis,arr,n)){
        solve(x,y-1,arr,n,ans,path+"L",vis);
    }

    //Right
    if(isSafe(x,y+1,vis,arr,n)){
        solve(x,y+1,arr,n,ans,path+"R",vis);
    }

    //Up
    if(isSafe(x-1,y,vis,arr,n)){
        solve(x-1,y,arr,n,ans,path+"U",vis);
    }
    vis[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path = "";

    if(arr[0][0] == 0){
        return ans;
    }

    solve(0,0,arr,n,ans,path,visited);
    return ans;
}

// Tc -> 4^(n^2)
// Sc -> O(n^2)