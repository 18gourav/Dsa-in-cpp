class Solution {
  public:
    void solve(Node* root,vector<int> &ans,int level){
        //base case
        if(root == NULL){
            return ;
        }
        
        //to check we neterd in anew level
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        
        //go in left
        solve(root->left,ans,level+1);
        
        //go in right
        solve(root->right,ans,level+1);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        
        solve(root,ans,0);
        
        return ans;
    }
};