class Solution {
  public:
    pair<bool,int> isSumTreefast(Node* root){
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> left = isSumTreefast(root->left);
        pair<bool,int> right = isSumTreefast(root->right);
        
        bool op1 = left.first;
        bool op2 = right.first;
        bool op3 = (root->data) == (left.second + right.second);
        
        pair<bool,int> ans;
        
        if(op1 && op2 && op3){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
        }
        
        return ans;
        
    }
    bool isSumTree(Node* root) {
        // Your code here
        return isSumTreefast(root).first;
    }
};