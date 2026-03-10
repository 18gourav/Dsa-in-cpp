class Solution {
    private:
    bool knows(vector<vector<int>>& mat,int a ,int b,int n){
        if(mat[a][b] == 1){
            return true;
        }
        else{
            false;
        }
    }
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int row = mat.size();
        
        stack<int> s;
        
        for(int i=0; i<row; i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(mat,a,b,row)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int ans = s.top();
        
        int zeroCount=0;
        
        for(int i=0;i<row; i++){
            if(mat[ans][i]==0){
                zeroCount++;
            }
        }
        
        if(zeroCount != row-1){
            return -1;
        }
        
        int oneCount = 0;
        
        for(int i=0; i<row;i++){
            if(mat[i][ans]==1){
                oneCount++;
            }
        }
        
        if(oneCount != row){
            return -1;
        }
        
        return ans;
        
    }
};