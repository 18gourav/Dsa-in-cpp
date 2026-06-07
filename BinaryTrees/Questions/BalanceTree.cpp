//This is the approach1
class Solution {
    private:
    int height(Node* root){
        //base case
        if(root == NULL){
            return -1;
        }
        
        //left tree
        int n1 = height(root->left);
        int n2 = height(root->right);
        
        int ans = max(n1,n2) + 1;
        
        return ans;
    }
  public:
    bool isBalanced(Node* root) {
        // code here
        //base case
        if(root == NULL){
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right  = isBalanced(root->right);
        
        bool balance = abs(height(root->left) - height(root->right)) <= 1;
        
        if(left & right & balance){
            return true;
        }
        
        return false;
        
    }
};

//this is the approach2
class Solution {
    
  public:
    pair<bool,int> isBalancedFast(Node* root){
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right =isBalancedFast(root->right);
        
        bool op1 = left.first;
        bool op2 = right.first;
        bool op3 = abs(left.second - right.second) <= 1;
        
        pair<bool,int> ans;
        ans.second = max(left.second,right.second) + 1;
        
        if(op1 & op2 & op3){
            ans.first = true;
            return ans;
        }
        
        ans.first = false;
        return ans;
    }
    bool isBalanced(Node* root) {
        // code here
        
        return isBalancedFast(root).first;
    }
};